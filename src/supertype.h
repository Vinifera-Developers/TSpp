/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for super weapon types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "tibsun_defines.h"


class ShapeSet;
class ObjectClass;
class CCINIClass;
class WeaponTypeClass;
class BuildingTypeClass;


class DECLSPEC_UUID("0CF2BCE7-36E4-11D2-B8D8-006008C809ED")
SuperWeaponTypeClass : public AbstractTypeClass
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
    SuperWeaponTypeClass(const char* ini_name = nullptr);
    SuperWeaponTypeClass(const NoInitClass& noinit);
    virtual ~SuperWeaponTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;

    virtual ActionType What_Action(const Cell& cell, ObjectClass* object) const;

    static const SuperWeaponTypeClass* From_Action(ActionType action);

    static SuperWeaponType From_Name(const char* name);
    static const char* Name_From(SuperWeaponType type);
    static SuperWeaponTypeClass* Find_Or_Make(const char* name);

public:
    SuperWeaponType HeapID;
    WeaponTypeClass* Weapon;
    VoxType VoxRecharge;
    VoxType VoxCharging;
    VoxType VoxImpatient;
    VoxType VoxSuspend;
    int RechargeTime;
    SuperWeaponType Type;
    ShapeSet* SidebarIcon;
    ActionType Action;
    BuildingTypeClass* AuxBuilding;
    TStringID<24> SidebarImage;
    bool IsUseChargeDrain;
    bool IsPowered;
    bool IsManualControl;
};
