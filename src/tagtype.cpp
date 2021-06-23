/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TAGTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for object trigger-tag types.
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
#include "tagtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const TagTypeClass &TagTypeClass::As_Reference(TagType type)
{
    TSPP_ASSERT(type != TAG_NONE && type < TagTypes.Count());
    return *TagTypes[type];
}


const TagTypeClass *TagTypeClass::As_Pointer(TagType type)
{
    TSPP_ASSERT(type != TAG_NONE && type < TagTypes.Count());
    return type != TAG_NONE && type < TagTypes.Count() ? TagTypes[type] : nullptr;
}


const TagTypeClass &TagTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const TagTypeClass *TagTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


TagType TagTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TAG_NONE;
    }

    if (name != nullptr) {
        for (TagType index = TAG_FIRST; index < TagTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return TAG_NONE;
}


const char *TagTypeClass::Name_From(TagType type)
{
    return (type != TAG_NONE && type < TagTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const TagTypeClass *TagTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (TagType index = TAG_FIRST; index < TagTypes.Count(); ++index) {
        if (!strcasecmp(TagTypes[index]->Name(), name)) {
            return TagTypes[index];
        }
    }

    TagTypeClass *ptr = new TagTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
