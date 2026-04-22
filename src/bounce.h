/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Anim/object bouncing physics.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "quat.h"
#include "vector3.h"


class NoInitClass;
class Coord;


class BounceClass
{
public:
    BounceClass();
    BounceClass(const NoInitClass& noinit);
    ~BounceClass();

    // 004245B0
    // 00424700
    Coord Get_Coord() const;
    // 00424900
    // 00424930
    // 00424A20

public:
    double Elasticity;
    double field_8;
    double field_10;
    Vector3 Coords;
    Vector3 field_24;    // some sort of steps for Coords, maybe velocity.
    Quaternion field_30; // quaternion made from angle
    Quaternion field_40; // quaternion made from angular

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    BounceClass(const BounceClass&) = delete;
    BounceClass& operator=(const BounceClass&) = delete;
};
