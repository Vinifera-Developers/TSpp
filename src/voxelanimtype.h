/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for voxel anim types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "objecttype.h"
#include "tibsun_defines.h"


class AnimTypeClass;
class WarheadTypeClass;
class ParticleSystemTypeClass;


class DECLSPEC_UUID("2EBB6D66-0D4D-11D2-8172-006008055BB5")
VoxelAnimTypeClass : public ObjectTypeClass
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
    VoxelAnimTypeClass(const char* ini_name = nullptr);
    VoxelAnimTypeClass(const NoInitClass& noinit);
    virtual ~VoxelAnimTypeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
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

    static VoxelAnimType From_Name(const char* name);
    static const char* Name_From(VoxelAnimType type);
    static VoxelAnimTypeClass *Find_Or_Make(const char* name);

public:
    bool IsNormalized;
    bool IsTranslucent;
    bool IsSharesSourceData;
    int VoxelIndex;
    int Duration;
    double Elasticity;
    double MinAngularVelocity;
    double MaxAngularVelocity;
    double MinZVel;
    double MaxZVel;
    double MaxXYVel;
    bool IsMeteor;
    VoxelAnimTypeClass* Spawns;
    int SpawnCount;
    VocType StartSound;
    VocType BounceSound;
    VocType ExpireSound;
    AnimTypeClass* BounceAnim;
    AnimTypeClass* ExpireAnim;
    AnimTypeClass* TrailerAnim;
    int Damage;
    int DamageRadius;
    WarheadTypeClass* Warhead;
    ParticleSystemTypeClass* AttachedSystem;
    bool IsTiberium;
};
