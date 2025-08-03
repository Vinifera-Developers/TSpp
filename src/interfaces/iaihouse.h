/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IAIHOUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IAIHouse interface.
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
#include <comdef.h>
#include <unknwn.h>


/*******************************************************************************
 *  @class   IAIHouse
 *
 *  @brief   AI for House.
 */
DECLARE_INTERFACE_IID_(IAIHouse, IUnknown, "96F02EC4-6FE8-11D1-B6FD-00A024DDAFD1")
{
    /**
     *  Links house to an advisor object.
     */
    STDMETHOD_(LONG, Link_House)(IHouse * house) PURE;

    /**
     *  AI processing entry function.
     */
    STDMETHOD_(LONG, AI)(long* framedelay) PURE;
};

/**
 *  IAIHouse com smart pointer declaration.
 */
_COM_SMARTPTR_TYPEDEF(IAIHouse, __uuidof(IAIHouse));
