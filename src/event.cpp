/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Event class is used to contain all game events that are transferred
 *          between computers in multiplayer games.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "event.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"


const char* EventClass::Event_Name(EventType event)
{
    TSPP_ASSERT(event < EVENT_COUNT);

    return EventNames[event];
}


unsigned char EventClass::Event_Length(EventType event)
{
    TSPP_ASSERT(event < EVENT_COUNT);

    return EventLength[event];
}
