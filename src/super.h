/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Special weapon handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "ftimer.h"
#include "supertype.h"
#include "tibsun_defines.h"
#include "ttimer.h"


class HouseClass;
class SuperWeaponTypeClass;


class DECLSPEC_UUID("D7F754C6-391C-11D2-9B64-00104B972FE8")
SuperClass : public AbstractClass
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

    /**
     *  IRTTITypeInfo
     */
    IFACEMETHOD_(int, What_Am_I)();

public:
    SuperClass();
    SuperClass(const SuperWeaponTypeClass* classof, HouseClass* house);
    SuperClass(const NoInitClass& x);
    virtual ~SuperClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    bool AI(bool player = false);

    bool Suspend(bool on);
    bool Enable(bool onetime = false, bool player = false, bool quiet = false);
    void Forced_Charge(bool player = false);
    bool Remove();
    bool Recharge(bool player = false);
    void Impatient_Click() const;
    int Anim_Stage() const;
    bool Discharged(bool player, Cell& cell = Cell(0, 0));
    const char* Ready_String() const;
    bool Can_Place() const;
    void Set_Readiness(bool ready) { IsReady = ready; }
    bool Is_Ready() const { return IsReady; }
    bool Is_Present() const { return IsPresent; }
    bool Is_One_Time() const { return IsOneTime && IsPresent; }
    bool Is_Powered() const;
    bool Needs_Redraw() const;

    void Place(Cell* cell, bool player = false);

    char const* Name() const;

public:
    SuperWeaponTypeClass* Class;
    HouseClass* House;
    CDTimerClass<FrameTimerClass> Control;
    bool field_28;
    bool IsPresent;
    bool IsOneTime;
    bool IsReady;
    bool IsSuspended;
    int OldStage;
    int field_34;
};
