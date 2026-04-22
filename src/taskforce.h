/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for taks force types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "tibsun_defines.h"


class TechnoTypeClass;


class TaskForceMemberClass
{
public:
    int Quantity;                 // Number of objects desired for this type.
    const TechnoTypeClass* Class; // The type of object desired.
};


class DECLSPEC_UUID("61DE341E-0774-11D2-ACA5-006008055BB5")
TaskForceClass : public AbstractTypeClass
{
public:
    enum TaskForceClassEnums {
        MAX_TEAM_CLASSCOUNT = 5
    };

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
    TaskForceClass(const char* ini_name = nullptr);
    TaskForceClass(const NoInitClass& noinit);
    virtual ~TaskForceClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;
    virtual bool Write_INI(CCINIClass& ini) const override;

    int Required_Object_Count(void) const;
    int Needed_Tech_Level(void) const;
    bool Has_Only_Infantry(void) const;

    static void Read_Scenario_INI(CCINIClass& ini, int a2);
    static void Write_Scenario_INI(CCINIClass& ini, int a2);

    static TaskForceType From_Name(const char* name);
    static TaskForceType From_Full_Name(const char* name);
    static const char* Name_From(TaskForceType type);
    static TaskForceClass* Find_Or_Make(const char* name);

public:
    int Group;
    int ClassCount;
    int field_68;
    TaskForceMemberClass Members[MAX_TEAM_CLASSCOUNT];
};
