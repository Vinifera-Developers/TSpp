/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Text file i/o class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "rawfile.h"


class TextFileClass : public RawFileClass
{
public:
    enum {
        MAX_LINE_LENGTH = 128
    };

public:
    TextFileClass() : RawFileClass() {}
    TextFileClass(char const* filename) : RawFileClass(filename) {}
    TextFileClass(Wstring const& filename);
    virtual ~TextFileClass() {}

    int Read_Line(char* string, bool& last_line);
    int Write_Line(char* string);
    int Write_Line_Format(char* string, ...);
};
