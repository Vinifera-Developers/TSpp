/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IAPPLICATION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IApplication interface.
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
#include "iswizzle.h"


/*******************************************************************************
 *  @class   IApplication
 *
 *  @brief   Application object.
 */
DECLARE_INTERFACE_IID_(IApplication, IUnknown, "96F02EC3-6FE8-11D1-B6FD-00A024DDAFD1")
{
    /**
     *  Returns the full name of the application.
     */
    STDMETHOD_(LONG, Full_Name)(wchar_t *retval) PURE;

    /**
     *  Returns the name of the application.
     */
    STDMETHOD_(LONG, Name)(wchar_t *retval) PURE;

    /**
     *  Exits the application gracefully.
     */
    STDMETHOD_(LONG, Quit)() PURE;

    /**
     *  Internal scenario name.
     */
    STDMETHOD_(LONG, Scenario_Name)(wchar_t *retval) PURE;

    /**
     *  Game frame count.
     */
    STDMETHOD_(LONG, Frame_Count)(long *retval) PURE;

    /**
     *  ISwizzle Interface.
     */
    STDMETHOD_(LONG, Swizzle_Interface)(ISwizzle **pVal) PURE;
};
