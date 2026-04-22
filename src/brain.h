/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "vector.h"


class NeuronClass;


class BrainClass
{
public:
    BrainClass();
    virtual ~BrainClass();

    // 0x004255B0
    // 0x004255F0
    // 0x00425640
    // 0x004256B0
    // 0x00425720

public:
    DynamicVectorClass<NeuronClass*> Neurons;
    NeuronClass* field_1C; // head neuron?
    int Max;
};


class DECLSPEC_UUID("241AB316-4CF5-11D2-BC26-00104B8FB04D")
NeuronClass : public AbstractClass
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
    NeuronClass();
    virtual ~NeuronClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool a1 = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

public:
    void* field_14;
    void* field_18;
    BrainClass* Brain;
    int CreationFrame;
    int field_24;
};
