/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Particle class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "object.h"
#include "rgb.h"
#include "tibsun_defines.h"
#include "vector3.h"


class ParticleTypeClass;
class ParticleSystemClass;


class DECLSPEC_UUID("0E272DCC-9C0F-11D1-B709-00A024DDAFD1")
ParticleClass : public ObjectClass
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
    ParticleClass();
    ParticleClass(ParticleTypeClass* classof, Coord& a2, Coord& a3 = Coord(0, 0, 0), ParticleSystemClass* particlesys = nullptr);
    ParticleClass(const NoInitClass& noinit);
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
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual Cell* Occupy_List(bool placement = false) const override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;
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
    ParticleTypeClass* Class;
    RGBClass Color;
    int field_54;
    double field_58;
    Coord field_60;
    Vector3 field_6C;
    Coord field_78;
    float Velocity;
    Coord field_88;
    Coord field_94;
    Coord field_A0;
    Vector3 field_AC;
    Vector3 field_B8;
    ParticleSystemClass* ParticleSystem;
    unsigned short RemainingEC;
    unsigned short RemainingDC;
    unsigned char StateAIAdvance;
    bool field_CD;
    unsigned char StateAI;
    unsigned char Translucency;
    bool field_D0;
    bool ToDelete;
};
