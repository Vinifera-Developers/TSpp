/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TARGET.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Type handling object targets.
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


class TargetClass;
class AbstractTypeClass;
class TagClass;
class TagTypeClass;
class AbstractClass;
class TechnoClass;
class ObjectClass;
class FootClass;
class TriggerClass;
class HouseClass;
class TechnoTypeClass;
class TriggerTypeClass;
class TeamTypeClass;
class TerrainClass;
class BulletClass;
class AnimClass;
class TeamClass;
class InfantryClass;
class UnitClass;
class BuildingClass;
class AircraftClass;
class CellClass;


bool Target_Legal(TARGET target, bool check_active = false);

bool Is_Target_Team(TARGET a);
bool Is_Target_TeamType(TARGET a);
bool Is_Target_Trigger(TARGET a);
bool Is_Target_TriggerType(TARGET a);
bool Is_Target_Infantry(TARGET a);
bool Is_Target_Bullet(TARGET a);
bool Is_Target_Terrain(TARGET a);
bool Is_Target_Cell(TARGET a);
bool Is_Target_Unit(TARGET a);
bool Is_Target_Building(TARGET a);
bool Is_Target_Aircraft(TARGET a);
bool Is_Target_Animation(TARGET a);
bool Is_Target_Object(TARGET a);
bool Is_Target_TypeClass(TARGET a);

InfantryClass *Target_As_Infantry(TARGET a, bool use_dynamic_cast = true);
BulletClass *Target_As_Bullet(TARGET a, bool use_dynamic_cast = true);
TerrainClass *Target_As_Terrain(TARGET a, bool use_dynamic_cast = true);
CellClass *Target_As_Cell(TARGET a, bool use_dynamic_cast = true);
UnitClass *Target_As_Unit(TARGET a, bool use_dynamic_cast = true);
BuildingClass *Target_As_Building(TARGET a, bool use_dynamic_cast = true);
AircraftClass *Target_As_Aircraft(TARGET a, bool use_dynamic_cast = true);
AnimClass *Target_As_Animation(TARGET a, bool use_dynamic_cast = true);


class xTargetClass
{
    public:
        operator RTTIType () const { return RTTIType(RTTI); }

        bool operator == (xTargetClass &tgt) { return tgt.RTTI == RTTI; }
        bool operator != (xTargetClass &tgt) { return tgt.RTTI != RTTI; }

        int Value() const { return ID; }
        RTTIType Kind() const { return RTTIType(RTTI); }

        void Invalidate() { RTTI = RTTI_NONE; ID = 0; }
        bool Is_Valid() const { return RTTI != RTTI_NONE; }

        int Pack() const;
        TargetClass Unpack(int target);

        bool Is_Legal(bool check_active = false);

        AbstractTypeClass *As_TypeClass() const;
        TagClass *As_Tag() const;
        TagTypeClass *As_TagType() const;
        AbstractClass *As_Abstract() const;
        TechnoClass *As_Techno() const;
        ObjectClass *As_Object() const;
        FootClass *As_Foot() const;
        TriggerClass *As_Trigger() const;
        HouseClass *As_House() const;
        TechnoTypeClass *As_TechnoType() const;
        TriggerTypeClass *As_TriggerType() const;
        TeamTypeClass *As_TeamType() const;
        TerrainClass *As_Terrain() const;
        BulletClass *As_Bullet() const;
        AnimClass *As_Anim() const;
        TeamClass *As_Team() const;
        InfantryClass *As_Infantry() const;
        UnitClass *As_Unit() const;
        BuildingClass *As_Building() const;
        AircraftClass *As_Aircraft() const;
        CellClass *As_Cell() const;

        unsigned Pack_Target(TARGET t);

    protected:
        int RTTI;
        int ID;
};


class TargetClass : public xTargetClass
{
    public:
        TargetClass() { Invalidate(); }
        TargetClass(const NoInitClass &noinit) {}
        TargetClass(Cell &cell);
        TargetClass(Coordinate &coord);
        TargetClass(TARGET ptr);
};
