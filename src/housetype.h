/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for house types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstracttype.h"


class DECLSPEC_UUID("1DD43928-046B-11D2-ACA4-006008055BB5")
HouseTypeClass : public AbstractTypeClass
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD_(LONG, IsDirty)();
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);
    IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER* pcbSize);

public:
    HouseTypeClass(const char* ini_name = nullptr);
    HouseTypeClass(const NoInitClass& noinit);
    virtual ~HouseTypeClass();

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

    static HousesType From_Name(const char* name);
    static const char* Name_From(HousesType type);
    static HouseTypeClass* Find_Or_Make(const char* name);

public:
    HousesType HeapID;
    HousesType House;
    SideType Side;
    ColorSchemeType Scheme;
    double FirepowerBias;
    double GroundspeedBias;
    double AirspeedBias;
    double ArmorBias;
    double ROFBias;
    double CostBias;
    double BuildSpeedBias;
    char Suffix[4];
    char Prefix;
    bool IsMultiplay;
    bool IsMultiplayPassive;
    bool IsWallOwner;
    bool IsSmartAI;
};
