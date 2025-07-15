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
        AnimClass(const AnimTypeClass *classof, const Coord &coord, unsigned timedelay = 0, unsigned loop = 1, unsigned flags = 0x600, int zadjust = 0);
        AnimClass(const NoInitClass &noinit);
        virtual ~AnimClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual Coord Center_Coord() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual const ObjectTypeClass * Class_Of() const override;
        virtual int Sort_Y() const override;
        virtual bool Limbo() override;
        virtual void Delete_Me() override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual Cell *Occupy_List(bool placement = false) const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        virtual int Get_Height() const override;

        /**
         *  AnimClass
         */
        virtual int Bounce_AI();
        virtual int Stage_Count() const;

        void Attach_To(ObjectClass *obj);
        void Start();
        void Middle();
        void Disable();
        void Enable();
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
        ObjectClass * xObject;
        HousesType OwnerHouse;
        ConvertClass *AlternativeDrawer;
        unsigned AlternativeBrightness;
        int ZAdjust;
        int YSortAdjust;
        Coord FlamingGuyCoords;
        int FlamingGuyRetries;
        bool IsBuildingAnim;
        BounceClass Bounce;
        char TranslucencyLevel;
        int Delay;
        double Accum;
        int ShapeFlags;
        bool IsDebris;
        unsigned char Loops;
        bool IsAttachedToCell;
        bool field_FF;
        bool IsInert;
        bool IsFogged;
        bool field_102;
        bool IsToDelete;
        bool IsBrandNew;
        bool IsInvisible;
        bool IsDisabled;
};

void Shorten_Attached_Anims();
