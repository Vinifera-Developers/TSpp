/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base64 data pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"


class Base64Pipe : public Pipe
{
public:
    typedef enum CodeControl {
        ENCODE,
        DECODE
    } CodeControl;

    Base64Pipe(CodeControl control) : Control(control), Counter(0), CBuffer(), PBuffer() {}

    virtual int Flush() override;
    virtual int Put(const void* source, int slen) override;

private:
    CodeControl Control;
    int Counter;
    char CBuffer[4];
    char PBuffer[3];

private:
    Base64Pipe(const Base64Pipe& rvalue) = delete;
    Base64Pipe& operator=(const Base64Pipe&) = delete;
};
