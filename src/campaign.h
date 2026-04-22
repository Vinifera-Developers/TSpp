/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for game campaign types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "tibsun_defines.h"


class CCINIClass;


class DECLSPEC_UUID("FFDAC848-1517-11D2-8175-006008055BB5")
CampaignClass : public AbstractTypeClass
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
    CampaignClass(const char* ini_name = nullptr);
    CampaignClass(const NoInitClass& noinit);
    virtual ~CampaignClass();

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

    static int Process(CCINIClass& ini);

    static CampaignType From_Name(const char* name);
    static const char* Name_From(CampaignType type);
    static CampaignClass* Find_Or_Make(const char* name);

public:
    DiskID WhichCD;
    char Scenario[512];
    VQType FinalMovie;
    char Description[128];
    AddonType RequiredAddon;
};
