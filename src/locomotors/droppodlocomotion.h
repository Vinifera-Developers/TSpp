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


class DECLSPEC_UUID("4A582745-9839-11D1-B709-00A024DDAFD1")
DropPodLocomotionClass : public LocomotionClass, public IPiggyback
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

    /**
     *  ILocomotion
     */
    IFACEMETHOD_(bool, Is_Moving)();
    IFACEMETHOD_(Coord, Destination)();
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(int, Drawing_Code)();

    /**
     *  IPiggyback
     */
    IFACEMETHOD(Begin_Piggyback)(ILocomotion* pointer);
    IFACEMETHOD(End_Piggyback)(ILocomotion** pointer);
    IFACEMETHOD_(bool, Is_Ok_To_End)();
    IFACEMETHOD(Piggyback_CLSID)(CLSID* classid);
    IFACEMETHOD_(bool, Is_Piggybacking)();

public:
    DropPodLocomotionClass();
    DropPodLocomotionClass(const NoInitClass& noinit);
    virtual ~DropPodLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

public:
    typedef enum DropPodDirType {
        DPOD_DIR_NE,
        DPOD_DIR_NW,
        DPOD_DIR_SE,
        DPOD_DIR_SW,
    } DropPodDirType;

    DropPodDirType Direction;
    Coord DestinationCoord;
    ILocomotionPtr Piggybacker;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    DropPodLocomotionClass(const DropPodLocomotionClass&);
    DropPodLocomotionClass& operator=(const DropPodLocomotionClass&);
};
