/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COORD.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Coord utility functions.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


Coord Coord_Move(const Coord& start, DirType &facing, unsigned distance);
Coord Coord_Scatter(const Coord& coord, unsigned distance, bool lock = false);
Coord Adjacent_Coord_With_Height(const Coord& coord, FacingType facing);

inline Cell Cell_Move(Cell const& start, DirType const& dir, short distance)
{
	double radians = dir.Get_Radian();
	return Cell((start.X + cos(radians) * distance), (start.Y - sin(radians) * distance));
}
