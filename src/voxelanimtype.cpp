/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELANIMTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for voxel anim types.
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
#include "voxelanimtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"
#include "findmake.h"


VoxelAnimType VoxelAnimTypeClass::From_Name(const char *name)
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


const char *VoxelAnimTypeClass::Name_From(VoxelAnimType type)
{
    return (type != VOXELANIM_NONE && type < VoxelAnimTypes.Count() ? VoxelAnimTypes[type]->Name() : "<none>");
}


const VoxelAnimTypeClass *VoxelAnimTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, VoxelAnimTypes);
}
