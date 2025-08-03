/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DSURFACE.CPP
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Direct Draw surface class.
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
#include "dsurface.h"
#include "rgb.h"
#include "wwmath.h"


static void Sort_Vertices(Point2D* p1, Point2D* p2, Point2D* p3)
{
    Point2D* temp;
    if (p1->Y > p2->Y) {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
    if (p1->Y > p3->Y) {
        temp = p1;
        p1 = p3;
        p3 = temp;
    }
    if (p2->Y > p3->Y) {
        temp = p2;
        p2 = p3;
        p3 = temp;
    }
}


static void Fill_Triangle_Top(Surface& surface, Point2D& point1, Point2D& point2, Point2D& point3, unsigned color)
{
    if (point2.X > point3.X) {
        Point2D temp = point2;
        point2 = point3;
        point3 = temp;
    }
    float a = (point2.X - point1.X) / (point2.Y - point1.Y);
    float b = (point3.X - point1.X) / (point3.Y - point1.Y);
    float left = point1.X;
    float right = point1.X;
    for (int idy = point1.Y; idy <= point2.Y; ++idy) {
        for (int idx = left; idx <= right; ++idx) {
            surface.Put_Pixel(Point2D(idx, idy), color);
        }
        left += a;
        right += b;
    }
}


static void Fill_Triangle_Bottom(Surface& surface, Point2D& point1, Point2D& point2, Point2D& point3, unsigned color)
{
    if (point1.X > point2.X) {
        Point2D temp = point2;
        point2 = point1;
        point1 = temp;
    }
    float a = (point3.X - point1.X) / (point3.Y - point1.Y);
    float b = (point3.X - point2.X) / (point3.Y - point2.Y);
    float left = point3.X;
    float right = point3.X;
    for (int idy = point3.Y; idy > point2.Y; --idy) {
        for (int idx = left; idx <= right; ++idx) {
            surface.Put_Pixel(Point2D(idx, idy), color);
        }
        left -= a;
        right -= b;
    }
}


bool DSurface::Draw_Triangle(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, unsigned color)
{
    Draw_Line(rect, point1, point2, color);
    Draw_Line(rect, point2, point3, color);
    Draw_Line(rect, point3, point1, color);

    return true;
}


/**
 *
 *
 *  @author: Darth Jane
 */
bool DSurface::Fill_Triangle(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, unsigned color)
{
    if (!rect.Is_Valid()) {
        return false;
    }

    Rect r1 = Intersect(Get_Rect(), rect);

    if (!r1.Is_Valid()) {
        return false;
    }

    Point2D r1_tl = r1.Top_Left();
    unsigned short* buffptr = (unsigned short*)Lock(r1_tl.X, r1_tl.Y);
    if (buffptr == nullptr) {
        return false;
    }

    /**
     *  At first sort the three vertices by y-coordinate ascending so v1 is the topmost vertice.
     */
    Sort_Vertices(&point1, &point2, &point3);

    /**
     *  Here we know that point1.Y <= point2.Y <= point3.Y
     *  check for trivial case of bottom-flat triangle.
     */
    if (point2.Y == point3.Y) {
        Fill_Triangle_Top(*this, point1, point2, point3, color);

        /**
         *  Check for trivial case of top-flat triangle.
         */
    } else if (point1.Y == point2.Y) {
        Fill_Triangle_Bottom(*this, point1, point2, point3, color);

        /**
         *  General case - split the triangle in a topflat and bottom-flat one.
         */
    } else {
        Point2D point4((int)(point1.X + ((float)(point2.Y - point1.Y) / (float)(point3.Y - point1.Y)) * (point3.X - point1.X)), point2.Y);
        Fill_Triangle_Top(*this, point1, point2, point4, color);
        Fill_Triangle_Bottom(*this, point2, point4, point3, color);
    }

    return true;
}


bool DSurface::Fill_Triangle_Trans(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, RGBClass& rgb, unsigned opacity)
{
    // TODO
    return false;
}


bool DSurface::Draw_Quad(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, Point2D& point4, unsigned color)
{
    Draw_Line(rect, point1, point2, color);
    Draw_Line(rect, point2, point3, color);
    Draw_Line(rect, point3, point4, color);
    Draw_Line(rect, point4, point1, color);

    return true;
}


bool DSurface::Fill_Quad(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, Point2D& point4, unsigned color)
{
    Fill_Triangle(rect, point1, point2, point3, color);
    Fill_Triangle(rect, point2, point3, point4, color);

    return true;
}


bool DSurface::Fill_Quad_Trans(Rect& rect, Point2D& point1, Point2D& point2, Point2D& point3, Point2D& point4, RGBClass& rgb, unsigned opacity)
{
    // TODO
    return true;
}


/**
 *  Draw a circle.
 *
 *  Uses a modified Bresenham's Circle Drawing algorithm.
 */
void DSurface::Fill_Circle(const Point2D center, unsigned radius, Rect rect, unsigned color)
{
    Point2D pt(radius, 0);

    Point2D sxy;
    Point2D dxy;

    /**
     *  The roundness factor of the circle.
     *  0 is circle. 50 is rect.
     */
    int roundness_val = 2;

    /**
     *  Calculate start decision delta.
     */
    int d = 3 - (roundness_val * radius);

    do {

        dxy = center + Point2D(pt.X, pt.Y);
        sxy = center + Point2D(-pt.X, pt.Y);
        Draw_Line(rect, sxy, dxy, color);

        dxy = center + Point2D(pt.Y, pt.X);
        sxy = center + Point2D(-pt.Y, pt.X);
        Draw_Line(rect, sxy, dxy, color);

        dxy = center + Point2D(pt.X, -pt.Y);
        sxy = center + Point2D(-pt.X, -pt.Y);
        Draw_Line(rect, sxy, dxy, color);

        dxy = center + Point2D(pt.Y, -pt.X);
        sxy = center + Point2D(-pt.Y, -pt.X);
        Draw_Line(rect, sxy, dxy, color);

        /**
         *  Check decision and update it, x and y.
         */
        if (d < 0) {

            /**
             *  Calculate delta for vertical pixel.
             */
            d += (4 * pt.Y) + 6;

        } else {

            /**
             *  Calculate delta for diagonal pixel.
             */
            d += 4 * (pt.Y - pt.X) + 10;
            pt.X--;
        }

        ++pt.Y;

    } while (pt.X >= pt.Y);
}


void DSurface::Fill_Circle_Trans(const Point2D center, unsigned radius, Rect rect, RGBClass& rgb, unsigned opacity)
{
    Fill_Ellipse_Trans(center, radius, radius, rect, rgb, opacity);
}


void DSurface::Draw_Circle(const Point2D center, unsigned radius, Rect rect, unsigned color)
{
    Draw_Ellipse(center, radius, radius, rect, color);
}


bool DSurface::Fill_Ellipse(Point2D point, int radius_x, int radius_y, Rect clip, unsigned color)
{
    // TODO
    return false;
}


bool DSurface::Fill_Ellipse_Trans(Point2D point, int radius_x, int radius_y, Rect clip, RGBClass& rgb, unsigned opacity)
{
    // TODO
    return false;
}


bool DSurface::Put_Pixel_Trans(Point2D& point, RGBClass& rgb, unsigned opacity)
{
    int bpp = Get_Bytes_Per_Pixel();
    if (bpp != 2) {
        return false;
    }

    opacity = std::min((int)opacity, 100);

    unsigned scale = (opacity * 255) / 100;
    unsigned short delta = (255 - scale) & 0xFFFF;

    unsigned int red_max = (unsigned int)(255 >> RedRight) << RedLeft;
    unsigned int green_max = (unsigned int)(255 >> GreenRight) << GreenLeft;
    unsigned int blue_max = (unsigned int)(255 >> BlueRight) << BlueLeft;

    unsigned short color = RGB_To_Pixel(rgb.Red, rgb.Green, rgb.Blue);

    unsigned rscaled = scale * (color & red_max);
    unsigned gscaled = scale * (color & green_max);
    unsigned bscaled = scale * (color & blue_max);

    unsigned short rmax = red_max & 0xFFFF;
    unsigned short gmax = green_max & 0xFFFF;
    unsigned short bmax = blue_max & 0xFFFF;

    unsigned short* current_pixel = (unsigned short*)Lock(point.X, point.Y);
    *current_pixel = (unsigned short)(((*current_pixel & rmax) * (delta + rscaled) >> 8) & rmax) | (((*current_pixel & gmax) * (delta + gscaled) >> 8) & gmax) | (((*current_pixel & bmax) * (delta + bscaled) >> 8) & bmax);

    Unlock();

    return true;
}
