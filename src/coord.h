/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Coord utility functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


Coord Coord_Move(const Coord& start, DirType& facing, unsigned distance);
Coord Coord_Scatter(const Coord& coord, unsigned distance, bool lock = false);
Coord Adjacent_Coord_With_Height(const Coord& coord, FacingType facing);

inline Cell Cell_Move(Cell const& start, DirType const& dir, short distance)
{
    double radians = dir.Get_Radian();
    return Cell((start.X + cos(radians) * distance), (start.Y - sin(radians) * distance));
}
