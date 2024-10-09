/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELGLOBALS.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Various globals for the voxel system.
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
#include "voxel.hh"


extern int VPL_RemapStart;
extern int VPL_RemapEnd;
extern int VPL_SectionCount;
extern int VPL_field_C;


extern RGBStruct Voxel_Palette[VOXEL_PALETTE_SIZE];
extern unsigned char Voxel_PaletteLookup[MAX_PALETTE_LOOKUP_ENTRIES][VOXEL_PALETTE_SIZE];
