/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Runtime casting within the C&C Engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


/**
 *  Perform a runtime C&C engine cast.
 *
 *  @author: CCHyper
 */
template<typename TDerived>
TDerived* CC_Dynamic_Cast(AbstractClass* abstract)
{
    /**
     *  Check if the desired class is really derived from AbstractClass
     */
    if (!std::is_base_of<AbstractClass, TDerived>()) {
        return nullptr;
    }

    /**
     *  Base class sanity check.
     */
    if (abstract == nullptr) {
        return nullptr;
    }

    /**
     *  Invalid RTTI type, return null.
     */
    if (abstract->Fetch_RTTI() == RTTI_NONE || !(abstract->Fetch_RTTI() < RTTI_COUNT)) {
        return nullptr;
    }

    /**
     *  Passed validity checks, cast to the derived class.
     */
    return reinterpret_cast<TDerived*>(abstract);
}
