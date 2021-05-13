/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BULLET.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Projectile game object class.
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
#include "fuse.h"


class BulletTypeClass;


struct FlyClass
{
    DirStruct Direction();
    double Distance_2D();
    double Distance_3D();
    double Distance_2D_0();
    void Update_Position(DirStruct &dir);
    void If_XYZ_0_Set_X_100();
    void If_XY_0_Set_X_100();

    double field_88; // x?
    double field_90; // y?
    double field_98; // z?
};


int Projectile_Motion(Coordinate &a1, FlyClass &a2, Coordinate &a3, DirStruct &dir, bool is_aircraft, bool is_airburst, bool is_very_high);


class DECLSPEC_UUID("0E272DC9-9C0F-11D1-B709-00A024DDAFD1")
BulletClass :	public ObjectClass
{
    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD_(ULONG, AddRef)();
        IFACEMETHOD_(ULONG, Release)();

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
        BulletClass();
        BulletClass(BulletType id, TARGET target, TechnoClass *payback, int strength, WarheadType warhead, int speed);
        BulletClass(const NoInitClass &noinit);
        virtual ~BulletClass();

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
        virtual CellStruct *Occupy_List(bool placement = false) const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;

        /**
         *  BulletClass
         */
        virtual int Shape_Number() const;
        virtual void Assign_Target(TARGET target);
        virtual bool Unlimbo(Coordinate &coord, FlyClass &flyer);

        // 00444580
        bool Is_Forced_To_Explode(Coordinate &coord) const;
        void Bullet_Explodes(bool forced);
        // 00446640
        bool Homes_In() const; // 00447210
        // 004472C0

        static BulletClass *Create_Bullet(BulletTypeClass *type, TARGET target, TechnoClass *payback, int strength, WarheadTypeClass *warhead, int max_speed, int range, bool bright); // 00447220

    public:
        BulletTypeClass *Class;
        TechnoClass *Payback;
        bool IsInaccurate;
        FuseClass Fuse;
        bool IsBright;
        FlyClass Fly;
        int field_A0;
        bool field_A4;
        bool field_A45;
        TARGET TarCom;
        int MaxSpeed;
        int field_B0;
        double field_B8;
        WarheadTypeClass *Warhead;
        unsigned char AnimFrame;
        unsigned char AnimFrameDelay;
        int Range;
};
