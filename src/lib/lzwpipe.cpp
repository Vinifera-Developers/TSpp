/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LZW driven pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "lzwpipe.h"
#include "lzw.h"
#include "tspp_assert.h"
#include <memory>


LZWPipe::LZWPipe(CompControl control, int blocksize) : Control(control), Counter(0), Buffer(nullptr), Buffer2(nullptr), BlockSize(blocksize)
{
    SafetyMargin = BlockSize;
    Buffer = new char[BlockSize + SafetyMargin];
    Buffer2 = new char[BlockSize + SafetyMargin];
    BlockHeader.CompCount = 0xFFFF;
}


LZWPipe::~LZWPipe()
{
    delete[] Buffer;
    Buffer = nullptr;

    delete[] Buffer2;
    Buffer2 = nullptr;
}


int LZWPipe::Put(void const* source, int slen)
{
    if (source == nullptr || slen < 1) {
        return Pipe::Put(source, slen);
    }

    TSPP_ASSERT(Buffer != nullptr);

    int total = 0;

    if (Control == DECOMPRESS) {

        while (slen > 0) {

            if (BlockHeader.CompCount == 0xFFFF) {
                int len = (slen < ((int)sizeof(BlockHeader) - Counter)) ? slen : (sizeof(BlockHeader) - Counter);
                std::memmove(&Buffer[Counter], source, len);
                source = ((char*)source) + len;
                slen -= len;
                Counter += len;

                if (Counter == sizeof(BlockHeader)) {
                    std::memmove(&BlockHeader, Buffer, sizeof(BlockHeader));
                    Counter = 0;
                }
            }

            if (slen > 0) {
                int len = (slen < (BlockHeader.CompCount - Counter)) ? slen : (BlockHeader.CompCount - Counter);

                std::memmove(&Buffer[Counter], source, len);
                slen -= len;
                source = ((char*)source) + len;
                Counter += len;

                if (Counter == BlockHeader.CompCount) {
                    LZW_Uncompress(Buffer, Buffer2);
                    total += Pipe::Put(Buffer2, BlockHeader.UncompCount);
                    Counter = 0;
                    BlockHeader.CompCount = 0xFFFF;
                }
            }
        }

    } else {

        if (Counter > 0) {
            int tocopy = (slen < (BlockSize - Counter)) ? slen : (BlockSize - Counter);
            std::memmove(&Buffer[Counter], source, tocopy);
            source = ((char*)source) + tocopy;
            slen -= tocopy;
            Counter += tocopy;

            if (Counter == BlockSize) {
                int len = LZW_Compress(::Buffer(Buffer, BlockSize), Buffer2);

                BlockHeader.CompCount = (unsigned short)len;
                BlockHeader.UncompCount = (unsigned short)BlockSize;
                total += Pipe::Put(&BlockHeader, sizeof(BlockHeader));
                total += Pipe::Put(Buffer2, len);
                Counter = 0;
            }
        }

        while (slen >= BlockSize) {
            int len = LZW_Compress(::Buffer((void*)source, BlockSize), Buffer2);

            source = ((char*)source) + BlockSize;
            slen -= BlockSize;

            BlockHeader.CompCount = (unsigned short)len;
            BlockHeader.UncompCount = (unsigned short)BlockSize;
            total += Pipe::Put(&BlockHeader, sizeof(BlockHeader));
            total += Pipe::Put(Buffer2, len);
        }

        if (slen > 0) {
            std::memmove(Buffer, source, slen);
            Counter = slen;
        }
    }

    return total;
}


int LZWPipe::Flush()
{
    TSPP_ASSERT(Buffer != nullptr);

    int total = 0;

    if (Counter > 0) {
        if (Control == DECOMPRESS) {

            if (BlockHeader.CompCount == 0xFFFF) {
                total += Pipe::Put(Buffer, Counter);
                Counter = 0;
            }

            if (Counter > 0) {
                total += Pipe::Put(&BlockHeader, sizeof(BlockHeader));
                total += Pipe::Put(Buffer, Counter);
                Counter = 0;
                BlockHeader.CompCount = 0xFFFF;
            }

        } else {

            int len = LZW_Compress(::Buffer(Buffer, Counter), Buffer2);

            BlockHeader.CompCount = (unsigned short)len;
            BlockHeader.UncompCount = (unsigned short)Counter;
            total += Pipe::Put(&BlockHeader, sizeof(BlockHeader));
            total += Pipe::Put(Buffer2, len);
            Counter = 0;
        }
    }

    total += Pipe::Flush();
    return total;
}
