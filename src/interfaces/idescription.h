/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IDescription interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include <unknwn.h>


/*******************************************************************************
 *  @class   IDescription
 *
 *  @brief   Textual description of house AI.
 */
DECLARE_INTERFACE_IID_(IDescription, IUnknown, "3C13CFA0-8886-11D1-B707-00A024DDAFD1")
{
    /**
     *  Name of AI.
     */
    STDMETHOD_(BSTR, Short_Name)() PURE;

    /**
     *  Description of AI.
     */
    STDMETHOD_(BSTR, Description)() PURE;
};
