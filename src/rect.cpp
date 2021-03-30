/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RECT.CPP
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
#include "rect.h"
#include <algorithm>


const Rect Rect::Invalid = Rect(0, 0, 0, 0);


Rect::Rect() :
    X(0),
    Y(0),
    Width(0),
    Height(0)
{
}


Rect::Rect(int x, int y, int w, int h) :
    X(x), Y(y), Width(w), Height(h)
{
}


Rect::Rect(const Point2D &xy, int w, int h) :
    X(xy.X),
    Y(xy.Y),
    Width(w),
    Height(h)
{
}


Rect::Rect(const Point2D &xy, const Point2D &wh) :
    X(xy.X),
    Y(xy.Y),
    Width(wh.X),
    Height(wh.Y)
{
}


Rect::Rect(const Rect &that) :
   X(that.X),
    Y(that.Y),
    Width(that.Width),
    Height(that.Height)
{
}


const Rect Rect::Intersect_With(const Rect &rectangle, int *x, int *y) const
{
    return Intersect(*this, rectangle, x, y);
}


bool Rect::Is_Valid() const
{
	return Width > 0 && Height > 0;
}


const Rect Intersect(const Rect &rect1, const Rect &rect2, int *x, int *y)
{
    Rect rect(0, 0, 0, 0);
    Rect r = rect2;

    if (!rect1.Is_Valid() || !rect2.Is_Valid()) {
        return rect;
    }

    if (r.X < rect1.X) {
        r.Width -= rect1.X - r.X;
        r.X = rect1.X;
    }
    if (r.Width < 1) return rect;

    if (r.Y < rect1.Y) {
        r.Height -= rect1.Y - r.Y;
        r.Y = rect1.Y;
    }
    if (r.Height < 1) return rect;

    if (r.X + r.Width > rect1.X + rect1.Width) {
        r.Width = rect1.X + rect1.Width - r.X;
    }
    if (r.Width < 1) return rect;

    if (r.Y + r.Height > rect1.Y + rect1.Height) {
        r.Height = rect1.Y + rect1.Height - r.Y;
    }
    if (r.Height < 1) return rect;

    if (x != nullptr) {
        *x -= (r.X-rect2.X);
    }
    if (y != nullptr) {
        *y -= (r.Y-rect2.Y);
    }

    return r;
}


const Rect Union(const Rect &rect1, const Rect &rect2)
{
    Rect r = rect1;

    if (!rect1.Is_Valid()) {
        return rect2;
    }
    if (!rect2.Is_Valid()) {
        return rect1;
    }

    if (r.X > rect2.X) {
        r.Width += r.X-rect2.X;
        r.X = rect2.X;
    }
    if (r.Y > rect2.Y) {
        r.Height += r.Y-rect2.Y;
        r.Y = rect2.Y;
    }
    if (r.X + r.Width < rect2.X + rect2.Width) {
        r.Width = ((rect2.X + rect2.Width) - r.X) + 1;
    }
    if (r.Y + r.Height < rect2.Y + rect2.Height) {
        r.Height = ((rect2.Y + rect2.Height) - r.Y) + 1;
    }
    return r;
}
