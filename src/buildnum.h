/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUILDNUM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic build information (Author, number, date, etc).
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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
        static const char *Original_Get_Build_Number_String(char *buffer, unsigned buflen);
        static const char *Original_Get_Builder_Name_String(char *buffer, unsigned buflen);
        static const char *Original_Get_Build_Date_String(char *buffer, unsigned buflen);
        static const char *Original_Get_Builder_Initials(char *buffer);
        static const char *Original_Get_Build_Version_String(char *buffer, unsigned buflen);

    public:
        static uint32_t Get_Build_Number()
        {
            return Original_Get_Build_Number();
        }

        static const char *Get_Build_Number_String()
        {
            static char _buffer[1024];
            Original_Get_Build_Number_String(_buffer, sizeof(_buffer));
            return _buffer;
        }

        static const char *Get_Builder_Name_String()
        {
            static char _buffer[1024];
            Original_Get_Builder_Name_String(_buffer, sizeof(_buffer));
            return _buffer;
        }

        static const char *Get_Build_Date_String()
        {
            static char _buffer[1024];
            Original_Get_Build_Date_String(_buffer, sizeof(_buffer));
            return _buffer;
        }

        static const char *Get_Builder_Initials()
        {
            static char _buffer[1024];
            Original_Get_Builder_Initials(_buffer);
            return _buffer;
        }

        static const char *Get_Build_Version_String()
        {
            static char _buffer[1024];
            Original_Get_Build_Version_String(_buffer, sizeof(_buffer));
            return _buffer;
        }
};
