/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IRTTITYPEINFO.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IRTTITypeInfo interface.
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
#include <unknwn.h>


/*******************************************************************************
 *  @class   IRTTITypeInfo
 *
 *  @brief   RTTI Type Info Interface.
 */
DECLARE_INTERFACE_IID_(IRTTITypeInfo, IUnknown, "170DAC82-12E4-11D2-8175-006008055BB5")
{
    /**
     *  Fetch the RTTI type ID number.
     */
    STDMETHOD_(int, What_Am_I)() const PURE;

    /**
     *  Fetch unique ID number for this RTTI typed object.
     */
    STDMETHOD_(int, Fetch_ID)() const PURE;

    /**
     *  Create unique ID number for this RTTI typed object.
     */
    STDMETHOD_(VOID, Create_ID)() PURE;
};
