/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COMBAT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         General damage and combat routines.
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

#include "tibsun_defines.h"


class TechnoClass;
class WarheadTypeClass;
class AnimTypeClass;


int Modify_Damage(int damage, const WarheadTypeClass * warhead, ArmorType armor, int distance);
void Chain_Reaction_Damage(Cell &cell);
void Explosion_Damage(const Coordinate &coord, int strength, TechnoClass * source, const WarheadTypeClass * warhead, bool a5 = false);
const AnimTypeClass * Combat_Anim(int damage, const WarheadTypeClass * warhead, LandType land, const Coordinate *coord);
void Combat_Lighting(Coordinate coord, int damage, WarheadTypeClass const * warhead, bool a4 = false);
void Wide_Area_Damage(const Coordinate &coord, LEPTON radius, int rawdamage, TechnoClass * source, const WarheadTypeClass * warhead);
int Get_Explosion_Z(int z, Coordinate* coord);
