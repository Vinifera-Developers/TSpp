/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RECT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Basic rectangle class.
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
#include "point.h"
#include <algorithm>


class Rect
{
    friend const Rect Intersect(const Rect &rect1, const Rect &rect2);
    friend const Rect Intersect(const Rect &rect1, const Rect &rect2, int *x, int *y);
    friend const Rect Union(const Rect &rect1, const Rect &rect2);

    public:
        Rect();
        Rect(int x, int y, int w, int h);
        Rect(const Point2D &xy, int w, int h);
        Rect(const Point2D &xy, const Point2D &wh);
        Rect(const Rect &that);

        int &operator[](int index) { return (&X)[index]; }
        const int &operator[](int index) const { return (&X)[index]; }

        Rect &operator=(const Rect &that)
        {
            if (this != &that) {
                X = that.X;
                Y = that.Y;
                Width = that.Width;
                Height = that.Height;
            }
            return *this;
        }

        bool operator==(const Rect &that) const
        {
            return (that.X == X) && (that.Width == Width)
                && (that.Y == Y) && (that.Height == Height);
        }

        bool operator!=(const Rect &that) const
        {
          return (that.X != X) && (that.Width != Width)
              && (that.Y != Y) && (that.Height != Height);
        }

        Rect &operator|=(const Rect &that) { *this = ::Union(*this, that); return *this; }
        Rect &operator&=(const Rect &that) { *this = ::Intersect(*this, that); return *this; }
        Rect &operator+=(const Point2D &point) { X += point.X; Y += point.Y; return *this; }

        Rect &operator+=(const Rect &rect)
        {
            X += rect.X;
            Y += rect.Y;
            Width += rect.Width;
            Height += rect.Height;
            return *this;
        }

        Rect &operator-=(const Point2D &point) { X -= point.X; Y -= point.Y; return *this; }

        Rect &operator-=(const Rect &rect)
        {
            X -= rect.X;
            Y -= rect.Y;
            Width -= rect.Width;
            Height -= rect.Height;
            return *this;
        }

        Rect operator+(const Point2D &point)
        {
            Rect tmp = *this;
            tmp.X = X + point.X;
            tmp.Y = Y + point.Y;
            return tmp;
        }

        Rect operator-(const Point2D &point)
        {
            Rect tmp = *this;
            tmp.X = X - point.X;
            tmp.Y = Y - point.Y;
            return tmp;
        }

        Rect Bias_To(const Rect &rect)
        {
            Rect tmp;
            Point2D xy = Top_Left() + rect.Top_Left();
            tmp = Rect(xy, Width, Height);
            return tmp;
        }

        bool Intersects_With(const Rect &with) const
        {
            return (X > with.Width) || (Width < with.X) || (Y > with.Height) || (Height < with.Y);
        }

        bool Is_Overlapping(const Rect &rect)
        {
            return X < rect.X + rect.Width
                && Y < rect.Y + rect.Height
                && X + Width > rect.X
                && Y + Height > rect.Y;
        }

        __forceinline bool Is_Within(const Rect &rect) const { return (rect.X >= X && rect.X < (X + Width)) && (rect.Width >= Y && rect.Width < (Y + Height)); }
        __forceinline bool Is_Within(const Point2D &point) const { return (point.X >= X && point.X < (X + Width)) && (point.Y >= Y && point.Y < (Y + Height)); }
        __forceinline bool Is_Within(int x, int y) const { return (x >= X && x < (X + Width)) && (y >= Y && y < (Y + Height)); }

        void Inflate(int w, int h, bool adjust_xy = false)
        {
            if (adjust_xy) {
                X -= w;
                Y -= h;
            }
            Width += w;
            Height += h;
        }
        
        void Move(int x, int y) { X += x; Y += y; }
        void Move(const Point2D &point) { X += point.X; Y += point.Y; }

        const Rect Intersect_With(const Rect &rectangle, int *x = nullptr, int *y = nullptr) const;

        inline int Size() const { return Width * Height; }

        inline Point2D Center_Point() const { return Point2D(X + (Width / 2), Y + (Height / 2)); }
        inline Point2D Top_Left() const { return Point2D(X, Y); }
        inline Point2D Top_Right() const { return Point2D(X + Width, Y); }
        inline Point2D Bottom_Left() const { return Point2D(X, Y + Height); }
        inline Point2D Bottom_Right() const { return Point2D(X + Width, Y + Height); }
        inline Point2D Top_Center() const { return Point2D((X + Width) / 2, Y); }
        inline Point2D Bottom_Center() const { return Point2D((X + Width) / 2, Height); }
        inline Point2D Left_Center() const { return Point2D(X, (Y + Height) / 2); }
        inline Point2D Center_Right() const { return Point2D(Width, (Y + Height) / 2); }

        inline void Reset_Position() { X = 0; Y = 0; }

        bool Is_Valid() const;

    public:
        int X;
        int Y;
        int Width;
        int Height;

    public:
        static const Rect Invalid;
};


const Rect Intersect(const Rect &rect1, const Rect &rect2, int *x, int *y);
inline const Rect Intersect(const Rect &rect1, const Rect &rect2) { return Intersect(rect1, rect2, nullptr, nullptr); }

const Rect Union(const Rect &rect1, const Rect &rect2);


inline bool operator==(const Rect &left, const Rect &right)
{
    return (left.X == right.X)
        && (left.Width == right.Width)
        && (left.Y == right.Y)
        && (left.Height == right.Height);
}


inline bool operator!=(const Rect &left, const Rect &right)
{
    return (left.X != right.X)
        && (left.Width != right.Width)
        && (left.Y != right.Y)
        && (left.Height != right.Height);
}


inline Rect operator+(const Rect &left, const Rect &right)
{
    Rect result = left;
    Rect tmp = right;
    result += tmp;
    return result;
}


inline Rect operator-(const Rect &left, const Rect &right)
{
    Rect result = left;
    Rect tmp = right;
    result -= tmp;
    return result;
}
