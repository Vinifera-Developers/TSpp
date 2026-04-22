/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LCW compression pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"


class LCWPipe : public Pipe
{
public:
    typedef enum CompControl {
        COMPRESS,
        DECOMPRESS
    } CompControl;

    LCWPipe(CompControl control, int blocksize = 1024 * 8);
    virtual ~LCWPipe();

    virtual int Flush() override;
    virtual int Put(const void* source, int slen) override;

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
    LCWPipe(const LCWPipe&) = delete;
    LCWPipe& operator=(const LCWPipe&) = delete;
};
