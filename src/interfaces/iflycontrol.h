/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IFlyControl interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
