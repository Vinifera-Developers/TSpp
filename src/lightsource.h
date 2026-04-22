/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Light sources on the map.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "tibsun_defines.h"


class LightConvertClass;


class DECLSPEC_UUID("6F9C48F0-1207-11D2-8174-006008055BB5")
LightSourceClass : public AbstractClass
{
public:
    class PendingCellClass
    {
    public:
        PendingCellClass() : Drawer(nullptr), Intensity(65536), Ambient(0), RedTint(1000), GreenTint(1000), BlueTint(1000), Cell(0, 0) {}

        ~PendingCellClass() {}

    public:
        LightConvertClass* Drawer;
        int Intensity;
        int Ambient;
        short RedTint;
        short GreenTint;
        short BlueTint;
        Cell Cell;
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
    LightSourceClass();
    LightSourceClass(Coord coord, int visibility, int intensity, int red, int green, int blue);
    LightSourceClass(const NoInitClass& noinit);
    virtual ~LightSourceClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    void Enable(bool update = false);
    void Disable(bool update = false);
    void Process();

    const char* Name() const;

    static void Init_Clear();
    // 00501950

public:
    int Intensity;
    int RedTint;
    int GreenTint;
    int BlueTint;
    Coord Where;
    int Visibility;
    bool IsEnabled;

public:
    static bool& Recalc;
};


/**
 *  This must be here because we can't forward declare nested classes.
 */
extern DynamicVectorClass<LightSourceClass::PendingCellClass*>& PendingLightCells;
