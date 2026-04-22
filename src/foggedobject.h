/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Fogged (Fog of War) object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "tibsun_defines.h"


class ObjectTypeClass;
class BuildingClass;
class TerrainClass;


class DECLSPEC_UUID("1C470B0E-69D7-11D2-B8F2-006008C809ED")
FoggedObjectClass : public AbstractClass
{
public:
    typedef struct DrawRecord {
        ObjectTypeClass* TypeClass;
        int Frame;
        int HeightAdjust;
        int ZAdjust;
    } DrawRecord;

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
    FoggedObjectClass();
    FoggedObjectClass(Coord& coord, OverlayType overlay, int overlay_data);
    FoggedObjectClass(Coord& coord, SmudgeType smudge, int smudge_data);
    FoggedObjectClass(const BuildingClass* building, bool to_draw = false);
    FoggedObjectClass(const TerrainClass* terrain);
    FoggedObjectClass(NoInitClass& noinit);
    virtual ~FoggedObjectClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool a1 = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    virtual Cell Get_Cell() const;

    Cell* Get_Occupy_List() const;
    const ObjectTypeClass* Get_Object() const;

    static void Draw_All();
    static void Update_All();

public:
    OverlayType Overlay;
    HouseClass* Owner;
    int OverlayData;
    RTTIType RTTI;
    Coord Position;
    Rect BoundingRect;
    int CellLevel;
    SmudgeType Smudge;
    int SmudgeData;
    DynamicVectorClass<DrawRecord*> Records;
    bool ToDraw;
};
