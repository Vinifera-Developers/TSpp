/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLESYS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Particle system class.
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
#include "vector.h"


class ParticleClass;
class ParticleTypeClass;
class ParticleSystemTypeClass;


class ParticleSystemClass : public ObjectClass
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
        ParticleSystemClass();
        ParticleSystemClass(const ParticleSystemTypeClass *classof, Coordinate &a2, TARGET a3 = nullptr, TARGET a4 = nullptr, Coordinate &a5 = Coordinate(0,0,0));
        ParticleSystemClass(const NoInitClass &noinit);
        virtual ~ParticleSystemClass();
        
        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual bool Is_Inactive() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual void entry_E4() override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;

        ParticleClass *Spawn_Held_Particle(Coordinate &a1, Coordinate &a2);
        ParticleClass *Spawn_Particle(ParticleTypeClass *particletype, Coordinate &a2);
        ParticleClass *Spawn_Held_Particle_Random(Coordinate &a1, Coordinate &a2, int a3);
        bool Delete_Particle(int index);
        void Delete_All_Particles();
        void Gas_AI();
        void Spark_AI();
        void Smoke_AI();
        void Railgun_AI();
        void Fire_AI();
        void Web_AI();

    public:
        ParticleSystemTypeClass *Class;
        Coordinate field_50;
        DynamicVectorClass<ParticleClass *> Particles;
        Coordinate SpawnCoord;
        TARGET xObject;
        TARGET Target;
        int SpawnFrames;
        int Lifetime;
        int SparkSpawnFrames;
        int field_94;
        bool field_98;
        bool field_99;
};