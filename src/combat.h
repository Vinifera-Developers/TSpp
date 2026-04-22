/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  General damage and combat routines.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "tibsun_defines.h"


class TechnoClass;
class WarheadTypeClass;
class AnimTypeClass;


int Modify_Damage(int damage, const WarheadTypeClass* warhead, ArmorType armor, int distance);
void Chain_Reaction_Damage(const Cell& cell);
void Explosion_Damage(const Coord& coord, int strength, TechnoClass* source, const WarheadTypeClass* warhead, bool do_chain_reaction = true);
const AnimTypeClass* Combat_Anim(int damage, const WarheadTypeClass* warhead, LandType land, const Coord* coord);
void Combat_Lighting(Coord coord, int damage, WarheadTypeClass const* warhead, bool a4 = false);
void Wide_Area_Damage(const Coord& coord, LEPTON radius, int rawdamage, TechnoClass* source, const WarheadTypeClass* warhead);
int Get_Explosion_Z(Coord coord);
