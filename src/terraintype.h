/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for terrain types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "objecttype.h"
#include "tibsun_defines.h"


class OverlayTypeClass;


class DECLSPEC_UUID("5AF2CE7B-0634-11D2-ACA4-006008055BB5")
TerrainTypeClass : public ObjectTypeClass
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
    TerrainTypeClass(const char* ini_name = nullptr);
    TerrainTypeClass(const NoInitClass& noinit);
    virtual ~TerrainTypeClass();

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
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;
    virtual Cell* Occupy_List(bool placement = false) const override;

    static void Init(TheaterType theater);

    static TerrainType From_Name(const char* name);
    static const char* Name_From(TerrainType type);
    static TerrainTypeClass* Find_Or_Make(const char* name);

public:
    TerrainType HeapID;
    BSizeType Size;
    RGBStruct RadarColor;
    int AnimationRate;
    float AnimationProbability;
    int YDrawFudge;
    TiberiumType TiberiumToSpawn;
    int TemperateOccupationBits;
    int SnowOccupationBits;
    bool IsWaterBased;
    bool IsTiberiumSpawn;
    bool IsFlammable;
    bool IsAnimated;
    bool IsVeinhole;
    const Cell* Occupy;
};
