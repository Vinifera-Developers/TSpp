/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Walker locomotion class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ipiggyback.h"
#include "locomotion.h"


class DECLSPEC_UUID("4A582744-9839-11D1-B709-00A024DDAFD1")
WalkLocomotionClass : public LocomotionClass, public IPiggyback
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
    IFACEMETHOD_(bool, Is_Really_Moving_Now)();
    IFACEMETHOD_(void, Stop_Movement_Animation)();

    /**
     *  IPiggyback
     */
    IFACEMETHOD(Begin_Piggyback)(ILocomotion* pointer);
    IFACEMETHOD(End_Piggyback)(ILocomotion** pointer);
    IFACEMETHOD_(bool, Is_Ok_To_End)();
    IFACEMETHOD(Piggyback_CLSID)(CLSID* classid);
    IFACEMETHOD_(bool, Is_Piggybacking)();

public:
    WalkLocomotionClass();
    WalkLocomotionClass(const NoInitClass& noinit);
    virtual ~WalkLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

    void Internal_Process(bool a2 = false);
    bool func_66E170(Coord& coord);

public:
    Coord DestinationCoord;
    Coord HeadToCoord;
    bool IsMoving;
    bool field_31; // flagged when "processing" walking.
    bool IsReallyMoving;
    ILocomotionPtr Piggybacker;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    WalkLocomotionClass(const WalkLocomotionClass&);
    WalkLocomotionClass& operator=(const WalkLocomotionClass&);
};
