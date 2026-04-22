/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Isometric tile objects.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "object.h"
#include "tibsun_defines.h"


class IsometricTileTypeClass;


class DECLSPEC_UUID("0E272DC0-9C0F-11D1-B709-00A024DDAFD1")
IsometricTileClass : public ObjectClass
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
    IsometricTileClass(IsometricTileType type, Cell& cell);
    IsometricTileClass(const NoInitClass& noinit);
    virtual ~IsometricTileClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;

    /**
     *  ObjectClass
     */
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual bool Limbo() override;
    virtual bool Unlimbo(const Coord& coord, Dir256 dir = DIR_N) override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;
    virtual bool Mark(MarkType mark = MARK_CHANGE) override;

public:
    IsometricTileTypeClass* Class;
};
