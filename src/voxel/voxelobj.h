/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Compound voxel object struct.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ccfile.h"
#include "motionlib.h"
#include "voxellib.h"

struct VoxelObject {
public:
    VoxelObject() :
        VoxelLibrary(nullptr),
        MotionLibrary(nullptr)
    {
        
    }

    VoxelObject(NoInitClass const& x) {}

    ~VoxelObject()
    {
        delete VoxelLibrary;
        VoxelLibrary = nullptr;
        delete MotionLibrary;
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
            } else {
                MotionLibrary->Scale(VoxelLibrary->Get_Layer_Info(0, 0)->Scale);
            }
        } else {
            success = false;
        }

        if (success) {
            index.Clear();
        } else {
            delete VoxelLibrary;
            VoxelLibrary = nullptr;
            delete MotionLibrary;
            MotionLibrary = nullptr;
        }

        return success;
    }

    VoxelLibraryClass* VoxelLibrary;
    MotionLibraryClass* MotionLibrary;
};
