/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Cached straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "straw.h"


class CacheStraw : public Straw
{
public:
    CacheStraw(const Buffer& buffer) : BufferPtr(buffer), Index(0), Length(0) {}
    CacheStraw(int length = 4096) : BufferPtr(length), Index(0), Length(0) {}
    virtual ~CacheStraw() {}

    virtual int Get(void* source, int slen) override;

private:
    bool Is_Valid() { return BufferPtr.Is_Valid(); }

private:
    Buffer BufferPtr;
    int Index;
    int Length;

private:
    CacheStraw(const CacheStraw&) = delete;
    CacheStraw& operator=(const CacheStraw&) = delete;
};
