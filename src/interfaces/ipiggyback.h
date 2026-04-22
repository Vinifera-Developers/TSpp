/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IPiggyback interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ilocomotion.h"
#include "tibsun_defines.h"
#include <comdef.h>
#include <unknwn.h>


/*******************************************************************************
 *  @class   IPiggyback
 *
 *  @brief   'piggyback' one locomotor onto another.
 */
DECLARE_INTERFACE_IID_(IPiggyback, IUnknown, "92FEA800-A184-11D1-B70A-00A024DDAFD1")
{
    /**
     *  Piggybacks a locomotor onto this one.
     */
    STDMETHOD(Begin_Piggyback)(ILocomotion* pointer) PURE;

    /**
     *  End piggyback process and restore locomotor interface pointer.
     */
    STDMETHOD(End_Piggyback)(ILocomotion** pointer) PURE;

    /**
     *  Is it ok to end the piggyback process?
     */
    STDMETHOD_(bool, Is_Ok_To_End)() PURE;

    /**
     *  Fetches piggybacked locomotor class ID.
     */
    STDMETHOD(Piggyback_CLSID)(CLSID* classid) PURE;

    /**
     *  Is it currently piggy backing another locomotor?
     */
    STDMETHOD_(bool, Is_Piggybacking)() PURE;
};


/**
 *  IPiggyback com smart pointer declaration.
 */
_COM_SMARTPTR_TYPEDEF(IPiggyback, __uuidof(IPiggyback));
