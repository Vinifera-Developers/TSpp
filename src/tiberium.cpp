/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBERIUM.CPP
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for tiberium types.
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
#include "tiberium.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const TiberiumClass &TiberiumClass::As_Reference(TiberiumType type)
{
    TSPP_ASSERT(type != TIBERIUM_NONE && type < Tiberiums.Count());
    return *Tiberiums[type];
}


const TiberiumClass *TiberiumClass::As_Pointer(TiberiumType type)
{
    TSPP_ASSERT(type != TIBERIUM_NONE && type < Tiberiums.Count());
    return type != TIBERIUM_NONE && type < Tiberiums.Count() ? Tiberiums[type] : nullptr;
}


const TiberiumClass &TiberiumClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const TiberiumClass *TiberiumClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


TiberiumType TiberiumClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TIBERIUM_NONE;
    }

    if (name != nullptr) {
        for (TiberiumType index = TIBERIUM_FIRST; index < Tiberiums.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return TIBERIUM_NONE;
}


const char *TiberiumClass::Name_From(TiberiumType type)
{
    return (type != TIBERIUM_NONE && type < Tiberiums.Count() ? As_Reference(type).Name() : "<none>");
}


const TiberiumClass* TiberiumClass::Find_Or_Make(const char* name) {
  TSPP_ASSERT(name != nullptr);

  if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
    return nullptr;
  }

  for (TiberiumType index = TIBERIUM_FIRST; index < Tiberiums.Count(); ++index) {
    if (!strcasecmp(Tiberiums[index]->Name(), name)) {
      return Tiberiums[index];
    }
  }

  TiberiumClass* ptr = new TiberiumClass(name);
  TSPP_ASSERT(ptr != nullptr);
  return ptr;
}
