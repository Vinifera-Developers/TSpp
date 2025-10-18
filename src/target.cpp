/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TARGET.CPP
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
#include "target.h"
#include "abstract.h"
#include "abstracttype.h"
#include "aircraft.h"
#include "anim.h"
#include "building.h"
#include "bullet.h"
#include "cell.h"
#include "infantry.h"
#include "isotile.h"
#include "object.h"
#include "team.h"
#include "teamtype.h"
#include "terrain.h"
#include "trigger.h"
#include "triggertype.h"
#include "unit.h"


AbstractClass* As_Target(AbstractClass* a)
{
    return reinterpret_cast<AbstractClass*>(a);
}


bool Is_Target_Team(AbstractClass* a)
{
    return dynamic_cast<TeamClass*>(a);
}


bool Is_Target_TeamType(AbstractClass* a)
{
    return dynamic_cast<TeamTypeClass*>(a);
}


bool Is_Target_Trigger(AbstractClass* a)
{
    return dynamic_cast<TriggerClass*>(a);
}


bool Is_Target_TriggerType(AbstractClass* a)
{
    return dynamic_cast<TriggerTypeClass*>(a);
}


bool Is_Target_Infantry(AbstractClass* a)
{
    return dynamic_cast<InfantryClass*>(a);
}


bool Is_Target_Bullet(AbstractClass* a)
{
    return dynamic_cast<BulletClass*>(a);
}


bool Is_Target_Terrain(AbstractClass* a)
{
    return dynamic_cast<TerrainClass*>(a);
}


bool Is_Target_Cell(AbstractClass* a)
{
    return dynamic_cast<CellClass*>(a);
}


bool Is_Target_Unit(AbstractClass* a)
{
    return dynamic_cast<UnitClass*>(a);
}


bool Is_Target_Building(AbstractClass* a)
{
    return dynamic_cast<BuildingClass*>(a);
}


bool Is_Target_Aircraft(AbstractClass* a)
{
    return dynamic_cast<AircraftClass*>(a);
}


bool Is_Target_Animation(AbstractClass* a)
{
    return dynamic_cast<AnimClass*>(a);
}


bool Is_Target_IsoTile(AbstractClass* a)
{
    return dynamic_cast<IsometricTileClass*>(a);
}


bool Is_Target_Object(AbstractClass* a)
{
    return dynamic_cast<ObjectClass*>(a);
}


bool Is_Target_Foot(AbstractClass* a)
{
    return dynamic_cast<FootClass*>(a);
}


bool Is_Target_Techno(AbstractClass* a)
{
    return dynamic_cast<TechnoClass*>(a);
}


bool Is_Target_TypeClass(AbstractClass* a)
{
    return dynamic_cast<AbstractTypeClass*>(a);
}


InfantryClass* Target_As_Infantry(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<InfantryClass*>(a);
    } else {
        return a->RTTI == RTTI_INFANTRY ? reinterpret_cast<InfantryClass*>(a) : nullptr;
    }
}


BulletClass* Target_As_Bullet(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<BulletClass*>(a);
    } else {
        return a->RTTI == RTTI_BULLET ? reinterpret_cast<BulletClass*>(a) : nullptr;
    }
}


TerrainClass* Target_As_Terrain(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<TerrainClass*>(a);
    } else {
        return a->RTTI == RTTI_TERRAIN ? reinterpret_cast<TerrainClass*>(a) : nullptr;
    }
}

CellClass* Target_As_Cell(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<CellClass*>(a);
    } else {
        return a->RTTI == RTTI_CELL ? reinterpret_cast<CellClass*>(a) : nullptr;
    }
}


UnitClass* Target_As_Unit(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<UnitClass*>(a);
    } else {
        return a->RTTI == RTTI_UNIT ? reinterpret_cast<UnitClass*>(a) : nullptr;
    }
}


BuildingClass* Target_As_Building(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<BuildingClass*>(a);
    } else {
        return a->RTTI == RTTI_BUILDING ? reinterpret_cast<BuildingClass*>(a) : nullptr;
    }
}


AircraftClass* Target_As_Aircraft(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<AircraftClass*>(a);
    } else {
        return a->RTTI == RTTI_AIRCRAFT ? reinterpret_cast<AircraftClass*>(a) : nullptr;
    }
}


AnimClass* Target_As_Animation(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<AnimClass*>(a);
    } else {
        return a->RTTI == RTTI_ANIM ? reinterpret_cast<AnimClass*>(a) : nullptr;
    }
}

IsometricTileClass* Target_As_IsoTile(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<IsometricTileClass*>(a);
    } else {
        return a->RTTI == RTTI_ISOTILE ? reinterpret_cast<IsometricTileClass*>(a) : nullptr;
    }
}


TechnoClass* Target_As_Techno(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<TechnoClass*>(a);
    } else {
        return (a->RTTI == RTTI_UNIT || a->RTTI == RTTI_AIRCRAFT || a->RTTI == RTTI_INFANTRY || a->RTTI == RTTI_BUILDING) ? reinterpret_cast<TechnoClass*>(a) : nullptr;
    }
}


FootClass* Target_As_Foot(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<FootClass*>(a);
    } else {
        return (a->RTTI == RTTI_UNIT || a->RTTI == RTTI_AIRCRAFT || a->RTTI == RTTI_INFANTRY) ? reinterpret_cast<FootClass*>(a) : nullptr;
    }
}


ObjectClass* Target_As_Object(AbstractClass* a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<ObjectClass*>(a);
    } else {
        return (a->RTTI == RTTI_ANIM ||
                a->RTTI == RTTI_LIGHTSOURCE ||
                a->RTTI == RTTI_BULLET ||
                a->RTTI == RTTI_ISOTILE ||
                a->RTTI == RTTI_OVERLAY ||
                a->RTTI == RTTI_PARTICLE ||
                a->RTTI == RTTI_PARTICLESYSTEM ||
                a->RTTI == RTTI_SMUDGE ||
                a->RTTI == RTTI_TERRAIN ||
                a->RTTI == RTTI_VOXELANIM ||
                a->RTTI == RTTI_VEINHOLEMONSTER ||
                a->RTTI == RTTI_WAVE ||
                a->RTTI == RTTI_UNIT ||
                a->RTTI == RTTI_AIRCRAFT ||
                a->RTTI == RTTI_INFANTRY ||
                a->RTTI == RTTI_BUILDING)
                   ? reinterpret_cast<FootClass*>(a)
                   : nullptr;
    }
}


bool xTargetClass::Is_Legal(bool check_active)
{
    if (RTTI == RTTI_NONE) {
        return false;
    }
    ObjectClass* obj = As_Object();
    if (obj == nullptr) {
        return false;
    }
    if (check_active) {
        return obj->IsActive;
    }
    return true;
}
