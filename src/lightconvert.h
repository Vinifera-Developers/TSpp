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
    LightConvertClass(PaletteClass* artpalette, PaletteClass* screenpalette, Surface* typicalsurface, int red_tint = -1, int green_tint = -1, int blue_tint = -1, bool blitters_created = false, bool* tint_mask = nullptr, int intensity_levels = 63);
    LightConvertClass(const NoInitClass& noinit);
    virtual ~LightConvertClass();

    virtual void Apply_Tint(int red_tint, int green_tint, int blue_tint, bool ion_light);

    void Add_Reference() { ReferenceCount++; }
    void Remove_Reference() { ReferenceCount--; }

private:
    PaletteClass* ArtPalette;
    PaletteClass* ScreenPalette;
    bool* TintMask; // colors with "true" are tinted, colors with "false" are just shaded
    int ReferenceCount;
    int NormalRedTint;
    int NormalGreenTint;
    int NormalBlueTint;
    int IonRedTint;
    int IonGreenTint;
    int IonBlueTint;
    bool UseIonLighting;
};
