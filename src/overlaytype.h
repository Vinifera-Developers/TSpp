/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for overlay types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "objecttype.h"
#include "tibsun_defines.h"


class AnimTypeClass;


class DECLSPEC_UUID("5AF2CE79-0634-11D2-ACA4-006008055BB5")
OverlayTypeClass : public ObjectTypeClass
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
    OverlayTypeClass(const char* ini_name = nullptr);
    OverlayTypeClass(const NoInitClass& noinit);
    virtual ~OverlayTypeClass();

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
    virtual ShapeSet* const Get_Image_Data() const override;

    /**
     *  OverlayTypeClass
     */
    virtual void Draw_It(Point2D& xy, Rect& a2, int frame) const;

    RGBStruct Get_Radar_Color(int a1 = 0);

    static void Init(TheaterType theater = THEATER_TEMPERATE);

    static OverlayType From_Name(const char* name);
    static const char* Name_From(OverlayType type);
    static OverlayTypeClass* Find_Or_Make(const char* name);

public:
    OverlayType HeapID;
    LandType Land;
    AnimTypeClass* CellAnim;
    int DamageLevels;
    int DamagePoints;
    bool IsWall;
    bool IsHigh;
    bool IsTiberium;
    bool IsCrate;
    bool IsCrateTrigger;
    bool NoUseTileLandType;
    bool IsVeinholeMonster;
    bool IsVeins;
    bool IsDemandLoad;
    bool IsExplosive;
    bool IsChainReactive;
    bool IsPriority;
    bool DrawFlat;
    bool IsARock;
};
