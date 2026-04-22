/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Text file i/o class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "textfile.h"
#include "readline.h"
#include "tspp_assert.h"


int TextFileClass::Read_Line(char* string, bool& eof)
{
    TSPP_ASSERT(string != nullptr);

    char buffer[MAX_LINE_LENGTH];
    eof = false; // Reset

    int total = ::Read_Line(*this, buffer, sizeof(buffer), eof);
    std::strcpy(string, buffer);

    return total;
}


int TextFileClass::Write_Line(char* string)
{
    TSPP_ASSERT(string != nullptr);

    int len = std::strlen(string);

    int total = RawFileClass::Write(string, len);
    if (total == len) {
        return total;
    }

    return -1;
}


int TextFileClass::Write_Line_Format(char* format, ...)
{
    TSPP_ASSERT(format != nullptr);

    char buffer[MAX_LINE_LENGTH];

    va_list args;
    va_start(args, format);

    std::vsnprintf(buffer, sizeof(buffer), format, args);

    va_end(args);

    int len = std::strlen(buffer);

    int total = RawFileClass::Write(buffer, len);
    if (total == len) {
        return total;
    }

    return -1;
}
