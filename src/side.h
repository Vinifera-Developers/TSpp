/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for side types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"
#include "always.h"
#include "typelist.h"


class DECLSPEC_UUID("C53DD372-151E-11D2-8175-006008055BB5")
SideClass : public AbstractTypeClass
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
    SideClass(const char* ini_name = nullptr);
    SideClass(const NoInitClass& noinit);
    virtual ~SideClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    static SideType From_Name(const char* name);
    static const char* Name_From(SideType type);
    static SideClass* Find_Or_Make(const char* name);

public:
    TypeList<HousesType> Houses;
};
