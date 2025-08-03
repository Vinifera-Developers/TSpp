/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ILINKSTREAM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         ILinkStream interface.
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
 *  @class   ILinkStream
 *
 *  @brief   Link one stream to another.
 */
DECLARE_INTERFACE_IID_(ILinkStream, IUnknown, "0D5CD78E-6470-11D2-9B74-00104B972FE8")
{
    /**
     *  Link base stream.
     */
    STDMETHOD(Link_Stream(IUnknown* stream)) PURE;

    /**
     *  Unlink stream.
     */
    STDMETHOD(Unlink_Stream(IUnknown** stream)) PURE;
};
