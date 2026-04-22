/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for object trigger-tag types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "tibsun_defines.h"


class TriggerTypeClass;


class DECLSPEC_UUID("54F6E433-09ED-11D2-ACA5-006008055BB5")
TagTypeClass : public AbstractTypeClass
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
    TagTypeClass(const char* ini_name = nullptr);
    TagTypeClass(const NoInitClass& noinit);
    virtual ~TagTypeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true);
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;
    virtual bool Write_INI(CCINIClass& ini) const override;

    // 0061F270
    // 0061F290
    AttachType Attaches_To() const;
    // 0061F660
    // 0061F690
    // 0061F6C0
    // 0061F6F0

    static void Read_Scenario_INI(CCINIClass& ini);
    static void Write_Scenario_INI(CCINIClass& ini);

    static TagType From_Name(const char* name);
    static const char* Name_From(TagType type);
    static TagTypeClass* Find_Or_Make(const char* name);

public:
    TagType HeapID;
    PersistantType Persistence;
    TriggerTypeClass* TriggerType;
};
