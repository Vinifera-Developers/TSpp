/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CELL.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Representation of a cell on the game world map.
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

#include "abstract.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"
#include "vector.h"


class NoInitClass;
class ObjectClass;
class TechnoClass;
class FootClass;
class UnitClass;
class AircraftClass;
class InfantryClass;
class BuildingClass;
class TerrainClass;
class BuildingTypeClass;
class FoggedObjectClass;
class LightConvertClass;
class TagClass;
class TiberiumClass;
class RGBClass;


class DECLSPEC_UUID("C1BF99CE-1A8C-11D2-8175-006008055BB5")
CellClass : public AbstractClass
{
public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

    /**
     *  IRTTITypeInfo
     */
    IFACEMETHOD_(int, What_Am_I)();

public:
    CellClass();
    CellClass(const NoInitClass& x);
    virtual ~CellClass();

    int operator!=(const CellClass& cell) const { return cell.CellID != CellID; }
    int operator==(const CellClass& cell) const { return cell.CellID == CellID; }

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual Coord Center_Coord() const override;
    virtual Coord entry_5C() const override;

    int Get_Height(const Coord& coord) const;
    int Preview_Cell_Color(void* a1, bool a2 = false);
    void Cell_Color(RGBClass& a1, RGBClass& a2);
    ObjectClass* Cell_Find_Object(RTTIType rtti, bool a2 = false) const;
    ObjectClass* const Cell_Object(const Point2D& xy = Point2D(), bool a2 = false) const;
    TechnoClass* const Cell_Techno(const Point2D& xy = Point2D(), bool a2 = false, TechnoClass* a3 = nullptr) const;
    UnitClass* const Cell_Unit(bool a2 = false) const;
    AircraftClass* const Cell_Aircraft(bool a2 = false) const;
    InfantryClass* const Cell_Infantry(bool a2 = false) const;
    BuildingClass* const Cell_Building() const;
    TerrainClass* const Cell_Terrain(bool a2 = false) const;
    bool Is_Clear_To_Build(SpeedType loco, const BuildingTypeClass* buildtype = nullptr, const HouseClass* house = nullptr);
    // 004526A0
    // 004531A0
    void Recalc_Attributes(int level = -1);
    // 00453CF0
    // 00453FB0
    // 004543E0
    void Occupy_Down(ObjectClass* object, bool a2 = false);
    void Occupy_Up(ObjectClass* object, bool a2 = false);
    // 00454B80
    // 00454E60
    // 00455130
    // 00455450
    // 004555E0
    Rect Overlay_Render_Rect() const;
    Rect Overlay_Shadow_Render_Rect() const;
    Rect Cell_Render_Rect() const;
    // 00456270
    // 00456300
    // 00456370
    // 00456420
    // 004564D0
    // 00456690
    void Wall_Update(bool a1 = false);
    Coord Cell_Coord() const;
    int Reduce_Tiberium(int levels);
    int Reduce_Wall(int damage);
    bool Is_Spot_Free(int spot_index, bool a2 = false) const;
    Coord Closest_Free_Spot(Coord& coord, bool a2 = false, bool a3 = false) const;
    // 00457600
    int Clear_Icon(IsometricTileType tile, int tile_sequence_count);
    void Incoming(Coord& threat = Coord(), bool forced = false, bool no_kidding = false, bool a4 = false);
    CellClass& Adjacent_Cell(FacingType facing) const;
    void Adjust_Threat(HousesType house, int threat_value);
    long Tiberium_Adjust(bool pre_game = false);
    bool Goodie_Check(FootClass* object = nullptr);
    bool Flag_Place(HousesType house);
    bool Flag_Remove();
    void Shimmer();
    bool Is_Clear_To_Move(SpeedType loco, bool ignore_infantry = false, bool ignore_vehicles = false, int zone = -1, MZoneType check = MZONE_NORMAL, int cell_level = -1, bool a7 = true);
    bool Is_Bridge_Here() const;
    bool Can_Tiberium_Grow() const;
    bool Can_Tiberium_Spread() const;
    bool Grow_Tiberium();
    bool Spread_Tiberium(bool forced = false);
    bool Can_Tiberium_Germinate(TiberiumClass* tiberium = nullptr) const;
    // 00459A00
    // 00459B80
    // 00459D90
    // 00459EC0
    // 0045A310
    // 0045A4A0
    // 0045A670
    // 0045A680
    bool CellClass::Has_Tunnel(void) const;
    bool CellClass::Is_Near_Tunnel_NW(void) const;
    bool CellClass::Is_Near_Tunnel_ES(void) const;
    // 0045AAD0
    // 0045AAE0
    // 0045AB10
    // 0045ABA0
    TiberiumType Tiberium_Type_Here();
    int Get_Tiberium_Value() const;
    bool Is_Tile_Water() const { return ITType >= WaterSet && ITType < (WaterSet + 14); } // 0045ACB0
    int Occupier_Height() const;                                                          // 0045ACD0
    void Detach(AbstractClass* target);
    // 0045AE90
    void Attach_Tag(TagClass* tag);
    // 0045AF20
    // 0045B000
    // 0045B0D0
    // 0045B200
    // 0045B760
    bool Is_Tile_Clear() const { return ITType == ISOTILE_NONE || ITType == ISOTILE_CLEAR; }                                                       // 0045BFF0
    bool Is_Tile_Ramp() const { return (ITType >= RampBase && ITType < (RampBase + 20)) || (ITType >= RampSmooth && ITType < (RampSmooth + 12)); } // 0045C010
    // bool Is_() const { return ; } // 0045C040     <- cliffset, water cliffs, waterfall, bridges, destroyable cliffs
    bool Is_Tile_Shore() const { return ITType >= ShorePieces && ITType < (ShorePieces + 42); } // 0045C220
    // bool Is_() const { return ; } // 0045C240     <- shore and waterfalls
    // bool Is_() const { return ; } // 0045C2C0     <- swamp and water LAT
    bool Is_Tile_Misc_Pavement() const { return ITType >= MiscPaveTile && ITType < (MiscPaveTile + 14); } // 0045C2F0
    bool Is_Tile_Pavement() const { return ITType >= PaveTile && ITType < (PaveTile + 16); }              // 0045C310
    bool Is_Tile_Dirt_Road() const                                                                        // 0045C330
    {
        return ITType >= DirtRoadJunction && ITType < (DirtRoadJunction + 11) || ITType >= DirtRoadCurve && ITType < (DirtRoadCurve + 24) || ITType >= DirtRoadStraight && ITType < (DirtRoadStraight + 66);
    }
    bool Is_Tile_Paved_Road() const { return ITType >= PavedRoads && ITType < (PavedRoads + 15); }                // 0045C370
    bool Is_Tile_Paved_Road_End() const { return ITType >= PavedRoadEnds && ITType < (PavedRoadEnds + 4); }       // 0045C390
    bool Is_Tile_Paved_Road_Slope() const { return ITType >= PavedRoadSlopes && ITType < (PavedRoadSlopes + 4); } // 0045C3B0
    bool Is_Tile_Paved_Road_Median() const { return ITType >= Medians && ITType < (Medians + 14); }               // 0045C3D0
    // bool Is_() const { return ; } // 0045C3F0     <- ice1 and ice2 sets
    bool Is_Tile_Bridge() const { return ITType >= BridgeSet && ITType < (BridgeSet + 16); }                 // 0045C410
    bool Is_Tile_Train_Bridge() const { return ITType >= TrainBridgeSet && ITType < (TrainBridgeSet + 16); } // 0045C430
    // bool Is_() const { return ; } // 0045C450     <- clear to sand LAT
    //  0045C470      <- clear to green LAT
    bool Is_Tile_Destroyable_Cliff() const { return ITType == DestroyableCliff || ITType == (DestroyableCliff + 1); } // 0045C5A0
    bool Is_Tile_Bridge_Middle() const
    {
        const IsometricTileType ttype = ITType - BridgeSet + 1;
        return (ttype == BridgeMiddle1 + 0 || ttype == BridgeMiddle1 + 1 || ttype == BridgeMiddle1 + 2 || ttype == BridgeMiddle1 + 3 || ttype == BridgeMiddle2 + 0 || ttype == BridgeMiddle2 + 1 || ttype == BridgeMiddle2 + 2 || ttype == BridgeMiddle2 + 3);
    }

    bool Is_Tile_Train_Bridge_Middle() const
    {
        const IsometricTileType ttype = ITType - TrainBridgeSet + 1;
        return (ttype == BridgeMiddle1 + 0 || ttype == BridgeMiddle1 + 1 || ttype == BridgeMiddle1 + 2 || ttype == BridgeMiddle1 + 3 || ttype == BridgeMiddle2 + 0 || ttype == BridgeMiddle2 + 1 || ttype == BridgeMiddle2 + 2 || ttype == BridgeMiddle2 + 3);
    }
    // 0045C490
    // 0045C4E0
    // 0045C530
    void Trigger_Veins();
    // 0045C700
    // 0045C880
    // 0045C8E0
    unsigned Toggle_Occupied_By(HousesType house);
    // 0045CAC0
    void Redraw_Overlay(); // 0045CB00
    // 0045CC80
    bool Cloaked_By(HousesType house) const;
    bool Sensed_By(HousesType house) const;
    void Set_Cloaked_By(HousesType house);
    void Clear_Cloaked_By(HousesType house);
    void Set_Sensed_By(HousesType house);
    void Clear_Sensed_By(HousesType house);
    bool Place_Tiberium(TiberiumType tiberium, int frame);
    // 0045D290
    // 0045D4A0
    // 0045D500
    // 0045D560
    // 0045D720

    ObjectClass* Cell_Occupier(bool alt = false) const { return alt ? AltOccupierPtr : OccupierPtr; }

    bool Is_Any_Spot_Free(bool alt = false) const
    {
        bool free = false;
        for (int spot_index = 0; spot_index < 5; ++spot_index) {
            if (alt) {
                free = (!(AltFlag.Composite & (1 << spot_index)));
            } else {
                free = (!(Flag.Composite & (1 << spot_index)));
            }
            if (free) {
                return true;
            }
        }

        return free;
    }

    LandType Land_Type() const { return Land; }

    static int Spot_Index(Coord& coord);

    bool Spread_Tiberium(TiberiumType tiberium, bool forced = false);

    bool Is_Tile_Ice_Shore() const { return ITType >= IceShoreSet && ITType < (IceShoreSet + 48); }
    bool Is_Tile_Dirt_Road_Slope() const { return ITType >= DirtRoadSlopes && ITType < (DirtRoadSlopes + 8); }
    bool Is_Tile_Black() const { return ITType == BlackTile; }

    bool Is_Overlay_Low_Bridge() const { return Overlay >= OVERLAY_LOWBRIDGE_BEGIN && Overlay <= OVERLAY_LOWBRIDGE_END; }
    bool Is_Overlay_Train_Tracks() const { return Overlay >= OVERLAY_TRACK_BEGIN && Overlay <= OVERLAY_TRACK_END; }
    bool Is_Overlay_Bridge() const { return Overlay == OVERLAY_BRIDGE1 || Overlay == OVERLAY_BRIDGE2; }
    bool Is_Overlay_Rail_Bridge() const { return Overlay == OVERLAY_RAIL_BRIDGE1 || Overlay == OVERLAY_RAIL_BRIDGE2; }

    CellClass* Get_Bridge_Owner() const;

    Cell Cell_Number() { return CellID; }

public:
    Cell CellID;
    DynamicVectorClass<FoggedObjectClass*>* FoggedObjects;
    CellClass* BridgeOwner;
    int field_20;
    LightConvertClass* Drawer;
    IsometricTileType ITType;
    TagClass* CellTag;
    OverlayType Overlay;
    SmudgeType Smudge;
    PassabilityType Passability;
    HousesType Owner;
    HousesType InfType;
    HousesType AltInfType;
    int field_48;  // shadow/shroud flag? Changes as shroud gets mapped
    int field_4C;  // -- always "-1"
    int field_50;  // -- always "-1"
    Rect field_54; // set on cells that are the center of a bridge.
    unsigned CloakedBy;
    unsigned SensedBy;
    unsigned OccupiedBy;
    ObjectClass* OccupierPtr;
    ObjectClass* AltOccupierPtr;
    LandType Land;
    unsigned Intensity;
    short Ambient;
    short Brightness;
    short TileBrightness;
    short field_86;
    short field_88;
    short field_8A;
    short field_8C;
    short Tube;
    unsigned char field_90;
    unsigned char IsIceGrowthAllowed;
    unsigned char SubTile;
    unsigned char Height;
    unsigned char Ramp;
    unsigned char field_95;
    unsigned char OverlayData;
    unsigned char SmudgeData;
    char field_98; // shadow flags? Changes as shroud gets mapped
    char field_99; // shadow flags? Changes as shroud gets mapped
    unsigned char AdjacentObjectCount;

    union {
        struct {
            unsigned Center : 1;
            unsigned NW : 1;
            unsigned NE : 1;
            unsigned SW : 1;
            unsigned SE : 1;
            unsigned Vehicle : 1;  // Reserved for vehicle occupation.
            unsigned Monolith : 1; // Some immovable blockage is in cell.
            unsigned Building : 1; // A building of some time (usually blocks movement).
        } Occupy;
        unsigned char Composite;
    } Flag;

    union {
        struct {
            unsigned Center : 1;
            unsigned NW : 1;
            unsigned NE : 1;
            unsigned SW : 1;
            unsigned SE : 1;
            unsigned Vehicle : 1;  // Reserved for vehicle occupation.
            unsigned Monolith : 1; // Some immovable blockage is in cell.
            unsigned Building : 1; // A building of some time (usually blocks movement).
        } Occupy;
        unsigned char Composite;
    } AltFlag;

    unsigned IsPlot : 1;
    unsigned IsCursorHere : 1;
    unsigned IsMapped : 1;
    unsigned IsVisible : 1;
    unsigned IsFogMapped : 1;
    unsigned IsFogVisible : 1;
    unsigned IsWaypoint : 1;
    unsigned IsRadarCursor : 1;

    unsigned IsFlagged : 1;
    unsigned IsToShroud : 1;
    unsigned IsToFog : 1;
    unsigned IsBridgeOwner : 1;  // is the starting point of a bridge connection? (from start to end?)
    unsigned IsUnderBridge : 1;  // is covered by bridge overlay?
    unsigned WasUnderBridge : 1; // is covered by bridge overlay? also
    unsigned Bit2_64 : 1;        // unrepaired/repairable bridge connection.
    unsigned Bit2_128 : 1;       // draws on cells that are the length of the bridge body. (low down?)

    unsigned Bit3_1 : 1; // draws on cells that are the length of the bridge body. (high up?)
    unsigned Bit3_2 : 1;
    unsigned Bit3_4 : 1; // Is ice edge? Flagged when smoothing required.
    unsigned Bit3_8 : 1;
    unsigned IsOvershadowed : 1; // Casts shadow? or Overcasted with shadow?
    unsigned IsAnimAttached : 1;
    unsigned Bit3_64 : 1; // Toggled by A* pathfinding code.
    unsigned Bit3_128 : 1;

    unsigned IsHorizontalLine : 1;
    unsigned IsVerticalLine : 1;
    unsigned Bit4_4 : 1; // Completely shrouded? Visually unclear?

private:
    // Copy and assignment not implemented; prevent their use by declaring as private.
    CellClass(const CellClass&);
    CellClass& operator=(const CellClass&);
};
