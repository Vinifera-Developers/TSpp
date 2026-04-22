/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Palette drawer.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
