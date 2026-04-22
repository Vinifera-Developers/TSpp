/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Map trigger events.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "ftimer.h"
#include "tibsun_defines.h"
#include "ttimer.h"


class NoInitClass;
class ObjectClass;
class TechnoClass;
class TeamTypeClass;


class DECLSPEC_UUID("4F0EC393-0A55-11D2-ACA7-006008055BB5")
TEventClass : public AbstractClass
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
    TEventClass();
    TEventClass(TEventType event);
    TEventClass(const NoInitClass& noinit);
    ~TEventClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = false) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    void Read_INI();
    void Build_INI_Entry(char* buffer) const;

    bool Is_Temporal() const;
    bool Has_Memory() const;

    bool operator()(TEventType event, HouseClass* house, const ObjectClass* object, CDTimerClass<FrameTimerClass>& timer, bool& is_perm, TechnoClass* source);

    static const char* Event_Name(TEventType event);
    static const char* Event_Description(TEventType event);

public:
    int HeapID;
    TEventClass* Next;
    TEventType Event;
    TeamTypeClass* Team;

    union {
        StructType Structure;
        UnitType Unit;
        InfantryType Infantry;
        AircraftType Aircraft;
        HousesType House;
        float Float;
        long Value;
    } Data;

public:
    struct EventDescriptionStruct {
        char const* Name;
        char const* Description;
    };

private:
    static EventDescriptionStruct EventDescriptions[TEVENT_COUNT];
};

NeedType Event_Needs(TEventType event);
AttachType Attaches_To(TEventType event);
