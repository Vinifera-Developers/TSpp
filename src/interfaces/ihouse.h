/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IHouse interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "iapplication.h"
#include "tibsun_defines.h"
#include <unknwn.h>


enum CategoryType;


/*******************************************************************************
 *  @class   IHouse
 *
 *  @brief   House Interface visible to owning AI general.
 */
DECLARE_INTERFACE_IID_(IHouse, IUnknown, "941582E0-86DA-11D1-B706-00A024DDAFD1")
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
     *  Returns IApplication interface.
     */
    STDMETHOD_(IApplication*, Get_Application)() PURE;

    /**
     *  Available money.
     */
    STDMETHOD_(LONG, Available_Money)() PURE;

    /**
     *  Available tiberium storage.
     */
    STDMETHOD_(LONG, Available_Storage)() PURE;

    /**
     *  Current power output.
     */
    STDMETHOD_(LONG, Power_Output)() PURE;

    /**
     *  Current power drain.
     */
    STDMETHOD_(LONG, Power_Drain)() PURE;

    /**
     *  Quantity owned by category.
     */
    STDMETHOD_(LONG, Category_Quantity)(CategoryType category) PURE;

    /**
     *  Total strength available by category.
     */
    STDMETHOD_(LONG, Category_Power)(CategoryType category) PURE;

    /**
     *  Center location of base.
     */
    STDMETHOD_(Cell, Base_Center)() PURE;

    /**
     *  Sell all buildings.
     */
    STDMETHOD_(LONG, Fire_Sale)() PURE;

    /**
     *  All units to attack enemy.
     */
    STDMETHOD_(LONG, All_To_Hunt)() PURE;
};
