/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IPublicHouse interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ihouse.h"
#include "tibsun_defines.h"
#include <unknwn.h>


enum CategoryType;


/*******************************************************************************
 *  @class   IPublicHouse
 *
 *  @brief   House Interface visible to enemies.
 */
DECLARE_INTERFACE_IID_(IPublicHouse, IUnknown, "CAACF210-86E3-11D1-B706-00A024DDAFD1")
{
    /**
     *  Unique House ID.
     */
    STDMETHOD_(LONG, ID_Number)() PURE;

    /**
     *  House name.
     */
    STDMETHOD_(BSTR, Name)() PURE;

    /**
     *  Quantity owned by category.
     */
    STDMETHOD_(LONG, Apparent_Category_Quantity)(CategoryType category) PURE;

    /**
     *  Total strength available by category.
     */
    STDMETHOD_(LONG, Apparent_Category_Power)(CategoryType category) PURE;

    /**
     *  Center location of base.
     */
    STDMETHOD_(Cell, Apparent_Base_Center)() PURE;

    /**
     *  Is base visibly powered?
     */
    STDMETHOD_(bool, Is_Powered)() PURE;
};
