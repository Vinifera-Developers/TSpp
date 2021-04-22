/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TACTION.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Map trigger actions.
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
#include "taction.h"


const char *TActionClass::Action_Name(TActionType action)
{
    return ActionDescriptions[action].Name;
}


const char *TActionClass::Action_Description(TActionType action)
{
    return ActionDescriptions[action].Description;
}


TActionClass::ActionDescriptionStruct TActionClass::ActionDescriptions[TACTION_COUNT] = {
    { "-No Action-", "This is a null action. It will do nothing and is equivalent to not having an action at all. Why use it?" },
    { "Winner is...", "The winner will be forced to be the house specified. The game will end immediately. Typically, the player's house is specified." },
    { "Loser is...", "The loser will be force to be the house specified. The game will end immediately. Typically, the player's house is specified." },
    { "Production Begins", "The computer's house (as specified) will begin production of units and structures." },
    { "Create Team...", "Creates a team of the type specified (owned by the house of this trigger). The team member are NOT automatically created however." },
    { "Destroy All Teams", "Destroys all instances of the team type specified. The units in those existing teams will remain and be available for recruiting into other teams." },
    { "All to Hunt...", "Forces all units, of the house specified, into 'hunt' mode. They will seek out and destroy their enemies." },
    { "Reinforcement (team)...", "Create a reinforcement of the specified team. The members of the team WILL be created magically by this action." },
    { "Drop Zone Flare (waypoint)...", "Display a drop zone flair at the waypoint specified. The map will also be revealed around that location." },
    { "Fire Sale...", "Cause all buildings of the specified house to be sold (for cash and prizes). Typically this is used in the final assault by the computer." },
    { "Play Movie...", "Displays the specified movie (full screen). The game is paused while this occurs and resumes normally after it completes." },
    { "Text Trigger (ID num)...", "Display the text identified by the string file <label>." },
    { "Destroy Trigger...", "Destroy all current instances of the trigger type specified. This does not prevent future instances of that trigger >from being created." },
    { "Autocreate Begins...", "Initiates auto-create for the house specified. This will cause the computer's house to build auto-create teams as it sees fit." },
    { "Change House...", "Changes owning house to the one specified for attached objects." },
    { "Allow Win", "Removes one 'blockage' from allowing the player to win. The blockage number is equal the number of triggers created that have this action." },
    { "Reveal all map", "Reveals the entire map to the player." },
    { "Reveal around waypoint...", "Reveals a region of the map to the player around the waypoint specified." },
    { "Reveal zone of waypoint...", "Reveals all cells that share the same zone as the waypoint specified. This yields some weird results. Use with caution." },
    { "Play sound effect...", "Plays the sound effect specified." },
    { "Play music theme...", "Plays the music theme specified." },
    { "Play speech...", "Plays the speech sound specified." },
    { "Force Trigger...", "Force all triggers of this specified type to spring regardless of what it's event flags may indicate." },
    { "Timer Start", "Start the global mission timer." },
    { "Timer Stop", "Stop the global mission timer." },
    { "Timer Extend (1/10th min)...", "Extend the global mission timer by the time specified." },
    { "Timer Shorten (1/10th min)...", "Shorten the global mission timer by the time specified. It can never be reduced below 'zero' time." },
    { "Timer Set (1/10th min)...", "Set the global mission timer to the value specified." },
    { "Global Set...", "Set the global flag. Global flags are named in the file Globals.INI. Global flags can be either 'true' or 'false'." },
    { "Global Clear...", "Clear the global flag. Global flags are named in the file Globals.INI. Global flags can either be 'true' or 'false'." },
    { "Auto Base Building...", "Initialize the computer skirmish mode build control to either 'on' or 'off' state. When 'on', the computer takes over as if it were in skirmish mode. (gs make sure he has a con yard)." },
    { "Grow shroud one 'step'", "Increase the shroud darkness by one step (cell)." },
    { "Destroy attached building", "Destroy any buildings, bridges, or units that this trigger is attached to." },
    { "Add 1-time special weapon...", "Add a one-shot special weapon (as indicated) to the trigger's house." },
    { "Add repeating special weapon...", "Add a permanent special weapon (as indicated) to the trigger's house." },
    { "Preferred target...", "Specify what the trigger's house should use as its preferred target when using special weapon attacks." },
    { "All change house...", "All objects of one house change ownership to specified house." },
    { "Make ally...", "Cause this trigger's house to ally with the house specified." },
    { "Make enemy...", "Cause this trigger's house to un-ally (declare war) with the house specified." },
    { "Change Zoom Level...", "Changes the zoom out level of the player's radar map.  Use 1 for normal view, 2 for zoomed out." },
    { "Resize Player View...", "Changes the player's viewing rectangle into the map.\nEnter as: x,y,w,h\nwhere xy gives the upper left corner and wh give the width and height." },
    { "Play Anim At...", "Plays the specified anim in the specified cell." },
    { "Do Explosion At...", "Creates an explosion in the specified cell, using the specified warhead." },
    { "Meteor Impact At...", "Sends a meteor at the specified cell." },
    { "Ion Storm start...", "Starts an ion storm sequence to run for the specified number of game frames." },
    { "Ion Storm stop...", "End an Ion storm in progress." },
    { "Lock input", "Disables user input." },
    { "Unlock input", "Enables user input." },
    { "Center Camera at Waypoint...", "Moves the tactical view to a specified waypoint." },
    { "Zoom in", "Zooms the tactical map in." },
    { "Zoom out", "Zooms the tactical map out." },
    { "Reshroud Map", "Reshrouds the entire map." },
    { "Change Light Behavior", "Changes the way a building spotlight behaves. Attach this trigger to a building that casts a spotlight." },
    { "Enable Trigger", "Enables the target trigger." },
    { "Disable Trigger", "Disables the target trigger." },
    { "Create Radar Event", "Creates a radar event at the specified waypoint." },
    { "Local Set...", "Set the local flag. Local flags can be either 'on/set/true' or 'off/clear/false'." },
    { "Local Clear...", "Clear the local flag. Local flags can either be 'on/set/true' or 'off/clear/false'." },
    { "Meteor Shower At...", "Creates a meteor shower around the specified waypoint." },
    { "Reduce Tiberium At...", "Reduces Tiberium around the specified waypoint." },
    { "Sell building", "Sells the building attached to this trigger." },
    { "Turn off building", "Turn off building attached to this trigger." },
    { "Turn on building", "Turn on building attached to this trigger." },
    { "Apply 100 damage at...", "Applies 100 points of HE damage at location." },
    { "Light flash (small) at...", "Shows a small light flash at location." },
    { "Light flash (medium) at...", "Shows a medium light flash at location." },
    { "Light flash (large) at...", "Shows a large light flash at location." },
    { "Announce Win", "Announce that player has won." },
    { "Announce Lose", "Announce that player has lost." },
    { "Force end", "Force end of scenario." },
    { "Destroy Tag...", "Destroy tag and all attached triggers." },
    { "Set ambient step...", "Sets ambient light fade step value." },
    { "Set ambient rate...", "Sets ambient light fade rate." },
    { "Set ambient light...", "Fades ambient light to new lighting level." },
    { "AI triggers begin...", "Start AI triggers for specified house." },
    { "AI triggers stop...", "Stop AI triggers for specified house." },
    { "Ratio of AI trigger teams...", "AI percentage of teams created for AI triggers (100 = all for AI trigger teams, 0 = all for regular teams)." },
    { "Ratio of team aircraft...", "AI percentage of aircraft created for teams (100 = all for teams, 0 = all random)." },
    { "Ratio of team infantry...", "AI percentage of infantry created for teams (100 = all for teams, 0 = all random)." },
    { "Ratio of team units...", "AI percentage of units created for teams (100 = all for teams, 0 = all random)." },
    { "Reinforcement (team) [at waypoint]...", "Create reinforcement team at special waypoint location." },
    { "Wakeup self", "Breaks out of sleep or harmless mode so as to enter guard mode." },
    { "Wakeup all sleepers", "Breaks all units out of sleep mode." },
    { "Wakeup all harmless", "Breaks all out of harmless mode." },
    { "Wakeup group...", "Wakeup all units of specified group." },
    { "Vein growth...", "Control if veins grow or not." },
    { "Tiberium growth...", "Control if Tiberium grows or not." },
    { "Ice growth...", "Control if ice grows or not." },
    { "Particle Anim at...", "Show particle animation at location." },
    { "Remove Particle Anim at...", "Delete particle anims at specified location." },
    { "Lightning strike at...", "A single Ion Storm lightning strike." },
    { "Go Berzerk", "Attached object (cyborg) goes berzerk." },
    { "Activate Firestorm Defense", "Turns on a house's firestorm defense." },
    { "Deactivate Firestorm Defense", "Turns off a house's firestorm defense." },
    { "Ion-cannon strike...", "Fires Ion-Cannon at waypoint specified." },
    { "Nuke strike...", "Fires Nuke at waypoint specified from nearest edge." },
    { "Chem-missile strike...", "Fires Chemical missile at waypoint specified." },
    { "Toggle Train Cargo", "Toggles state of cargo train dropping crate." },
    { "Play Sound Effect (Random)...", "Plays sound effect at random waypoint." },
    { "Play Sound Effect At...", "Plays sound effect specified at waypoint specified." },
    { "Play Ingame Movie...", "Displays the specified movie ingame. Player still has control of interface and units." },
    { "Reshroud Map At...", "Does an anti-map ping at waypoint specified." },
    { "Lightning Storm strike...", "Lightning storm owned by owner of trigger at waypoint." },
    { "Timer Text...", "What text label to display with timer (i.e. actual text is in game.str)." },
    { "Flash Team...", "Flashes the specified team for the specified number of frames" },
    { "Talk Bubble...", "Displays talk bubble over unit." }
};
