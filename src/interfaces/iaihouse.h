/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IAIHouse interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
