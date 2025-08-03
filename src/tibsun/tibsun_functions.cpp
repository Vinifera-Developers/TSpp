/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_FUNCTIONS.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Global and uncategorised functions.
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
#include "tibsun_functions.h"
#include "abstracttype.h"
#include "ccfile.h"
#include "foot.h"
#include "iomap.h"
#include "object.h"
#include "objecttype.h"
#include "techno.h"
#include "tibsun_globals.h"


/***************************************************************************
**  These are the text representations of the radio messages that can be transmitted.
*/
static const char * const RadioMessages[RADIO_COUNT] =
{
    "static (no message)",
    "Roger.",
    "Come in.",
    "Over and out.",
    "Requesting transport.",
    "Attach to transport.",
    "I've got a delivery for you.",
    "I'm performing load/unload maneuver. Be careful.",
    "I'm clear.",
    "You are clear to unload. Driving away now.",
    "Am unable to comply.",
    "I'm starting construction now... act busy.",
    "I've finished construction. You are free.",
    "We bumped, redraw yourself please.",
    "I'm trying to load up now.",
    "May I become a passenger?",
    "Are you ready to receive shipment?",
    "Are you trying to become a passenger?",
    "Move to location X.",
    "Do you need to move?",
    "All right already. Now what?",
    "I'm a passenger now.",
    "Backup into refinery now.",
    "Run away!",
    "Tether established.",
    "Tether broken.",
    "Repair one step.",
    "Are you prepared to fight?",
    "Attack this target please.",
    "Reload one step.",
    "Circumstances prevent success.",
    "All done with the request.",
    "Do you need service depot work?",
    "Are you sitting on service depot?",
    "Gimme a ride!"
};


/***************************************************************************
**  These are the ASCII names for the cell land types.
*/
static const char * const LandName[LAND_COUNT] =
{
    "Clear",
    "Road",
    "Water",
    "Rock",
    "Wall",
    "Tiberium",
    "Beach",
    "Rough",
    "Ice",
    "Railroad",
    "Tunnel",
    "Weeds",
};


/***************************************************************************
**  These are the ASCII names for the display drawing layer types.
*/
static const char * const LayerName[LAYER_COUNT] =
{
    "Underground",
    "Surface",
    "Ground",
    "Air",
    "Top"
};


/***************************************************************************
**  These are the ASCII names for the basic unit facing types.
*/
static const char * const FacingName[FACING_COUNT] =
{
    "north",
    "north-east",
    "east",
    "south-east",
    "south",
    "south-west",
    "west",
    "north-west"
};


/**
 *  Retrieves the name for the given ArmorType.
 *
 *  @author: CCHyper
 */
const char *Name_From_Armor(ArmorType armor)
{
    if (armor >= ARMOR_NONE && armor < ARMOR_COUNT) {
        return ArmorName[armor];
    }
    return "<none>";
}


/**
 *  Converts ASCII name into ActionType.
 * 
 *  @author: CCHyper
 */
ActionType Action_From_Name(const char *name)
{
    if (name) {
        for (ActionType action = ACTION_FIRST; action < ACTION_COUNT; ++action) {
            if (stricmp(ActionName[action], name) == 0) {
                return action;
            }
        }
    }
    return ACTION_NONE;
}


/**
 *  Retrieves the name for the given ActionType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_Action(ActionType action)
{
    if (action != LAYER_NONE && action < ACTION_COUNT) {
        return ActionName[action];
    }
    return "<none>";
}


/**
 *  Converts ASCII name into LandType.
 * 
 *  @author: CCHyper
 */
LayerType Layer_From_Name(const char *name)
{
    if (name) {
        for (LayerType layer = LAYER_FIRST; layer < LAYER_COUNT; ++layer) {
            if (stricmp(LayerName[layer], name) == 0) {
                return layer;
            }
        }
    }
    return LAYER_NONE;
}


/**
 *  Retrieves the name for the given LandType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_Layer(LayerType layer)
{
    if (layer != LAYER_NONE && layer < LAYER_COUNT) {
        return LayerName[layer];
    }
    return "<none>";
}


/**
 *  Converts ASCII name into FacingType.
 * 
 *  @author: CCHyper
 */
FacingType Facing_From_Name(const char *name)
{
    if (name) {
        for (FacingType facing = FACING_FIRST; facing < FACING_COUNT; ++facing) {
            if (stricmp(FacingName[facing], name) == 0) {
                return facing;
            }
        }
    }
    return FACING_NONE;
}


/**
 *  Retrieves the name for the given FacingType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_Facing(FacingType facing)
{
    if (facing != FACING_NONE && facing < FACING_COUNT) {
        return FacingName[facing];
    }
    return "<none>";
}


/**
*  Converts ASCII name into LandType.
* 
*  @author: CCHyper
*/
LandType Land_From_Name(const char *name)
{
    if (name) {
        for (LandType land = LAND_FIRST; land < LAND_COUNT; ++land) {
            if (stricmp(LandName[land], name) == 0) {
                return land;
            }
        }
    }
    return LAND_NONE;
}


/**
*  Retrieves the name for the given LandType.
* 
*  @author: CCHyper
*/
const char *Name_From_Land(LandType land)
{
    if (land != LAND_NONE && land < LAND_COUNT) {
        return LandName[land];
    }
    return "<none>";
}


/**
 *  Retrieves the name for the given RadioMessageType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_RadioMessage(RadioMessageType msg)
{
    if (msg >= RADIO_STATIC && msg < RADIO_COUNT) {
        return RadioMessages[msg];
    }
    return "<unknown>";
}


/**
 *  Causes all selected objects to become unselected except the object specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(ObjectClass *object)
{
    int index = 0;
    while (index < CurrentObjects.Count()) {

        if (CurrentObjects[index] == object) {
            ++index;
            continue;
        }

        int count_before = CurrentObjects.Count();
        CurrentObjects[index]->Unselect();

        if (count_before <= CurrentObjects.Count()) {
            CurrentObjects.Delete(CurrentObjects[index]);
        }
    }
}


/**
 *  Causes all selected objects to become unselected except the objecttype specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(ObjectTypeClass *objecttype)
{
    int index = 0;
    while (index < CurrentObjects.Count()) {

        if (CurrentObjects[index]->Class_Of() == objecttype) {
            ++index;
            continue;
        }

        int count_before = CurrentObjects.Count();
        CurrentObjects[index]->Unselect();

        if (count_before <= CurrentObjects.Count()) {
            CurrentObjects.Delete(CurrentObjects[index]);
        }
    }
}


/**
 *  Causes all selected objects to become unselected except the object type specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(RTTIType rtti)
{
    int index = 0;
    while (index < CurrentObjects.Count()) {

        if (CurrentObjects[index]->Fetch_RTTI() == rtti) {
            ++index;
            continue;
        }

        int count_before = CurrentObjects.Count();
        CurrentObjects[index]->Unselect();

        if (count_before <= CurrentObjects.Count()) {
            CurrentObjects.Delete(CurrentObjects[index]);
        }
    }
}


/**
 *  Loads and allocates buffer for a file.
 * 
 *  @author: 10/17/1994 JLB
 */
void *Load_Alloc_Data(char const *name, int flags)
{
    CCFileClass file(name);
    return Load_Alloc_Data(file);
}


/**
 *  Allocates a buffer and loads the file into it.
 * 
 *  @author: 10/17/1994 JLB
 */
void *Load_Alloc_Data(FileClass &file)
{
    void *ptr = nullptr;
    long size = file.Size();

    ptr = new char [size];
    if (ptr) {
        file.Read(ptr, size);
    }

    return ptr;
}


bool Is_Object(const AbstractClass *a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<const ObjectClass *>(a);
    } else {
        return (a->Fetch_RTTI() == RTTI_UNIT
             || a->Fetch_RTTI() == RTTI_AIRCRAFT
             || a->Fetch_RTTI() == RTTI_INFANTRY
             || a->Fetch_RTTI() == RTTI_BUILDING
             || a->Fetch_RTTI() == RTTI_ANIM
             || a->Fetch_RTTI() == RTTI_LIGHT
             || a->Fetch_RTTI() == RTTI_BULLET
             || a->Fetch_RTTI() == RTTI_ISOTILE
             || a->Fetch_RTTI() == RTTI_PARTICLE
             || a->Fetch_RTTI() == RTTI_PARTICLESYSTEM
             || a->Fetch_RTTI() == RTTI_SMUDGE
             || a->Fetch_RTTI() == RTTI_TERRAIN
             || a->Fetch_RTTI() == RTTI_VOXELANIM
             || a->Fetch_RTTI() == RTTI_VEINHOLEMONSTER
             || a->Fetch_RTTI() == RTTI_WAVE);
    }
}


bool Is_Techno(const AbstractClass *a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<const TechnoClass *>(a);
    } else {
        return (a->Fetch_RTTI() == RTTI_UNIT
             || a->Fetch_RTTI() == RTTI_AIRCRAFT
             || a->Fetch_RTTI() == RTTI_INFANTRY
             || a->Fetch_RTTI() == RTTI_BUILDING);
    }
}


bool Is_Foot(const AbstractClass *a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<const FootClass *>(a);
    } else {
        return (a->Fetch_RTTI() == RTTI_UNIT
             || a->Fetch_RTTI() == RTTI_AIRCRAFT
             || a->Fetch_RTTI() == RTTI_INFANTRY);
    }
}


bool Is_TypeClass(const AbstractClass *a, bool use_dynamic_cast)
{
    if (use_dynamic_cast) {
        return dynamic_cast<const AbstractTypeClass *>(a);
    } else {
        RTTIType rtti = a->Fetch_RTTI();
        return (rtti == RTTI_UNITTYPE
             || rtti == RTTI_AIRCRAFTTYPE
             || rtti == RTTI_INFANTRYTYPE
             || rtti == RTTI_BUILDINGTYPE
             || rtti == RTTI_ANIMTYPE
             || rtti == RTTI_AITRIGGERTYPE
             || rtti == RTTI_BULLETTYPE
             || rtti == RTTI_CAMPAIGN
             || rtti == RTTI_SIDE
             || rtti == RTTI_HOUSETYPE
             || rtti == RTTI_ISOTILETYPE
             || rtti == RTTI_OVERLAYTYPE
             || rtti == RTTI_SMUDGETYPE
             || rtti == RTTI_PARTICLETYPE
             || rtti == RTTI_PARTICLESYSTEMTYPE
             || rtti == RTTI_SCRIPTTYPE
             || rtti == RTTI_SUPERWEAPONTYPE
             || rtti == RTTI_TAGTYPE
             || rtti == RTTI_TASKFORCE
             || rtti == RTTI_TEAMTYPE
             || rtti == RTTI_TERRAINTYPE
             || rtti == RTTI_TIBERIUM
             || rtti == RTTI_TRIGGERTYPE
             || rtti == RTTI_VOXELANIMTYPE
             || rtti == RTTI_WARHEADTYPE
             || rtti == RTTI_WEAPONTYPE);
    }
}


/**
 *  Get the tactical area.
 * 
 *  @author: CCHyper
 */
Rect Get_Tactical_Rect(bool use_options_size)
{
    Rect rect;

    int width = use_options_size ? Options.ScreenWidth : ScreenRect.Width;
    int height = use_options_size ? Options.ScreenHeight : ScreenRect.Height;

    rect.X = (Options.SidebarOn == SIDEBAR_SIDE_LEFT && !Debug_Map) ? SidebarClass::SIDE_WIDTH : 0;
    rect.Y = TabClass::TAB_HEIGHT;
    rect.Width = width - SidebarClass::SIDE_WIDTH;
    rect.Height = height - TabClass::TAB_HEIGHT;

    return rect;
}

/***********************************************************************************************
 * List_Copy -- Makes a copy of a cell offset list.                                            *
 *                                                                                             *
 *    This routine will make a copy of a cell offset list. It will only copy the significant   *
 *    elements of the list limited by the maximum length specified.                            *
 *                                                                                             *
 * INPUT:   source   -- Pointer to a cell offset list.                                         *
 *                                                                                             *
 *          len      -- The maximum number of cell offset elements to store in to the          *
 *                      destination list pointer.                                              *
 *                                                                                             *
 *          dest     -- Pointer to the destination list to store the copy into.                *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Ensure that the destination list is large enough to hold the list copy.         *
 *                                                                                             *
 * HISTORY:
 *   02/11/2025 Rampastring : Adjusted for Tiberian Sun.
 *   09/04/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void List_Copy(Cell const* source, int len, Cell* dest)
{
    if (source == nullptr || dest == nullptr) {
        return;
    }

    while (len > 0) {
        *dest = *source;
        if (*dest == REFRESH_EOL) return;
        dest++;
        source++;
        len--;
    }

    // Terminate the list.
    *(dest - 1) = REFRESH_EOL;
}


TechnoClass* As_TechnoClass(AbstractClass* target)
{
    if (target != nullptr) {
        switch (target->RTTI) {
        case RTTI_INFANTRY:
        case RTTI_UNIT:
        case RTTI_BUILDING:
        case RTTI_AIRCRAFT:
            return static_cast<TechnoClass*>(target);
        }
    }
    return nullptr;
}


TechnoClass* As_Techno(AbstractClass* target)
{
    if (target != nullptr) {
        switch (target->RTTI) {
        case RTTI_INFANTRY:
        case RTTI_UNIT:
        case RTTI_BUILDING:
        case RTTI_AIRCRAFT:
            return static_cast<TechnoClass*>(target);
        }
    }
    return nullptr;
}
