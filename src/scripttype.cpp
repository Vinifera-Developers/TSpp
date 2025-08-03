/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCRIPTTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for script types.
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
#include "scripttype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const char* ScriptMissionClass::Mission_Name(ScriptMissionType mission)
{
    return MissionDescriptions[mission].Name;
}


const char* ScriptMissionClass::Mission_Description(ScriptMissionType mission)
{
    return MissionDescriptions[mission].Description;
}


ScriptMissionClass::MissionDescriptionStruct ScriptMissionClass::MissionDescriptions[SMISSION_COUNT] = {{"Attack...", "Attack some general target."},
    {"Attack Waypoint...", "Attack anything nearby the specified waypoint."},
    {"Go Berzerk", "Cyborg members of the team will go berzerk."},
    {"Move to waypoint...", "Orders the team to move to a waypoint on the map."},
    {"Move to Cell...", "Orders the team to move to a specific cell on the map."},
    {"Guard area (timer ticks)...", "Guard an area for a specified amount of time."},
    {"Jump to line #...", "Move to a new line number in the script. Used for loops."},
    {"Player wins", "The player wins. The game will end immediately."},
    {"Unload...", "Unloads all loaded units. The command parameter specifies which units should stay a part of the team, and which should be severed from the team."},
    {"Deploy", "Causes all deployable units in the team to deploy."},
    {"Follow friendlies", "Causes the team to follow the nearest friendly unit."},
    {"Do this...", "Give all team members the specified mission."},
    {"Set global...", "Sets a global variable."},
    {"Idle Anim...", "Causes team members to enter their idle animation."},
    {"Load onto Transport", "Causes all units to load into transports, if able."},
    {"Spy on bldg @ waypt...", "Spy on a building at the specified waypoint."},
    {"Patrol to waypoint...", "Move to a waypoint while scanning for enemies."},
    {"Change script...", "Causes the team to start using a new script."},
    {"Change team...", "Causes the team to switch team types."},
    {"Panic", "Causes all units in the team to panic."},
    {"Change house...", "All units in the team switch houses."},
    {"Scatter", "Tells all units to scatter."},
    {"Goto nearby shroud", "Causes units to flee to a shrouded cell."},
    {"Player loses", "Causes the player to lose."},
    {"Play speech...", "Plays the specified voice file."},
    {"Play sound...", "Plays the specified sound file."},
    {"Play movie...", "Plays the specified movie file."},
    {"Play music...", "Plays the specified theme."},
    {"Reduce tiberium", "Reduces the amount of tiberium around team members."},
    {"Begin production", "Signals the owning house to begin production."},
    {"Fire sale", "Causes an AI house to sell all of its buildings and do a Braveheart."},
    {"Self destruct", "Causes all team members to self destruct."},
    {"Ion storm start in...", "Causes an ion storm to begin at the specified time."},
    {"Ion storm end", "Causes an ion storm to end."},
    {"Center view on team (speed)...", "Center view on team (speed)..."},
    {"Reshroud map", "Reshrouds the map."},
    {"Reveal map", "Reveals the map."},
    {"Delete team members", "Delete all members from the team."},
    {"Clear global...", "Clears the specified global variable."},
    {"Set local...", "Sets the specified local variable."},
    {"Clear local...", "Clears the specified local variable."},
    {"Unpanic", "Causes all team members to stop panicking."},
    {"Force facing...", "Forces team members to face a certain direction."},
    {"Wait till fully loaded", "Waits until all transports are full."},
    {"Truck unload", "Causes all trucks to unload their crates (ie, change imagery)."},
    {"Truck load", "Causes all trucks to load crates (ie, change imagery)."},
    {"Attack enemy building", "Attack a specific type of building with the specified property."},
    {"Move to enemy building", "Move to a specific type of building with the specified property."},
    {"Scout", "The team will scout the bases of the players that have not been scouted."},
    {"Success", "Record a team as having successfully accomplished its mission. Used for AI trigger weighting. Put this at the end of every AITrigger script."},
    {"Flash", "Flashes a team for a period of team."},
    {"Play Anim", "Plays an anim over every unit in the team."},
    {"Talk Bubble", "Displays talk bubble over first unit in the team."}};


ScriptType ScriptTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SCRIPT_NONE;
    }

    if (name != nullptr) {
        for (ScriptType index = SCRIPT_FIRST; index < ScriptTypes.Count(); ++index) {
            if (!strcasecmp(ScriptTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return SCRIPT_NONE;
}


const char* ScriptTypeClass::Name_From(ScriptType type)
{
    return (type != SCRIPT_NONE && type < ScriptTypes.Count() ? ScriptTypes[type]->Name() : "<none>");
}


const ScriptTypeClass* ScriptTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, ScriptTypes);
}
