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
#include "vector.h"
#include "tibsun_defines.h"


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


class DECLSPEC_UUID("C1BF99CE-1A8C-11D2-8175-006008055BB5")
CellClass : public AbstractClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

        /**
         *  IRTTITypeInfo
         */
        IFACEMETHOD_(int, What_Am_I)();

    public:
        CellClass();
        CellClass(const NoInitClass &x);
        virtual ~CellClass();

        int operator != (const CellClass & cell) const { return cell.Pos != Pos; }
        int operator == (const CellClass & cell) const { return cell.Pos == Pos; }

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual Coordinate Center_Coord() const override;
        virtual Coordinate entry_5C() const override;

        int Get_Height(const Coordinate &coord) const;
        // 00451900
        // 00451AF0
        ObjectClass *Cell_Find_Object(RTTIType rtti, bool a2 = false) const;
        ObjectClass *const Cell_Object(const Point2D &xy = Point2D(), bool a2 = false) const;
        TechnoClass *const Cell_Techno(const Point2D &xy = Point2D(), bool a2 = false, TechnoClass *a3 = nullptr) const;
        UnitClass *const Cell_Unit(bool a2 = false) const;
        AircraftClass *const Cell_Aircraft(bool a2 = false) const;
        InfantryClass *const Cell_Infantry(bool a2 = false) const;
        BuildingClass *const Cell_Building(bool a2 = false) const;
        TerrainClass *const Cell_Terrain(bool a2 = false) const;
        bool Is_Clear_To_Build(SpeedType loco, const BuildingTypeClass *buildtype = nullptr, const HouseClass *house = nullptr);
        // 004526A0
        // 004531A0
        void Recalc_Attributes(int level = -1);
        // 00453CF0
        // 00453FB0
        // 004543E0
        void Occupy_Down(ObjectClass *object, bool a2 = false);
        void Occupy_Up(ObjectClass *object, bool a2 = false);
        // 00454B80
        // 00454E60
        // 00455130
        // 00455450
        // 004555E0
        // 00455B30
        // 00455E40
        Rect Get_Rect() const;
        // 00456270
        // 00456300
        // 00456370
        // 00456420
        // 004564D0
        // 00456690
        void Wall_Update(bool a1 = false);
        Coordinate Cell_Coord() const;
        int Reduce_Tiberium(int levels);
        int Reduce_Wall(int damage);
        bool Is_Spot_Free(int spot_index, bool a2 = false) const;
        Coordinate Closest_Free_Spot(Coordinate &coord, bool a2 = false, bool a3 = false) const;
        // 00457600
        // 00457650
        void Incoming(Coordinate &threat = Coordinate(), bool forced = false, bool no_kidding = false, bool a4 = false);
        CellClass &Adjacent_Cell(FacingType facing) const;
        void Adjust_Threat(HousesType house, int threat_value);
        long Tiberium_Adjust(bool pre_game = false);
        bool Goodie_Check(FootClass *object = nullptr);
        bool Flag_Place(HousesType house);
        bool Flag_Remove();
        void Shimmer();
        bool Is_Clear_To_Move(SpeedType loco, bool ignore_infantry = false, bool ignore_vehicles = false, int zone = -1, MZoneType check = MZONE_NORMAL, int cell_level = -1, bool a7 = true);
        bool Is_Bridge_Here() const;
        bool Can_Tiberium_Grow() const;
        bool Can_Tiberium_Spread() const; 
        bool Grow_Tiberium();
        bool Spread_Tiberium(bool forced = false);
        bool Can_Tiberium_Germinate(TiberiumClass *tiberium = nullptr) const;
        // 00459A00
        // 00459B80
        // 00459D90
        // 00459EC0
        // 0045A310
        // 0045A4A0
        // 0045A670
        // 0045A680
        // 0045A6A0
        // 0045A6D0
        // 0045A930
        // 0045AAD0
        // 0045AAE0
        // 0045AB10
        // 0045ABA0
        // 0045AC10
        // 0045AC70
        // 0045ACB0
        // 0045ACD0
        void Detach(TARGET target);
        // 0045AE90
        void Attach_Tag(TagClass *tag);
        // 0045AF20
        // 0045B000
        // 0045B0D0
        // 0045B200
        // 0045B760
        // 0045BFF0
        // 0045C010
        // 0045C040
        // 0045C220
        // 0045C240
        // 0045C2C0
        // 0045C2F0
        // 0045C310
        // 0045C330
        // 0045C370
        // 0045C390
        // 0045C3B0
        // 0045C3D0
        // 0045C3F0
        // 0045C410
        // 0045C430
        // 0045C450
        // 0045C470
        // 0045C490
        // 0045C4E0
        // 0045C530
        // 0045C5A0
        // 0045C5C0
        // 0045C700
        // 0045C880
        // 0045C8E0
        // 0045CA20
        // 0045CAC0
        // 0045CB00
        // 0045CC80
        // 0045CD30
        // 0045CD50
        // 0045CD70
        // 0045CD90
        // 0045CDB0
        // 0045CDD0
        // 0045CDF0
        // 0045D290
        // 0045D4A0
        // 0045D500
        // 0045D560
        // 0045D720

        LandType Land_Type() const { return Land; }

        static int Spot_Index(Coordinate &coord);

    public:
        Cell Pos;
        DynamicVectorClass<FoggedObjectClass *> *field_18;
        int field_1C;
        int field_20;
        LightConvertClass *field_24;
        IsometricTileType Tile;
        TagClass *CellTag;
        OverlayType Overlay;
        SmudgeType Smudge;
        int field_38;
        HousesType Owner;
        HousesType InfType;
        HousesType field_44;
        int field_48;
        int field_4C;
        int field_50;
        Rect field_54;
        int field_64;
        int field_68;
        int field_6C;
        ObjectClass *OccupierPtr;
        ObjectClass *field_74;
        LandType Land;
        int field_7C;
        unsigned short field_80;
        wRGBStruct field_82;
        wRGBStruct field_88;
        short field_8E;
        unsigned char field_90;
        unsigned char IsIceGrowthAllowed;
        unsigned char Height;
        unsigned char Level;
        unsigned char field_94;
        unsigned char field_95;
        unsigned char OverlayData;
        unsigned char SmudgeData;
        unsigned char field_98;
        unsigned char field_99;
        unsigned char field_9A;

        union {
            struct {
                unsigned Center:1;
                unsigned NW:1;
                unsigned NE:1;
                unsigned SW:1;
                unsigned SE:1;
                unsigned Vehicle:1;         // Reserved for vehicle occupation.
                unsigned Monolith:1;        // Some immovable blockage is in cell.
                unsigned Building:1;        // A building of some time (usually blocks movement).
            } Occupy;
            unsigned char Composite;
        } Flag;

        union {
            struct {
                unsigned Center:1;
                unsigned NW:1;
                unsigned NE:1;
                unsigned SW:1;
                unsigned SE:1;
                unsigned Vehicle:1;         // Reserved for vehicle occupation.
                unsigned Monolith:1;        // Some immovable blockage is in cell.
                unsigned Building:1;        // A building of some time (usually blocks movement).
            } Occupy;
            unsigned char Composite;
        } AltFlag;

        unsigned IsPlot:1;
        unsigned IsCursorHere:1;
        unsigned IsMapped:1;
		unsigned IsVisible:1;
        unsigned IsFogMapped:1;
        unsigned IsFogVisible:1;
        unsigned IsWaypoint:1;
        unsigned IsRadarCursor:1;

        unsigned IsFlagged:1;
        unsigned IsToShroud:1;
        unsigned Bit2_4:1;
        unsigned Bit2_8:1;              // is the starting point of a bridge connection? (from start to end?)
        unsigned Bit2_16:1;             // is covered by bridge overlay?
        unsigned Bit2_32:1;             // is covered by bridge overlay? also
        unsigned Bit2_64:1;             // unrepaired/repairable bridge connection.
        unsigned Bit2_128:1;            // draws on cells that are the length of the bridge body. (low down?)

        unsigned Bit3_1:1;              // draws on cells that are the length of the bridge body. (high up?)
        unsigned Bit3_2:1;
        unsigned Bit3_4:1;              // Is ice edge? Flagged when smoothing required.
        unsigned Bit3_8:1;
        unsigned IsOvershadowed:1;      // Casts shadow? or Overcasted with shadow?
        unsigned IsAnimAttached:1;
        unsigned Bit3_64:1;             // Toggled by A* pathfinding code.
        unsigned Bit3_128:1;

        unsigned Bit4_1:1;              // Has horizontal tag?
        unsigned Bit4_2:1;              // Has vertical tag?
        unsigned Bit4_4:1;              // Completely shrouded? Visually unclear?

    private:
        // Copy and assignment not implemented; prevent their use by declaring as private.
        CellClass(const CellClass &);
        CellClass &operator=(const CellClass &);
};
