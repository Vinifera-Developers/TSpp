/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Graphical laser drawing.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "rgb.h"
#include "stage.h"
#include "tibsun_defines.h"


class LaserDrawClass
{
public:
    LaserDrawClass(Coord source, Coord target, int z_adjust, bool a9, RGBClass inner, RGBClass outer, RGBClass outer_spread, int duration, bool blinks = false, bool fades = true, float start_int = 0.5f, float end_int = 1.0f);
    ~LaserDrawClass();

    void Draw_It();
    void AI();

    static void Update_All();
    static void Clear_All();
    static void Draw_All();

public:
    StageClass DrawStage;
    Coord Source;
    Coord Target;
    int ZAdjust;
    bool field_34;
    RGBClass InnerColor;
    RGBClass OuterColor;
    RGBClass OuterSpreadColor;
    int Duration;
    bool Blinks;
    bool BlinkState;
    bool FadeOut;
    float StartIntensity;
    float EndIntensity;
};
