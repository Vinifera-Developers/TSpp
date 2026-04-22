/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Data buffer pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "pipe.h"


class BufferPipe : public Pipe
{
public:
    BufferPipe(const Buffer& buffer) : BufferPtr(buffer), Index(0) {}
    BufferPipe(void* buffer, int length) : BufferPtr(buffer, length), Index(0) {}

    virtual int Put(const void* source, int slen) override;

private:
    bool Is_Valid() { return BufferPtr.Is_Valid(); }

private:
    Buffer BufferPtr;
    int Index;

private:
    BufferPipe(BufferPipe&) = delete;
    BufferPipe& operator=(const BufferPipe&) = delete;
};
