/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Special case reinforcements.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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


bool Need_To_Take(const AircraftClass* air);
bool Do_Reinforcements(const TeamTypeClass* team, WAYPOINT wp = WAYPOINT_NONE);
bool Pop_Group_Out_Of_Object(FootClass* group, TechnoClass* object);
int Create_Tunnel_Reinforcement(const TeamTypeClass* teamtype, FootClass* object, Cell& cell, bool a4 = false);
bool Create_Special_Reinforcement(HouseClass* house, const TechnoTypeClass* type, const TechnoTypeClass* another, ScriptMissionType mission = SMISSION_NONE, int argument = 0);
int Create_Air_Reinforcement(HouseClass* house, AircraftType air, int number, MissionType mission, AbstractClass* tarcom, AbstractClass* navcom, InfantryType passenger = INFANTRY_NONE);
