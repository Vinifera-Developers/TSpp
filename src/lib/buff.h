/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A general purpose buffer object.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class Buffer
{
public:
    Buffer(char* ptr, long size = 0);
    Buffer(void* ptr = nullptr, long size = 0);
    Buffer(const void* ptr, long size = 0);
    Buffer(long size);
    Buffer(const Buffer& buffer);
    ~Buffer();

    Buffer& operator=(const Buffer& buffer);

    operator void*() const { return BufferPtr; }
    operator char*() const { return (char*)BufferPtr; }

    void Reset();
    void* Get_Buffer() const { return BufferPtr; }
    long Get_Size() const { return Size; }
    bool Is_Valid() const { return BufferPtr != nullptr; }

protected:
    void* BufferPtr;
    long Size;
    bool IsAllocated;
};
