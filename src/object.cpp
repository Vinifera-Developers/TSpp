/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "object.h"
#include "objecttype.h"


/**
 *  Returns this object as a TechnoClass pointer in applicable.
 *
 *  @author: CCHyper
 */
TechnoClass* ObjectClass::As_Techno()
{
    switch (What_Am_I()) {
    case RTTI_UNIT:
    case RTTI_AIRCRAFT:
    case RTTI_BUILDING:
    case RTTI_INFANTRY:
        return reinterpret_cast<TechnoClass*>(this);
    default:
        return nullptr;
    };
}


/**
 *  Returns this object as a FootClass pointer in applicable.
 *
 *  @author: CCHyper
 */
FootClass* ObjectClass::As_Foot()
{
    switch (What_Am_I()) {
    case RTTI_UNIT:
    case RTTI_AIRCRAFT:
    case RTTI_BUILDING:
    case RTTI_INFANTRY:
        return reinterpret_cast<FootClass*>(this);
    default:
        return nullptr;
    };
}
