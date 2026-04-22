/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for unit types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "point.h"
#include "technotype.h"
#include "tibsun_defines.h"


class DECLSPEC_UUID("DCBD42EA-0546-11D2-ACA4-006008055BB5")
UnitTypeClass : public TechnoTypeClass
{
public:
    enum UnitTypeClassEnums {
        FIRING_SYNC_FRAME_MAX = 2
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
    UnitTypeClass(const char* ini_name = nullptr);
    UnitTypeClass(const NoInitClass& noinit);
    virtual ~UnitTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual int Get_Object_Size_Delta() const override;
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
    virtual Point3D Pixel_Dimensions() const override;
    virtual Point3D Lepton_Dimensions() const override;
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;

    /**
     *  TechnoTypeClass
     */
    virtual int Repair_Step() const override;

    const TPoint3D<int> Turret_Adjust(Dir256 dir, TPoint3D<int>& pos) const;

    static UnitType From_Name(const char* name);
    static const char* Name_From(UnitType type);
    static UnitTypeClass* Find_Or_Make(const char* name);

    static void One_Time();

public:
    UnitType HeapID;
    LandType MovementRestrictedTo;
    TPoint3D<int> HalfDamageSmokeLocation;
    bool IsPassive;
    bool IsCrateGoodie;
    bool IsToHarvest;
    bool IsToVeinHarvest;
    bool IsFireAnim;
    bool IsLockTurret;
    bool IsNoFireWhileMoving;
    bool IsDeployToFire;
    bool IsTilter;
    bool UseTurretShadow;
    bool IsTooBigToFitUnderBridge;
    bool IsSmallVisceroid;
    bool IsLargeVisceroid;
    bool IsCarriesCrate;
    ShapeSet* AltImage;
    bool IsNonVehicle;
    bool IsJellyfish;
    bool IsLimpetDrone;
    bool IsMobileEMP;
    bool IsCoreDefender;
    char StandingFrames;
    char DeathFrames;
    char DeathFrameRate;
    int MaxCharge;
    int StartCharge;
    int FiringSyncFrame[FIRING_SYNC_FRAME_MAX];
    int StartStandFrame;
    int StartWalkFrame;
    int StartFiringFrame;
    int StartDeathFrame;
    int MaxDeathCounter;
    int Facings;
    char WalkFrames;
    char FiringFrames;
    TStringID<24> AltImageFile;
};
