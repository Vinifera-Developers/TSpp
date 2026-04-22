/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  General unit facing handler class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ftimer.h"
#include "tibsun_defines.h"
#include "ttimer.h"


class NoInitClass;


class FacingClass
{
public:
    FacingClass();
    FacingClass(int rate);
    FacingClass(DirType& facing);
    FacingClass(Dir256 dir);
    FacingClass(FacingClass& that) : DesiredFacing(that.DesiredFacing), StartFacing(that.StartFacing), RotationTimer(that.RotationTimer), ROT(that.ROT) {}

    FacingClass(const NoInitClass& noinit);

    FacingClass& operator=(const FacingClass& that)
    {
        if (this != &that) {
            DesiredFacing = that.DesiredFacing;
            StartFacing = that.StartFacing;
            RotationTimer = that.RotationTimer;
            ROT = that.ROT;
        }
        return *this;
    }

    bool Set_Desired(const DirType& facing);
    bool Set(const DirType& facing);

    DirType Desired() const;
    DirType Current() const;

    bool Is_Rotating() const;
    bool Is_Rotating_CW() const;
    bool Is_Rotating_CCW() const;

    DirType Difference() const;
    DirType Difference(DirType& facing) const;

    void Set_ROT(int rate);

public:
    DirType DesiredFacing;
    DirType StartFacing; // The starting direction from which to calcuate the rotation.
    CDTimerClass<FrameTimerClass> RotationTimer;
    DirType ROT;
};
