/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          POINT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Basic 2-dimensional and 3-dimensional geometry.
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
#include "wwmath.h"


template<typename T>
class TPoint2D
{
public:
    TPoint2D() {} // Default constructor does nothing by design.
    TPoint2D(T x, T y) : X(x), Y(y) {}

    bool operator==(const TPoint2D& that) const { return X == that.X && Y == that.Y; }
    bool operator!=(const TPoint2D& that) const { return X != that.X && Y != that.Y; }

    TPoint2D operator+(const TPoint2D& that) const { return TPoint2D(X + that.X, Y + that.Y); }
    TPoint2D& operator+=(const TPoint2D& that) { X += that.X; Y += that.Y; return *this; }

    TPoint2D operator-(const TPoint2D& that) const { return TPoint2D(X - that.X, Y - that.Y); }
    TPoint2D& operator-=(const TPoint2D& that) { X -= that.X; Y -= that.Y; return *this; }

    TPoint2D operator*(T scalar) const { return TPoint2D(X * scalar, Y * scalar); }
    TPoint2D& operator*=(T scalar) { X *= scalar; Y *= scalar; return *this; }

    TPoint2D operator/(T scalar) const { return TPoint2D(X / scalar, Y / scalar); }
    TPoint2D& operator/=(T scalar) { X /= scalar; Y /= scalar; return *this; }

    TPoint2D operator%(T scalar) const { return TPoint2D(X % scalar, Y % scalar); }
    TPoint2D& operator%=(T scalar) { X %= scalar; Y %= scalar; return *this; }

    T Length() const { return static_cast<T>(sqrt(static_cast<double>(X) * static_cast<double>(X) + static_cast<double>(Y) * static_cast<double>(Y))); }
    T Distance_To(TPoint2D const& point) const { return (*this - point).Length(); }

    TPoint2D Normalized() const
    {
        T length = Length();
        if (length == 0) {
            return *this;
        }

        return *this / length;
    }

public:
    T X;
    T Y;
};


template<typename T>
class TPoint3D : public TPoint2D<T>
{
public:
    TPoint3D() : TPoint2D<T>() {} // Default constructor does nothing by design.
    TPoint3D(T x, T y, T z) : TPoint2D<T>(x, y), Z(z) {}

    // Shuts up Intellisense warnings.
    using TPoint2D<T>::X;
    using TPoint2D<T>::Y;

    bool operator==(const TPoint3D& that) const { return X == that.X && Y == that.Y && Z == that.Z; }
    bool operator!=(const TPoint3D& that) const { return X != that.X && Y != that.Y && Z != that.Z; }

    TPoint3D operator+(const TPoint3D& that) const { return TPoint3D(X + that.X, Y + that.Y, Z + that.Z); }
    TPoint3D& operator+=(const TPoint3D& that) { X += that.X; Y += that.Y; Z += that.Z; return *this; }

    TPoint3D operator-(const TPoint3D& that) const { return TPoint3D(X - that.X, Y - that.Y, Z - that.Z); }
    TPoint3D& operator-=(const TPoint3D& that) { X -= that.X; Y -= that.Y; Z -= that.Z; return *this; }

    TPoint3D operator*(T scalar) const { return TPoint3D(X * scalar, Y * scalar, Z * scalar); }
    TPoint3D& operator*=(T scalar) { X *= scalar; Y *= scalar; Z *= scalar; return *this; }

    TPoint3D operator/(T scalar) const { return TPoint3D(X / scalar, Y / scalar, Z / scalar); }
    TPoint3D& operator/=(T scalar) { X /= scalar; Y /= scalar; Z /= scalar; return *this; }

    TPoint3D operator%(T scalar) const { return TPoint3D(X % scalar, Y % scalar, Z % scalar); }
    TPoint3D& operator%=(T scalar) { X %= scalar; Y %= scalar; Z %= scalar; return *this; }

    T Length() const { return static_cast<T>(sqrt(static_cast<double>(X) * static_cast<double>(X) + static_cast<double>(Y) * static_cast<double>(Y) + static_cast<double>(Z) * static_cast<double>(Z))); }
    T Distance_To(TPoint3D const& point) const { return (*this - point).Length(); }

    TPoint3D Normalized() const
    {
        T length = Length();
        if (length == 0) {
            return *this;
        }

        return *this / length;
    }

public:
    T Z;
};


/**
 *  These typedefs provide uncluttered type names for integer points.
 */
typedef TPoint2D<int> Point2D;
typedef TPoint3D<int> Point3D;
