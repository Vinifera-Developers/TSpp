/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IHOUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IHouse interface.
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
#include "iapplication.h"
#include "tibsun_defines.h"
#include <unknwn.h>


enum CategoryType;


/*******************************************************************************
 *  @class   IHouse
 *
 *  @brief   House Interface visible to owning AI general.
 */
DECLARE_INTERFACE_IID_(IHouse, IUnknown, "941582E0-86DA-11D1-B706-00A024DDAFD1")
{
    /**
     *  Unique House ID.
     */
    STDMETHOD_(LONG, ID_Number)() PURE;

    /**
     *  House name.
     */
    STDMETHOD_(BSTR, Name)() PURE;

    /**
     *  Returns IApplication interface.
     */
    STDMETHOD_(IApplication *, Get_Application)() PURE;

    /**
     *  Available money.
     */
    STDMETHOD_(LONG, Available_Money)() PURE;

    /**
     *  Available tiberium storage.
     */
    STDMETHOD_(LONG, Available_Storage)() PURE;

    /**
     *  Current power output.
     */
    STDMETHOD_(LONG, Power_Output)() PURE;

    /**
     *  Current power drain.
     */
    STDMETHOD_(LONG, Power_Drain)() PURE;

    /**
     *  Quantity owned by category.
     */
    STDMETHOD_(LONG, Category_Quantity)(CategoryType category) PURE;

    /**
     *  Total strength available by category.
     */
    STDMETHOD_(LONG, Category_Power)(CategoryType category) PURE;

    /**
     *  Center location of base.
     */
    STDMETHOD_(Cell, Base_Center)() PURE;

    /**
     *  Sell all buildings.
     */
    STDMETHOD_(LONG, Fire_Sale)() PURE;

    /**
     *  All units to attack enemy.
     */
    STDMETHOD_(LONG, All_To_Hunt)() PURE;
};
