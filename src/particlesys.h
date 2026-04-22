/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Particle system class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    ParticleSystemClass();
    ParticleSystemClass(const ParticleSystemTypeClass* classof, const Coord& a2, AbstractClass* a3 = nullptr, AbstractClass* a4 = nullptr, const Coord& a5 = Coord(0, 0, 0));
    ParticleSystemClass(const NoInitClass& noinit);
    virtual ~ParticleSystemClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual bool Is_Inactive() const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual LayerType In_Which_Layer() const override;
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual void Delete_Me() override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;

    ParticleClass* Spawn_Held_Particle(const Coord& a1, const Coord& a2);
    ParticleClass* Spawn_Particle(ParticleTypeClass* particletype, const Coord& a2);
    ParticleClass* Spawn_Held_Particle_Random(const Coord& a1, const Coord& a2, int a3);
    bool Delete_Particle(int index);
    void Delete_All_Particles();
    void Gas_AI();
    void Spark_AI();
    void Smoke_AI();
    void Railgun_AI();
    void Fire_AI();
    void Web_AI();

public:
    ParticleSystemTypeClass* Class;
    Coord field_50;
    DynamicVectorClass<ParticleClass*> Particles;
    Coord SpawnCoord;
    AbstractClass* xObject;
    AbstractClass* Target;
    int SpawnFrames;
    int Lifetime;
    int SparkSpawnFrames;
    int field_94;
    bool field_98;
    bool field_99;
};
