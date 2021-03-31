/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IFLYCONTROL.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IFlyControl interface.
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
 *  @class   IFlyControl
 *
 *  @brief   Flyer feedback to flying locomotor.
 */
DECLARE_INTERFACE_IID_(IFlyControl, IUnknown, "820F501C-4F39-11D2-9B70-00104B972FE8")
{
    /**
     *  Landing altitude.
     */
    STDMETHOD_(LONG, Landing_Altitude)() PURE;

    /**
     *  Landing direction.
     */
    STDMETHOD_(LONG, Landing_Direction)() PURE;

    /**
     *  Loaded with cargo?
     */
    STDMETHOD_(BOOL, Is_Loaded)() PURE;

    /**
     *  Does it strafe over the target rather than hover?
     */
    STDMETHOD_(LONG, Is_Strafe)() PURE;

    /**
     *  Is the aircraft locked into straight flight?
     */
    STDMETHOD_(LONG, Is_Locked)() PURE;
};
