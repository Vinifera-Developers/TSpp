/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEVENT.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Map trigger events.
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
#include "tevent.h"
#include "tibsun_inline.h"


void TEventClass::Reset(CDTimerClass<FrameTimerClass> &timer) const
{
    if (Event == TEVENT_TIME) {
        timer = Data.Value * TICKS_PER_SECOND;
    }
    if (Event == TEVENT_RANDOM_TIME) {
        timer = Data.Value / 2 + Random_Pick(0, (int)Data.Value) * TICKS_PER_SECOND;
    }
}


const char *TEventClass::Event_Name(TEventType event)
{
    return EventDescriptions[event].Name;
}


const char *TEventClass::Event_Description(TEventType event)
{
    return EventDescriptions[event].Description;
}


TEventClass::EventDescriptionStruct TEventClass::EventDescriptions[TEVENT_COUNT] = {
    { "-No Event-", "This is a null event. There is no need to ever use this in a real trigger." },
    { "Entered by...", "Triggers when an infantry or vehicle enters the attached object. Typically this trigger is attached to a building or a cell." },
    { "Spied by...", "Detects when a spy has entered the attached building." },
    { "Thieved by...", "Triggers when a thief steals money from the specified house." },
    { "Discovered by player", "Detects when the attached object has been discovered by the player. Discovered means revealed from under the shroud." },
    { "House Discovered...", "Triggers when the specified house has any of its units or buildings discovered by the player." },
    { "Attacked by anybody", "Triggers when the attached unit is attacked in some manner. Incidental damage or friendly fire does not count." },
    { "Destroyed by anybody", "Triggers when the attached object has been destroyed. Destroyed by incidental damage or friendly fire doesn't count." },
    { "Any Event", "When used alone, it will force the trigger to spring immediately." },
    { "Destroyed, Units, All...", "Triggers when all units of the specified house have been destroyed. Typically used for end of game conditions." },
    { "Destroyed, Buildings, All...", "Triggers when all buildings of the specified side have been destroyed. Typically used for end of game conditions." },
    { "Destroyed, All...", "Triggers when all objects owned by the specified house have been destroyed. This is the normal (destroy everyone) trigger condition for end of game." },
    { "Credits exceed (x100)...", "Triggers when the house (for this trigger) credit total exceeds this specified amount." },
    { "Elapsed Time (1/10th min)...", "Triggers when the elapsed time has expired. This time is initialized when the trigger is created. Timer is reset whenever trigger is sprung when trigger is 'persistant'." },
    { "Mission Timer Expired", "Triggers when the global mission timer (as displayed on the screen) has reached zero." },
    { "Destroyed, Buildings, #...", "Triggers when the number of buildings, owned by the trigger's specified house, have been destroyed." },
    { "Destroyed, Units, #...", "Triggers when the number of units, owned by the trigger's specified house, have been destroyed." },
    { "No Factories left", "Triggers when there are no factories left for the house specified in the trigger." },
    { "Civilians Evacuated", "Triggers when civilians have been evacuated (left the map)." },
    { "Build Building Type...", "When the trigger's house builds the building type specified, then this event will spring." },
    { "Build Unit Type...", "When the trigger's house builds the unit type specified, then this event will spring." },
    { "Build Infantry Type...", "When the trigger's house builds the infantry type specified, then this event will spring." },
    { "Build Aircraft Type...", "When the trigger's house builds the aircraft type specified, then this event will spring." },
    { "Leaves map (team)...", "Triggers when the specified team leaves the map. If the team is destroyed, it won't trigger. If all but one member is destroyed and that last member leaves the map, it WILL spring." },
    { "Zone Entry by...", "Triggers when a unit of the specified house enters the same zone that this trigger is located in. This trigger must be located in a cell and only a cell." },
    { "Crosses Horizontal Line...", "Triggers when a unit of the specified house crosses the horizontal line as indicated by the location of this trigger. This trigger must be placed in a cell." },
    { "Crosses Vertical Line...", "Triggers when a unit of the specified house crosses the vertical line as indicated by the location of this trigger. This trigger must be placed in a cell." },
    { "Global is set...", "Triggers when the specified global (named in Globals.INI) is turned on." },
    { "Global is clear...", "Triggers when the specified global (named in Globals.INI) is turned off." },
    { "Destroyed, Fakes, All...", "Triggers when attached object is destroyed, but not if it infiltrates a building/unit." },
    { "Low Power...", "Triggers when the specified house's power falls below 100% level." },
    { "Bridge destroyed", "Triggers when the attached bridge is destroyed. A bridge is considered destroyed when an impassable gap is created in the bridge." },
    { "Building exists...", "Triggers when the building (owned by the house of this trigger) specified exists on the map. This works for buildings that are preexisting or constructed by deploying." },
    { "Selected by player", "Triggers when the unit is selected by the player. Use in single-player only." },
    { "Comes near waypoint...", "Triggers when the object comes near the specified waypoint." },
    { "Enemy in Spotlight...", "Triggers when an enemy unit enters the spotlight cast by the attached building." },
    { "Local is set...", "Triggers when the specified local is turned on." },
    { "Local is clear...", "Triggers when the specified local is turned off." },
    { "First damaged (combat only)", "Triggers when first suffering from combat damage from combat damage only." },
    { "Half health (combat only)", "Triggers when damaged to half health >from combat damage only." },
    { "Quarter health (combat only)", "Triggers when damaged to quarter health from combat damage only." },
    { "First damaged (any source)", "Triggers when first suffering from combat damage from any source." },
    { "Half health (any source)", "Triggers when damaged to half health >from any source." },
    { "Quarter health (any source)", "Triggers when damaged to quarter health from any source." },
    { "Attacked by (house)", "When attacked by some unit of specified house." },
    { "Ambient light <=", "Triggers when the ambient light drops below a certain level. Use numbers between 0 and 100." },
    { "Ambient light >=", "Triggers when the ambient light rises above a certain level. Use numbers between 0 and 100." },
    { "Elapsed Scenario Time...", "When time has elapsed since start of scenario." },
    { "Destroyed by anything", "Triggers when destroyed by anything what-so-ever." },
    { "Pickup Crate", "When crate is picked up object the trigger is attached to." },
    { "Pickup Crate (any)", "When crate is picked up by any unit." },
    { "Random delay...", "Delays a random time between 50 and 150 percent of time specified." },
    { "Credits below...", "Triggers when the house (for this trigger) credit total is below this specified amount." },
    { "Paralyzed", "Triggers when a object is paralyzed under EMP effect or web." },
    { "Enemy in Spotlight... (duplicate)", "Triggers when an enemy unit enters the spotlight cast by the attached building." },
    { "Limped", "Triggers when a object has been limped by a limpet drone." }
};
