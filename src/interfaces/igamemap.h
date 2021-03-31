/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IGAMEMAP.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IGameMap interface.
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


struct CellStruct;


/*******************************************************************************
 *  @class   IGameMap
 *
 *  @brief   Map interface.
 */
DECLARE_INTERFACE_IID_(IGameMap, IUnknown, "96F02EC7-6FE8-11D1-B6FD-00A024DDAFD1")
{
    /**
     *  Is location visible?
     */
    STDMETHOD_(BOOL, Is_Visible)(CellStruct &cell) PURE;
};
