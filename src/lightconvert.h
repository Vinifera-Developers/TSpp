/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LIGHTCONVERT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Palette drawer.
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

#include "convert.h"


class Surface;
class PaletteClass;


class LightConvertClass : public ConvertClass
{
public:
    LightConvertClass(PaletteClass* pal1, PaletteClass* pal2, Surface* surface, int r = -1, int g = -1, int b = -1, bool a8 = false, bool* a9 = nullptr, int a10 = 63);
    LightConvertClass(const NoInitClass& noinit);
    virtual ~LightConvertClass();

    virtual void Adjust(int r, int g, int b, bool a4);

private:
    PaletteClass* field_190;
    PaletteClass* field_194;
    bool* field_198; // mask?
    int field_19C;   // ref count?
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    bool field_1B8;
};
