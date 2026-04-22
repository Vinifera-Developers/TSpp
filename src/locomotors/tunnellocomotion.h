/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Tunnel locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ftimer.h"
#include "locomotion.h"
#include "ttimer.h"


class DECLSPEC_UUID("4A582743-9839-11D1-B709-00A024DDAFD1")
TunnelLocomotionClass : public LocomotionClass
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
    IFACEMETHOD_(MoveType, Can_Enter_Cell)(Cell cell);
    IFACEMETHOD_(bool, Is_To_Have_Shadow)();
    IFACEMETHOD_(Matrix3D, Draw_Matrix)(int* key);
    IFACEMETHOD_(VisualType, Visual_Character)(bool flag);
    IFACEMETHOD_(int, Z_Adjust)();
    IFACEMETHOD_(ZGradientType, Z_Gradient)();
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(void, Do_Turn)(DirType coord);
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(bool, Is_Moving_Now)();
    IFACEMETHOD_(FireErrorType, Can_Fire)();
    IFACEMETHOD_(bool, Is_Surfacing)();

public:
    TunnelLocomotionClass();
    TunnelLocomotionClass(const NoInitClass& noinit);
    virtual ~TunnelLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

public:
    typedef enum ProcessStateType {
        NORMAL,
        DIGGING_IN_START,
        DIGGING_IN_FINISH,
        DIGGING_DOWN,
        UNDERGROUND,
        DIGGING_UP,
        DIGGING_OUT,
        POST_DUG_OUT
    } ProcessStateType;

    ProcessStateType CurrentState;
    Coord DestinationCoord;
    ProgressTimerClass<FrameTimerClass> DigTimer;
    bool IsMoving;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    TunnelLocomotionClass(const TunnelLocomotionClass&);
    TunnelLocomotionClass& operator=(const TunnelLocomotionClass&);
};
