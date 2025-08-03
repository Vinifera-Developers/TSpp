/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLESYSTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for particle system types.
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
#include "rgb.h"
#include "tibsun_defines.h"
#include "typelist.h"


class DECLSPEC_UUID("703E044A-0FB1-11D2-8172-006008055BB5")
ParticleSystemTypeClass : public ObjectTypeClass
{
public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    ParticleSystemTypeClass(const char* ini_name = nullptr);
    ParticleSystemTypeClass(const NoInitClass& noinit);
    virtual ~ParticleSystemTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;

    /**
     *  ObjectTypeClass
     */
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;

    static ParticleSystemType From_Name(const char* name);
    static const char* Name_From(ParticleSystemType type);
    static const ParticleSystemTypeClass* Find_Or_Make(const char* name);

public:
    ParticleType HoldsWhat;
    bool Spawns;
    int SpawnFrames;
    float Slowdown;
    int ParticleCap;
    int SpawnRadius;
    float SpawnCutoff;
    float SpawnTranslucencyCutoff;
    ParticleBehaviourType BehavesLike;
    int Lifetime;
    Point3D SpawnDirection;
    double ParticlesPerCoord;
    double SpiralDeltaPerCoord;
    double SpiralRadius;
    double PositionPerturbationCoefficient;
    double MovementPerturbationCoefficient;
    double VelocityPerturbationCoefficient;
    double SpawnSparkPercentage;
    int SparkSpawnFrames;
    int LightSize;
    RGBStruct LaserColor;
    bool Laser;
    bool OneFrameLight;
};
