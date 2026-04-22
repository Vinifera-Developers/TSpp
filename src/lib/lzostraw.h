/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LZO driven straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "straw.h"


class LZOStraw : public Straw
{
public:
    typedef enum CompControl {
        COMPRESS,
        DECOMPRESS
    } CompControl;

    LZOStraw(CompControl control, int blocksize = 1024 * 8);
    virtual ~LZOStraw();

    virtual int Get(void* source, int slen) override;

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
    LZOStraw(LZOStraw&) = delete;
    LZOStraw& operator=(const LZOStraw&) = delete;
};
