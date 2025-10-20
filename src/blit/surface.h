/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SURFACE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Surface abstract class.
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

#include "clipline.h"
#include "point.h"
#include "rect.h"


class RGBClass;


#define TBLACK 0 // Transparent black pixel.


class Surface
{
public:
    Surface(int width, int height);
    virtual ~Surface() {}

    virtual bool Blit_From(Rect const& dcliprect, Rect const& destrect, Surface const& source, Rect const& scliprect, Rect const& sourcerect, bool trans = false, bool a7 = true) = 0;
    virtual bool Blit_From(Rect const& destrect, Surface const& source, Rect const& sourcerect, bool trans = false, bool a5 = true) = 0;
    virtual bool Blit_From(Surface const& source, bool trans = false, bool a3 = true) = 0;
    virtual bool Fill_Rect(Rect const& rect, int color) = 0;
    virtual bool Fill_Rect(Rect const& cliprect, Rect const& fillrect, int color) = 0;
    virtual bool Fill(int color) = 0;
    virtual bool Fill_Rect_Trans(Rect const& rect, RGBClass const& color, int opacity) = 0;
    virtual bool Draw_Ellipse(Point2D center, int radius_x, int radius_y, Rect clip, int color) = 0;
    virtual bool Put_Pixel(Point2D const& point, int color) = 0;
    virtual int Get_Pixel(Point2D const& point) = 0;
    virtual bool Draw_Line(Point2D const& startpoint, Point2D const& endpoint, int color) = 0;
    virtual bool Draw_Line(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int color) = 0;
    virtual bool Draw_Line_entry_34(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int color, int a5, int a6, bool a7 = false) = 0;
    virtual bool Draw_Line_entry_38(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int a4, int a5, int a6, bool a7 = false) = 0;
    virtual bool Draw_Line_entry_3C(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, RGBClass const& color, int a5, int a6, bool a7, bool a8, bool a9, bool a10, float a11) = 0;
    virtual bool Plot_Line(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, void (*drawer_callback)(Point2D&)) = 0;
    virtual int Draw_Dashed_Line(Point2D const& startpoint, Point2D const& endpoint, int color, bool pattern[], int offset) = 0;
    virtual int entry_48(Point2D const& startpoint, Point2D const& endpoint, int color, bool pattern[], int offset, bool a6) = 0;
    virtual bool entry_4C(Point2D const& startpoint, Point2D const& endpoint, int color, bool a4 = false) = 0;
    virtual bool Draw_Rect(Rect const& rect, int color) = 0;
    virtual bool Draw_Rect(Rect const& cliprect, Rect const& rect, int color) = 0;
    virtual void* Lock(Point2D point = Point2D(0, 0)) const = 0;
    virtual bool Unlock() const = 0;
    virtual bool Can_Lock(int x = 0, int y = 0) const;
    virtual bool entry_64(int x = 0, int y = 0) const;
    virtual bool Is_Locked() const = 0;
    virtual int Bytes_Per_Pixel() const = 0;
    virtual int Stride() const = 0;
    virtual Rect Get_Rect() const;
    virtual int Get_Width() const;
    virtual int Get_Height() const;
    virtual bool Is_Direct_Draw() const;
    virtual bool entry_84(Point2D const& point, int color, Rect const& rect) = 0;
    virtual int entry_88(Point2D const& point, Rect const& rect) const = 0;

    bool Clear() { return Fill(TBLACK); }
    bool Clear(Rect const& area) { return Fill_Rect(area, TBLACK); }

    int Draw_Dashed_Line(const Rect& xcliprect, Point2D& startpoint, Point2D& endpoint, unsigned color, bool pattern[], int offset)
    {
        /**
         *  Ensure that the clipping rectangle is legal.
         */
        Rect cliprect = Intersect(xcliprect, Get_Rect());

        /**
         *  Ensure that the line lies within the rectangle.
         */
        if (!Clip_Line(startpoint, endpoint, cliprect)) return offset;

        return Draw_Dashed_Line(startpoint, endpoint, color, pattern, offset);
    }

public:
    int Width;
    int Height;
};
