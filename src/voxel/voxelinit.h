/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELINIT.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief
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


class FileClass;


void Set_Voxel_Light_Angle(float theta);
void Init_Voxel_Matrices();
bool Init_Voxel_Palette(FileClass* file);

extern float& VoxelLightAngle;
extern Vector3& VoxelLightSource;
extern Vector3& VoxelShadowLightSource;
