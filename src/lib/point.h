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
#include "tpoint.h"


class Rect;


class Point2D
{
    public:
        Point2D();
        Point2D(int x, int y);
        Point2D(const Point2D &that);
        Point2D(const TPoint2D<int> &that);

        Point2D &operator=(const Point2D &that)
        {
            if (this != &that) {
                X = that.X;
                Y = that.Y;
            }
            return *this;
        }

        Point2D &operator=(const TPoint2D<int> &that)
        {
            X = that.X;
            Y = that.Y;
            return *this;
        }

        bool operator==(const Point2D &that) const { return X == that.X && Y == that.Y; }
        bool operator!=(const Point2D &that) const { return X != that.X && Y != that.Y; }

        Point2D operator+() const { return Point2D(+X, +Y); }
        Point2D operator-() const { return Point2D(-X, -Y); }

        Point2D operator+(const Point2D &that) const { return Point2D(X + that.X, Y + that.Y); }
        Point2D &operator+=(const Point2D &that) { X += that.X; Y += that.Y; return *this; }

        Point2D operator-(const Point2D &that) const { return Point2D(X - that.X, Y - that.Y); }
        Point2D &operator-=(const Point2D &that) { X -= that.X; Y -= that.Y; return *this; }

        Point2D operator*(const Point2D &that) const { return Point2D(X * that.X, Y * that.Y); }
        Point2D operator*=(const Point2D &that) { X *= that.X; Y *= that.Y; return *this; }
        Point2D operator*(int factor) const { return Point2D(X * factor, Y * factor); }
        Point2D &operator*=(int factor) { X *= factor; Y *= factor; return *this; }

        Point2D operator/(const Point2D &that) const { return Point2D(X / that.X, Y / that.Y); }
        Point2D operator/=(const Point2D &that) { X /= that.X; Y /= that.Y; return *this; }
        Point2D operator/(int factor) const { return Point2D(X / factor, Y / factor); }
        Point2D &operator/=(int factor) { X /= factor; Y /= factor; return *this; }

        Point2D operator%(const Point2D &that) const { return Point2D(X / that.X, Y / that.Y); }
        Point2D operator%=(const Point2D &that) { X /= that.X; Y /= that.Y; return *this; }
        Point2D operator%(int factor) const { return Point2D(X / factor, Y / factor); }
        Point2D &operator%=(int factor) { X /= factor; Y /= factor; return *this; }

        Point2D operator&(const Point2D &that) const { return Point2D(X & that.X, Y & that.Y); }
        Point2D operator&=(const Point2D &that) { X &= that.X; Y &= that.Y; return *this; }
        Point2D operator&(int factor) const { return Point2D(X & factor, Y & factor); }
        Point2D &operator&=(int factor) { X &= factor; Y &= factor; return *this; }

        bool operator>(const Point2D &that) const { return X > that.X || X == that.X && Y > that.Y; }
        bool operator>=(const Point2D &that) const { return X >= that.X || X == that.X && Y >= that.Y; }

        bool operator<(const Point2D &that) const { return X < that.X || X == that.X && Y < that.Y; }
        bool operator<=(const Point2D &that) const { return X <= that.X || X == that.X && Y <= that.Y; }

        bool Is_Valid() const { return X > 0 || Y > 0; }

    public:
        int X;
        int Y;
};


class Point3D
{
    public:
        Point3D();
        Point3D(int x, int y, int z);
        Point3D(const Point3D &that);
        Point3D(const TPoint3D<int> &that);

        Point3D &operator=(const Point3D &that)
        {
            if (this != &that) {
                X = that.X;
                Y = that.Y;
                Z = that.Z;
            }
            return *this;
        }

        Point3D &operator=(const TPoint3D<int> &that)
        {
            X = that.X;
            Y = that.Y;
            Z = that.Z;
            return *this;
        }

        bool operator==(const Point3D &that) const { return X == that.X && Y == that.Y && Z == that.Z; }
        bool operator!=(const Point3D &that) const { return X != that.X && Y != that.Y && Z != that.Z; }

        Point3D operator+() const { return Point3D(+X, +Y, +Z); }
        Point3D operator-() const { return Point3D(-X, -Y, -Z); }

        Point3D operator+(const Point3D &that) const { return Point3D(X + that.X, Y + that.Y, Z + that.Z); }
        Point3D &operator+=(const Point3D &that) { X += that.X; Y += that.Y; Z += that.Z; return *this; }

        Point3D operator-(const Point3D &that) const { return Point3D(X - that.X, Y - that.Y, Z - that.Z); }
        Point3D &operator-=(const Point3D &that) { X -= that.X; Y -= that.Y; Z -= that.Z; return *this; }

        Point3D operator*(const Point3D &that) const { return Point3D(X * that.X, Y * that.Y, Z * that.Z); }
        Point3D operator*=(const Point3D &that) { X *= that.X; Y *= that.Y; Z *= that.Z; return *this; }
        Point3D operator*(int factor) const { return Point3D(X * factor, Y * factor, Z * factor); }
        Point3D &operator*=(int factor) { X *= factor; Y *= factor; Z *= factor; return *this; }

        Point3D operator%(const Point3D &that) const { return Point3D(X / that.X, Y / that.Y, Z / that.Z); }
        Point3D operator%=(const Point3D &that) { X /= that.X; Y /= that.Y; Z /= that.Z; return *this; }
        Point3D operator%(int factor) const { return Point3D(X / factor, Y / factor, Z / factor); }
        Point3D &operator%=(int factor) { X /= factor; Y /= factor; Z /= factor; return *this; }

        Point3D operator&(const Point3D &that) const { return Point3D(X & that.X, Y & that.Y, Z & that.Z); }
        Point3D operator&=(const Point3D &that) { X &= that.X; Y &= that.Y; Z &= that.Z; return *this; }
        Point3D operator&(int factor) const { return Point3D(X & factor, Y & factor, Z & factor); }
        Point3D &operator&=(int factor) { X &= factor; Y &= factor; Z &= factor; return *this; }

        bool Is_Valid() const { return X > 0 || Y > 0 || Z > 0; }

    public:
        int X;
        int Y;
        int Z;
};


inline Point2D::Point2D() :
	X(0),
	Y(0)
{
}


inline Point2D::Point2D(int x, int y) :
	X(x),
	Y(y)
{
}


inline Point2D::Point2D(const Point2D &that) :
	X(that.X),
	Y(that.Y)
{
}


inline Point2D::Point2D(const TPoint2D<int> &that) :
    X(that.X),
    Y(that.Y)
{
}


inline Point3D::Point3D() :
	X(0),
	Y(0),
	Z(0)
{
}


inline Point3D::Point3D(int x, int y, int z) :
	X(x),
	Y(y),
	Z(z)
{
}


inline Point3D::Point3D(const Point3D &that) :
	X(that.X),
	Y(that.Y),
	Z(that.Z)
{
}


inline Point3D::Point3D(const TPoint3D<int> &that) :
    X(that.X),
    Y(that.Y),
    Z(that.Z)
{
}
