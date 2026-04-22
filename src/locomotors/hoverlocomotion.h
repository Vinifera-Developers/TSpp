/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Hover locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "facing.h"
#include "locomotion.h"


class DECLSPEC_UUID("4A582742-9839-11D1-B709-00A024DDAFD1")
HoverLocomotionClass : public LocomotionClass
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

    /**
     *  ILocomotion
     */
    IFACEMETHOD_(bool, Is_Moving)();
    IFACEMETHOD_(Coord, Destination)();
    IFACEMETHOD_(Coord, Head_To_Coord)();
    IFACEMETHOD_(Matrix3D, Draw_Matrix)(int* key);
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(void, Do_Turn)(DirType coord);
    IFACEMETHOD_(bool, Power_Off)();
    IFACEMETHOD_(bool, Is_Powered)();
    IFACEMETHOD_(bool, Is_Ion_Sensitive)();
    IFACEMETHOD_(bool, Push)(DirType dir);
    IFACEMETHOD_(bool, Shove)(DirType dir);
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(bool, Is_Moving_Now)();
    IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);
    IFACEMETHOD_(bool, Is_Moving_Here)(Coord to);

public:
    HoverLocomotionClass();
    HoverLocomotionClass(const NoInitClass& noinit);
    virtual ~HoverLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

public:
    Coord DestinationCoord;
    Coord HeadToCoord;
    FacingClass Facing;
    double field_48;
    double field_50;
    double field_58;
    double field_60;
    bool field_68;
    int field_6C;
    bool field_70;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    HoverLocomotionClass(const HoverLocomotionClass&) = delete;
    HoverLocomotionClass& operator=(const HoverLocomotionClass&) = delete;
};
