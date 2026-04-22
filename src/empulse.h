/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  EM Pulse state class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "always.h"


class DECLSPEC_UUID("B825CB22-200E-11D2-9FA9-0060089AD458")
EMPulseClass : public AbstractClass
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
    EMPulseClass();
    EMPulseClass(Cell cell, int spread, int duration, TechnoClass* source);
    EMPulseClass(const NoInitClass& noinit);
    virtual ~EMPulseClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    static void Init_Clear();
    static void Update_All();

public:
    Cell Center;
    int Spread;
    int CreationFrame;
    int Duration;
};
