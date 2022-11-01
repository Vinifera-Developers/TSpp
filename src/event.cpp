/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
*
*  @project       TS++
*
*  @file          EVENT.CPP
*
*  @authors       CCHyper
*
*  @brief         Event class is used to contain all game events that are
*                 transferred between computers in multiplayer games.
*
*  @license       TS++ is free software: you can redistribute it and/or
*                 modify it under the terms of the GNU General Public License
*                 as published by the Free Software Foundation, either version
*                 3 of the License, or (at your option) any later version.
*
*                 TS++ is distributed in the hope that it will be
*                 useful, but WITHOUT ANY WARRANTY; without even the implied
*                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*                 PURPOSE. See the GNU General Public License for more details.
*
*                 You should have received a copy of the GNU General Public
*                 License along with this program.
*                 If not, see <http://www.gnu.org/licenses/>.
*
******************************************************************************/
#include "event.h"
#include "tibsun_globals.h"
#include "tibsun_defines.h"


const char *EventClass::Event_Name(EventType event)
{
    TSPP_ASSERT(event < LAST_EVENT);

    return EventNames[event];
}


unsigned char EventClass::Event_Length(EventType event)
{
    TSPP_ASSERT(event < LAST_EVENT);

    return EventLength[event];
}
