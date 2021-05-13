/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUILDINGLIGHT.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Building spotlight class.
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
#include "tibsun_defines.h"


class TechnoClass;


class DECLSPEC_UUID("54822258-D8A8-11D1-B462-006097C6A979")
BuildingLightClass : public ObjectClass
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
        BuildingLightClass(TechnoClass *source = nullptr);
        BuildingLightClass(const NoInitClass &noinit);
        virtual ~BuildingLightClass();
        
        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = false) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(Coordinate &coord, DirType dir = DIR_N) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;

        // 00422BA0
        void Set_Behavior(SpotlightBehaviorType behavior);
        // 00422EE0
        // 00422FC0

    public:
        double Speed;
        Coordinate Coord1;
        Coordinate Coord2;
        double Acceleration;
        bool SweepToggle;
        SpotlightBehaviorType Behavior;
        TechnoClass *Following;
        TechnoClass *Source;
};