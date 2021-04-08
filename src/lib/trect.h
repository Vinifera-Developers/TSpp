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
#include "tpoint.h"


template<typename T>
class TRect
{
    public:
        TRect() : X(0), Y(0), Width(0), Height(0) { }
        TRect(T x, T y, T w, T h) : X(x), Y(y), Width(w), Height(h) {}
        TRect(const TRect &that) : X(that.X), Y(that.Y), Width(that.Width), Height(that.Height) {}

        TRect &operator=(const TRect &that)
        {
            if (this != &that) {
                X = that.X;
                Y = that.Y;
                Width = that.Width;
                Height = that.Height;
            }
            return *this;
        }

        bool operator==(const TRect &that) const
        {
            return (that.X == X) && (that.Width == Width)
                && (that.Y == Y) && (that.Height == Height);
        }

        bool operator!=(const TRect &that) const
        {
          return (that.X != X) && (that.Width != Width)
              && (that.Y != Y) && (that.Height != Height);
        }

    public:
        T X;
        T Y;
        T Width;
        T Height;
};


template<typename T>
bool operator==(const TRect<T> &left, const TRect<T> &right)
{
    return (left.X == right.X)
        && (left.Width == right.Width)
        && (left.Y == right.Y)
        && (left.Height == right.Height);
}


template<typename T>
bool operator!=(const TRect<T> &left, const TRect<T> &right)
{
    return (left.X != right.X)
        && (left.Width != right.Width)
        && (left.Y != right.Y)
        && (left.Height != right.Height);
}


template<typename T>
TRect<T> operator+(const TRect<T> &left, const TRect<T> &right)
{
    Rect result = left;
    Rect tmp = right;
    result += tmp;
    return result;
}


template<typename T>
TRect<T> operator-(const TRect<T> &left, const TRect<T> &right)
{
    Rect result = left;
    Rect tmp = right;
    result -= tmp;
    return result;
}
