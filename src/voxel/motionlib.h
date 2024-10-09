/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MOTIONLIB.H
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


class FileClass;
class Matrix3D;


class MotionLibraryClass
{
public:
    MotionLibraryClass();
    MotionLibraryClass(FileClass *file);
    ~MotionLibraryClass();

    void Clear();
    bool Read_File(FileClass *file);
    void Scale(float scale);

    bool Load_Failed() const { return LoadFailed; }
    int Get_Section_Count() const { return LayerCount; }
    int Get_Layer_Count() const { return FrameCount; }
    const Matrix3D &Get_Layer_Matrices() const { return *LayerMatrices; }

private:
    bool LoadFailed;
    int LayerCount;
    int FrameCount;
    Matrix3D *LayerMatrices;
};
