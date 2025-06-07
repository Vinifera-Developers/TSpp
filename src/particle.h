/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Particle class.
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

#include "always.h"
#include "object.h"
#include "rgb.h"
#include "vector3.h"
#include "tibsun_defines.h"


class ParticleTypeClass;
class ParticleSystemClass;


class DECLSPEC_UUID("0E272DCC-9C0F-11D1-B709-00A024DDAFD1")
ParticleClass : public ObjectClass
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
        ParticleClass();
        ParticleClass(ParticleTypeClass *classof, Coordinate &a2, Coordinate &a3 = Coordinate(0,0,0), ParticleSystemClass *particlesys = nullptr);
        ParticleClass(const NoInitClass &noinit);
        virtual ~ParticleClass();
        
        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual const ObjectTypeClass * Class_Of() const override;
        virtual Cell *Occupy_List(bool placement = false) const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;

        virtual int Shape_Number() const;

        void Smoke_Behavior_AI();
        void Railgun_Behavior_AI();
        void Gas_Behavior_AI();
        void Spark_Behavior_AI();
        void Fire_Behavior_AI();
        void Web_Behavior_AI();
        void Behaviour_AI();
        void Smoke_Coord_AI();
        void Gas_Coord_AI();
        void Fire_Coord_AI();
        void Coord_AI();

    public:
        ParticleTypeClass *Class;
        RGBClass Color;
        int field_54;
        double field_58;
        Coordinate field_60;
        Vector3 field_6C;
        Coordinate field_78;
        float Velocity;
        Coordinate field_88;
        Coordinate field_94;
        Coordinate field_A0;
        Vector3 field_AC;
        Vector3 field_B8;
        ParticleSystemClass *ParticleSystem;
        unsigned short RemainingEC;
        unsigned short RemainingDC;
        unsigned char StateAIAdvance;
        bool field_CD;
        unsigned char StateAI;
        unsigned char Translucency;
        bool field_D0;
        bool ToDelete;
};