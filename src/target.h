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
class IsometricTileClass;
class TeamClass;
class InfantryClass;
class UnitClass;
class BuildingClass;
class AircraftClass;
class CellClass;


bool Target_Legal(AbstractClass * target, bool check_active = false);

AbstractClass * As_Target(AbstractClass *a);

bool Is_Target_Team(AbstractClass * a);
bool Is_Target_TeamType(AbstractClass * a);
bool Is_Target_Trigger(AbstractClass * a);
bool Is_Target_TriggerType(AbstractClass * a);
bool Is_Target_Infantry(AbstractClass * a);
bool Is_Target_Bullet(AbstractClass * a);
bool Is_Target_Terrain(AbstractClass * a);
bool Is_Target_Cell(AbstractClass * a);
bool Is_Target_Unit(AbstractClass * a);
bool Is_Target_Building(AbstractClass * a);
bool Is_Target_Aircraft(AbstractClass * a);
bool Is_Target_Animation(AbstractClass * a);
bool Is_Target_IsoTile(AbstractClass * a);
bool Is_Target_Object(AbstractClass * a);
bool Is_Target_Foot(AbstractClass * a);
bool Is_Target_Techno(AbstractClass * a);
bool Is_Target_TypeClass(AbstractClass * a);

InfantryClass *Target_As_Infantry(AbstractClass * a, bool use_dynamic_cast = true);
BulletClass *Target_As_Bullet(AbstractClass * a, bool use_dynamic_cast = true);
TerrainClass *Target_As_Terrain(AbstractClass * a, bool use_dynamic_cast = true);
CellClass *Target_As_Cell(AbstractClass * a, bool use_dynamic_cast = true);
UnitClass *Target_As_Unit(AbstractClass * a, bool use_dynamic_cast = true);
BuildingClass *Target_As_Building(AbstractClass * a, bool use_dynamic_cast = true);
AircraftClass *Target_As_Aircraft(AbstractClass * a, bool use_dynamic_cast = true);
AnimClass *Target_As_Animation(AbstractClass * a, bool use_dynamic_cast = true);
IsometricTileClass *Target_As_IsoTile(AbstractClass * a, bool use_dynamic_cast = true);
TechnoClass *Target_As_Techno(AbstractClass * a, bool use_dynamic_cast = true);
FootClass *Target_As_Foot(AbstractClass * a, bool use_dynamic_cast = true);
ObjectClass *Target_As_Object(AbstractClass * a, bool use_dynamic_cast = true);


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

        unsigned Pack_Target(AbstractClass * t);

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
        TargetClass(Coord &coord);
        TargetClass(AbstractClass * ptr);
};
