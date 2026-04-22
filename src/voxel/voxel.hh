/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Main voxel format header.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "matrix3d.h"
#include "rgb.h"
#include "vector3.h"


/**
 *  Voxel file identifier.
 */
#define VOXEL_ID "Voxel Animation"

/**
 *  Max internal name length.
 */
#define MAX_VOXEL_NAME_LENGTH 16 // #WARNING: Do not change this!

/**
 *  Size of the voxel palette, 256 colors.
 */
#define VOXEL_PALETTE_SIZE 256

#define VOXEL_BOUNDS_MAX 8

/**
 *  Number of palette adjustment tables (game engine supports max 32 facings).
 */
#define MAX_PALETTE_LOOKUP_ENTRIES 32


/**
 *  Voxel file header (VXL).
 */
typedef struct VoxelHeaderStruct {
    char Name[MAX_VOXEL_NAME_LENGTH];
    int PaletteCount;
    int LayerCount;
    int LayerInfoCount;
    int DataSize;
};


/**
 *  Voxel layer header.
 */
typedef struct VoxelLayerHeaderStruct {
    char Name[MAX_VOXEL_NAME_LENGTH];
    int InfoIndex;
    int field_14;
    unsigned char field_18;
};


/**
 *  Voxel layer info header.
 */
typedef struct VoxelLayerInfoStruct {
    int StartOffset;
    int EndOffset;
    int DataOffset;
    float Scale;
    Matrix3D Transform;
    Vector3 MinBounds;
    Vector3 MaxBounds;
    unsigned char XSize;
    unsigned char YSize;
    unsigned char ZSize;
    unsigned char NormalType;
};


typedef struct VoxelCubeStruct {
    unsigned char ColorIndex;
    unsigned char NormalIndex;
};


typedef struct VoxelSliceStruct {
    unsigned char field_0; // Known as "skip count."
    unsigned char Count;
};


/**
 *  Voxel anim control header (HVA: Hierarchical Voxel Animation).
 */
typedef struct VoxelAnimFileHeaderStruct {
    char Name[MAX_VOXEL_NAME_LENGTH];
    int FrameCount;
    int LayerCount;
};
