/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Mech locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "locomotion.h"


class DECLSPEC_UUID("55D141B8-DB94-11D1-AC98-006008055BB5")
MechLocomotionClass : public LocomotionClass
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
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(void, Do_Turn)(DirType coord);
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(void, Force_Immediate_Destination)(Coord coord);
    IFACEMETHOD_(bool, Is_Moving_Now)();
    IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);
    IFACEMETHOD_(bool, Is_Moving_Here)(Coord to);

public:
    MechLocomotionClass();
    MechLocomotionClass(const NoInitClass& noinit);
    virtual ~MechLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

public:
    Coord DestinationCoord;
    Coord HeadToCoord;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    MechLocomotionClass(const MechLocomotionClass&);
    MechLocomotionClass& operator=(const MechLocomotionClass&);
};
