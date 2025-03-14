/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FOGGEDOBJECT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Fogged (Fog of War) object class.
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


class ObjectTypeClass;
class BuildingClass;
class TerrainClass;


class DECLSPEC_UUID("1C470B0E-69D7-11D2-B8F2-006008C809ED")
FoggedObjectClass : public AbstractClass
{
    public:
        typedef struct DrawRecord
        {
            ObjectTypeClass *TypeClass;
            int Frame;
            int HeightAdjust;
            int ZAdjust;
        } DrawRecord;

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
        FoggedObjectClass();
        FoggedObjectClass(Coordinate &coord, OverlayType overlay, int overlay_data);
        FoggedObjectClass(Coordinate &coord, SmudgeType smudge, int smudge_data);
        FoggedObjectClass(const BuildingClass *building, bool to_draw = false);
        FoggedObjectClass(const TerrainClass *terrain);
        FoggedObjectClass(NoInitClass &noinit);
        virtual ~FoggedObjectClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool a1 = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        virtual Cell Get_Cell() const;

        Cell *Get_Occupy_List() const;
        const ObjectTypeClass *Get_Object() const;

        static void Draw_All();
        static void Update_All();

    public:
        OverlayType Overlay;
        HouseClass *Owner;
        int OverlayData;
        RTTIType RTTI;
        Coordinate Coord;
        Rect BoundingRect;
        int CellLevel;
        SmudgeType Smudge;
        int SmudgeData;
        DynamicVectorClass<DrawRecord *> Records;
        bool ToDraw;
};
