/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Teleport locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "locomotion.h"


class DECLSPEC_UUID("4A582747-9839-11D1-B709-00A024DDAFD1")
TeleportLocomotionClass : public LocomotionClass
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
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(LayerType, In_Which_Layer)();

public:
    TeleportLocomotionClass();
    TeleportLocomotionClass(const NoInitClass& noinit);
    virtual ~TeleportLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

    /**
     *  TeleportLocomotionClass
     */
    virtual bool Is_Stationary() const;

public:
    Coord DestinationCoord;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    TeleportLocomotionClass(const TeleportLocomotionClass&);
    TeleportLocomotionClass& operator=(const TeleportLocomotionClass&);
};
