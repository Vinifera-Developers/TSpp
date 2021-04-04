/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OVERLAYTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for overlay types.
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
#include "overlaytype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const OverlayTypeClass &OverlayTypeClass::As_Reference(OverlayType type)
{
    TSPP_ASSERT(type != BULLET_NONE && type < OverlayTypes.Count());
    return *OverlayTypes[type];
}


const OverlayTypeClass *OverlayTypeClass::As_Pointer(OverlayType type)
{
    TSPP_ASSERT(type != BULLET_NONE && type < OverlayTypes.Count());
    return type != BULLET_NONE && type < OverlayTypes.Count() ? OverlayTypes[type] : nullptr;
}


const OverlayTypeClass &OverlayTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const OverlayTypeClass *OverlayTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


OverlayType OverlayTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return OVERLAY_NONE;
    }

    if (name != nullptr) {
        for (OverlayType index = OVERLAY_FIRST; index < OverlayTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return OVERLAY_NONE;
}


const char *OverlayTypeClass::Name_From(OverlayType type)
{
    return (type != BULLET_NONE && type < OverlayTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const OverlayTypeClass *OverlayTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    OverlayType type = From_Name(name);
    if (type != BULLET_NONE) {
        return As_Pointer(type);
    }

    OverlayTypeClass *ptr = new OverlayTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
