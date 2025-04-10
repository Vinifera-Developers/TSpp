/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ISOTILETYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for isometric tile types.
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

#include "objecttype.h"
#include "vector.h"
#include "tibsun_defines.h"


class CCINIClass;
class AnimTypeClass;


class DECLSPEC_UUID("5AF2CE7A-0634-11D2-ACA4-006008055BB5")
IsometricTileTypeClass : public ObjectTypeClass
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

    public:
        IsometricTileTypeClass(IsometricTileType type, char a2 = 0, char a3 = 0, const char *ini_name = nullptr, bool a5 = true);
        IsometricTileTypeClass(const NoInitClass &noinit);
        virtual ~IsometricTileTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        /**
         *  ObjectTypeClass
         */
        virtual Coordinate Coord_Fixup(Coordinate *coord) const;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;
        virtual Cell *Occupy_List(bool placement = false) const override;

    private:
        // Use Get_Tile_Data instead for IsometricTileTypeClass.
        virtual ShapeSet *const Get_Image_Data() const;

    public:
        IsoTileFileStruct *const Get_Tile_Data() const { return (IsoTileFileStruct *)IsometricTileTypeClass::Get_Image_Data(); }

        // 004F34B0
        // 004F34F0
        void Load_Image_Data();
        // 004F36B0
        // 004F36E0
        // 004F3720
        // 004F3880
        // 004F3890
        // 004F39E0
        // 004F56D0
        // 004F5940
        // 004F5A20
        // 004F5A60
        // 004F5AC0
        // 004F5B00
        // 004F5B40
        // 004F5CB0
        // 004F6630
        // 004F8160
        // 004F8330
        // 004F8390
        // 004F8460
        // 004F8740
        // 004F8770
        // 004F87B0
        // 004F8A40
        // 004F8A70

        static const IsometricTileTypeClass &As_Reference(IsometricTileType type);
        static const IsometricTileTypeClass *As_Pointer(IsometricTileType type);
        static const IsometricTileTypeClass &As_Reference(const char *name);
        static const IsometricTileTypeClass *As_Pointer(const char *name);
        static IsometricTileType From_Name(const char *name);
        static const char *Name_From(IsometricTileType type);

    public:
        IsometricTileType HeapID;
        IsometricTileType MarbleMadness;
        IsometricTileType NonMarbleMadness;
        int field_130;
        DynamicVectorClass<unsigned short *> field_134;
        IsometricTileTypeClass *NextTileTypeInSet;
        IsometricTileType ToSnowTheater;
        IsometricTileType ToTemperateTheater;
        AnimType Anim;
        int XOffset;
        int YOffset;
        int AttachesTo;
        int ZAdjust;
        int field_16C;
        bool IsMorphable;
        bool IsShadowCaster;
        bool IsAllowToPlace;
        bool IsRequiredForRMG;
        int TileBlockHeight;
        int TileBlockWidth;
        int field_17C;
        int TilesInSequence;
        bool IsFileLoaded;
        char Filename[12 + 4];
        bool IsAllowBurrowing;
        bool IsAllowTiberium;
        int field_198;
};
