/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Various globals for the voxel system.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "voxel.hh"


extern int VPL_RemapStart;
extern int VPL_RemapEnd;
extern int VPL_SectionCount;
extern int VPL_field_C;


extern RGBStruct Voxel_Palette[VOXEL_PALETTE_SIZE];
extern unsigned char Voxel_PaletteLookup[MAX_PALETTE_LOOKUP_ENTRIES][VOXEL_PALETTE_SIZE];
