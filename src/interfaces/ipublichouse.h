/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IPUBLICHOUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IPublicHouse interface.
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
#include "ihouse.h"
#include "tibsun_defines.h"
#include <unknwn.h>


enum CategoryType;


/*******************************************************************************
 *  @class   IPublicHouse
 *
 *  @brief   House Interface visible to enemies.
 */
DECLARE_INTERFACE_IID_(IPublicHouse, IUnknown, "CAACF210-86E3-11D1-B706-00A024DDAFD1")
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
     *  Quantity owned by category.
     */
    STDMETHOD_(LONG, Apparent_Category_Quantity)(CategoryType category) PURE;

    /**
     *  Total strength available by category.
     */
    STDMETHOD_(LONG, Apparent_Category_Power)(CategoryType category) PURE;

    /**
     *  Center location of base.
     */
    STDMETHOD_(Cell, Apparent_Base_Center)() PURE;

    /**
     *  Is base visibly powered?
     */
    STDMETHOD_(bool, Is_Powered)() PURE;
};
