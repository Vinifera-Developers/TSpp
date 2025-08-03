/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LZWSTRAW.CPP
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         LZW driven straw.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#include "lzwstraw.h"
#include "lzw.h"
#include "tspp_assert.h"
#include <memory>


LZWStraw::LZWStraw(CompControl control, int blocksize) :
    Control(control),
    Counter(0),
    Buffer(nullptr),
    Buffer2(nullptr),
    BlockSize(blocksize)
{
    SafetyMargin = BlockSize;
    Buffer = new char[BlockSize + SafetyMargin];
    if (control == COMPRESS) {
        Buffer2 = new char[BlockSize + SafetyMargin];
    }
}


LZWStraw::~LZWStraw(void)
{
    delete[] Buffer;
    Buffer = nullptr;

    delete[] Buffer2;
    Buffer2 = nullptr;
}


int LZWStraw::Get(void* destbuf, int slen)
{
    TSPP_ASSERT(Buffer != nullptr);

    int total = 0;

    if (destbuf == nullptr || slen < 1) {
        return 0;
    }

    while (slen > 0) {

        if (Counter) {
            int len = (slen < Counter) ? slen : Counter;
            if (Control == DECOMPRESS) {
                std::memmove(destbuf, &Buffer[BlockHeader.UncompCount - Counter], len);
            } else {
                std::memmove(destbuf, &Buffer2[(BlockHeader.CompCount + sizeof(BlockHeader)) - Counter], len);
            }
            destbuf = ((char*)destbuf) + len;
            slen -= len;
            Counter -= len;
            total += len;
        }
        if (slen == 0) break;

        if (Control == DECOMPRESS) {
            int incount = Straw::Get(&BlockHeader, sizeof(BlockHeader));
            if (incount != sizeof(BlockHeader)) break;

            void* ptr = &Buffer[(BlockSize + SafetyMargin) - BlockHeader.CompCount];
            incount = Straw::Get(ptr, BlockHeader.CompCount);
            if (incount != BlockHeader.CompCount) break;

            LZW_Uncompress(ptr, Buffer);
            Counter = BlockHeader.UncompCount;
        } else {
            BlockHeader.UncompCount = (unsigned short)Straw::Get(Buffer, BlockSize);
            if (BlockHeader.UncompCount == 0) break;
            BlockHeader.CompCount = (unsigned short)LZW_Compress(::Buffer(Buffer, BlockHeader.UncompCount), &Buffer2[sizeof(BlockHeader)]);
            std::memmove(Buffer2, &BlockHeader, sizeof(BlockHeader));
            Counter = BlockHeader.CompCount + sizeof(BlockHeader);
        }
    }

    return total;
}
