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

#include "rect.h"
#include "tpoint.h"


class RGBClass;


#define TBLACK 0 // Transparent black pixel.


class Surface
{
    public:
        Surface() : Width(0), Height(0) {}
        Surface(int width, int height);
        virtual ~Surface() {}

        virtual bool Copy_From(Rect &toarea, Rect &torect, Surface &fromsurface, Rect &fromarea, Rect &fromrect, bool trans_blit = false, bool a7 = true) = 0;
        virtual bool Copy_From(Rect &torect, Surface &fromsurface, Rect &fromrect, bool trans_blit = false, bool a5 = true) = 0;
        virtual bool Copy_From(Surface &fromsurface, bool trans_blit = false, bool a3 = true) = 0;
        virtual bool Fill_Rect(Rect &rect, unsigned color) = 0;
        virtual bool Fill_Rect(Rect &area, Rect &rect, unsigned color) = 0;
        virtual bool Fill(unsigned color) = 0;
        virtual bool Fill_Rect_Trans(Rect &rect, const RGBClass &color, unsigned opacity) = 0;
        virtual bool Draw_Ellipse(Point2D center, int radius_x, int radius_y, Rect clip, unsigned color) = 0;
        virtual bool Put_Pixel(Point2D &point, unsigned color) = 0;
        virtual unsigned Get_Pixel(Point2D &point) = 0;
        virtual bool Draw_Line(Point2D &start, Point2D &end, unsigned color) = 0;
        virtual bool Draw_Line(Rect &area, Point2D &start, Point2D &end, unsigned color) = 0;
        virtual bool Draw_Line_entry_34(Rect &area, Point2D &start, Point2D &end, unsigned color, int a5, int a6, bool z_only = false) = 0;
        virtual bool Draw_Line_entry_38(Rect &area, Point2D &start, Point2D &end, int a4, int a5, int a6, bool a7 = false) = 0;
        virtual bool Draw_Line_entry_3C(Rect &area, Point2D &start, Point2D &end, RGBClass &color, int a5, int a6, bool a7, bool a8, bool a9, bool a10, float a11) = 0;
        virtual bool entry_40(Rect &area, Point2D &start, Point2D &end, void(*drawer_callback)(Point2D &)) = 0;
        virtual int Draw_Dashed_Line(Point2D &start, Point2D &end, unsigned color, bool pattern[], int offset) = 0;
        virtual int entry_48(Point2D &start, Point2D &end, unsigned color, bool pattern[], int offset, bool a6) = 0;
        virtual bool entry_4C(Point2D &start, Point2D &end, unsigned color, bool a4 = false) = 0;
        virtual bool Draw_Rect(Rect &rect, unsigned color) = 0;
        virtual bool Draw_Rect(Rect &area, Rect &rect, unsigned color) = 0;
        virtual void *Lock(int x = 0, int y = 0) = 0;
        virtual bool Unlock() = 0;
        virtual bool Can_Lock(int x = 0, int y = 0) const;
        virtual bool entry_64(int x = 0, int y = 0) const;
        virtual bool Is_Locked() const = 0;
        virtual int Get_Bytes_Per_Pixel() const = 0;
        virtual int Get_Pitch() const = 0;
        virtual Rect Get_Rect() const;
        virtual int Get_Width() const;
        virtual int Get_Height() const;
        virtual bool entry_80() const;

        bool Clear() { return Fill(TBLACK); }
        bool Clear(Rect &area) { return Fill_Rect(area, TBLACK); }

    protected:
        int Width;
        int Height;
};
