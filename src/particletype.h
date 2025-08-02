/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLETYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for particle types.
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
#include "typelist.h"
#include "rgb.h"
#include "tibsun_defines.h"


class WarheadTypeClass;
class ParticleTypeClass;


class DECLSPEC_UUID("703E044B-0FB1-11D2-8172-006008055BB5")
ParticleTypeClass : public ObjectTypeClass
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
        ParticleTypeClass(const char *ini_name = nullptr);
        ParticleTypeClass(const NoInitClass &noinit);
        virtual ~ParticleTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true);
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;

        static ParticleType From_Name(const char *name);
        static const char *Name_From(ParticleType type);
        static const ParticleTypeClass *Find_Or_Make(const char *name);

    public:
        Point3D NextParticleOffset;
        int XVelocity;
        int YVelocity;
        int MinZVelocity;
        int ZVelocityRange;
        double ColorSpeed;
        TypeList<RGBClass> ColorList;
        RGBStruct StartColor1;
        RGBStruct StartColor2;
        int MaxDC;
        int MaxEC;
        WarheadTypeClass *Warhead;
        int Damage;
        int StartFrame;
        int NumLoopFrames;
        int Translucency;
        int WindEffect;
        float Velocity;
        float Deacc;
        int Radius;
        bool DeleteOnStateLimit;
        unsigned char EndStateAI;
        unsigned char StartStateAI;
        unsigned char StateAIAdvance;
        unsigned char FinalDamageState;
        unsigned char Translucent25State;
        unsigned char Translucent50State;
        bool IsNormalized;
        ParticleTypeClass *NextParticle;
        ParticleBehaviourType BehavesLike;
};
