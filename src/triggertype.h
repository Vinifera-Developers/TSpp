/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for trigger types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "tibsun_defines.h"


class TEventClass;
class TActionClass;
class HouseTypeClass;


class DECLSPEC_UUID("C02D1591-0A2A-11D2-ACA7-006008055BB5")
TriggerTypeClass : public AbstractTypeClass
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
    TriggerTypeClass(const char* ini_name = nullptr);
    TriggerTypeClass(const NoInitClass& noinit);
    virtual ~TriggerTypeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;
    virtual bool Write_INI(CCINIClass& ini) const override;

    // 00649F30
    // 00649F50
    // 00649F70
    // 00649F90
    // 00649FB0
    // 00649FF0
    AttachType Attaches_To() const;
    bool Remove_Action(TActionClass* action);
    bool Remove_Event(TEventClass* event);

    static void Read_Scenario_INI(CCINIClass& ini);
    static void Write_Scenario_INI(CCINIClass& ini);

    static TriggerType From_Name(const char* name);
    static const char* Name_From(TriggerType type);
    static TriggerTypeClass* Find_Or_Make(const char* name);

public:
    TriggerType HeapID;
    bool Enabled;
    bool IsEnabledEasy;
    bool IsEnabledMedium;
    bool IsEnabledHard;
    PersistantType IsPersistant;
    HouseTypeClass* House;
    TriggerTypeClass* Next;
    TEventClass* Event;
    TActionClass* Action;
};
