/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Main voxel object container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "matrix3d.h"
#include "voxel.hh"


class FileClass;
class Vector3;


class VoxelLibraryClass
{
public:
    struct LayerStruct {
        int InfoIndex;
        int field_4;
        unsigned char field_8;
    };

    struct LayerInfoStruct {
        unsigned char* StartOffset;
        unsigned char* EndOffset;
        unsigned char* DataOffset;
        float Scale;
        Matrix3D Transform;
        Vector3 Bounds[VOXEL_BOUNDS_MAX];
        unsigned char XSize;
        unsigned char YSize;
        unsigned char ZSize;
        unsigned char NormalType;
    };

public:
    VoxelLibraryClass();
    VoxelLibraryClass(FileClass* file, bool load_file_palette = false);
    ~VoxelLibraryClass();

    void Clear();
    bool Read_File(FileClass* file, bool load_file_palette = false);

    LayerStruct* Get_Layer(int layer);
    LayerInfoStruct* Get_Layer_Info(int layer, int info);

    void func_668680(Vector3& a1, int layer, int info);
    int Memory_Used();
    void func_668730(void* a1, Vector3& a2);
    void func_668A00(void* a1, Vector3& a2);
    void func_668BA0();

    bool Load_Failed() const { return LoadFailed; }
    int Get_Layer_Count() const { return LayerCount; }
    int Get_Layer_Info_Count() const { return LayerInfoCount; }
    int Get_Data_Size() const { return DataSize; }

private:
    bool LoadFailed;
    int LayerCount;              // Layer header count.
    int LayerInfoCount;          // Layer info count (these info can be reused).
    int DataSize;                // Size of body data.
    LayerStruct* LayerHeaders;   // Layer headers.
    LayerInfoStruct* LayerInfos; // Layer info data.
    unsigned char* Data;         // Section body data.
};
