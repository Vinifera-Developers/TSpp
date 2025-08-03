/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INLINE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Various inlines and C&C utility functions.
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

#include "scenario.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"
#include "wwmath.h"
#include <algorithm>


extern const Cell AdjacentCell[FACING_COUNT];
extern const Coord AdjacentCoord[FACING_COUNT];
extern unsigned char const Facing8[256];
extern unsigned char const Facing16[256];
extern unsigned char const Facing32[256];


inline FacingType Dir_Facing(Dir256 facing)
{
    return (FacingType)(((unsigned char)((int)facing + 0x10) & 255) >> 5);
}


inline Dir256 Facing_Dir(FacingType facing)
{
    return (Dir256)((int)facing << 5);
}


inline FacingType Dir_To_8(Dir256 facing)
{
    return (FacingType)Facing8[facing];
}


inline FacingType Dir_To_16(Dir256 facing)
{
    return (FacingType)Facing16[facing];
}


inline FacingType Dir_To_32(Dir256 facing)
{
    return (FacingType)Facing32[facing];
}


inline Dir256 Dir_Snap(Dir256 facing)
{
    return Facing_Dir(Dir_To_8(facing));
}


inline DirType Desired_Facing(int x1, int y1, int x2, int y2)
{
    DirType dir;

    /**
     *  Get the angle between the two points.
     */
    double angle = WWMath::Atan2((double)y2 - y1, (double)x1 - x2);

    /**
     *  Assign direction to return.
     */
    dir.Set_Radian<65536>(angle);

    return dir;
}

inline DirType Direction(Coord const& coord1, Coord const& coord2)
{
    return Desired_Facing(coord2.X, coord2.Y, coord1.X, coord1.Y);
}


inline DirType Desired_Facing(const Point2D& point1, const Point2D& point2)
{
    return Desired_Facing(point2.X, point2.Y, point1.X, point1.Y);
}


inline Dir256 Desired_Facing256(const Point2D& point1, const Point2D& point2)
{
    Dir256 facing = Desired_Facing(point2.X, point2.Y, point1.X, point1.Y).Get_Dir();
    return facing;
}


inline FacingType Desired_Facing8(const Point2D& point1, const Point2D& point2)
{
    FacingType facing = Dir_Facing(Desired_Facing(point2.X, point2.Y, point1.X, point1.Y).Get_Dir());
    return facing;
}


inline Dir256 Direction256(const Coord& coord1, const Coord& coord2)
{
    Dir256 facing = Desired_Facing(coord2.X, coord2.Y, coord1.X, coord1.Y).Get_Dir();
    return facing;
}


inline FacingType Direction8(const Coord& coord1, const Coord& coord2)
{
    FacingType facing = Dir_Facing(Desired_Facing(coord1.X, coord1.Y, coord2.X, coord2.Y).Get_Dir());
    return facing;
}


inline Dir256 Direction256(const Cell& cell1, const Cell& cell2)
{
    Dir256 facing = Desired_Facing(cell1.X, cell1.Y, cell2.X, cell2.Y).Get_Dir();
    return facing;
}


inline FacingType Direction8(const Cell& cell1, const Cell& cell2)
{
    FacingType facing = Dir_Facing(Desired_Facing(cell1.X, cell1.Y, cell2.X, cell2.Y).Get_Dir());
    return facing;
}


inline int Distance(const Coord& coord1, const Coord& coord2)
{
    Coord coord;
    coord = coord1 - coord2;
    return coord.Length();
}


inline int Distance_Level_Snap(const Coord& coord1, const Coord& coord2)
{
    int z1 = coord1.Z;
    int z2 = coord2.Z;
    if (abs(z2 - z1) < LEVEL_LEPTON_H) {
        z2 = coord1.Z;
    }
    return Coord(coord1.X - coord2.X, coord1.Y - coord2.Y, z1 - z2).Length();
}


inline short Distance(const Cell& cell1, const Cell& cell2)
{
    Cell cell;
    cell = cell1 - cell2;
    return cell.Length();
}


inline bool Is_Distance_Within_Range(const Coord& coord1, const Coord& coord2, int min, int max)
{
    int dist = Distance(coord1, coord2);
    return dist >= min && dist <= max;
}


inline bool Is_Distance_Within_Range(const Cell& cell1, const Cell& cell2, int min, int max)
{
    int dist = Distance(cell1, cell2);
    return dist >= min && dist <= max;
}


inline void Move_Point(Point2D& point, Dir256 dir, int distance)
{
    double radians = (double)(dir - 0x3FFF) * -DEG_TO_RAD(360) / (UINT16_MAX - 1);

    point.Y -= (WWMath::Sin(radians) * distance);
    point.X += (WWMath::Cos(radians) * distance);
}


inline void Move_Coord(Coord& coord, Dir256 dir, int distance)
{
    double radians = (double)(dir - 0x3FFF) * -DEG_TO_RAD(360) / (UINT16_MAX - 1);

    coord.Y -= (WWMath::Sin(radians) * distance);
    coord.X += (WWMath::Cos(radians) * distance);
}


inline void Move_Cell(Cell& cell, Dir256 dir, int distance)
{
    double radians = (double)(dir - 0x3FFF) * -DEG_TO_RAD(360) / (UINT16_MAX - 1);

    cell.Y -= (WWMath::Sin(radians) * distance);
    cell.X += (WWMath::Cos(radians) * distance);
}


inline int Lepton_To_Pixel(LEPTON lepton)
{
    return (((int)(signed short)lepton * CELL_PIXEL_W) + (CELL_LEPTON_W / 2) - ((lepton < 0) ? (CELL_LEPTON_W - 1) : 0)) / CELL_LEPTON_W;
}


inline LEPTON Pixel_To_Lepton(int pixel)
{
    return (LEPTON)(((pixel * CELL_LEPTON_W) + (CELL_PIXEL_W / 2) - ((pixel < 0) ? (CELL_PIXEL_W - 1) : 0)) / CELL_PIXEL_W);
}


inline Coord Lerp(const Coord& coord1, const Coord& coord2, float t)
{
    Coord coord;
    coord.X = ((double)coord1.X * (1.0f - (double)t)) + ((double)coord2.X * t);
    coord.Y = ((double)coord1.Y * (1.0f - (double)t)) + ((double)coord2.Y * t);
    coord.Z = ((double)coord1.Z * (1.0f - (double)t)) + ((double)coord2.Z * t);
    return coord;
}


inline Cell Lerp(const Cell& cell1, const Cell& cell2, float t)
{
    Cell cell;
    cell.X = ((double)cell1.X * (1.0f - (double)t)) + ((double)cell2.X * t);
    cell.Y = ((double)cell1.Y * (1.0f - (double)t)) + ((double)cell2.Y * t);
    return cell;
}


inline Coord Coord_Snap(const Coord& coord)
{
    // Convert coord to cell, and back again to get the absolute position.
    Cell cell;
    cell.X = coord.X / 256;
    cell.Y = coord.Y / 256;

    Coord tmp;
    tmp.X = cell.X * 256;
    tmp.Y = cell.Y * 256;

    // Snap coord to cell center.
    tmp.X += CELL_LEPTON_W / 2;
    tmp.Y += CELL_LEPTON_W / 2;

    // Restore input coord Z value.
    tmp.Z = coord.Z;

    return tmp;
}


inline Coord Coord_Fraction(const Coord& coord)
{
    Coord tmp;
    tmp.X = coord.X % CELL_LEPTON_W;
    tmp.Y = coord.Y % CELL_LEPTON_H;
    return tmp;
}


inline Coord Coord_Whole(const Coord& coord)
{
    // Convert coord to cell, and back again to get the absolute position.
    Cell cell;
    cell.X = coord.X / CELL_LEPTON_W;
    cell.Y = coord.Y / CELL_LEPTON_H;

    Coord tmp;
    tmp.X = cell.X * CELL_LEPTON_W;
    tmp.Y = cell.Y * CELL_LEPTON_H;

    return tmp;
}


inline LEPTON Cell_To_Lepton(int cell_distance)
{
    LEPTON lepton = cell_distance * CELL_LEPTON_W;
    return lepton;
}


inline int Lepton_To_Cell(LEPTON lepton_distance)
{
    if (lepton_distance >= (CELL_LEPTON_W / 2)) {
        return (lepton_distance / 256) + 1;
    }
    return (lepton_distance / 256);
}


inline Coord Adjacent_Cell(const Coord& coord, FacingType dir)
{
    return coord + AdjacentCoord[(int)dir & (FACING_COUNT - 1)];
}


inline Coord Adjacent_Cell(const Coord& coord, Dir256 dir)
{
    return Adjacent_Cell(coord, Dir_Facing(dir));
}


inline Cell Adjacent_Cell(const Cell& cell, FacingType dir)
{
    return (Cell)(cell + AdjacentCell[(int)dir & (FACING_COUNT - 1)]);
}


inline Cell Adjacent_Cell(const Cell& cell, Dir256 dir)
{
    return Adjacent_Cell(cell, Dir_Facing(dir));
}


template<typename T>
inline T Random_Pick(T a, T b)
{
    return Scen->RandomNumber(a, b);
};


inline double Random_Pick2(int a, int b)
{
    int num = Scen->RandomNumber(a, b);
    return (num * double(a + 1) / double(b));
}


inline float Random_Pick_Float(float a, float b)
{
    return ((unsigned)Scen->RandomNumber() % 4096) / 4096.0f * (b - a) + a;
};


inline bool Percent_Chance(int percent)
{
    return Scen->RandomNumber(0, 99) < percent;
}


inline bool Probability_Of(double probability)
{
    return ((std::abs(Scen->RandomNumber()) % 1000000) / 1000000.0) < probability;
}


inline bool Probability_Of2(double probability)
{
    return (((Scen->RandomNumber(0, INT_MAX - 1) / (double)(INT_MAX - 1))) < probability);
}


template<typename T>
inline T Sim_Random_Pick(T a, T b)
{
    return NonCriticalRandomNumber(a, b);
};


inline float Sim_Random_Pick_Float(float a, float b)
{
    return ((unsigned)NonCriticalRandomNumber() % 4096) / 4096.0f * (b - a) + a;
};


inline bool Sim_Percent_Chance(int percent)
{
    return NonCriticalRandomNumber(0, 99) < percent;
}
