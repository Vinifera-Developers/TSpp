/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Unit team object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "team.h"
#include "foot.h"
#include "tibsun_globals.h"


/**
 *  Checks to see if unit is an active team member.
 *
 *  @author: 03/11/1996 JLB
 */
bool Is_It_Breathing(const FootClass* object)
{
    if (object == nullptr || !object->IsActive || object->Strength == 0) {
        return false;
    }

    if (!ScenarioInit && object->IsInLimbo) {
        return false;
    }

    return true;
}


/**
 *  Determines if unit is active and an initiated team member.
 *
 *  @author: 03/11/1996 JLB
 */
bool Is_It_Playing(const FootClass* object)
{
    if (!Is_It_Breathing(object)) {
        return false;
    }

    if (!object->IsInitiated && object->Fetch_RTTI() != RTTI_AIRCRAFT) {
        return false;
    }

    return true;
}
