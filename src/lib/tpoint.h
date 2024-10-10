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

    TPoint2D &operator=(const TPoint2D &that) {
        X = that.X;
        Y = that.Y;
        return *this;
    }

    bool operator==(const TPoint2D &that) const { return X == that.X && Y == that.Y; }
    bool operator!=(const TPoint2D &that) const { return X != that.X && Y != that.Y; }

    TPoint2D &operator+=(const TPoint2D &that)
    {
        X += that.X;
        Y += that.Y;
        return *this;
    }

    TPoint2D& operator-=(const TPoint2D& that) {
        X -= that.X;
        Y -= that.Y;
        return *this;
    }

    TPoint2D operator+(const TPoint2D &that) const {
        TPoint2D result = *this;
        result += that;
        return result;
    }

    TPoint2D operator-(const TPoint2D& that) const {
        TPoint2D result = *this;
        result -= that;
        return result;
    }
     
    TPoint2D operator-() const { return TPoint2D(-X, -Y); }
    TPoint2D operator+() const { return TPoint2D(X, Y); }

    bool Is_Valid() const { return X > 0 || Y > 0; }

public:
    T X;
    T Y;
};


template<typename T>
class TPoint3D
{
public:
    TPoint3D() : X(0), Y(0), Z(0) {}
    TPoint3D(T x, T y, T z) : X(x), Y(y), Z(z) {}
    TPoint3D(const TPoint3D &that) : X(that.X), Y(that.Y), Z(that.Z) {}

    TPoint3D &operator=(const TPoint3D &that) {
        X = that.X;
        Y = that.Y;
        Z = that.Z;
        return *this;
    }

    bool operator==(const TPoint3D &that) const { return X == that.X && Y == that.Y && Z == that.Z; }
    bool operator!=(const TPoint3D &that) const { return X != that.X && Y != that.Y && Z != that.Z; }

    TPoint3D& operator+=(const TPoint3D& that) {
        X += that.X;
        Y += that.Y;
        Z += that.Z;
        return *this;
    }

    TPoint3D& operator-=(const TPoint3D& that) {
        X -= that.X;
        Y -= that.Y;
        Z -= that.Z;
        return *this;
    }

    TPoint3D operator+(const TPoint3D& that) const {
        TPoint3D result = *this;
        result += that;
        return result;
    }

    TPoint3D operator-(const TPoint3D& that) const {
        TPoint3D result = *this;
        result -= that;
        return result;
    }

    TPoint3D operator-() const { return TPoint3D(-X, -Y, -Z); }
    TPoint3D operator+() const { return TPoint3D(X, Y, Z); }

    bool Is_Valid() const { return X > 0 || Y > 0 || Z > 0; }

public:
    T X;
    T Y;
    T Z;
};
