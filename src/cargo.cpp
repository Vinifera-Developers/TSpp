/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CARGO.H
 *
 *  @authors       ZivDero
 *
 *  @brief         Class that handles the basic cargo logic.
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
#include "cargo.h"
#include "foot.h"


/**
 *  Counts how many objects of this type are in this cargo.
 *
 *  @author: ZivDero
 */
int CargoClass::How_Many(RTTIType rtti) const
{
    ObjectClass* object = CargoHold;
    int count = 0;

    while (object != nullptr) {
        if (object->RTTI == rtti) {
            count++;
        }
        object = object->Next;
    }

    return count;
}


/**
 *  Returns if there are any objects of this type are in this cargo.
 *
 *  @author: ZivDero
 */
bool CargoClass::Is_Something_Attached(RTTIType rtti) const
{
    return How_Many(rtti) > 0;
}


/**
 *  Fetches an attached object of this type.
 *
 *  @author: ZivDero
 */
FootClass* CargoClass::Attached_Object(RTTIType rtti) const
{
    FootClass* object = CargoHold;

    while (object != nullptr) {
        if (object->RTTI == rtti) {
            return object;
        }
        object = static_cast<FootClass*>(object->Next);
    }

    return nullptr;
}


/**
 *  Detaches an attached object of this type.
 *
 *  @author: ZivDero
 */
FootClass* CargoClass::Detach_Object(RTTIType rtti)
{
    FootClass* unit = Attached_Object(rtti);

    if (unit != nullptr) {
        Detach(unit);
        Quantity--;
    }

    return unit;
}
