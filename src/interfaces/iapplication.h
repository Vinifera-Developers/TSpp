/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IApplication interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "iswizzle.h"


/*******************************************************************************
 *  @class   IApplication
 *
 *  @brief   Application object.
 */
DECLARE_INTERFACE_IID_(IApplication, IUnknown, "96F02EC3-6FE8-11D1-B6FD-00A024DDAFD1")
{
    /**
     *  Returns the full name of the application.
     */
    STDMETHOD_(LONG, Full_Name)(wchar_t* retval) PURE;

    /**
     *  Returns the name of the application.
     */
    STDMETHOD_(LONG, Name)(wchar_t* retval) PURE;

    /**
     *  Exits the application gracefully.
     */
    STDMETHOD_(LONG, Quit)() PURE;

    /**
     *  Internal scenario name.
     */
    STDMETHOD_(LONG, Scenario_Name)(wchar_t* retval) PURE;

    /**
     *  Game frame count.
     */
    STDMETHOD_(LONG, Frame_Count)(long* retval) PURE;

    /**
     *  ISwizzle Interface.
     */
    STDMETHOD_(LONG, Swizzle_Interface)(ISwizzle** pVal) PURE;
};
