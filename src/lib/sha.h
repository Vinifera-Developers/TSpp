/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Implementation of the Secure Hash Algorithm.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include <new>


class SHAEngine
{
private:
    typedef union {
        unsigned long Long[5];
        unsigned char Char[20];
    } SHADigest;

    enum : unsigned {
        SRC_BLOCK_SIZE = 16 * sizeof(long),
        PROC_BLOCK_SIZE = 80 * sizeof(long)
    };

public:
    SHAEngine();

    void Init() { new ((void*)this) SHAEngine; };

    int Result(void* result) const;
    void Hash(void const* data, long length);
    void Process_Block(void const* source, SHADigest& acc) const;
    void Process_Partial(void const*& data, long& length);

    static int Digest_Size() { return sizeof(SHADigest); }

private:
    bool IsCached;
    SHADigest FinalResult;
    SHADigest Acc;
    long Length;
    int PartialCount;
    char Partial[SRC_BLOCK_SIZE];
};
