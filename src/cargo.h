/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class that handles the basic cargo logic.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "noinit.h"


class FootClass;
enum RTTIType;


class CargoClass
{
public:
    CargoClass();
    CargoClass(const NoInitClass& noinit);
    ~CargoClass();

    void AI();

    int How_Many() const { return Quantity; }
    bool Is_Something_Attached() const { return CargoHold != nullptr; }
    FootClass* Attached_Object() const;
    FootClass* Detach_Object();
    void Attach(FootClass* object);
    void Detach(FootClass* object);

    /**
     *  New methods to allow for more precise manipulations.
     */
    int How_Many(RTTIType rtti) const;
    bool Is_Something_Attached(RTTIType rtti) const;
    FootClass* Attached_Object(RTTIType rtti) const;
    FootClass* Detach_Object(RTTIType rtti);

public:
    unsigned Quantity;
    FootClass* CargoHold;
};
