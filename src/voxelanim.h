/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Voxel animation game object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "bounce.h"
#include "object.h"


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
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    VoxelAnimClass();
    VoxelAnimClass(const VoxelAnimTypeClass* classof, const Coord& coord, HouseClass* house = nullptr);
    VoxelAnimClass(const NoInitClass& noinit);
    virtual ~VoxelAnimClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual LayerType In_Which_Layer() const override;
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual bool Render(Rect& rect, bool force = false, bool a3 = false) override;
    virtual Cell* Occupy_List(bool placement = false) const override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;

    void Make_Invisible() { IsInvisible = true; }
    void Make_Visible() { IsInvisible = false; }

    static void Init();

public:
    int field_4C;
    BounceClass Bouncer;
    int field_A0; // looks unused
    VoxelAnimTypeClass* Class;
    ParticleSystemClass* AttachedParticleSys;
    HouseClass* House;
    bool field_B0; // time to die (on next update)?   // expired?
    bool IsInvisible;
    int field_B4; // duration? counting down to zero
};
