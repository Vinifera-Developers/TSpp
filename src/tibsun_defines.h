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


class AbstractClass;


/**
 *  This head contains all the game enums, structs and primitive types.
 */


// Max stored views/bookmarks
#define VIEW_COUNT 4

// Save filename description.
#define	DESCRIP_MAX	44			// 40 chars + CR + LF + CTRL-Z + NULL


typedef enum WaypointEnum
{
    WAYPT_HOME = 98,	// Home-cell for this scenario
    WAYPT_REINF,		// cell where reinforcements arrive
    WAYPT_SPECIAL,		// Used by special airdrop reinforcements.
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


typedef enum DirType {} DirType;
typedef enum MPHType {} MPHType;
typedef enum CrateType {} CrateType;
typedef enum VocType {} VocType;
typedef enum VQType {} VQType;
typedef enum ThemeType {} ThemeType;

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

typedef enum TheaterType {} TheaterType;
typedef enum PipType {} PipType;
typedef enum PipScaleType {} PipScaleType;
typedef enum CategoryType {} CategoryType;

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
typedef enum MZoneType {} MZoneType;
typedef enum SideType {} SideType;
typedef enum SourceType {} SourceType;

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
typedef enum SuperType {} SuperType;
typedef enum ActionType {} ActionType;
typedef enum VoxType {} VoxType;
typedef enum LandType {} LandType;
typedef enum ArmorType {} ArmorType;
typedef enum MissionType {} MissionType;
typedef enum WeaponSlotType {} WeaponSlotType;


typedef enum ColorSchemeType
{
    COLORSCHEME_NONE = 0
} ColorSchemeType;


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
    bool Interrupt;	        // Can it be interrupted?
    bool IsMobile;	        // Can it move while doing this?
    bool RandomStart;	    // Should animation be "randomized"?
    unsigned char Rate;		// Frame rate.
} DoStruct;


typedef struct DoInfoStruct
{
    int Frame;	            // Starting frame of the animation.
    unsigned int Count;	    // Number of frames of animation.
    unsigned int Jump;	    // Frames to jump between facings.
    FacingType Finish;	    // Direction to face when finished.
} DoInfoStruct;


class xTargetClass
{
    public:
        int RTTI;
        int ID;
};
