/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Functions for applying lighting to a voxel based on its source.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "voxel.hh"


class Vector3;


/**
 *  The available normal shading table types.
 */
typedef enum VoxelNormalType {
    NORMAL_NONE,

    NORMAL_1, // Low
    NORMAL_2,
    NORMAL_3,
    NORMAL_4, // High

    NORMAL_COUNT
};


void Voxel_Calc_Normal_To_Pal_Indexes(const Vector3& voxel, int normal_type);
void Voxel_Calc_Normal_To_Pal_Indexes(const Vector3& light, const Vector3& voxel, float value, int normal_type);
int Voxel_Find_Best_Normal_Index(const Vector3& voxel, int normal_type);
void Init_Normal_Lookup();
