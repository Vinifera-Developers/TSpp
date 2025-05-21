/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELANIM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Voxel animation game object class.
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
#include "bounce.h"


class HouseClass;
class VoxelAnimTypeClass;
class ParticleSystemClass;


class DECLSPEC_UUID("0E272DC1-9C0F-11D1-B709-00A024DDAFD1")
VoxelAnimClass : public ObjectClass
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
        VoxelAnimClass();
        VoxelAnimClass(const VoxelAnimTypeClass *classof, const Coordinate &coord, HouseClass *house = nullptr);
        VoxelAnimClass(const NoInitClass &noinit);
        virtual ~VoxelAnimClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual const ObjectTypeClass * Class_Of() const override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual Cell *Occupy_List(bool placement = false) const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;

        void Make_Invisible() { IsInvisible = true; }
        void Make_Visible() { IsInvisible = false; }

        static void Init();

    public:
        int field_4C;
        BounceClass Bouncer;
        int field_A0; // looks unused
        VoxelAnimTypeClass *Class;
        ParticleSystemClass *AttachedParticleSys;
        HouseClass *House;
        bool field_B0; // time to die (on next update)?   // expired?
        bool IsInvisible;
        int field_B4; // duration? counting down to zero
};
