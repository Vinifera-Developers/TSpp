/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BULLETTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for bullet types.
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
#include "bullettype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const BulletTypeClass &BulletTypeClass::As_Reference(BulletType type)
{
    TSPP_ASSERT(type != BULLET_NONE && type < BulletTypes.Count());
    return *BulletTypes[type];
}


const BulletTypeClass *BulletTypeClass::As_Pointer(BulletType type)
{
    TSPP_ASSERT(type != BULLET_NONE && type < BulletTypes.Count());
    return type != BULLET_NONE && type < BulletTypes.Count() ? BulletTypes[type] : nullptr;
}


const BulletTypeClass &BulletTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const BulletTypeClass *BulletTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


BulletType BulletTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return BULLET_NONE;
    }

    if (name != nullptr) {
        for (BulletType index = BULLET_FIRST; index < BulletTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return BULLET_NONE;
}


const char *BulletTypeClass::Name_From(BulletType type)
{
    return (type != BULLET_NONE && type < BulletTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const BulletTypeClass *BulletTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    BulletType type = From_Name(name);
    if (type != BULLET_NONE) {
        return As_Pointer(type);
    }

    BulletTypeClass *ptr = new BulletTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
