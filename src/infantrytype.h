/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for infantry types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "technotype.h"
#include "tibsun_defines.h"
#include "typelist.h"


class DECLSPEC_UUID("AE8B33D8-061C-11D2-ACA4-006008055BB5")
InfantryTypeClass : public TechnoTypeClass
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
    InfantryTypeClass(const char* ini_name = nullptr);
    InfantryTypeClass(const NoInitClass& noinit);
    virtual ~InfantryTypeClass();

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

    /**
     *  ObjectTypeClass
     */
    virtual Coord Coord_Fixup(Coord* coord) const override;
    virtual Point3D Lepton_Dimensions() const override;
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;
    virtual Cell* Occupy_List(bool placement = false) const;

    /**
     *  TechnoTypeClass
     */
    virtual int Repair_Cost() const override;
    virtual int Repair_Step() const override;

    void Sequence_Read_INI();

    static InfantryType From_Name(const char* name);
    static const char* Name_From(InfantryType type);
    static InfantryTypeClass* Find_Or_Make(const char* name);

public:
    InfantryType HeapID;
    PipEnum Pip;
    DoInfoStruct* DoControls;
    int FireLaunch;
    int ProneLaunch;
    TypeList<VocType> VoiceComment;
    bool IsCyborg;
    bool IsFearless;
    bool IsCrawling;
    bool IsCapture;
    bool IsFraidyCat;
    bool IsTiberiumProof;
    bool IsCivilian;
    bool IsBomber;
    bool IsEngineer;
    bool IsDisguised;
    bool IsAgent;
    bool IsThief;
    bool IsVehicleThief;
    bool IsDoggie;
    bool IsJumpJet;
    bool IsWebImmune;
};
