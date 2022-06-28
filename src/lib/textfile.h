/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEXTFILE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Text file i/o class.
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
#include "rawfile.h"


class TextFileClass : public RawFileClass
{
    public:
        enum {
            MAX_LINE_LENGTH = 128
        };

    public:
        TextFileClass() : RawFileClass() {}
        TextFileClass(char const *filename) : RawFileClass(filename) {}
        virtual ~TextFileClass() {}

        int Read_Line(char *string, bool &last_line);
        int Write_Line(char *string);
        int Write_Line_Format(char *string, ...);
};
