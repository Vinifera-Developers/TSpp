/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ISWIZZLE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         ISwizzle interface.
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


/**
 *  Forward declaration of IStream, required for ISwizzle methods.
 */
struct IStream;


/*******************************************************************************
 *  @class   ISwizzle
 *
 *  @brief   Pointer Swizzling Interface.
 */
DECLARE_INTERFACE_IID_(ISwizzle, IUnknown, "5FF0CA70-8B12-11D1-B708-00A024DDAFD1")
{
    /**
     *  Reset swizzler in preparation for load.
     */
    STDMETHOD_(LONG, Reset)() PURE;

    /**
     *  Swizzle a pointer after load.
     */
    STDMETHOD_(LONG, Swizzle)(void **pointer) PURE;

    /**
     *  Convert pointer to ID number.
     */
    STDMETHOD_(LONG, Fetch_Swizzle_ID)(void *pointer, LONG *id) PURE;

    /**
     *  Inform swizzler of new object location.
     */
    STDMETHOD_(LONG, Here_I_Am)(LONG id, void *pointer) PURE;

    /**
     *  Save interface pointer to stream.
     */
    STDMETHOD(Save_Interface)(IStream *stream, IUnknown *pointer) PURE;

    /**
     *  Loads interface pointer from stream.
     */
    STDMETHOD(Load_Interface)(IStream *stream, CLSID *riid, void **pointer) PURE;

    /**
     *  Fetch bytes required to save interface pointer.
     */
    STDMETHOD_(LONG, Get_Save_Size)(LONG *size) PURE;
};
