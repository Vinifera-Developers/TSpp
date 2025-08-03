/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELNORMAL.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Functions for applying lighting to a voxel based on its source.
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
