/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_DEFINES.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file which contains all the games types.
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


/**
 *  This head contains all the game enums, structs and primitive types.
 */


typedef enum DiffType : int
{
	DIFF_EASY,
	DIFF_NORMAL,
	DIFF_HARD,

	DIFF_COUNT,
	DIFF_FIRST = 0
};


typedef enum FacingType
{
    FACING_N,
    FACING_NE,
    FACING_E,
    FACING_SE,
    FACING_S,
    FACING_SW,
    FACING_W,
    FACING_NW,

    FACING_COUNT,

    FACING_NONE = -1,
    FACING_FIRST = 0
} FacingType;
DEFINE_ENUMERATION_OPERATORS(FacingType);


typedef enum DirType {} DirType;
typedef enum MPHType {} MPHType;
typedef enum CrateType {} CrateType;
typedef enum VocType {} VocType;


typedef unsigned long LEPTON;
