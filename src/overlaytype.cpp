/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for overlay types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "overlaytype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


OverlayType OverlayTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return OVERLAY_NONE;
    }

    if (name != nullptr) {
        for (OverlayType index = OVERLAY_FIRST; index < OverlayTypes.Count(); ++index) {
            if (!strcasecmp(OverlayTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return OVERLAY_NONE;
}


const char* OverlayTypeClass::Name_From(OverlayType type)
{
    return (type != OVERLAY_NONE && type < OverlayTypes.Count() ? OverlayTypes[type]->Name() : "<none>");
}


OverlayTypeClass* OverlayTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, OverlayTypes);
}
