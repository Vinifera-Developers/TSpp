/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELOBJ.H
 *
 *  @authors       ZivDero
 *
 *  @brief         Compound voxel object struct.
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
#include "ccfile.h"
#include "voxellib.h"
#include "motionlib.h"

struct VoxelObject
{
public:
    ~VoxelObject()
    {
        delete VoxelLibrary;
        VoxelLibrary = nullptr;
        delete MotionLibrary;
        MotionLibrary = nullptr;
    }

    void Clear()
    {
        VoxelLibrary = nullptr;
        MotionLibrary = nullptr;
    }

    /**
     *  Loads a voxel object from files.
     *
     *  @author: ZivDero
     */
    bool Load(VoxelIndexClass& index, const char* graphic_name)
    {
        char buffer[260];
        bool success = true;

        _makepath(buffer, nullptr, nullptr, graphic_name, ".VXL");
        CCFileClass vxl(buffer);

        if (vxl.Is_Available()) {
            delete VoxelLibrary;
            VoxelLibrary = new VoxelLibraryClass(&vxl);

            if (!VoxelLibrary || VoxelLibrary->Load_Failed()) {
                success = false;
            }

            _makepath(buffer, nullptr, nullptr, graphic_name, ".HVA");
            CCFileClass hva(buffer);

            delete MotionLibrary;
            MotionLibrary = new MotionLibraryClass(&hva);

            if (!MotionLibrary || MotionLibrary->Load_Failed()) {
                success = false;
            }
            else {
                MotionLibrary->Scale(VoxelLibrary->Get_Layer_Info(0, 0)->Scale);
            }
        }
        else {
            success = false;
        }

        if (success) {
            index.Clear();
        }
        else {
            this->~VoxelObject();
        }

        return success;
    }

    VoxelLibraryClass* VoxelLibrary;
    MotionLibraryClass* MotionLibrary;
};
