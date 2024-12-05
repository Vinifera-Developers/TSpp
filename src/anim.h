/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ANIM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Animation game object class.
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
#include "bounce.h"
#include "tibsun_defines.h"


class AnimTypeClass;
class ConvertClass;


class DECLSPEC_UUID("0E272DC3-9C0F-11D1-B709-00A024DDAFD1")
AnimClass : public ObjectClass, public StageClass
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
        AnimClass();
        AnimClass(const AnimTypeClass *classof, const Coordinate &coord, unsigned timedelay = 0, unsigned loop = 1, unsigned flags = 0x600, int zadjust = 0);
        AnimClass(const NoInitClass &noinit);
        virtual ~AnimClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual Coordinate Center_Coord() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual int Sort_Y() const override;
        virtual bool Limbo() override;
        virtual void Remove_This() override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual Cell *Occupy_List(bool placement = false) const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        virtual int Get_Z_Coord() const override;

        /**
         *  AnimClass
         */
        virtual int entry_1A8();
        virtual int entry_1AC() const;

        operator AnimType () const;

        void Attach_To(ObjectClass *obj);
        void Start();
        void Middle();
        void Enable();
        void Disable();
        void Vein_Attack_AI();
        void Flaming_Guy_AI();
        // 00416E90
        // 00417270

        void Make_Invisible() { IsInvisible = true; }
        void Make_Visible() { IsInvisible = false; }

        static void Init();
        static void Do_Atom_Damage(HousesType ownerhouse, Cell &cell);

    public:
        AnimTypeClass *Class;
        TARGET xObject;
        HousesType OwnerHouse;
        ConvertClass *Drawer;
        unsigned TintColor;
        int ZAdjust;
        int YSortAdjust;
        Coordinate FlamingGuyCoords;
        int FlamingGuyRetries;
        bool IsBuildingAnim;
        BounceClass Bounce;
        char TranslucencyLevel;
        int Delay;
        double Accum;
        int ShapeFlags;
        bool field_FC;
        unsigned char Loops;
        bool IsAttachedToCell;
        bool field_FF;
        bool IsPlaying;
        bool IsFogged;
        bool field_102;
        bool IsToDelete;
        bool IsBrandNew;
        bool IsInvisible;
        bool IsEnabled;
};
