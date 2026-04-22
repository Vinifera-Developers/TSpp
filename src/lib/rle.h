/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Run-length encoding (RLE) implementation.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "buff.h"


class RLEClass
{
public:
    RLEClass() {}

    int Compress(void* source, void* dest, int length);
    int Uncompress(void* source, void* dest);
};


inline int RLE_Compress(const Buffer& inbuff, const Buffer& outbuff)
{
    RLEClass rle;
    return rle.Compress(inbuff, outbuff, inbuff.Get_Size());
}


inline int RLE_Uncompress(const Buffer& inbuff, const Buffer& outbuff)
{
    RLEClass rle;
    return rle.Uncompress(inbuff, outbuff);
}
