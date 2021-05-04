/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WAVE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for graphical wave types.
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
#include "facing.h"
#include "vector.h"
#include "matrix3d.h"
#include "tibsun_defines.h"


class CellClass;


class DECLSPEC_UUID("0E272DCD-9C0F-11D1-B709-00A024DDAFD1")
WaveClass : public ObjectClass
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
        WaveClass();
        WaveClass(CoordStruct &from, CoordStruct &to, TARGET a3, WaveType type, TARGET source);
        WaveClass(const NoInitClass &noinit);
        virtual ~WaveClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(CoordStruct &coord, DirType dir = DIR_N) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;

        void Sonic_AI();
        void Laser_AI();
        void func_6709C0(CellStruct &cell); // add cell?
        void Sonic_Draw_It(Point2D &xy, Rect &rect) const; // draw sonic beam?
        void Laser_Draw_It(Point2D &xy, Rect &rect) const; // draw laser beam?
        void func_670370(int a1, int a2, int a3, int a4); // blend sonic beam?
        void func_670650(); // default sonic beam colour?
        void func_670840(CoordStruct &coord); // sonic beam damage update/ai?
        void func_671C40(); // update cells under sonic beam? or start and end cells?
        void func_672AA0(); // update sonic beam/beam ai?
        void func_672160();

        static void func_670580(); // recalc tables?
        static void func_6704B0(int a1, int a2); // do wave beam colouring? (inlined in above function perhaps?)

    private:
        TARGET xTarget;
        WaveType Type;
        CoordStruct field_54;
        CoordStruct field_60;
        Point2D field_6C; // initial wave pixel start
        Point2D field_74; // initial wave pixel end
        Point2D field_7C; // initial wave pixel end left
        Point2D field_84; // initial wave pixel end right
        Point2D field_8C; // initial wave pixel start left
        Point2D field_94; // initial wave pixel start right
        CoordStruct field_9C;
        CoordStruct field_A8;
        CoordStruct field_B4;
        CoordStruct field_C0;
        bool field_CC;
        int SonicEC;
        double field_D8; // sonic starting percent
        double field_E0; // sonic ending percent
        int field_E8;
        int field_EC;
        Point2D field_F0; // active wave pixel start
        Point2D field_F8; // active wave pixel end
        Point2D field_100; // active wave pixel end left
        Point2D field_108; // active wave pixel end right
        Point2D field_110; // active wave pixel start left
        Point2D field_118; // active wave pixel start right
        int field_120;
        int field_124;
        int field_128;
        int field_12C[FACING_COUNT];
        FacingType field_14C;
        int LaserEC;
        TARGET xObject;
        FacingClass field_158;
        DynamicVectorClass<CellClass *> field_170;
        int field_188[13]; // current wave effect table or intensity table?
};
