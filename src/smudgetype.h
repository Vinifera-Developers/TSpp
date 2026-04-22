/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for smudge types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "objecttype.h"
#include "tibsun_defines.h"


class DECLSPEC_UUID("5AF2CE78-0634-11D2-ACA4-006008055BB5")
SmudgeTypeClass : public ObjectTypeClass
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
    SmudgeTypeClass(const char* ini_name = nullptr);
    SmudgeTypeClass(const NoInitClass& noinit);
    virtual ~SmudgeTypeClass();

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
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;

    /**
     *  SmudgeTypeClass
     */
    virtual void Draw_It(Point2D& xy, Rect& a2, int index, int a4, Cell& cell) const;

    bool Can_Place_Here(Cell& cell, bool a3);
    void Place(Cell& cell);

    static bool Create_Scorch(const Coord& coord, int width, int height, bool large = false);
    static bool Create_Crater(const Coord& coord, int width, int height, bool large = false);
    static void Init(TheaterType theater = THEATER_TEMPERATE);

    static SmudgeType From_Name(const char* name);
    static const char* Name_From(SmudgeType type);
    static SmudgeTypeClass* Find_Or_Make(const char* name);

public:
    SmudgeType HeapID;
    int Width;
    int Height;
    bool IsCrater;
    bool IsScorch;
};
