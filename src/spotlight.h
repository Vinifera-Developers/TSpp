/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Alpha spotlights.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class SpotlightClass
{
public:
    SpotlightClass(Coord coord, int spotlight_size);
    ~SpotlightClass();

    void Remove_If_Large();
    void Draw_It();

    static void Update_All();
    static void One_Time();
    static void Clear_All();
    static void Draw_All();

private:
    Coord Position;
    int Radius;
    int Size;
};
