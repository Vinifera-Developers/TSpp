/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Alpha shape object class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "rect.h"


class DECLSPEC_UUID("623C7584-74E7-11D2-B8F5-006008C809ED")
AlphaShapeClass : public AbstractClass
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
    AlphaShapeClass();
    AlphaShapeClass(AbstractClass* target, int width, int height);
    AlphaShapeClass(NoInitClass& noinit);
    virtual ~AlphaShapeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool a1 = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    // 0x00412A90
    // 0x00412B40
    // 0x00412F70
    // 0x004132D0

public:
    AbstractClass* AttachedTo;
    Rect Size;
    ShapeSet* Image;
    bool field_2C;
};
