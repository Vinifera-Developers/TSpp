/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DICT.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Hash table using a dictionary type.
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
#include "wstring.h"


class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    static unsigned CRC(Wstring& string);

public:
    void* Entries;  // 0x00
    int EntryCount; // 0x04
    int field_8;
    int field_0C;
    int field_10;
    bool field_14;
    void* CRC_Function; // 0x18
    int field_1C;
    double field_20;
    double field_28;
    double field_30;
};
