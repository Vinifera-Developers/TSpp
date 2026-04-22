/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Smudge game object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "object.h"
#include "tibsun_defines.h"


class SmudgeTypeClass;
class CCINIClass;


class DECLSPEC_UUID("0E272DC5-9C0F-11D1-B709-00A024DDAFD1")
SmudgeClass : public ObjectClass
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
    SmudgeClass(SmudgeTypeClass* classof = nullptr, Coord& pos = Coord(-1, -1, -1), HousesType house = HOUSE_NONE);
    SmudgeClass(const NoInitClass& noinit);
    virtual ~SmudgeClass();

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
    virtual bool Mark(MarkType mark = MARK_CHANGE) override;

    void Disown(Cell& cell);

    static void Read_INI(CCINIClass& ini);
    static void Write_INI(CCINIClass& ini);

public:
    SmudgeTypeClass* Class;
};
