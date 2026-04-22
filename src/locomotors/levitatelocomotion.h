/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Drop pod locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ipiggyback.h"
#include "locomotion.h"


class DECLSPEC_UUID("3DC0B295-6546-11D3-80B0-00902792494C")
LevitateLocomotionClass : public LocomotionClass
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
    IFACEMETHOD(Link_To_Object)(void* object);
    IFACEMETHOD_(bool, Is_Moving)();
    IFACEMETHOD_(Coord, Destination)();
    IFACEMETHOD_(Coord, Head_To_Coord)();
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(bool, Is_Moving_Now)();
    IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);

    void func_4FDF80();

public:
    LevitateLocomotionClass();
    LevitateLocomotionClass(const NoInitClass& noinit);
    virtual ~LevitateLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

public:
    int field_14;    // State?
    double field_18; // CurrentVelocity?
    double field_20; // DeltaX?
    double field_28; // DeltaY?
    double field_30; // AccelerationDurationCosinus?
    double field_38; // AccelerationDurationNegSinus?
    int field_40;    // AccelerationDuration?
    int field_44;    // BlocksCounter?
    double field_48; // CurrentSpeed?
    double field_50; // Dampen?
    double field_58;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    LevitateLocomotionClass(const LevitateLocomotionClass&);
    LevitateLocomotionClass& operator=(const LevitateLocomotionClass&);
};
