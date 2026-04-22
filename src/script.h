/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Script mission value container.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "tibsun_defines.h"


class ScriptTypeClass;
class ScriptMissionClass;


class DECLSPEC_UUID("42F3A646-0789-11D2-ACA5-006008055BB5")
ScriptClass : public AbstractClass
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
    ScriptClass(ScriptTypeClass* classof);
    ScriptClass(const NoInitClass& noinit);
    virtual ~ScriptClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    ScriptMissionClass Get_Current_Mission();
    ScriptMissionClass Get_Next_Mission();
    bool Stop_Script();
    bool Set_Line(int line);
    bool Next_Mission();
    bool Has_Missions_Remaining() const;

    const char* Name() const;

public:
    ScriptTypeClass* Class;
    int field_18;
    int CurrentMission;
};
