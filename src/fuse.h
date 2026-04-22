/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  The fuse is used by projectiles.
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
class FileClass;


enum FuseResultType {
    FUSE_DONT_IGNITE,
    FUSE_IGNITE,
    FUSE_2,
};


class FuseClass
{
public:
    FuseClass();
    FuseClass(const NoInitClass& noinit);
    ~FuseClass();

    void Arm_Fuse(Coord& location, Coord& target, int time = 255, int arming = 0);
    FuseResultType Fuse_Checkup(Coord& newlocation);

    Coord Fuse_Target() { return HeadTo; }

public:
    CDTimerClass<FrameTimerClass> Timer;

private:
    CDTimerClass<FrameTimerClass> Arming;
    Coord HeadTo;
    int Proximity;
};
