/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TERRAIN.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Terrain game object class.
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

#include "object.h"
#include "stage.h"
#include "tibsun_defines.h"


class TerrainTypeClass;
class CCINIClass;


class DECLSPEC_UUID("0E272DCE-9C0F-11D1-B709-00A024DDAFD1")
TerrainClass : public ObjectClass, public StageClass
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
        TerrainClass();
        TerrainClass(TerrainTypeClass *classof, CellStruct &pos);
        TerrainClass(const NoInitClass &noinit);
        virtual ~TerrainClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(CoordStruct &coord, DirType dir = DIR_N) override;
        virtual void Set_Occupy_Bit(CoordStruct &coord) override;
        virtual void Clear_Occupy_Bit(CoordStruct &coord) override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual void Placement_Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        virtual Rect entry_118() const override;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false) override;
        virtual bool Catch_Fire() override;
        virtual void Fire_Out() override;
        virtual MoveType Can_Enter_Cell(const CellClass *cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass *a4 = nullptr, bool a5 = false) override;

        void Start_To_Crumble();
        bool Is_Animating() const;

        static void Read_INI(CCINIClass &ini);
        static void Write_INI(CCINIClass &ini);

    public:
        TerrainTypeClass *Class;
        bool IsOnFire;
        bool IsCrumbling;
        int field_6C;
        int field_70;
        Point2D DrawOffset;
};
