/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LZW driven pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"


class LZWPipe : public Pipe
{
public:
    typedef enum CompControl {
        COMPRESS,
        DECOMPRESS
    } CompControl;

    LZWPipe(CompControl, int blocksize = 1024 * 8);
    virtual ~LZWPipe();

    virtual int Flush() override;
    virtual int Put(void const* source, int slen) override;

private:
    CompControl Control;
    int Counter;
    char* Buffer;
    char* Buffer2;
    int BlockSize;
    int SafetyMargin;
    struct {
        unsigned short CompCount;
        unsigned short UncompCount;
    } BlockHeader;

private:
    LZWPipe(LZWPipe&) = delete;
    LZWPipe& operator=(const LZWPipe&) = delete;
};
