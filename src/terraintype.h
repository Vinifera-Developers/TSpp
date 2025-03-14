/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TERRAINTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for terrain types.
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
#include "tibsun_defines.h"


class OverlayTypeClass;


class DECLSPEC_UUID("5AF2CE7B-0634-11D2-ACA4-006008055BB5")
TerrainTypeClass : public ObjectTypeClass
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
        TerrainTypeClass(const char *ini_name = nullptr);
        TerrainTypeClass(const NoInitClass &noinit);
        virtual ~TerrainTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Coordinate Coord_Fixup(Coordinate *coord) const override;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;
        virtual Cell *Occupy_List(bool placement = false) const override;

        static void Init(TheaterType theater);

        static const TerrainTypeClass &As_Reference(TerrainType type);
        static const TerrainTypeClass *As_Pointer(TerrainType type);
        static const TerrainTypeClass &As_Reference(const char *name);
        static const TerrainTypeClass *As_Pointer(const char *name);
        static TerrainType From_Name(const char *name);
        static const char *Name_From(TerrainType type);
        static const TerrainTypeClass *Find_Or_Make(const char *name);

    public:
		TerrainType Type;
        BSizeType Size;
        RGBStruct RadarColor;
        int AnimationRate;
        int AnimationProbability;
        int YDrawFudge;
        TiberiumType TiberiumToSpawn;
        unsigned TemperateOccupationBits;
        unsigned SnowOccupationBits;
		bool IsWaterBased;
		bool IsSpawnsTiberium;
		bool IsFlammable;
		bool IsAnimated;
		bool IsVeinhole;
		const Cell *Occupy;
};
