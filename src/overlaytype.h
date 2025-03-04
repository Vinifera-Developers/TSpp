/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OVERLAYTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for overlay types.
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


class AnimTypeClass;


class DECLSPEC_UUID("5AF2CE79-0634-11D2-ACA4-006008055BB5")
OverlayTypeClass : public ObjectTypeClass
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
        OverlayTypeClass(const char *ini_name = nullptr);
        OverlayTypeClass(const NoInitClass &noinit);
        virtual ~OverlayTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

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
        virtual ShapeFileStruct *const Get_Image_Data() const override;

        /**
         *  OverlayTypeClass
         */
        virtual void Draw_It(Point2D &xy, Rect &a2, int frame) const;

        RGBStruct Get_Radar_Color(int a1 = 0);
        
        static void Init(TheaterType theater = THEATER_TEMPERATE);

        static const OverlayTypeClass &As_Reference(OverlayType type);
        static const OverlayTypeClass *As_Pointer(OverlayType type);
        static const OverlayTypeClass &As_Reference(const char *name);
        static const OverlayTypeClass *As_Pointer(const char *name);
        static OverlayType From_Name(const char *name);
        static const char *Name_From(OverlayType type);
        static const OverlayTypeClass *Find_Or_Make(const char *name);

    public:
        OverlayType Type;
        LandType Land;
        AnimTypeClass *CellAnim;
        int DamageLevels;
        int DamagePoints;
        bool IsWall;
        bool IsHigh;
        bool IsTiberium;
        bool IsCrate;
        bool IsCrateTrigger;
        bool NoUseTileLandType;
        bool IsVeinholeMonster;
        bool IsVeins;
        bool IsDemandLoad;
        bool IsExplosive;
        bool IsChainReactive;
        bool IsPriority;
        bool DrawFlat;
        bool IsARock;
};
