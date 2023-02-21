/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CC_CAST.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Runtime casting within the C&C Engine.
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
#include "tibsun_defines.h"


/**
 *  Perform a runtime C&C engine cast.
 *  
 *  @author: CCHyper
 */
template<typename TDerived> TDerived * CC_Dynamic_Cast(AbstractClass * abstract)
{
    /**
     *  Check if the desired class is really derived from AbstractClass
     */
    if (!std::is_base_of<AbstractClass, TDerived>()) {
        return nullptr;
    }

    /**
     *  Base class sanity check.
     */
    if (abstract == nullptr) {
        return nullptr;
    }

    /**
     *  Invalid RTTI type, return null.
     */
    if (abstract->What_Am_I() == RTTI_NONE || !(abstract->What_Am_I() < RTTI_COUNT)) {
        return nullptr;
    }

    /**
     *  Passed validity checks, cast to the derived class.
     */
    return reinterpret_cast<TDerived *>(abstract);
}
