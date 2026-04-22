/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for weapon types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "typelist.h"


class AnimTypeClass;
class ParticleSystemTypeClass;


class DECLSPEC_UUID("A8C54DA4-0F7B-11D2-8172-006008055BB5")
WarheadTypeClass : public AbstractTypeClass
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
    WarheadTypeClass(const char* ini_name = nullptr);
    WarheadTypeClass(const NoInitClass& noinit);
    virtual ~WarheadTypeClass();

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

    static WarheadType From_Name(const char* name);
    static const char* Name_From(WarheadType type);
    static WarheadTypeClass* Find_Or_Make(const char* name);

public:
    double Deform;
    double Modifier[ARMOR_COUNT];
    double ProneFactor;
    int DeformThreshhold;
    TypeList<AnimTypeClass*> AnimList;
    int InfantryDeath;
    int SpreadFactor;
    int WebDuration;
    int WebDurationVariation;
    int WebRadius;
    int LimpetFactor;
    ParticleSystemTypeClass* Particle;
    bool IsWallDestroyer;
    bool IsWebby;
    bool IsWoodDestroyer;
    bool IsTiberiumDestroyer;
    bool IsOrganic;
    bool IsSparky;
    bool IsFire;
    bool IsConventional;
    bool IsRocker;
    bool IsBright;
    bool IsEMEffect;
    bool IsVeinhole;
};
