/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base64 data straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "straw.h"


class Base64Straw : public Straw
{
public:
    typedef enum CodeControl {
        ENCODE,
        DECODE
    } CodeControl;

public:
    Base64Straw(CodeControl control) : Control(control), Counter(0), CBuffer(), PBuffer() {}

    virtual int Get(void* source, int slen) override;

private:
    CodeControl Control;
    int Counter;
    char CBuffer[4];
    char PBuffer[3];

private:
    Base64Straw(const Base64Straw&) = delete;
    Base64Straw& operator=(const Base64Straw&) = delete;
};
