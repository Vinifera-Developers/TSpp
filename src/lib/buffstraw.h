/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Data buffer straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "straw.h"


class BufferStraw : public Straw
{
public:
    BufferStraw(const Buffer& buffer) : BufferPtr(buffer), Index(0) {}
    BufferStraw(const void* buffer, int length) : BufferPtr((void*)buffer, length), Index(0) {}

    virtual int Get(void* source, int slen) override;

private:
    bool Is_Valid() { return BufferPtr.Is_Valid(); }

private:
    Buffer BufferPtr;
    int Index;

private:
    BufferStraw(BufferStraw&) = delete;
    BufferStraw& operator=(const BufferStraw&) = delete;
};
