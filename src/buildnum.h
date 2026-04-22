/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic build information (Author, number, date, etc).
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "always.h"


class BuildInfoClass
{
private:
    /**
     *  The original functions have a awkward prototype, use the public
     *  functions below instead of these.
     */
    static uint32_t Original_Get_Build_Number();
    static const char* Original_Get_Build_Number_String(char* buffer, unsigned buflen);
    static const char* Original_Get_Builder_Name_String(char* buffer, unsigned buflen);
    static const char* Original_Get_Build_Date_String(char* buffer, unsigned buflen);
    static const char* Original_Get_Builder_Initials(char* buffer);
    static const char* Original_Get_Build_Version_String(char* buffer, unsigned buflen);

public:
    static uint32_t Get_Build_Number() { return Original_Get_Build_Number(); }

    static const char* Get_Build_Number_String()
    {
        static char _buffer[1024];
        Original_Get_Build_Number_String(_buffer, sizeof(_buffer));
        return _buffer;
    }

    static const char* Get_Builder_Name_String()
    {
        static char _buffer[1024];
        Original_Get_Builder_Name_String(_buffer, sizeof(_buffer));
        return _buffer;
    }

    static const char* Get_Build_Date_String()
    {
        static char _buffer[1024];
        Original_Get_Build_Date_String(_buffer, sizeof(_buffer));
        return _buffer;
    }

    static const char* Get_Builder_Initials()
    {
        static char _buffer[1024];
        Original_Get_Builder_Initials(_buffer);
        return _buffer;
    }

    static const char* Get_Build_Version_String()
    {
        static char _buffer[1024];
        Original_Get_Build_Version_String(_buffer, sizeof(_buffer));
        return _buffer;
    }
};
