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


class FileClass;
class Matrix3D;


class MotionLibraryClass
{
public:
    MotionLibraryClass();
    MotionLibraryClass(FileClass* file);
    ~MotionLibraryClass();

    void Clear();
    bool Read_File(FileClass* file);
    void Scale(float scale);

    bool Load_Failed() const { return LoadFailed; }
    int Get_Section_Count() const { return LayerCount; }
    int Get_Layer_Count() const { return FrameCount; }
    const Matrix3D& Get_Layer_Matrices() const { return *LayerMatrices; }

private:
    bool LoadFailed;
    int LayerCount;
    int FrameCount;
    Matrix3D* LayerMatrices;
};
