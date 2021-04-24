/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_DEFINES.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file which contains all the games types.
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
#include "rect.h"
#include "fixed.h"


class AbstractClass;
class HouseClass;
class NoInitClass;


/**
 *  This head contains all the game enums, structs and primitive types.
 */


/**
 *  #NOTE:
 *  Some enumerations in this header mirror the object list in RULES.INI. The entries included
 *  here are for completeness and should *not* be used when fetching a type from the heap.
 *  If you wish to fetch a type from the heap, use the classes "From_Name" function, as
 *  it will return a null pointer if not found. Worst case scenario, use "Find_Or_Make".
 */


// Max stored views/bookmarks
#define VIEW_COUNT 4

// Save filename description.
#define DESCRIP_MAX 44          // 40 chars + CR + LF + CTRL-Z + NULL

// This is the max number of events supported in one frame.
#define MAX_EVENTS 64

// Size of the map in cells.
#define MAP_CELL_W 512
#define MAP_CELL_H 512
#define MAP_CELL_TOTAL (MAP_CELL_W * MAP_CELL_H)

// Cell pixel dimensions.
#define CELL_PIXEL_W 24
#define CELL_PIXEL_H 48

// Sub-cell dimensions.
#define CELL_LEPTON_W 256
#define CELL_LEPTON_H 256

#define PIXEL_LEPTON_W  (CELL_LEPTON_W / CELL_PIXEL_W)
#define PIXEL_LEPTON_H  (CELL_LEPTON_H / CELL_PIXEL_H)


/**
 *  The map is broken down into regions of this specified dimensions.
 */
#define REGION_WIDTH        4
#define REGION_HEIGHT       4
#define MAP_REGION_WIDTH    (((MAP_CELL_W + (REGION_WIDTH -1)) / REGION_WIDTH)+2)
#define MAP_REGION_HEIGHT   (((MAP_CELL_H + (REGION_WIDTH -1)) / REGION_HEIGHT)+2)
#define MAP_TOTAL_REGIONS   (MAP_REGION_WIDTH * MAP_REGION_HEIGHT)


/**
 *  Timer constants.
 */
#define TIMER_SECOND        60
#define TIMER_MINUTE        (TIMER_SECOND * 60)

#define TICKS_PER_SECOND    15
#define TICKS_PER_MINUTE    (TICKS_PER_SECOND * 60)
#define TICKS_PER_HOUR      (TICKS_PER_MINUTE * 60)


#define TXT_NONE    0
#define TXT_OK      10


#define TARGET_NONE TargetClass()


typedef enum WaypointEnum
{
    WAYPT_HOME = 98,    // Home-cell for this scenario
    WAYPT_REINF,        // cell where reinforcements arrive
    WAYPT_SPECIAL,      // Used by special airdrop reinforcements.
    WAYPT_COUNT
} WaypointEnum;


typedef enum DiffType : int
{
    DIFF_EASY,
    DIFF_NORMAL,
    DIFF_HARD,

    DIFF_COUNT,
    DIFF_FIRST = 0
};


typedef enum FacingType
{
    FACING_N,
    FACING_NE,
    FACING_E,
    FACING_SE,
    FACING_S,
    FACING_SW,
    FACING_W,
    FACING_NW,

    FACING_COUNT,

    FACING_NONE = -1,
    FACING_FIRST = 0
} FacingType;
DEFINE_ENUMERATION_OPERATORS(FacingType);

typedef enum DirType
{
    DIR_N = 0,          // 0
    DIR_NE = 1 << 5,    // 32
    DIR_E = 2 << 5,     // 64
    DIR_SE = 3 << 5,    // 96
    DIR_S = 4 << 5,     // 128
    DIR_SW = 5 << 5,    // 160
    DIR_W = 6 << 5,     // 192
    DIR_NW = 7 << 5,    // 224

    DIR_MIN = 0,
    DIR_MAX = 255,

    DIR_SW_X1 = DirType((5<<5)-8),  // 152      // Direction of harvester while unloading.
    DIR_SW_X2 = DirType((5<<5)-16), // 144      // Direction of harvester while unloading.
} DirType;
DEFINE_ENUMERATION_OPERATORS(DirType);

typedef enum MPHType {} MPHType;
typedef enum CrateType {} CrateType;

typedef enum VocType
{
    VOC_NONE = -1,

    VOC_FIRST = 0
} VocType;
DEFINE_ENUMERATION_OPERATORS(VocType);

typedef enum VQType {} VQType;

typedef enum ScriptType
{
    SCRIPT_NONE = -1,

    SCRIPT_FIRST = 0
} ScriptType;
DEFINE_ENUMERATION_OPERATORS(ScriptType);

typedef enum ThemeType
{
    THEME_QUIET = -3,
    THEME_PICK_ANOTHER = -2,
    THEME_NONE = -1,

    THEME_COUNT,
    THEME_FIRST = 0
} ThemeType;
DEFINE_ENUMERATION_OPERATORS(ThemeType);

typedef enum BulletType
{
    BULLET_NONE = -1,

    BULLET_FIRST = 0
} BulletType;
DEFINE_ENUMERATION_OPERATORS(BulletType);

typedef enum WeaponType
{
    WEAPON_NONE = -1,

    WEAPON_FIRST = 0
} WeaponType;
DEFINE_ENUMERATION_OPERATORS(WeaponType);

typedef enum VoxelAnimType
{
    VOXELANIM_NONE = -1,

    VOXELANIM_FIRST = 0
} VoxelAnimType;
DEFINE_ENUMERATION_OPERATORS(VoxelAnimType);

typedef enum AircraftType
{
    AIRCRAFT_NONE = -1,

    AIRCRAFT_FIRST = 0
} AircraftType;
DEFINE_ENUMERATION_OPERATORS(AircraftType);

typedef enum UnitType
{
    UNIT_NONE = -1,

    UNIT_FIRST = 0
} UnitType;
DEFINE_ENUMERATION_OPERATORS(UnitType);

typedef enum InfantryType
{
    INFANTRY_NONE = -1,

    INFANTRY_FIRST = 0
} InfantryType;
DEFINE_ENUMERATION_OPERATORS(InfantryType);

typedef enum HousesType
{
    HOUSE_NONE = -1,

    HOUSE_FIRST = 0
} HousesType;
DEFINE_ENUMERATION_OPERATORS(HousesType);

typedef enum PipType {} PipType;
typedef enum PipScaleType {} PipScaleType;

typedef enum CategoryType
{
    CATEGORY_SOLDIER,           // Soldier
    CATEGORY_CIVILIAN,          // Civilian
    CATEGORY_VIP,               // VIP/Agent
    CATEGORY_RECON,             // Recon Vehicle
    CATEGORY_AFV,               // Armored Fighting Vehicle
    CATEGORY_IFV,               // Infantry Fighting Vehicle
    CATEGORY_ARTY,              // Indirect Fire Support
    CATEGORY_SUPPORT,           // Misc. Support Vehicle
    CATEGORY_TRANSPORT,         // Transport Vehicle
    CATEGORY_AIRSUPPORT,        // Air Combat Support
    CATEGORY_AIRTRANSPORT,      // Air Transport

    CATEGORY_COUNT,

    CATEGORY_NONE = -1,
    CATEGORY_FIRST = 0
} CategoryType;

typedef enum TeamType
{
    TEAM_NONE = -1,
    TEAM_FIRST = 0,
} TeamType;
DEFINE_ENUMERATION_OPERATORS(TeamType);

typedef enum WaypointType : char
{
    WAYPOINT_NONE = -1,
    WAYPOINT_FIRST = 0,
} WaypointType;
DEFINE_ENUMERATION_OPERATORS(WaypointType);

typedef enum TubeType : char
{
    TUBE_NONE = -1,
    TUBE_FIRST = 0,
} TubeType;
DEFINE_ENUMERATION_OPERATORS(TubeType);

typedef enum TubeDirType : char
{
    TUBE_FACING_N, // North
    TUBE_FACING_NE, // North-East
    TUBE_FACING_E, // East
    TUBE_FACING_SE, // South-East
    TUBE_FACING_S, // South
    TUBE_FACING_SW, // South-West
    TUBE_FACING_W, // West
    TUBE_FACING_NW, // North-West

    TUBE_FACING_COUNT,

    TUBE_FACING_NONE = -1,
    TUBE_FACING_FIRST = 0,
} TubeDirType;
DEFINE_ENUMERATION_OPERATORS(TubeDirType);

typedef enum IsometricTileType
{
    ISOTILE_CLEAR = 0,

    ISOTILE_NONE = -1,

    ISOTILE_FIRST = 0
} IsometricTileType;
DEFINE_ENUMERATION_OPERATORS(IsometricTileType);

typedef enum BAnimType
{
    BANIM_UPGRADE_ONE,
    BANIM_UPGRADE_TWO,
    BANIM_UPGRADE_THREE,
    BANIM_ACTIVE_ONE,
    BANIM_ACTIVE_TWO,
    BANIM_ACTIVE_THREE,
    BANIM_ACTIVE_FOUR,
    BANIM_PRE_PRODUCTION,
    BANIM_PRODUCTION,
    BANIM_TURRET,
    BANIM_SPECIAL_ONE,
    BANIM_SPECIAL_TWO,
    BANIM_SPECIAL_THREE,

    BANIM_COUNT,

    BANIM_M2 = -2,              // used to free all anims?
    BANIM_NONE = -1,

    BANIM_FIRST = 0
};
DEFINE_ENUMERATION_OPERATORS(BAnimType);


typedef enum BStateType
{
    BSTATE_CONSTRUCTION,
    BSTATE_IDLE,
    BSTATE_ACTIVE,
    BSTATE_FULL,
    BSTATE_AUX1,
    BSTATE_AUX2,

    BSTATE_COUNT,

    BSTATE_NONE = -1
} BStateType;

typedef enum BSizeType {} BSizeType;

typedef enum MZoneType
{
    MZONE_NORMAL,               // Normal terrestrial objects (can't crush walls).
    MZONE_CRUSHER,              // Can crush crushable wall types.
    MZONE_DESTROYER,            // Can destroy walls.
    MZONE_AMPHIBIOUS_DESTROYER,
    MZONE_AMPHIBIOUS_CRUSHER,
    MZONE_AMPHIBIOUS,           // Water based objects.
    MZONE_SUBTERANNEAN,
    MZONE_INFANTRY,
    MZONE_INFANTRY_DESTROYER,
    MZONE_FLYER,
    MZONE_COUNT,

    MZONE_NONE = -1,
    MZONE_FIRST = 0,
} MZoneType;
DEFINE_ENUMERATION_OPERATORS(MZoneType);

typedef enum ZoneType
{
    ZONE_CORE,      // Center of base.
    ZONE_NORTH,     // North section.
    ZONE_EAST,      // East section.
    ZONE_SOUTH,     // South section.
    ZONE_WEST,      // West section.

    ZONE_COUNT,
    ZONE_NONE = -1,
    ZONE_FIRST = 0
} ZoneType;
DEFINE_ENUMERATION_OPERATORS(ZoneType);

typedef enum SideType
{
    SIDE_NONE = -1,

    SIDE_FIRST = 0
} SideType;
DEFINE_ENUMERATION_OPERATORS(SideType);

typedef enum SourceType {} SourceType;
typedef enum SmudgeType {} SmudgeType;

typedef enum OverlayType
{
    OVERLAY_NONE = -1,

    OVERLAY_FIRST = 0
} OverlayType;
DEFINE_ENUMERATION_OPERATORS(OverlayType);

typedef enum AnimType
{
    ANIM_NONE = -1,

    ANIM_FIRST = 0
} AnimType;
DEFINE_ENUMERATION_OPERATORS(AnimType);

typedef enum WarheadType
{
    WARHEAD_NONE = -1,

    WARHEAD_FIRST = 0
} WarheadType;
DEFINE_ENUMERATION_OPERATORS(WarheadType);

typedef enum AbilityType
{
    ABILITY_FASTER,
    ABILITY_STRONGER,
    ABILITY_FIREPOWER,
    ABILITY_SCATTER,
    ABILITY_ABILITY_ROF,
    ABILITY_SIGHT,
    ABILITY_CLOAK,
    ABILITY_TIBERIUM_PROOF,
    ABILITY_VEIN_PROOF,
    ABILITY_SELF_HEAL,
    ABILITY_EXPLODES,
    ABILITY_RADAR_INVISIBLE,
    ABILITY_SENSORS,
    ABILITY_FEARLESS,
    ABILITY_C4,
    ABILITY_TIBERIUM_HEAL,
    ABILITY_GUARD_AREA,
    ABILITY_CRUSHER,

    ABILITY_COUNT,

    ABILITY_NONE = -1,
    ABILITY_FIRST = 0
} AbilityType;
DEFINE_ENUMERATION_OPERATORS(AbilityType);

typedef enum ScriptMissionType
{
    SMISSION_ATTACK,                // Attack specified quarry type.
    SMISSION_ATT_WAYPT,             // Attack specified waypoint
    SMISSION_BEZERK,
    SMISSION_MOVE,                  // moves to waypoint specified.
    SMISSION_MOVECELL,              // moves to cell # specified.
    SMISSION_GUARD,                 // works like an infantry's guard mission
    SMISSION_LOOP,                  // loop back to start of mission list
    SMISSION_PLAYER_WIN,
    SMISSION_UNLOAD,                // Unload at current location.
    SMISSION_DEPLOY,                // Deploy mobile building type.
    SMISSION_HOUND_DOG,             // Follow nearest friendly unit.
    SMISSION_DO,                    // Do guard, sticky, area guard (mission sticks on this).
    SMISSION_SET_GLOBAL,            // Set global variable.
    SMISSION_IDLE,
    SMISSION_LOAD,                  // Load onto transport member of team.
    SMISSION_SPY,                   // Spy enter the building at specified waypoint
    SMISSION_PATROL,                // Move but look for enemies as well.
    SMISSION_CHANGE_SCRIPT,
    SMISSION_CHANGE_TEAM,
    SMISSION_PANIC,
    SMISSION_CHANGE_HOUSE,
    SMISSION_SCATTER,
    SMISSION_GOTO_NEARBY_SHROUD,
    SMISSION_PLAYER_LOSES,
    SMISSION_PLAY_SPEECH,
    SMISSION_PLAY_SOUND,
    SMISSION_PLAY_MOVIE,
    SMISSION_PLAY_MUSIC,
    SMISSION_REDUCE_TIBERIUM,
    SMISSION_BEGIN_PRODUCTION,
    SMISSION_FIRE_SALE,
    SMISSION_SELF_DESTRUCT,
    SMISSION_IOSTORM_START,
    SMISSION_IONSTORM_END,
    SMISSION_CENTER_VIEW_ON_TEAM,
    SMISSION_RESHROUD_MAP,
    SMISSION_REVEAL_MAP,
    SMISSION_DELETE_TEAM_MEMBERS,
    SMISSION_CLEAR_GLOBAL,
    SMISSION_SET_LOCAL,
    SMISSION_CLEAR_LOCAL,
    SMISSION_UNPANIC,
    SMISSION_FORCE_FACING,
    SMISSION_WAIT_TILL_FULLY_LOADED,
    SMISSION_TRUCK_UNLOAD,
    SMISSION_TRUCK_LOAD,
    SMISSION_ATTACK_ENEMY_BUILDING,
    SMISSION_MOVETO_ENEMY_BUILDING,
    SMISSION_SCOUT,
    SMISSION_SUCCESS,
    SMISSION_FLASH,
    SMISSION_PLAY_ANIM,
    SMISSION_TALK_BUBBLE,

    SMISSION_COUNT,

    SMISSION_NONE=-1,
    SMISSION_FIRST = 0
} ScriptMissionType;

typedef enum TaskForceType
{
    TASKFORCE_COUNT,

    TASKFORCE_NONE = -1,

    TASKFORCE_FIRST = 0
} TaskForceType;
DEFINE_ENUMERATION_OPERATORS(TaskForceType);

typedef enum VeterancyRankType
{
    RANK_ELITE,
    RANK_VETERAN,
    RANK_ROOKIE,       // Little experience
    RANK_DUMBASS,

    VETERANCY_NONE = -1,
} VeterancyRankType;
DEFINE_ENUMERATION_OPERATORS(VeterancyRankType);

typedef enum DoType
{
    DO_STAND_READY = 0,
    DO_STAND_GUARD,
    DO_PRONE,
    DO_WALK,
    DO_FIRE_WEAPON,
    DO_LIE_DOWN,
    DO_CRAWL,
    DO_GET_UP,
    DO_FIRE_PRONE,
    DO_IDLE1,
    DO_IDLE2,
    DO_GUN_DEATH,
    DO_EXPLOSION_DEATH,
    DO_EXPLOSION2_DEATH,
    DO_GRENADE_DEATH,
    DO_FIRE_DEATH,
    DO_HOVER,
    DO_FLY,
    DO_TUMBLE,
    DO_FIREFLY,
    DO_STRUGGLE,

    DO_COUNT,

    DO_NOTHING = -1,		// Not performing any choreographed sequence.
    DO_FIRST = 0
} DoType;

typedef enum FearType
{
    FEAR_NONE = 0,			// No fear at all (default state).
    FEAR_ANXIOUS = 10,		// Something makes them scared.
    FEAR_SCARED = 100,		// Scared enough to take cover.
    FEAR_PANIC = 200,		// Run away! Run away!
    FEAR_MAXIMUM = 255		// Scared to death.
} FearType;

typedef enum CloakType
{
    UNCLOAKED,      // Completely visible (normal state).
    CLOAKING,       // In process of cloaking.
    CLOAKED,        // Completely cloaked (invisible).
    UNCLOAKING      // In process of uncloaking.
} CloakType;

typedef enum BuildingType
{
    BUILDING_FIRST = 0,
    BUILDING_NONE = -1
} BuildingType;
DEFINE_ENUMERATION_OPERATORS(BuildingType);

typedef enum SpeedType
{
    SPEED_FOOT,
    SPEED_TRACK,
    SPEED_WHEEL,
    SPEED_HOVER,
    SPEED_WINGED,
    SPEED_FLOAT,
    SPEED_AMPHIBIOUS,
    SPEED_CREEP,

    SPEED_COUNT,

    SPEED_NONE = -1,
    SPEED_FIRST = 0
} SpeedType;

typedef enum PrerequisiteType {} PrerequisiteType;

typedef enum SpecialWeaponType
{
    SPECIAL_MULTI_MISSILE,        // Tactical nuclear weapon.
    SPECIAL_EM_PULSE,
    SPECIAL_FIRESTORM,
    SPECIAL_ION_CANNON,           // Partical beam from satellite (Akira effect).
    SPECIAL_HUNTER_SEEKER,
    SPECIAL_CHEM_MISSILE,
    SPECIAL_DROP_PODS,

    SPECIAL_COUNT,

    SPECIAL_NONE = -1,
    SPECIAL_FIRST = 0
} SpecialWeaponType;
DEFINE_ENUMERATION_OPERATORS(SpecialWeaponType);

typedef enum LayerType
{
    LAYER_UNDERGROUND,
    LAYER_SURFACE,      // Flat on the ground (no sorting or apparent vertical height).
    LAYER_GROUND,       // Touching the ground type object (units & buildings).
    LAYER_AIR,          // Flying above the ground (explosions & flames).
    LAYER_TOP,          // Topmost layer (aircraft & bullets).

    LAYER_COUNT,

    LAYER_NONE = -1,
    LAYER_FIRST = 0
} LayerType;
DEFINE_ENUMERATION_OPERATORS(LayerType);

typedef enum RadioMessageType
{
    RADIO_STATIC,           // "hisssss" -- non-message
    RADIO_ROGER,            // "Roger."
    RADIO_HELLO,            // "Come in. I wish to talk."
    RADIO_OVER_OUT,         // "Something came up, bye."
    RADIO_PICK_UP,          // "Please pick me up."
    RADIO_ATTACH,           // "Attach to transport."
    RADIO_DELIVERY,         // "I've got a delivery for you."
    RADIO_HOLD_STILL,       // "I'm performing load/unload maneuver. Be careful."
    RADIO_UNLOADED,         // "I'm clear."
    RADIO_UNLOAD,           // "You are clear to unload. Please start driving off now."
    RADIO_NEGATIVE,         // "Am unable to comply."
    RADIO_BUILDING,         // "I'm starting construction now... act busy."
    RADIO_COMPLETE,         // "I've finished construction. You are free."
    RADIO_REDRAW,           // "Oops, sorry. I might have bumped you a little."
    RADIO_DOCKING,          // "I'm trying to load up now."
    RADIO_CAN_LOAD,         // "May I become a passenger?"
    RADIO_ARE_REFINERY,     // "Are you a refinery ready to take shipment?"
    RADIO_TRYING_TO_LOAD,   // "Are you trying to become a passenger?"
    RADIO_MOVE_HERE,        // "Move to location X."
    RADIO_NEED_TO_MOVE,     // "Do you need to move somewhere?"
    RADIO_YEA_NOW_WHAT,     // "All right already. Now what?"
    RADIO_IM_IN,            // "I'm a passenger now."
    RADIO_BACKUP_NOW,       // "Begin backup into refinery now."
    RADIO_RUN_AWAY,         // "Run away! Run away!"
    RADIO_TETHER,           // "Establish tether contact."
    RADIO_UNTETHER,         // "Break tether contact."
    RADIO_REPAIR,           // "Repair one step."
    RADIO_PREPARED,         // "Are you prepared to fight?"
    RADIO_ATTACK_THIS,      // "Attack this target please."
    RADIO_RELOAD,           // "Reload one step please."
    RADIO_CANT,             // "Circumstances prevent success."
    RADIO_ALL_DONE,         // "I have completed the task."
    RADIO_NEED_REPAIR,      // "Are you in need of service depot work?"
    RADIO_ON_DEPOT,         // "Are you sitting on a service depot?"
    RADIO_WANT_RIDE,        // "Gimme a ride!"

    RADIO_COUNT
} RadioMessageType;
DEFINE_ENUMERATION_OPERATORS(RadioMessageType);

typedef enum PCPType
{
    PCP_ROTATION,   // When sitting in place and performing rotations.
    PCP_DURING,     // While moving between two cells.
    PCP_END,        // When the 'center' of a cell is reached during movement.
} PCPType;
DEFINE_ENUMERATION_OPERATORS(PCPType);

typedef enum ExitType
{
    EXIT_FAILED,
    EXIT_TRY_AGAIN,
    EXIT_NORMAL,
} ExitType;

typedef enum MarkType
{
    MARK_UP,              // Removed from the map.
    MARK_DOWN,            // Placed on the map.
    MARK_CHANGE,          // Altered in place on the map.
    MARK_CHANGE_REDRAW,   // Redraw because of animation change.
    MARK_OVERLAP_DOWN,    // Mark overlap cells on the map
    MARK_OVERLAP_UP       // Clear overlap cells on the map
} MarkType;

typedef enum ResultType
{
    RESULT_NONE,          // No damage was taken by the target.
    RESULT_LIGHT,         // Some damage was taken, but no state change occurred.
    RESULT_HALF,          // Damaged to below half strength (only returned on transition).
    RESULT_MAJOR,         // Damaged down to 1 hit point.
    RESULT_DESTROYED      // Damaged to complete destruction.
} ResultType;

typedef enum ActionType
{
    ACTION_NONE,            // Either undefined action or "do nothing".
    ACTION_MOVE,            // Can move there or at least try to.
    ACTION_NOMOVE,          // Special case for movable object, but illegal mouse position.
    ACTION_ENTER,           // Special case for infantry->APC or vehicle->Repair facility.
    ACTION_SELF,            // Self select special case.
    ACTION_ATTACK,          // Can attack or fire upon it in some fashion.
    ACTION_HARVEST,         // Special harvest mode.
    ACTION_SELECT,          // Would change selection to specified object.
    ACTION_TOGGLE_SELECT,   // Toggles select state of the object.
    ACTION_CAPTURE,         // The unit will try to capture the object.
    ACTION_REPAIR,          // The target object should be repaired.
    ACTION_SELL,            // The target building should be sold back.
    ACTION_SELL_UNIT,       // The target unit should be sold back.
    ACTION_NO_SELL,         // No sell or no repair.
    ACTION_NO_REPAIR,       // No sell or no repair.
    ACTION_SABOTAGE,        // The unit will try to sabotage/destroy the object.
    ACTION_TOTE,
    ACTION_PARA_BOMB,       // Parachute bomb strike.
    ACTION_PARA_SABOTEUR,   // Parachute saboteur strike.
    ACTION_NUKE_BOMB,       // That target object should be blasted.
    ACTION_AIR_STRIKE,      // That target object should be blasted.
    ACTION_CHRONOSPHERE,    // That target object should be teleported.
    ACTION_CHRONO2,         // Teleport it to the given coordinates now.
    ACTION_IRON_CURTAIN,    // That target object should be invulnerable.
    ACTION_SPY_MISSION,     // Photo recon mission.
    ACTION_GUARD_AREA,      // Guard the area/object clicked on.
    ACTION_HEAL,            // Heal the infantryman clicked on.
    ACTION_DAMAGE,          // Enter and damage building.
    ACTION_GREPAIR,         // Enter and complete repair building.
    ACTION_NO_DEPLOY,
    ACTION_NO_ENTER,
    ACTION_NO_GREPAIR,
    ACTION_TOGGLE_POWER,
    ACTION_NO_TOGGLE_POWER,
    ACTION_ENTER_TUNNEL,
    ACTION_NO_ENTER_TUNNEL,
    ACTION_EMPULSE,
    ACTION_ION_CANNON,
    ACTION_EMPULSE_RANGE,
    ACTION_CHEM_BOMB,
    ACTION_PLACE_WAYPOINT,
    ACTION_NO_PLACE_WAYPOINT,
    ACTION_ENTER_WAYPOINT_MODE,
    ACTION_FOLLOW_WAYPOINT,
    ACTION_SELECT_WAYPOINT,
    ACTION_LOOP_WAYPOINT_PATH,
    ACTION_DRAG_WAYPOINT,
    ACTION_ATTACK_WAYPOINT,
    ACTION_ENTER_WAYPOINT,
    ACTION_PATROL_WAYPOINT,
    ACTION_DROP_POD,
    ACTION_RALLY_TO_POINT,
    ACTION_ATTACK_SUPPORT,

    ACTION_COUNT,

    ACTION_FIRST = 0
} ActionType;

typedef enum VoxType
{
    VOX_ACCOMPLISHED,           // mission accomplished
    VOX_FAIL,                   // your mission has failed
    VOX_NO_FACTORY,             // unable to comply, building in progress
    VOX_CONSTRUCTION,           // construction complete
    VOX_UNIT_READY,             // unit ready
    VOX_NEW_CONSTRUCT,          // new construction options
    VOX_DEPLOY,                 // cannot deploy here
    VOX_STRUCTURE_DESTROYED,    // structure destroyed
//    VOX_INSUFFICIENT_POWER,     // insufficient power
    VOX_NO_CASH,                // insufficient funds
    VOX_CONTROL_EXIT,           // battle control terminated
    VOX_REINFORCEMENTS,         // reinforcements have arrived
    VOX_CANCELED,               // canceled
    VOX_BUILDING,               // building
    VOX_LOW_POWER,              // low power
//    VOX_NEED_MO_MONEY,          // need more funds
    VOX_BASE_UNDER_ATTACK,      // our base is under attack
//    VOX_UNABLE_TO_BUILD,        // unable to build more
    VOX_PRIMARY_SELECTED,       // primary building selected
    VOX_UNIT_LOST,              // unit lost
    VOX_SELECT_TARGET,          // select target
//    VOX_PREPARE,                // enemy approaching
    VOX_NEED_MO_CAPACITY,       // silos needed
    VOX_SUSPENDED,              // on hold
    VOX_REPAIRING,              // repairing
    VOX_TRAINING,               // training
    VOX_UPGRADE_ARMOR,
    VOX_UPGRADE_FIREPOWER,
    VOX_UPGRADE_SPEED,
//    VOX_UNIT_FULL,
    VOX_UNIT_REPAIRED,
    VOX_STRUCTURE_SOLD,
    VOX_HARVESTER_UNDER_ATTACK,
    VOX_CLOAKED_DETECTED,       // cloaked unit detected
    VOX_SUBTERRANEAN_DETECTED,  // subterranean unit detected
    VOX_TIME_20,                // twenty minutes remaining 
    VOX_TIME_10,
    VOX_TIME_5,
    VOX_TIME_4,
    VOX_TIME_3,
    VOX_TIME_2,
    VOX_TIME_1,                 // one minute remaining
    VOX_UNIT_SOLD,
    VOX_BUILDING_CAPTURED,
    VOX_CONTROL_ESTABLISHED,    // establishing battlefield control, standby 
    VOX_00_I176,
    VOX_00_I178,
    VOX_00_I198,
    VOX_00_I150,
    VOX_00_I152,
    VOX_00_I154,
    VOX_00_I156,
    VOX_00_I158,
    VOX_00_I162,
    VOX_00_I170,
    VOX_00_I100,
    VOX_00_I102,
    VOX_00_I104,
    VOX_00_I106,
    VOX_00_I194,
    VOX_00_I196,
    VOX_00_I208,
    VOX_00_I210,
    VOX_BUILDING_INFILTRATED,
    VOX_TIME_START,
    VOX_TIME_STOP,
    VOX_00_I118,
    VOX_00_I180,
    VOX_BUILDING_OFFLINE,
    VOX_BUILDING_ONLINE,
    VOX_00_I252,
    VOX_00_I268,
    VOX_00_I284,
    VOX_00_I286,
    VOX_00_I288,
    VOX_00_I290,
    VOX_ALLIANCE_FORMED,
    VOX_ALLIANCE_BROKEN,
    VOX_ALLY_ATTACK,            // our ally is under attack
    VOX_00_I310,
    VOX_00_I312,
    VOX_00_I314,
    VOX_00_I316,
    VOX_00_I318,
    VOX_00_I344,
    VOX_00_I346,
    VOX_00_I348,
    VOX_00_I352,
    VOX_00_I356,
    VOX_00_I360,
    VOX_00_I370,
    VOX_00_I372,
    VOX_00_I374,
    VOX_00_I376,
    VOX_01_I342,
    VOX_01_I350,
    VOX_01_I352,
    VOX_01_I356,
    VOX_01_I360,
    VOX_01_I362,
    VOX_01_I364,
    VOX_01_I366,
    VOX_01_I368,
    VOX_01_I378,
    VOX_33_N000,
    VOX_33_N002,
    VOX_33_N004,
    VOX_33_N008,
    VOX_33_N010,
    VOX_33_N012,
    VOX_33_N014,
    VOX_33_N020,
    VOX_33_N022,
    VOX_33_N024,
    VOX_35_N000,
    VOX_35_N002,
    VOX_35_N004,
    VOX_35_N008,
    VOX_35_N010,
    VOX_35_N012,
    VOX_35_N014,
    VOX_40_N000_1,
    VOX_00_N000,
    VOX_00_N002,
    VOX_00_N004,
    VOX_00_N006,
    VOX_00_N018,
    VOX_00_N020,
    VOX_00_N022,
    VOX_00_N024,
    VOX_00_N032,
    VOX_00_N034,
    VOX_00_N040,
    VOX_00_N042,
    VOX_00_N044,
    VOX_00_N052,
    VOX_00_N054,
    VOX_00_N055,
    VOX_00_N056,
    VOX_00_N058,
    VOX_00_N059,
    VOX_01_N320,
    VOX_01_N322,
    VOX_01_N324,
    VOX_01_N326,
    VOX_00_N068,
    VOX_00_N070,
    VOX_00_N072,
    VOX_00_N074,
    VOX_00_N075,
    VOX_01_N900,
    VOX_01_N901,
    VOX_00_N084,
    VOX_00_N086,
    VOX_00_N088,
    VOX_00_N090,
    VOX_00_N092,
    VOX_00_N094,
    VOX_00_N096,
    VOX_00_N098,
    VOX_01_N328,
    VOX_01_N330,
    VOX_00_N112,
    VOX_00_N114,
    VOX_00_N128,
    VOX_00_N130,
    VOX_00_N132,
    VOX_00_N134,
    VOX_00_N136,
    VOX_00_N138,
    VOX_00_N140,
    VOX_00_N142,
    VOX_00_N156,
    VOX_00_N158,
    VOX_00_N160,
    VOX_00_N162,
    VOX_00_N166,
    VOX_00_N168,
    VOX_00_N180,
    VOX_00_N182,
    VOX_00_N188,
    VOX_00_N190,
    VOX_00_N192,
    VOX_00_N206,
    VOX_00_N208,
    VOX_00_N210,
    VOX_00_N224,
    VOX_00_N226,
    VOX_00_N228,
    VOX_00_N236,
    VOX_00_N238,
    VOX_00_N240,
    VOX_00_N239,
    VOX_00_N241,
    VOX_00_N243,
    VOX_00_N245,
    VOX_00_N247,
    VOX_00_N248,
    VOX_00_N249,
    VOX_00_N250,
    VOX_00_N251,
    VOX_00_N252,
    VOX_00_N254,
    VOX_00_N255,
    VOX_38_N000,
    VOX_38_N002,
    VOX_38_N006,
    VOX_40_N000,
    VOX_41_N000,
    VOX_41_N002,
    VOX_41_N004,
    VOX_41_N006,
    VOX_43_N000,
    VOX_01_N000,
    VOX_01_N002,
    VOX_01_N004,
    VOX_01_N006,
    VOX_01_N008,
    VOX_01_N010,
    VOX_01_N005,
    VOX_01_N007,
    VOX_01_N009,
    VOX_01_N011,
    VOX_01_N020,
    VOX_01_N022,
    VOX_01_N024,
    VOX_01_N026,
    VOX_01_N027,
    VOX_01_N032,
    VOX_01_N034,
    VOX_01_N036,
    VOX_01_N038,
    VOX_01_N040,
    VOX_01_N054,
    VOX_01_N055,
    VOX_01_N064,
    VOX_01_N066,
    VOX_01_N068,
    VOX_01_N070,
    VOX_01_N072,
    VOX_01_N074,
    VOX_01_N076,
    VOX_01_N086,
    VOX_01_N088,
    VOX_01_N090,
    VOX_01_N100,
    VOX_01_N102,
    VOX_01_N114,
    VOX_01_N116,
    VOX_01_N128,
    VOX_01_N130,
    VOX_01_N132,
    VOX_01_N134,
    VOX_01_N136,
    VOX_01_N144,
    VOX_01_N156,
    VOX_01_N158,
    VOX_01_N160,
    VOX_01_N162,
    VOX_01_N164,
    VOX_01_N174,
    VOX_01_N176,
    VOX_01_N178,
    VOX_01_N180,
    VOX_01_N192,
    VOX_01_N194,
    VOX_01_N196,
    VOX_01_N208,
    VOX_01_N210,
    VOX_01_N212,
    VOX_01_N228,
    VOX_01_N230,
    VOX_01_N232,
    VOX_01_N233,
    VOX_01_N227,
    VOX_01_N229,
    VOX_01_N231,
    VOX_01_N234,
    VOX_01_N256,
    VOX_01_N258,
    VOX_01_N260,
    VOX_01_N262,
    VOX_01_N264,
    VOX_01_N266,
    VOX_01_N268,
    VOX_01_N270,
    VOX_01_N284,
    VOX_01_N286,
    VOX_10_N032,
    VOX_10_N034,
    VOX_10_N036,
    VOX_10_N038,
    VOX_10_N040,
    VOX_10_N042,
    VOX_10_N044,
    VOX_10_N046,
    VOX_44_N000,
    VOX_36_N000,
    VOX_36_N002,
    VOX_36_N004,
    VOX_36_N008,
    VOX_37_N000,
    VOX_37_N002,
    VOX_38_N004,
    VOX_38_N008,
    VOX_38_N010,
    VOX_38_N012,
    VOX_38_N014,
    VOX_38_N016,
    VOX_38_N018,
    VOX_38_N020,
    VOX_38_N022,
    VOX_38_N024,
    VOX_38_N026,
    VOX_38_N028,
    VOX_39_N000,
    VOX_47_N000,
    VOX_00_I020,

    /**
     *  Firestorm additions.
     */
    VOX_00_I500,
    VOX_00_I502,
    VOX_00_I504,
    VOX_00_N400,
    VOX_00_N402,
    VOX_00_N404,
    VOX_00_N406,
    VOX_00_N408,
    VOX_00_N410,
    VOX_00_N412,
    VOX_00_N414,
    VOX_00_N416,
    VOX_00_N418,
    VOX_00_N420,
    VOX_00_N422,
    VOX_00_N424,
    VOX_00_N426,
    VOX_00_N428,
    VOX_00_N430,
    VOX_00_N432,
    VOX_00_N434,
    VOX_00_N436,
    VOX_00_N438,
    VOX_00_N440,
    VOX_00_N442,
    VOX_00_N444,
    VOX_00_N446,
    VOX_00_N448,
    VOX_00_N450,
    VOX_00_N452,
    VOX_00_N454,
    VOX_00_N456,
    VOX_00_N458,
    VOX_00_N460,
    VOX_00_N462,
    VOX_00_N464,
    VOX_00_N466,
    VOX_00_N468,
    VOX_00_N470,
    VOX_00_N472,
    VOX_00_N474,
    VOX_00_N478,
    VOX_00_N479,
    VOX_00_N480,
    VOX_00_N482,
    VOX_00_N484,
    VOX_00_N486,
    VOX_00_N488,
    VOX_00_N490,
    VOX_00_N492,
    VOX_00_N494,
    VOX_00_N496,
    VOX_00_N498,
    VOX_00_N500,
    VOX_00_N502,
    VOX_00_N504,
    VOX_00_N506,
    VOX_00_N508,
    VOX_00_N510,
    VOX_01_N400,
    VOX_01_N402,
    VOX_01_N404,
    VOX_01_N406,
    VOX_01_N408,
    VOX_01_N410,
    VOX_01_N412,
    VOX_01_N414,
    VOX_01_N416,
    VOX_01_N418,
    VOX_01_N420,
    VOX_01_N422,
    VOX_01_N424,
    VOX_01_N426,
    VOX_01_N428,
    VOX_01_N430,
    VOX_01_N432,
    VOX_01_N434,
    VOX_01_N436,
    VOX_01_N438,
    VOX_01_N440,
    VOX_01_N442,
    VOX_01_N444,
    VOX_01_N446,
    VOX_01_N448,
    VOX_01_N450,
    VOX_01_N452,
    VOX_99_N454,
    VOX_99_N456,
    VOX_99_N458,
    VOX_99_N460,
    VOX_01_N462,
    VOX_99_N464,
    VOX_99_N466,
    VOX_01_N468,
    VOX_01_N470,
    VOX_01_N472,
    VOX_01_N474,
    VOX_01_N476,
    VOX_01_N478,
    VOX_19_N100,
    VOX_19_N102,
    VOX_38_N100,
    VOX_38_N102,
    VOX_38_N104,
    VOX_38_N106,
    VOX_38_N108,
    VOX_38_N110,
    VOX_38_N112,
    VOX_38_N114,
    VOX_38_N116,
    VOX_38_N118,
    VOX_38_N120,
    VOX_38_N122,
    VOX_38_N124,
    VOX_38_N126,
    VOX_38_N128,
    VOX_38_N130,
    VOX_38_N132,
    VOX_38_N134,
    VOX_38_N136,
    VOX_38_N138,
    VOX_38_N140,
    VOX_38_N142,
    VOX_38_N144,
    VOX_38_N146,
    VOX_38_N148,
    VOX_38_N150,
    VOX_38_N152,
    VOX_38_N154,
    VOX_38_N156,
    VOX_52_N000,
    VOX_52_N002,
    VOX_52_N004,
    VOX_54_N000,
    VOX_54_N002,
    VOX_54_N004,
    VOX_54_N006,
    VOX_54_N008,
    VOX_54_N010,
    VOX_54_N012,
    VOX_54_N014,
    VOX_54_N016,
    VOX_54_N018,
    VOX_54_N020,
    VOX_55_N000,
    VOX_55_N002,
    VOX_55_N004,
    VOX_55_N006,
    VOX_55_N008,
    VOX_55_N010,
    VOX_55_N012,
    VOX_55_N014,
    VOX_55_N016,
    VOX_55_N018,
    VOX_55_N020,
    VOX_55_N022,
    VOX_55_N024,
    VOX_55_N026,
    VOX_55_N028,
    VOX_55_N030,
    VOX_55_N032,
    VOX_55_N034,
    VOX_55_N036,
    VOX_55_N038,
    VOX_55_N040,
    VOX_55_N042,
    VOX_55_N044,
    VOX_56_N000,
    VOX_56_N002,
    VOX_56_N004,
    VOX_56_N006,
    VOX_56_N008,
    VOX_56_N010,
    VOX_56_N012,
    VOX_56_N014,
    VOX_56_N016,
    VOX_56_N018,
    VOX_56_N020,
    VOX_57_N100,
    VOX_57_N102,
    VOX_57_N104,
    VOX_57_N106,
    VOX_57_N108,
    VOX_57_N110,
    VOX_57_N112,
    VOX_57_N114,
    VOX_57_N116,
    VOX_57_N118,
    VOX_57_N120,
    VOX_57_N122,
    VOX_57_N124,
    VOX_58_N100,
    VOX_58_N102,
    VOX_58_N104,
    VOX_58_N106,
    VOX_58_N108,
    VOX_58_N110,
    VOX_58_N112,
    VOX_58_N114,
    VOX_58_N116,
    VOX_58_N118,
    VOX_58_N120,
    VOX_58_N122,
    VOX_58_N124,
    VOX_58_N126,
    VOX_58_N128,
    VOX_58_N130,
    VOX_58_N132,
    VOX_58_N134,
    VOX_58_N136,
    VOX_58_N138,
    VOX_58_N140,
    VOX_58_N142,
    VOX_59_N100,
    VOX_59_N102,
    VOX_59_N104,
    VOX_61_N000,
    VOX_61_N002,
    VOX_61_N004,
    VOX_61_N006,
    VOX_61_N008,
    VOX_61_N010,
    VOX_61_N012,
    VOX_22_N100,
    VOX_22_N102,
    VOX_22_N104,
    VOX_22_N106,
    VOX_22_N108,
    VOX_22_N110,
    VOX_22_N112,
    VOX_22_N114,
    VOX_22_N116,
    VOX_22_N118,
    VOX_22_N120,
    VOX_71_N000,
    VOX_71_N100,
    VOX_71_N102,
    VOX_71_N104,
    VOX_71_N106,
    VOX_71_N108,
    VOX_71_N110,
    VOX_71_N112,
    VOX_71_N114,
    VOX_71_N116,
    VOX_71_N118,
    VOX_71_N120,
    VOX_71_N122,
    VOX_71_N124,
    VOX_71_N126,
    VOX_71_N128,
    VOX_71_N130,
    VOX_71_N132,
    VOX_71_N134,
    VOX_71_N136,
    VOX_DROP_PODS_READY,         // drop pods available
    VOX_62_N000,
    VOX_62_N002,
    VOX_62_N004,
    VOX_62_N006,
    VOX_62_N008,
    VOX_62_N010,
    VOX_62_N012,

    VOX_COUNT,

    VOX_NONE = -1,
    VOX_FIRST = 0,
} VoxType;
DEFINE_ENUMERATION_OPERATORS(VoxType);

typedef enum LandType
{
    LAND_CLEAR,         // "Clear" terrain.
    LAND_ROAD,          // Road terrain.
    LAND_WATER,         // Water.
    LAND_ROCK,          // Impassable rock.
    LAND_WALL,          // Wall (blocks movement).
    LAND_TIBERIUM,      // Tiberium field.
    LAND_BEACH,         // Beach terrain.
    LAND_ROUGH,         // Rocky terrain.
    LAND_ICE,    // LAND_RIVER
    LAND_RAILROAD,
    LAND_TUNNEL,
    LAND_WEEDS,

    LAND_COUNT,

    LAND_NONE = -1,
    LAND_FIRST = 0
} LandType;
DEFINE_ENUMERATION_OPERATORS(LandType);

typedef enum CheckPointType
{
    CHECK_STACK,            // Holding area far away from airfield.
    CHECK_DOWNWIND,         // Downwind leg of approach.
    CHECK_CROSSWIND         // Crosswind leg of approach.
} CheckPointType;

typedef enum StateType
{
    STATE_BUILDUP,          // Base is building up (defensive buildup stage).
    STATE_BROKE,            // Low on money, need cash or income source.
    STATE_THREATENED,       // Enemy units are designated to move close by.
    STATE_ATTACKED,         // Base is under direct attack.
    STATE_ENDGAME           // Resistance is futile.
} StateType;
DEFINE_ENUMERATION_OPERATORS(StateType);

typedef enum UrgencyType
{
    URGENCY_NONE,           // No action on this matter is needed or desired.
    URGENCY_LOW,            // Minimal attention requested.
    URGENCY_MEDIUM,         // Normal attention requested.
    URGENCY_HIGH,           // High attention requested.
    URGENCY_CRITICAL,       // This matter must be addressed immediately.

    URGENCY_COUNT,
    URGENCY_FIRST = 0
} UrgencyType;
DEFINE_ENUMERATION_OPERATORS(UrgencyType);

typedef enum StrategyType
{
    STRATEGY_FIRE_SALE,         // Situation hopeless, sell and attack.
    STRATEGY_RAISE_MONEY,       // Money is low, emergency raise cash.

    STRATEGY_COUNT,
    STRATEGY_FIRST = 0
} StrategyType;
DEFINE_ENUMERATION_OPERATORS(StrategyType);

typedef enum QuarryType
{
    QUARRY_NONE,

    QUARRY_ANYTHING,    // Attack any enemy (same as "hunt").
    QUARRY_BUILDINGS,   // Attack buildings (in general).
    QUARRY_HARVESTERS,  // Attack harvesters or refineries.
    QUARRY_INFANTRY,    // Attack infantry.
    QUARRY_VEHICLES,    // Attack combat vehicles.
    QUARRY_FACTORIES,   // Attack factories (all types).
    QUARRY_DEFENSE,     // Attack base defense buildings.
    QUARRY_THREAT,      // Attack enemies near friendly base.
    QUARRY_POWER,       // Attack power facilities.

    QUARRY_COUNT,
    QUARRY_FIRST = 0
} QuarryType;

typedef enum FireErrorType
{
    FIRE_OK,            // Weapon is allowed to fire.
    FIRE_AMMO,          // No ammo available to fire?
    FIRE_FACING,        // Not correctly facing target?
    FIRE_REARM,         // It is busy rearming?
    FIRE_ROTATING,      // Is it in process of rotating?
    FIRE_ILLEGAL,       // Is it targeting something illegal?
    FIRE_CANT,          // Is this unit one that cannot fire anything?
    FIRE_MOVING,        // Is it moving and not allowed to fire while moving?
    FIRE_RANGE,         // Is the target out of range?
    FIRE_CLOAKED,       // Is the shooter currently cloaked?
    FIRE_BUSY,          // Is shooter currently doing something else?
    FIRE_MUST_DEPLOY,   // Must it deploy first before firing?

    FIRE_COUNT,

    FIRE_NONE = -1,
    FIRE_FIRST = 0
} FireErrorType;

typedef enum ZGradientType
{
    ZGRAD_GROUND,
    ZGRAD_45DEG,
    ZGRAD_90DEG,
    ZGRAD_135DEG,

    ZGRAD_COUNT,

    ZGRAD_NONE = -1,
    ZGRAD_FIRST = 0
} ZGradientType;

typedef enum VisualType
{
    VISUAL_NORMAL,         // Completely visible -- normal.
    VISUAL_INDISTINCT,     // The edges shimmer and become indistinct.
    VISUAL_DARKEN,         // Color and texture is muted along with shimmering.
    VISUAL_SHADOWY,        // Body is translucent in addition to shimmering.
    VISUAL_RIPPLE,         // Just a ripple (true predator effect).
    VISUAL_HIDDEN,         // Nothing at all is visible.

    VISUAL_COUNT,

    VISUAL_NONE = -1,
    VISUAL_FIRST = 0
} VisualType;

typedef enum MoveType
{
    MOVE_OK,                    // No blockage.
    MOVE_CLOAK,                 // A cloaked blocking enemy object.
    MOVE_MOVING_BLOCK,          // Blocked, but only temporarily.
    MOVE_CLOSED_GATE,
    MOVE_FRIENDLY_DESTROYABLE,
    MOVE_DESTROYABLE,           // Enemy unit or building is blocking.
    MOVE_TEMP,                  // Blocked by friendly unit.
    MOVE_NO,                    // Strictly prohibited terrain.

    MOVE_COUNT
} MoveType;

typedef enum ArmorType
{
    ARMOR_NONE,
    ARMOR_WOOD,
    ARMOR_ALUMINUM,
    ARMOR_STEEL,
    ARMOR_CONCRETE,

    ARMOR_COUNT,

    ARMOR_FIRST = 0
} ArmorType;

typedef enum MissionType
{
    MISSION_SLEEP,          // Do nothing whatsoever.
    MISSION_ATTACK,         // Attack nearest enemy.
    MISSION_MOVE,           // Guard location or unit.
    MISSION_QMOVE,          // A queue list movement mission.
    MISSION_RETREAT,        // Return home for R & R.
    MISSION_GUARD,          // Stay still.
    MISSION_STICKY,         // Stay still -- never recruit.
    MISSION_ENTER,          // Move into object cooperatively.
    MISSION_CAPTURE,        // Move into in order to capture.
    MISSION_HARVEST,        // Hunt for and collect nearby Tiberium.
    MISSION_GUARD_AREA,     // Active guard of area.
    MISSION_RETURN,         // Head back to refinery.
    MISSION_STOP,           // Sit still.
    MISSION_AMBUSH,         // Wait until discovered.
    MISSION_HUNT,           // Active search and destroy.
    MISSION_UNLOAD,         // Search for and deliver cargo.
    MISSION_SABOTAGE,       // Move into in order to destroy.
    MISSION_CONSTRUCTION,   // Building buildup operation.
    MISSION_DECONSTRUCTION, // Building builddown operation.
    MISSION_REPAIR,         // Repair process mission.
    MISSION_RESCUE,
    MISSION_MISSILE,
    MISSION_HARMLESS,       // Sit around and don't appear like a threat.
    MISSION_OPEN,
    MISSION_PATROL,

    MISSION_COUNT,

    MISSION_NONE = -1,
    MISSION_FIRST = 0
} MissionType;
DEFINE_ENUMERATION_OPERATORS(MissionType);

typedef enum WeaponSlotType
{
    WEAPON_SLOT_PRIMARY,
    WEAPON_SLOT_SECONDARY,
    WEAPON_SLOT_ELITE,

    WEAPON_SLOT_COUNT,

    WEAPON_SLOT_NONE = -1,
    WEAPON_SLOT_FIRST = 0,
} WeaponSlotType;

enum TiberiumType
{
    TIBERIUM_RIPARIUS,
    TIBERIUM_CRUENTUS,
    TIBERIUM_VINIFERA,
    TIBERIUM_ABOREUS,

    TIBERIUM_COUNT,

    TIBERIUM_NONE = -1,
    TIBERIUM_FIRST = 0
};
DEFINE_ENUMERATION_OPERATORS(TiberiumType);

typedef enum ColorSchemeType
{
    COLORSCHEME_NONE = 0
} ColorSchemeType;
DEFINE_ENUMERATION_OPERATORS(ColorSchemeType);


typedef enum RTTIType
{
    RTTI_NONE = 0,

    RTTI_UNIT,
    RTTI_AIRCRAFT,
    RTTI_AIRCRAFTTYPE,
    RTTI_ANIM,
    RTTI_ANIMTYPE,
    RTTI_BUILDING,
    RTTI_BUILDINGTYPE,
    RTTI_BULLET,
    RTTI_BULLETTYPE,
    RTTI_CAMPAIGN,
    RTTI_CELL,
    RTTI_FACTORY,
    RTTI_HOUSE,
    RTTI_HOUSETYPE,
    RTTI_INFANTRY,
    RTTI_INFANTRYTYPE,
    RTTI_ISOTILE,
    RTTI_ISOTILETYPE,
    RTTI_LIGHT,
    RTTI_OVERLAY,
    RTTI_OVERLAYTYPE,
    RTTI_PARTICLE,
    RTTI_PARTICLETYPE,
    RTTI_PARTICLESYSTEM,
    RTTI_PARTICLESYSTEMTYPE,
    RTTI_SCRIPT,
    RTTI_SCRIPTTYPE,
    RTTI_SIDE,
    RTTI_SMUDGE,
    RTTI_SMUDGETYPE,
    RTTI_SPECIAL,
    RTTI_SUPERWEAPONTYPE,
    RTTI_TASKFORCE,
    RTTI_TEAM,
    RTTI_TEAMTYPE,
    RTTI_TERRAIN,
    RTTI_TERRAINTYPE,
    RTTI_TRIGGER,
    RTTI_TRIGGERTYPE,
    RTTI_UNITTYPE,
    RTTI_VOXELANIM,
    RTTI_VOXELANIMTYPE,
    RTTI_WAVE,
    RTTI_TAG,
    RTTI_TAGTYPE,
    RTTI_TIBERIUM,
    RTTI_ACTION,
    RTTI_EVENT,
    RTTI_WEAPONTYPE,
    RTTI_WARHEADTYPE,
    RTTI_WAYPOINT,
    RTTI_ABSTRACT,
    RTTI_TUBE,
    RTTI_LIGHTSOURCE,
    RTTI_EMPULSE,
    RTTI_TACTICALMAP,
    RTTI_SUPERWEAPON,
    RTTI_AITRIGGER,
    RTTI_AITRIGGERTYPE,
    RTTI_NEURON,
    RTTI_FOGGEDOBJECT,
    RTTI_ALPHASHAPE,
    RTTI_VEINHOLEMONSTER,

    RTTI_COUNT,

    RTTI_FIRST = 0,
};
DEFINE_ENUMERATION_OPERATORS(RTTIType);


typedef enum ThreatType
{
    THREAT_NORMAL = 0x0000,         // Any distance threat scan?
    THREAT_RANGE = 0x0001,          // Limit scan to weapon range?
    THREAT_AREA = 0x0002,           // Limit scan to general area (twice weapon range)?
    THREAT_AIR = 0x0004,            // Scan for air units?
    THREAT_INFANTRY = 0x0008,       // Scan for infantry units?
    THREAT_VEHICLES = 0x0010,       // Scan for vehicles?
    THREAT_BUILDINGS = 0x0020,      // Scan for buildings?
    THREAT_TIBERIUM = 0x0040,       // Limit scan to Tiberium processing objects?
    THREAT_BOATS = 0x0080,          // Scan for gunboats?
    THREAT_CIVILIANS = 0x0100,      // Consider civilians to be primary target?
    THREAT_CAPTURE = 0x0200,        // Consider capturable buildings only?
    THREAT_FAKES = 0x0400,          // Consider fake buildings a greater target?
    THREAT_POWER = 0x0800,          // Consider power generating facilities a greater target?
    THREAT_FACTORIES = 0x1000,      // Consider factories a greater target?
    THREAT_BASE_DEFENSE = 0x2000,   // Consider base defense buildings a greater target?
    THREAT_4000 = 0x4000,
    THREAT_8000 = 0x8000,
} ThreatType;
DEFINE_ENUMERATION_OPERATORS(ThreatType);
DEFINE_ENUMERATION_BITWISE_OPERATORS(ThreatType);

typedef enum TheaterType
{
    THEATER_TEMPERATE,
    THEATER_SNOW,

    THEATER_COUNT,

    THEATER_NONE = -1,
    THEATER_FIRST = 0
} TheaterType;
DEFINE_ENUMERATION_OPERATORS(TheaterType);

#define THEATERF_TEMPERATE   (1 << THEATER_TEMPERATE)
#define THEATERF_SNOW        (1 << THEATER_SNOW)

typedef struct {
    char Name[16];
    char Root[10];
    char Suffix[4];
} TheaterDataType;


typedef enum EventType : unsigned char // We need this so the enum only takes up one byte.
{
    EMPTY,

    // Public events.
    POWERON,
    POWEROFF,
    ALLY,
    MEGAMISSION,
    MEGAMISSION_F,
    IDLE,
    SCATTER,
    DESTRUCT,
    DEPLOY,
    PLACE,
    OPTIONS,
    GAMESPEED,
    PRODUCE,
    SUSPEND,
    ABANDON,
    PRIMARY,
    SPECIAL_PLACE,
    EXIT,
    ANIMATION,
    REPAIR,
    SELL,
    SELLCELL,
    SPECIAL,

    // Private events.
    FRAMESYNC,
    MESSAGE,
    RESPONSE_TIME,
    FRAMEINFO,
    SAVEGAME,
    ARCHIVE,
    ADDPLAYER,
    TIMING,
    PROCESS_TIME,
    PAGEUSER,
    REMOVEPLAYER,
    LATENCYFUDGE,

    LAST_EVENT,
} EventType;

typedef enum MouseType
{
    MOUSE_NORMAL,
    MOUSE_N,
    MOUSE_NE,
    MOUSE_E,
    MOUSE_SE,
    MOUSE_S,
    MOUSE_SW,
    MOUSE_W,
    MOUSE_NW,
    MOUSE_NO_N,
    MOUSE_NO_NE,
    MOUSE_NO_E,
    MOUSE_NO_SE,
    MOUSE_NO_S,
    MOUSE_NO_SW,
    MOUSE_NO_W,
    MOUSE_NO_NW,
    MOUSE_CAN_SELECT,
    MOUSE_CAN_MOVE,
    MOUSE_NO_MOVE,
    MOUSE_STAY_ATTACK,
    MOUSE_CAN_ATTACK,
    MOUSE_AREA_GUARD,
    MOUSE_TOTE,
    MOUSE_NO_TOTE,
    MOUSE_ENTER,
    MOUSE_NO_ENTER,
    MOUSE_DEPLOY,
    MOUSE_NO_DEPLOY,
    MOUSE_UNDEPLOY,
    MOUSE_SELL_BACK,
    MOUSE_SELL_UNIT,
    MOUSE_NO_SELL_BACK,
    MOUSE_GREPAIR,          // Engineer entering friendly building to heal it.
    MOUSE_REPAIR,
    MOUSE_NO_REPAIR,
    MOUSE_WAYPOINT,
    MOUSE_PLACE_WAYPOINT,
    MOUSE_NO_PLACE_WAYPOINT,
    MOUSE_SELECT_WAYPOINT,
    MOUSE_ENTER_WAYPOINT_MODE,
    MOUSE_FOLLOW_WAYPOINT,
    MOUSE_WAYPOINT_TOTE,
    MOUSE_WAYPOINT_REPAIR,
    MOUSE_ATTACK_WAYPOINT,
    MOUSE_ENTER_WAYPOINT,
    MOUSE_LOOP_WAYPOINT_PATH,
    MOUSE_AIR_STRIKE,
    MOUSE_CHEMBOMB,
    MOUSE_DEMOLITIONS,
    MOUSE_NUCLEAR_BOMB,
    MOUSE_TOGGLE_POWER,
    MOUSE_NO_TOGGLE_POWER,
    MOUSE_HEAL,
    MOUSE_EM_PULSE,
    MOUSE_EM_PULSE_RANGE,
    MOUSE_SCROLL_COASTING,
    MOUSE_SCROLL_COASTING_N,
    MOUSE_SCROLL_COASTING_NE,
    MOUSE_SCROLL_COASTING_E,
    MOUSE_SCROLL_COASTING_SE,
    MOUSE_SCROLL_COASTING_S,
    MOUSE_SCROLL_COASTING_SW,
    MOUSE_SCROLL_COASTING_W,
    MOUSE_SCROLL_COASTING_NW,
    MOUSE_PATROL_WAYPOINT,

    MOUSE_COUNT
} MouseType;

typedef enum SplitGroupType
{
    SPLIT_KEEP_BOTH,            // Keep transports, keep units.
    SPLIT_LOSE_UNITS,           // Keep transports, lose units.
    SPLIT_LOSE_TRANSPORTS,      // Lose transports, keep units.
    SPLIT_LOSE_BOTH,            // Lose transports, lose units.
};

typedef enum FindTargetType
{
    ATTACK_LEAST_THREAT,
    ATTACK_GREATEST_THREAT,
    ATTACK_NEAREST,
    ATTACK_FARTHEST,
};

typedef enum NeedType
{
    NEED_NONE,              // No additional data is required.
    NEED_THEME,             // Need a musical theme.
    NEED_MOVIE,             // Need a movie to play.
    NEED_SOUND,             // Sound effect.
    NEED_SPEECH,            // Speech from EVA.
    NEED_INFANTRY,          // Infantry type class.
    NEED_UNIT,              // Unit type class.
    NEED_AIRCRAFT,          // Aircraft type class.
    NEED_STRUCTURE,         // Structure type class.
    NEED_WAYPOINT,          // Waypoint letter.
    NEED_NUMBER,            // General number.
    NEED_TRIGGER,           // Trigger object reference.
    NEED_TEAM,              // Team type class.
    NEED_HOUSE,             // House type number.
    NEED_TIME,              // Time delay value required.
    NEED_QUARRY,            // Quarry type is needed.
    NEED_BOOL,              // Boolean value is needed.
    NEED_SPECIAL,           // Special weapon ability.
    NEED_MISSION,           // General unit mission type.
    NEED_HEX_NUMBER,        // General number.
    NEED_SCRIPT,            // Script type.
    NEED_RECT,              // Rectangle.
    NEED_GLOBAL,            // Global variable.
    NEED_ANIM_WAYPOINT,     // Anim type class and waypoint pair.
    NEED_WEAPON_WAYPOINT,   // weapon type class and waypoint pair.
    NEED_LIGHT_BEHAVIOR,    // Spotlight behavior type.
    NEED_TAG,               // Tag type.
    NEED_METEOR_WAYPOINT,   // Meteor size type and waypoint pair.
    NEED_RADAR_WAYPOINT,    // Radar event type and waypoint pair.
    NEED_LOCAL,             // Local variable.
    NEED_VELOCITY_WAYPOINT, // Move camera velocity type and waypoint.
    NEED_METEOR_SHOWER_WAYPOINT,   // Meteor shower type and waypoint pair.
    NEED_VELOCITY,          // Move camera velocity type.
    NEED_FLOAT,             // Floating point number.
    NEED_TEAM_WAYPOINT,     // Team type class and waypoint pair.
    NEED_PARTICLE_WAYPOINT, // Particle type class and waypoint pair.
    NEED_BUILDING_ATTACK,   // Building type and find target type pair.
    NEED_SPLIT,             // Split group type.
    NEED_SOUND_WAYPOINT,    // Sound effect and waypoint pair.
    NEED_TEAM_FLASH,        // Team type and flash count pair.
    NEED_ANIM,              // Anim type.
    NEED_TALK_BUBBLE,       // Unit talk bubble type.
} NeedType;

typedef enum AttachType
{
    ATTACH_NONE,                // Trigger doesn't attach to anything (orphan trigger types).
    ATTACH_CELL = 1 << 0,       // Trigger can only attach to a cell.
    ATTACH_OBJECT = 1 << 1,     // Trigger can attach only to object (usually building or vehicle).
    ATTACH_MAP = 1 << 3,        // Trigger applies to the general map (usually zone or parallel triggers).
    ATTACH_HOUSE = 1 << 4,      // Trigger applies only to a house.
    ATTACH_GENERAL = 1 << 5,    // General purpose trigger attached to game state.
    ATTACH_TEAM = 1 << 6        // Trigger applies to team object.
} AttachType;

typedef enum TEventType
{
    TEVENT_NONE,

    TEVENT_PLAYER_ENTERED,            // player enters this square
    TEVENT_SPIED,                     // Spied by.
    TEVENT_THIEVED,                   // Thieved by (raided or stolen vehicle).
    TEVENT_DISCOVERED,                // player discovers this object
    TEVENT_HOUSE_DISCOVERED,          // House has been discovered.
    TEVENT_ATTACKED,                  // player attacks this object
    TEVENT_DESTROYED,                 // player destroys this object
    TEVENT_ANY,                       // Any object event will cause the trigger.
    TEVENT_UNITS_DESTROYED,           // all house's units destroyed
    TEVENT_BUILDINGS_DESTROYED,       // all house's buildings destroyed
    TEVENT_ALL_DESTROYED,             // all house's units & buildings destroyed
    TEVENT_CREDITS,                   // house reaches this many credits
    TEVENT_TIME,                      // Scenario elapsed time from start.
    TEVENT_MISSION_TIMER_EXPIRED,     // Pre expired mission timer.
    TEVENT_NBUILDINGS_DESTROYED,      // Number of buildings destroyed.
    TEVENT_NUNITS_DESTROYED,          // Number of units destroyed.
    TEVENT_NOFACTORIES,               // No factories left.
    TEVENT_EVAC_CIVILIAN,             // Civilian has been evacuated.
    TEVENT_BUILD,                     // Specified building has been built.
    TEVENT_BUILD_UNIT,                // Specified unit has been built.
    TEVENT_BUILD_INFANTRY,            // Specified infantry has been built.
    TEVENT_BUILD_AIRCRAFT,            // Specified aircraft has been built.
    TEVENT_LEAVES_MAP,                // Specified team member leaves map.
    TEVENT_ENTERS_ZONE,               // Enters same zone as waypoint 'x'.
    TEVENT_CROSS_HORIZONTAL,          // Crosses horizontal trigger line.
    TEVENT_CROSS_VERTICAL,            // Crosses vertical trigger line.
    TEVENT_GLOBAL_SET,                // If specified global has been set.
    TEVENT_GLOBAL_CLEAR,              // If specified global has been cleared.
    TEVENT_FAKES_DESTROYED,           // If all fake structures are gone.
    TEVENT_LOW_POWER,                 // When power drops below 100%.
    TEVENT_BRIDGE_DESTROYED,          // Attached bridge destroyed.
    TEVENT_BUILDING_EXISTS,           // Check for building existing.
    TEVENT_SELECTED_BY_PLAYER,
    TEVENT_COMES_NEAR_WAYPOINT,
    TEVENT_ENEMY_IN_SPOTLIGHT,
    TEVENT_LOCAL_SET,
    TEVENT_LOCAL_CLEARED,
    TEVENT_COMBAT_FIRST_DAMAGED,
    TEVENT_COMBAT_HALF_HEALTH,
    TEVENT_COMBAT_QUATER_HEALTH,
    TEVENT_FIRST_DAMAGED,
    TEVENT_HALF_HEALTH,
    TEVENT_QUARTER_HEALTH,
    TEVENT_ATTACKED_BY_HOUSE,
    TEVENT_AMBIENT_LESS_THAN,
    TEVENT_AMBIENT_GREATER_THAN,
    TEVENT_ELAPSED_SCENARIO_TIME,
    TEVENT_DESTROYED_BY_ANYTHING,
    TEVENT_PICKUP_CRATE,
    TEVENT_PICKUP_CRATE_ANY,
    TEVENT_RANDOM_DELAY,
    TEVENT_CREDITS_BELOW,
    TEVENT_PARALYZED,
    TEVENT_54, // Looks to be a copy of TEVENT_ENEMY_IN_SPOTLIGHT.
    TEVENT_LIMPED,

    TEVENT_COUNT,

    TEVENT_FIRST = 0
} TEventType;

typedef enum TActionType
{
    TACTION_NONE,

    TACTION_WIN,                   // player wins!
    TACTION_LOSE,                  // player loses.
    TACTION_BEGIN_PRODUCTION,      // computer begins factory production.
    TACTION_CREATE_TEAM,           // computer creates a certain type of team
    TACTION_DESTROY_TEAM,          // destroys all teams of a certain type.
    TACTION_ALL_HUNT,              // all enemy units go into hunt mode (teams destroyed).
    TACTION_REINFORCEMENTS,        // player gets reinforcements (house that gets them is determined by the Reinforcement instance)
    TACTION_DZ,                    // Deploy drop zone smoke.
    TACTION_FIRE_SALE,             // Sell all buildings and go on rampage.
    TACTION_PLAY_MOVIE,            // Play movie (temporarily suspend game).
    TACTION_TEXT_TRIGGER,          // Triggers a text message display.
    TACTION_DESTROY_TRIGGER,       // Destroy specified trigger.
    TACTION_AUTOCREATE,            // Computer to auto-create teams.
    TACTION_WINLOSE,               // Win if captured, lose if destroyed.
    TACTION_ALLOWWIN,              // Allows winning if triggered.
    TACTION_REVEAL_ALL,            // Reveal the entire map.
    TACTION_REVEAL_SOME,           // Reveal map around cell #.
    TACTION_REVEAL_ZONE,           // Reveal all of specified zone.
    TACTION_PLAY_SOUND,            // Play sound effect.
    TACTION_PLAY_MUSIC,            // Play musical score.
    TACTION_PLAY_SPEECH,           // Play EVA speech.
    TACTION_FORCE_TRIGGER,         // Force trigger to activate.
    TACTION_START_TIMER,           // Start mission timer.
    TACTION_STOP_TIMER,            // Stop mission timer.
    TACTION_ADD_TIMER,             // Increase mission timer time.
    TACTION_SUB_TIMER,             // Decrease mission timer time.
    TACTION_SET_TIMER,             // Set and start the mission timer.
    TACTION_SET_GLOBAL,            // Set global variable.
    TACTION_CLEAR_GLOBAL,          // Clear global variable.
    TACTION_BASE_BUILDING,         // Automated base building.
    TACTION_CREEP_SHADOW,          // Shadow grows back one 'step'.
    TACTION_DESTROY_OBJECT,        // Destroys the building this trigger is attached to.
    TACTION_1_SPECIAL,             // Add a one-time special weapon ability to house.
    TACTION_FULL_SPECIAL,          // Add a repeating special weapon ability to house.
    TACTION_PREFERRED_TARGET,      // Designates preferred target for house.
    TACTION_ALL_CHANGE_HOUSE,
    TACTION_MAKE_ALLY,
    TACTION_MAKE_ENEMY,
    TACTION_CHANGE_ZOOM_LEVEL,
    TACTION_RESIZE_VIEW,
    TACTION_PLAY_ANIM,
    TACTION_EXPLOSION,
    TACTION_METEOR_IMPACT,
    TACTION_ION_STORM_START,
    TACTION_ION_STORM_STOP,
    TACTION_LOCK_INPUT,
    TACTION_UNLOCK_INPUT,
    TACTION_CENTER_CAMERA,
    TACTION_ZOOM_IN,
    TACTION_ZOOM_OUT,
    TACTION_RESHROUD_MAP,
    TACTION_CHANGE_LIGHT_BEHAVIOR,
    TACTION_ENABLE_TRIGGER,
    TACTION_DISABLE_TRIGGER,
    TACTION_CREATE_RADAR_EVENT,
    TACTION_LOCAL_SET,
    TACTION_LOCAL_CLEAR,
    TACTION_METEOR_SHOWER,
    TACTION_REDUCE_TIBERIUM,
    TACTION_SELL_BUILDING,
    TACTION_TURN_OFF_BUILDING,
    TACTION_TURN_ON_BUILDING,
    TACTION_APPLY_100_DAMAGE,
    TACTION_LIGHT_FLASH_SMALL,
    TACTION_LIGHT_FLASH_MEDIUM,
    TACTION_LIGHT_FLASH_LARGE,
    TACTION_ANNOUNCE_WIN,
    TACTION_ANNOUNCE_LOSE,
    TACTION_FORCE_END,
    TACTION_DESTROY_TAG,
    TACTION_SET_AMBIENT_STEP,
    TACTION_SET_AMBIENT_RATE,
    TACTION_SET_AMBIENT_LIGHT,
    TACTION_AI_TRIGGERS_BEGIN,
    TACTION_AI_TRIGGERS_STOP,
    TACTION_RATIO_AI_TRIGGER_TEAMS,
    TACTION_RADIO_TEAM_AIRCRAFT,
    TACTION_RADIO_TEAM_INFANTRY,
    TACTION_RADIO_TEAM_UNITS,
    TACTION_REINFORCEMENT_TEAM,
    TACTION_WAKEUP_SELF,
    TACTION_WAKEUP_ALL_SLEEPERS,
    TACTION_WAKEUP_ALL_HARMLESS,
    TACTION_WAKEUP_GROUP,
    TACTION_VEIN_GROWTH,
    TACTION_TIBERIUM_GROWTH,
    TACTION_ICE_GROWTH,
    TACTION_PARTICLE_ANIM_AT,
    TACTION_REMOVE_PARTICLE_AT,
    TACTION_LIGHTENING_STRIKE,
    TACTION_GO_BERZERK,
    TACTION_ACTIVATE_FIRESTORM,
    TACTION_DEACTIVATE_FIRESTORM,
    TACTION_ION_CANNON_STRIKE,
    TACTION_NUKE_STRIKE,
    TACTION_CHEM_MISSILE_STRIKE,
    TACTION_TOGGLE_TRAIN_CARGO,
    TACTION_PLAY_RANDOM_SOUND_EFFECT,
    TACTION_PLAY_SOUND_EFFECT_AT,
    TACTION_PLAY_INGAME_MOVIE,
    TACTION_FLASH_TEAM,
    TACTION_DISABLE_SPEECH,
    TACTION_ENABLE_SPEECH,
    TACTION_SET_CONTROL_ID,
    TACTION_TALK_BUBBLE,

    TACTION_COUNT,

    TACTION_FIRST = 0
} TActionType;

typedef enum ProdFailType {
    PROD_OK,        // Production request successful.
    PROD_LIMIT,     // Failed with production capacity limit reached.
    PROD_ILLEGAL,   // Failed because of illegal request.
    PROD_CANT       // Failed because unable to comply (busy or occupied).
} ProdFailType;

typedef enum TileRampType
{
    /**
     *  A flat tile (i.e. no ramp).
     */
    RAMP_NONE = 0,
    
    /**
     *  Basic, two adjacent corners raised.
     */
    RAMP_WEST = 1,      // The west corner of the tile is raised.
    RAMP_NORTH = 2,     // The south corner of the tile is raised.
    RAMP_EAST = 3,      // The east corner of the tile is raised.
    RAMP_SOUTH = 4,     // The north corner of the tile is raised.
    
    /**
     *  Tile outside corners (One corner raised by half a cell).
     */
    RAMP_CORNER_NW = 5,
    RAMP_CORNER_NE = 6,
    RAMP_CORNER_SE = 7,
    RAMP_CORNER_SW = 8,
    
    /**
     *  Tile inside corners (three corners raised by half a cell).
     */
    RAMP_MID_NW = 9,
    RAMP_MID_NE = 10,
    RAMP_MID_SE = 11,
    RAMP_MID_SW = 12,
    
    /**
     *  Full tile sloped (mid corners raised by half cell, far corner by full cell).
     */
    RAMP_STEEP_SE = 13,     // Almost a invisible tile, but actually a fixup tile for ??.
    RAMP_STEEP_SW = 14,     // Full steep tile that faces NW (on the screen).
    RAMP_STEEP_NW = 15,     // Full steep tile that faces SE (on the screen).
    RAMP_STEEP_NE = 16,     // Full steep tile that faces SE (on the screen).

    /**
     *  Double ramps (two corners raised, alternating).
     */
    RAMP_DOUBLE_UP_SW_NE = 17,      // Double ramp tile that slopes up, faces SW-NE (in the game world).
    RAMP_DOUBLE_DOWN_SW_NE = 18,    // Double ramp tile that slopes down, faces SW-NE (in the game world).
    RAMP_DOUBLE_UP_NW_SE = 19,      // Double ramp tile that slopes up, faces NW-SE (in the game world).
    RAMP_DOUBLE_DOWN_NW_SE = 20,    // Double ramp tile that slopes down, faces NW-SE (in the game world).
} TileRampType;
DEFINE_ENUMERATION_OPERATORS(TileRampType);

/**
 *  Shape drawing flags.
 */
typedef enum ShapeFlagsType
{
    SHAPE_NORMAL,                   // Standard shape

    SHAPE_DARKEN = 1 << 0,
    SHAPE_TRANS25 = 1 << 1,
    SHAPE_TRANS50 = 1 << 2,
    SHAPE_TRANS75 = (SHAPE_TRANS25|SHAPE_TRANS50),
    SHAPE_REMAP = 1 << 3,
    SHAPE_Z_REMAP = 1 << 4,
    SHAPE_PLAIN = 1 << 5,
    SHAPE_WRITE_ALPHA = 1 << 6,
    SHAPE_80 = 1 << 7,
    SHAPE_MULTI_WRITE_ALPHA = 1 << 8,
    SHAPE_CENTER = 1 << 9,
    SHAPE_400 = 1 << 10,
    SHAPE_ALPHA = 1 << 11,
    SHAPE_1000 = 1 << 12,
    SHAPE_FLAT = 1 << 13,
    SHAPE_Z_READ_WRITE = 1 << 14,
    SHAPE_8000 = 1 << 15,
    SHAPE_ZERO_ALPHA = 1 << 16,
    SHAPE_NON_ZERO_ALPHA = 1 << 17,

} ShapeFlagsType;
DEFINE_ENUMERATION_OPERATORS(ShapeFlagsType);


typedef unsigned long LEPTON;
typedef AbstractClass * TARGET;


typedef struct VariableFlagStruct {
    char Name[40];
    unsigned char Value;
} VariableFlagStruct;


#pragma pack(1)
struct RGBStruct
{
    bool operator==(const RGBStruct &that) const { return R == that.R && G == that.G && B == that.B; }
    bool operator!=(const RGBStruct &that) const { return R != that.R && G != that.G && B != that.B; }

    unsigned char R;
    unsigned char G;
    unsigned char B;
};
#pragma pack()


#pragma pack(1)
struct wRGBStruct
{
    bool operator==(const RGBStruct &that) const { return R == that.R && G == that.G && B == that.B; }
    bool operator!=(const RGBStruct &that) const { return R != that.R && G != that.G && B != that.B; }

    unsigned short R;
    unsigned short G;
    unsigned short B;
};
#pragma pack()


#pragma pack(1)
struct HSVStruct
{
    bool operator==(const HSVStruct &that) const { return H == that.H && S == that.S && V == that.V; }
    bool operator!=(const HSVStruct &that) const { return H != that.H && S != that.S && V != that.V; }

    unsigned char H;
    unsigned char S;
    unsigned char V;
};
#pragma pack()


/**
 *  Shape file format header.
 */
#pragma pack(4)
struct ShapeFileHeaderStruct
{
    int16_t Type; // -1, 0
    int16_t Width; // Width of the shape in bytes.
    int16_t Height; // Height of the shape in scan lines.
    int16_t FrameCount; // Number of shapes in the file.
};
#pragma pack()


/**
 *  Shape file format frame struct.
 */
#pragma pack(4)
struct ShapeFileFrameStruct
{
    Rect Get_Frame_Dimensions() const { return Rect(FrameXPos, FrameYPos, FrameWidth, FrameHeight); }

    int16_t FrameXPos;
    int16_t FrameYPos;
    int16_t FrameWidth;
    int16_t FrameHeight;
    int32_t Flags; 
    RGBStruct Color;
    uint8_t field_F[5];
    int32_t FrameOffset;
};
#pragma pack()


/**
 *  Shape file format struct. Define pointers to loaded shapes with this
 *  struct instead of casting raw pointers to access header information.
 */
#pragma pack(4)
struct ShapeFileStruct
{
    public:
        operator void *() const { return (*this); } // This allows the struct to be passed implicitly as a raw pointer.

        ShapeFileFrameStruct *Get_Frame_Data(int index)
        {
            return &(&FrameData)[index * sizeof(ShapeFileFrameStruct)];
        }

        int Get_Width() const { return Header.Width; }
        int Get_Height() const { return Header.Height; }
        int Get_Frame_Count() const { return Header.FrameCount; }

    private:
        ShapeFileHeaderStruct Header;

        /**
         *  This is an instance of the first frame in the shape file, use Get_Frame_Data
         *  to get the frame information, do not access this directly!
         */
        ShapeFileFrameStruct FrameData;
};
#pragma pack()


#pragma pack(4)
struct IsoTileHeaderStruct
{
    int32_t Width;
    int32_t Height;
    int32_t ImageWidth;
    int32_t ImageHeight;
};
#pragma pack()


#pragma pack(4)
struct IsoTileImageStruct
{
    int32_t XPos;
    int32_t YPos;
    int32_t ExtraOffset;
    int32_t ZDataOffset;
    int32_t ExtraZOffset;
    int32_t ExtraXPos;
    int32_t ExtraYPos;
    int32_t ExtraWidth;
    int32_t ExtraHeight;
    int32_t Flags; 
    uint8_t Height; 
    uint8_t TileType; 
    uint8_t RampType; 
    RGBStruct LowColor;
    RGBStruct HighColor;
    uint8_t field_31[3];
};
#pragma pack()


#pragma pack(4)
struct IsoTileFileStruct
{
    public:
        operator void *() const { return (*this); } // This allows the struct to be passed implicitly as a raw pointer.

        IsoTileImageStruct *Get_Tiles_Data(int index)
        {
            return &(&Tiles)[index * sizeof(IsoTileImageStruct)];
        }

        int Get_Width() const { return Header.Width; }
        int Get_Height() const { return Header.Height; }

    private:
        IsoTileHeaderStruct Header;

        /**
         *  This is an instance of the first frame in the iso tile file, use Get_Frame_Data
         *  to get the image information, do not access this directly!
         */
        IsoTileImageStruct Tiles;
};
#pragma pack()


struct CellStruct
{
    CellStruct(int16_t x = 0, int16_t y = 0) : X(x), Y(y) {}
    CellStruct(const CellStruct &that) : X(that.X), Y(that.Y) {}

    operator bool () const { return X != 0 || Y != 0 /*&& As_Cell_Number() < MAP_CELL_TOTAL*/; }

    bool operator==(const CellStruct &that) const { return X == that.X && Y == that.Y; }
    bool operator!=(const CellStruct &that) const { return X != that.X && Y != that.Y; }

    int32_t As_Cell_Number() const { return X + (Y << 9); }

    int16_t X; // X component of location.
    int16_t Y; // Y component of location.
};


struct CoordStruct
{
    CoordStruct(int32_t x = 0, int32_t y = 0, int32_t z = 0) : X(x), Y(y), Z(z) {}
    CoordStruct(const CoordStruct &that) : X(that.X), Y(that.Y), Z(that.Z) {}

    operator bool () const { return X != 0 || Y != 0 || Z != 0; }

    bool operator==(const CoordStruct &that) const { return X == that.X && Y == that.Y && Z == that.Z; }
    bool operator!=(const CoordStruct &that) const { return X != that.X && Y != that.Y && Z != that.Z; }

    int32_t X; // X coordinate of the location.
    int32_t Y; // Y coordinate of the location.
    int32_t Z; // Z coordinate of the location.
};


struct xCellStruct
{
    int16_t X; // X component of location.
    int16_t Y; // Y component of location.
};


struct xCoordStruct
{
    int32_t X; // X coordinate of the location.
    int32_t Y; // Y coordinate of the location.
    int32_t Z; // Z coordinate of the location.
};


struct wDimensionStruct
{
    int16_t W;
    int16_t H;
};


struct AbilitiesStruct
{
    public:
        AbilitiesStruct()
        {
            // Init all flags to false.
            for (AbilityType type = ABILITY_FIRST; type < ABILITY_COUNT; ++type) {
                AbilitiesFlag[type] = false;
            }
        }

        bool operator[](AbilityType type) const { return AbilitiesFlag[type]; }

    public:
        bool AbilitiesFlag[ABILITY_COUNT];
};


typedef struct DoStruct
{
    bool Interrupt;         // Can it be interrupted?
    bool IsMobile;          // Can it move while doing this?
    bool RandomStart;       // Should animation be "randomized"?
    unsigned char Rate;     // Frame rate.
} DoStruct;


typedef struct DoInfoStruct
{
    int Frame;              // Starting frame of the animation.
    unsigned int Count;     // Number of frames of animation.
    unsigned int Jump;      // Frames to jump between facings.
    FacingType Finish;      // Direction to face when finished.
} DoInfoStruct;


class ZoneConnectionClass
{
    public:
        bool operator==(const ZoneConnectionClass &src) const { return false; }
        bool operator!=(const ZoneConnectionClass &src) const { return true; }

    public:
        CellStruct field_0;
        CellStruct field_4;
        bool field_8;
        int field_A;
};


struct SubzoneConnectionStruct
{
    bool operator==(const SubzoneConnectionStruct &src) const { return false; }
    bool operator!=(const SubzoneConnectionStruct &src) const { return true; }

    int field_4;
    int field_8;
};


struct SubzoneTrackingStruct
{
    bool operator==(const SubzoneTrackingStruct &src) const { return false; }
    bool operator!=(const SubzoneTrackingStruct &src) const { return true; }

    // TODO
};


struct CrackedIceStruct
{
    bool operator==(const CrackedIceStruct &src) const { return false; }
    bool operator!=(const CrackedIceStruct &src) const { return true; }

    int field_0; // cell number?
    int field_4; // cracking frame?
};


struct AngerStruct
{
    bool operator==(const AngerStruct &that) const
    {
        return (Whom == that.Whom && Level == that.Level);
    }
    bool operator!=(const AngerStruct &that) const
    {
        return (Whom != that.Whom && Level != that.Level);
    }

    HouseClass *Whom;
    int Level;
};


struct ScoutStruct
{
    bool operator==(const ScoutStruct &that) const
    {
        return (Whom == that.Whom && HasScouted == that.HasScouted);
    }
    bool operator!=(const ScoutStruct &that) const
    {
        return (Whom != that.Whom && HasScouted != that.HasScouted);
    }

    HouseClass *Whom;
    bool HasScouted;
};


/**
 *  DirStruct is in stages of 128 (0-32768) (128*256).
 */
#pragma pack(4)
typedef struct DirStruct : public fixed
{
    private:
        static inline FacingType Dir_To_Facing(DirType facing) { return (FacingType)(((unsigned char)((int)facing+0x10)&0xFF)>>5); }
        static inline DirType Facing_To_Dir(FacingType facing) { return (DirType)((int)facing<<5); }

    public:
        explicit DirStruct() : fixed(0) {}
        explicit DirStruct(int raw) { Set_Raw(raw); }
        explicit DirStruct(const DirType dir) : fixed(dir) {}
        explicit DirStruct(const FacingType facing) : fixed(Facing_To_Dir(facing)) {}
        explicit DirStruct(const NoInitClass &noinit) {}

        operator int () const { return fixed::Get_Raw(); }

        operator DirType() const { return (DirType)((((Get_Raw() >> 7) + 1) >> 1) & 255); }
        operator FacingType() const { return Dir_To_Facing((DirType)(Get_Raw() & 255)); }

        bool func_5589F0(const DirStruct &a, const DirStruct &b);
        bool func_558A20(const DirStruct &a, const DirStruct &b);

} DirStruct;
#pragma pack()
