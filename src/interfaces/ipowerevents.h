/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IPowerEvents interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include <unknwn.h>


/*******************************************************************************
 *  @class   IPowerEvents
 *
 *  @brief   Power event callback interface.
 */
DECLARE_INTERFACE_IID_(IPowerEvents, IUnknown, "56272740-89BB-11D1-B707-00A024DDAFD1")
{
    /**
     *  Triggered when power first becomes sufficient.
     */
    STDMETHOD_(LONG, Power_Activated)() PURE;

    /**
     *  Triggered when power first becomes insufficient.
     */
    STDMETHOD_(LONG, Power_Lost)() PURE;
};
