/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IGameMap interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include <unknwn.h>


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
    STDMETHOD_(BOOL, Is_Visible)(Cell cell) PURE;
};
