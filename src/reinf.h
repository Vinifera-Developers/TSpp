/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          REINF.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Special case reinforcements.
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
#pragma once

#include "always.h"
#include "tibsun_defines.h"


class AircraftClass;
class FootClass;
class TeamTypeClass;
class TechnoClass;
class HouseClass;
class AircraftClass;
class TechnoTypeClass;


bool Need_To_Take(const AircraftClass *air);
bool Do_Reinforcements(const TeamTypeClass *team, WaypointType wp = WAYPOINT_NONE);
bool Pop_Group_Out_Of_Object(FootClass *group, TechnoClass *object);
int Create_Tunnel_Reinforcement(const TeamTypeClass *teamtype, FootClass *object, Cell &cell, bool a4 = false);
bool Create_Special_Reinforcement(HouseClass *house, const TechnoTypeClass *type, const TechnoTypeClass *another, ScriptMissionType mission = SMISSION_NONE, int argument = 0);
int Create_Air_Reinforcement(HouseClass *house, AircraftType air, int number, MissionType mission, TARGET tarcom, TARGET navcom, InfantryType passenger = INFANTRY_NONE);
