/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OBJECT.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Game object class.
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
#include "object.h"
#include "objecttype.h"


/**
 *  Returns this object as a TechnoClass pointer in applicable.
 * 
 *  @author: CCHyper
 */
TechnoClass *ObjectClass::As_Techno()
{
    switch (What_Am_I()) {
        case RTTI_UNIT:
        case RTTI_AIRCRAFT:
        case RTTI_BUILDING:
        case RTTI_INFANTRY:
            return reinterpret_cast<TechnoClass *>(this);
        default:
            return nullptr;
    };
}


/**
 *  Returns this object as a FootClass pointer in applicable.
 * 
 *  @author: CCHyper
 */
FootClass *ObjectClass::As_Foot()
{
    switch (What_Am_I()) {
        case RTTI_UNIT:
        case RTTI_AIRCRAFT:
        case RTTI_BUILDING:
        case RTTI_INFANTRY:
            return reinterpret_cast<FootClass *>(this);
        default:
            return nullptr;
    };
}


/**
 *  This operator will automatically convert from a class object into the enumerated value.
 * 
 *  #NOTE: This is ONLY implemented for backwards compatability with legacy code!
 * 
 *  @author: CCHyper
 */
ObjectClass::operator int () const
{
    return Class_Of()->Get_Heap_ID();
}
