/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Voxel palette lookup container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "voxel.hh"


class VoxelLibraryClass;
class FileClass;


/**
 *  Voxel palette lookup file header (VPL: Voxel Palette Lookup).
 */
typedef struct VPLHeaderStruct {
    int RemapStart;
    int RemapEnd;
    int LUTCount;
    int field_C;
};


class VoxelPaletteClass
{
    friend VoxelLibraryClass;

public:
    VoxelPaletteClass(void* palette, void* lut);
    ~VoxelPaletteClass();

    bool Read_Palette_File(FileClass* file);
    bool Read_File(FileClass* file);
    bool Write_File(FileClass* file);

    void Calculate_Lookup_Table(float* a1 = nullptr, int lut_count = 0);
    unsigned char Closest_Color(float red, float green, float blue) const;
    unsigned char Closest_Color(float red, float green, float blue, bool is_remap) const;

    const VPLHeaderStruct& Get_Header_Info() const { return Header; }

private:
    /**
     *  Copy of the voxel palette file header.
     */
    VPLHeaderStruct Header;

    /**
     *  Standard 256 rgb color palette.
     */
    RGBStruct* Palette;

    /**
     *  This table is an adjustment for the main palette. Each of the table entries
     *  contains a remap index for the palette, allowing adjustments to the voxel for
     *  emulating lighting/shading when rendering.
     *
     *  Size defined by MAX_PALETTE_LOOKUP_ENTRIES.
     */
    unsigned char* PaletteLookup;

    /**
     *  Did we allocate the buffers ourself? (used for cleaning up memory)?
     */
    BOOL PaletteAllocated;
    BOOL LUTAllocated;
};
