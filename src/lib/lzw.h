/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LZW.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         LZW compression engine.
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once

#include "buff.h"


class LZWEngine
{
    public:
        LZWEngine();

        int Compress(Buffer const & input, Buffer const & output);
        int Uncompress(Buffer const & input, Buffer const & output);

        void Reset();

    private:
        typedef short CodeType;

        struct CodeClass
        {
            public:
                CodeClass() : CodeValue(0), ParentCode(0), CharValue(0) {}
                CodeClass(CodeType code, CodeType parent, char c) : CodeValue(code), ParentCode(parent), CharValue(c) {}

                enum { UNUSED = -1 };

                void Make_Unused() { CodeValue = UNUSED; }
                bool Is_Unused() const { return CodeValue == UNUSED; }
                bool Is_Matching(CodeType code, char c) const { return ParentCode == code && CharValue == c; }

            public:
                CodeType CodeValue;
                CodeType ParentCode;
                char CharValue;
        };

        enum {
            BITS = 12,
            MAX_CODE = ((1 << BITS ) - 1),
            FIRST_CODE = 257,
            END_OF_STREAM = 256,
            TABLE_SIZE = 5021
        };

        CodeClass Dict[TABLE_SIZE];

        char Decode_Stack[TABLE_SIZE];

        int Find_Child_Node(CodeType parent_code, char child_character);
        int Decode_String(char * ptr, CodeType code);
        static int Make_LZW_Hash(CodeType code, char character);
};


inline int LZW_Uncompress(const Buffer & inbuff, const Buffer & outbuff)
{
    LZWEngine lzw;
    return lzw.Uncompress(inbuff, outbuff);
}


inline int LZW_Compress(const Buffer & inbuff, const Buffer & outbuff)
{
    LZWEngine lzw;
    return lzw.Compress(inbuff, outbuff);
}
