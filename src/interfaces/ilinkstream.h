/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  ILinkStream interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include <unknwn.h>


/*******************************************************************************
 *  @class   ILinkStream
 *
 *  @brief   Link one stream to another.
 */
DECLARE_INTERFACE_IID_(ILinkStream, IUnknown, "0D5CD78E-6470-11D2-9B74-00104B972FE8")
{
    /**
     *  Link base stream.
     */
    STDMETHOD(Link_Stream(IUnknown* stream)) PURE;

    /**
     *  Unlink stream.
     */
    STDMETHOD(Unlink_Stream(IUnknown** stream)) PURE;
};
