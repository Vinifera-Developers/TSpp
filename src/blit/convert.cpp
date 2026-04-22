/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Palette drawer.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "convert.h"
#include "ccfile.h"
#include "mixfile.h"
#include "palette.h"
#include "tibsun_functions.h"
#include "tibsun_globals.h"


/**
 *  Creates a palette drawer from input surface and palette.
 *
 *  @author: CCHyper
 */
ConvertClass* ConvertClass::Create_Drawer(const char* pal_filename, PaletteClass* pal, XSurface* surface)
{
    const void* palfile = MFCD::Retrieve(pal_filename);
    if (!palfile) {
        return nullptr;
    }

    PaletteClass loaded_pal;
    std::memcpy(&loaded_pal, palfile, sizeof(PaletteClass));

    ConvertClass* drawer = new ConvertClass(&loaded_pal, pal, surface, 63, false);
    TSPP_ASSERT(drawer != nullptr);
    return drawer;
}


/**
 *  Loads palette and creates a drawer.
 *
 *  @warning	You must clean up memory if you use this function!
 *
 *  @author: CCHyper
 */
ConvertClass* ConvertClass::Create_Drawer(const char* pal_filename)
{
    CCFileClass file;

    file.Set_Name(pal_filename);
    file.Open(FILE_ACCESS_READ);

    if (!file.Is_Available()) {
        return nullptr;
    }

    void* data = Load_Alloc_Data(file);
    if (!data) {
        return nullptr;
    }

    PaletteClass loaded_pal;
    std::memcpy(&loaded_pal, data, sizeof(PaletteClass));

    ConvertClass* drawer = new ConvertClass(&loaded_pal, &OriginalPalette, VisibleSurface, 1);
    TSPP_ASSERT(drawer != nullptr);
    return drawer;
}
