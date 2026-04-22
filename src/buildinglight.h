/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Building spotlight class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    BuildingLightClass(TechnoClass* source = nullptr);
    BuildingLightClass(const NoInitClass& noinit);
    virtual ~BuildingLightClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = false) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual LayerType In_Which_Layer() const override;
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual bool Limbo() override;
    virtual bool Unlimbo(const Coord& coord, Dir256 dir = DIR_N) override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;

    // 00422BA0
    void Set_Behavior(SpotlightBehaviorType behavior);
    // 00422EE0
    // 00422FC0

public:
    double Speed;
    Coord Coord1;
    Coord Coord2;
    double Acceleration;
    bool SweepToggle;
    SpotlightBehaviorType Behavior;
    TechnoClass* Following;
    TechnoClass* Source;
};
