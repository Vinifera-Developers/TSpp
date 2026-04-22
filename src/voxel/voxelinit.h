/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
