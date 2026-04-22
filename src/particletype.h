/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for particle types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "objecttype.h"
#include "rgb.h"
#include "tibsun_defines.h"
#include "typelist.h"


class WarheadTypeClass;
class ParticleTypeClass;


class DECLSPEC_UUID("703E044B-0FB1-11D2-8172-006008055BB5")
ParticleTypeClass : public ObjectTypeClass
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
    ParticleTypeClass(const char* ini_name = nullptr);
    ParticleTypeClass(const NoInitClass& noinit);
    virtual ~ParticleTypeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true);
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

    static ParticleType From_Name(const char* name);
    static const char* Name_From(ParticleType type);
    static ParticleTypeClass* Find_Or_Make(const char* name);

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
    WarheadTypeClass* Warhead;
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
    ParticleTypeClass* NextParticle;
    ParticleBehaviourType BehavesLike;
};
