/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Overlay game object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "object.h"
#include "tibsun_defines.h"


class OverlayTypeClass;
class CCINIClass;


class DECLSPEC_UUID("0E272DC7-9C0F-11D1-B709-00A024DDAFD1")
OverlayClass : public ObjectClass
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
    OverlayClass(OverlayTypeClass* classof = nullptr, Cell& pos = CELL_NONE, HousesType house = HOUSE_NONE);
    OverlayClass(const NoInitClass& noinit);
    virtual ~OverlayClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;

    /**
     *  ObjectClass
     */
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;
    virtual void Placement_Draw_It(Point2D& point, Rect& bounds) const override;
    virtual bool Mark(MarkType mark = MARK_CHANGE) override;

    // 0058C850
    static TiberiumType To_TiberiumType(OverlayType overlay);
    static void Scenario_Load_Fixup_Veins();

    static void Read_INI(CCINIClass& ini);
    static void Write_INI(CCINIClass& ini);

public:
    OverlayTypeClass* Class;
};
