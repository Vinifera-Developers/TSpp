/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IRTTITypeInfo interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include <unknwn.h>


/*******************************************************************************
 *  @class   IRTTITypeInfo
 *
 *  @brief   RTTI Type Info Interface.
 */
DECLARE_INTERFACE_IID_(IRTTITypeInfo, IUnknown, "170DAC82-12E4-11D2-8175-006008055BB5")
{
    /**
     *  Fetch the RTTI type ID number.
     */
    STDMETHOD_(int, What_Am_I)() const PURE;

    /**
     *  Fetch unique ID number for this RTTI typed object.
     */
    STDMETHOD_(int, Fetch_ID)() const PURE;

    /**
     *  Create unique ID number for this RTTI typed object.
     */
    STDMETHOD_(VOID, Create_ID)() PURE;
};
