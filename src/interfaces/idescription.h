/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IDESCRIPTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IDescription interface.
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
 *  @class   IDescription
 *
 *  @brief   Textual description of house AI.
 */
DECLARE_INTERFACE_IID_(IDescription, IUnknown, "3C13CFA0-8886-11D1-B707-00A024DDAFD1")
{
    /**
     *  Name of AI.
     */
    STDMETHOD_(BSTR, Short_Name)() PURE;

    /**
     *  Description of AI.
     */
    STDMETHOD_(BSTR, Description)() PURE;
};
