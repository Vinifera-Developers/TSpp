/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DROPSHIP.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Dropship unit loadout class.
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


class TechnoTypeClass;
class XSurface;
class ConvertClass;
class Blitter;


class DropshipLoadoutClass
{
public:
    DropshipLoadoutClass();
    ~DropshipLoadoutClass();

    bool Add(TechnoTypeClass* technotype);
    bool Remove(int index);
    void Remove_All();
    void Load();
    TechnoTypeClass* Fetch(int index);

public:
    int field_0;
    int field_4;
    int field_8;
    bool field_C;
    int EntryCount;
    TechnoTypeClass* field_14[5];
    int field_28;
};

int Dropship_Get_Allowable_Index(TechnoTypeClass* technotype);
void Dropship_Draw_Text(int a1, int a2, XSurface* surface, Point2D* xy, char* string, bool a6, ConvertClass* drawer, Blitter* blitter);
void Dropship_Draw_Info_Text(XSurface* surface, ConvertClass* drawer, TechnoTypeClass* technotype, bool a4);
void Dropship_Loadout();
