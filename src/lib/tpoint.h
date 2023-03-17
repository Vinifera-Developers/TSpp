/*******************************************************************************
/*                    O P E N  S O U R C E  --  T S + +                       **
/*******************************************************************************
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


template<typename T>
class TPoint2D
{
    public:
        TPoint2D() : X(0), Y(0) {}
        TPoint2D(T x, T y) : X(x), Y(y) {}
        TPoint2D(const TPoint2D &that) : X(that.X), Y(that.Y) {}

        TPoint2D &operator=(const TPoint2D &that)
        {
            if ( this != &that ) {
                X = that.X;
                Y = that.Y;
            }
            return *this;
        }

        bool operator==(const TPoint2D &that) const { return X == that.X && Y == that.Y; }
        bool operator!=(const TPoint2D &that) const { return X != that.X && Y != that.Y; }

        bool Is_Valid() const { return X > 0 || Y > 0; }

    public:
        T X;
        T Y;
};


template<typename T>
bool operator==(const TPoint2D<T> &left, const TPoint2D<T> &right)
{
    return (left.X == right.X)
        && (left.Width == right.Width)
        && (left.Y == right.Y)
        && (left.Height == right.Height);
}


template<typename T>
bool operator!=(const TPoint2D<T> &left, const TPoint2D<T> &right)
{
    return (left.X != right.X)
        && (left.Width != right.Width)
        && (left.Y != right.Y)
        && (left.Height != right.Height);
}


template<typename T>
TPoint2D<T> operator+(const TPoint2D<T> &left, const TPoint2D<T> &right)
{
    Rect result = left;
    Rect tmp = right;
    result += tmp;
    return result;
}


template<typename T>
TPoint2D<T> operator-(const TPoint2D<T> &left, const TPoint2D<T> &right)
{
    Rect result = left;
    Rect tmp = right;
    result -= tmp;
    return result;
}



template<typename T>
class TPoint3D
{
    public:
        TPoint3D() : X(0), Y(0), Z(0) {}
        TPoint3D(T x, T y, T z) : X(x), Y(y), Z(z) {}
        TPoint3D(const TPoint3D &that) : X(that.X), Y(that.Y), Z(that.Z) {}

        TPoint3D &operator=(const TPoint3D &that)
        {
            if ( this != &that ) {
                X = that.X;
                Y = that.Y;
                Z = that.Z;
            }
            return *this;
        }

        bool operator==(const TPoint3D &that) const { return X == that.X && Y == that.Y && Z == that.Z; }
        bool operator!=(const TPoint3D &that) const { return X != that.X && Y != that.Y && Z != that.Z; }

        bool Is_Valid() const { return X > 0 || Y > 0; }

    public:
        T X;
        T Y;
        T Z;
};


template<typename T>
bool operator==(const TPoint3D<T> &left, const TPoint3D<T> &right)
{
    return (left.X == right.X)
        && (left.Width == right.Width)
        && (left.Y == right.Y)
        && (left.Height == right.Height);
}


template<typename T>
bool operator!=(const TPoint3D<T> &left, const TPoint3D<T> &right)
{
    return (left.X != right.X)
        && (left.Width != right.Width)
        && (left.Y != right.Y)
        && (left.Height != right.Height);
}


template<typename T>
TPoint3D<T> operator+(const TPoint3D<T> &left, const TPoint3D<T> &right)
{
    TPoint3D result = left;
    TPoint3D tmp = right;
    result += tmp;
    return result;
}


template<typename T>
TPoint3D<T> operator-(const TPoint3D<T> &left, const TPoint3D<T> &right)
{
    TPoint3D result = left;
    TPoint3D tmp = right;
    result -= tmp;
    return result;
}
