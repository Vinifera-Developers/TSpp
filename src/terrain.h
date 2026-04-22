/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Terrain game object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "object.h"
#include "stage.h"
#include "tibsun_defines.h"


class TerrainTypeClass;
class CCINIClass;


class DECLSPEC_UUID("0E272DCE-9C0F-11D1-B709-00A024DDAFD1")
TerrainClass : public ObjectClass, public StageClass
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
    TerrainClass();
    TerrainClass(TerrainTypeClass* classof, Cell& pos);
    TerrainClass(const NoInitClass& noinit);
    virtual ~TerrainClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual bool Limbo() override;
    virtual bool Unlimbo(const Coord& coord, Dir256 dir = DIR_N) override;
    virtual void Set_Occupy_Bit(Coord& coord) override;
    virtual void Clear_Occupy_Bit(Coord& coord) override;
    virtual bool Render(Rect& rect, bool force = false, bool a3 = false) override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;
    virtual void Placement_Draw_It(Point2D& point, Rect& bounds) const override;
    virtual bool Mark(MarkType mark = MARK_CHANGE) override;
    virtual Rect entry_118() const override;
    virtual ResultType Take_Damage(int& damage, int distance, const WarheadTypeClass* warhead, const ObjectClass* source, bool forced = false, bool a6 = false) override;
    virtual bool Catch_Fire() override;
    virtual void Fire_Out() override;
    virtual MoveType Can_Enter_Cell(const CellClass* cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass* a4 = nullptr, bool a5 = true) override;

    void Start_To_Crumble();
    bool Is_Animating() const;

    static void Read_INI(CCINIClass& ini);
    static void Write_INI(CCINIClass& ini);

public:
    TerrainTypeClass* Class;
    bool IsOnFire;
    bool IsCrumbling;
    int field_6C;
    int field_70;
    Point2D DrawOffset;
};
