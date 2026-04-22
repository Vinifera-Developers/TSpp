/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for voxel anim types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "voxelanimtype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


VoxelAnimType VoxelAnimTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return VOXELANIM_NONE;
    }

    if (name != nullptr) {
        for (VoxelAnimType index = VOXELANIM_FIRST; index < VoxelAnimTypes.Count(); ++index) {
            if (!strcasecmp(VoxelAnimTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return VOXELANIM_NONE;
}


const char* VoxelAnimTypeClass::Name_From(VoxelAnimType type)
{
    return (type != VOXELANIM_NONE && type < VoxelAnimTypes.Count() ? VoxelAnimTypes[type]->Name() : "<none>");
}


VoxelAnimTypeClass* VoxelAnimTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, VoxelAnimTypes);
}
