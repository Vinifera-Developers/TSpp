/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          XSURFACE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic drawing surface.
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

#include "surface.h"


class XSurface : public Surface
{
public:
    XSurface(int width = 0, int height = 0);

    bool Blit_From(Rect const& dcliprect, Rect const& destrect, Surface const& source, Rect const& scliprect, Rect const& sourcerect, bool trans = false, bool a7 = true) override;
    bool Blit_From(Rect const& destrect, Surface const& source, Rect const& sourcerect, bool trans = false, bool a5 = true) override;
    bool Blit_From(Surface const& source, bool trans = false, bool a3 = true) override;
    bool Fill_Rect(Rect const& rect, int color) override;
    bool Fill_Rect(Rect const& cliprect, Rect const& fillrect, int color) override;
    bool Fill(int color) override;
    bool Fill_Rect_Trans(Rect const& rect, RGBClass const& color, int opacity) override;
    bool Draw_Ellipse(Point2D point, int radius_x, int radius_y, Rect clip, int color) override;
    bool Put_Pixel(Point2D const& point, int color) override;
    int Get_Pixel(Point2D const& point) override;
    bool Draw_Line(Point2D const& startpoint, Point2D const& endpoint, int color) override;
    bool Draw_Line(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int color) override;
    bool Draw_Line_entry_34(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int color, int a5, int a6, bool a7 = false) override;
    bool Draw_Line_entry_38(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int a4, int a5, int a6, bool a7 = false) override;
    bool Draw_Line_entry_3C(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, RGBClass const& color, int a5, int a6, bool a7, bool a8, bool a9, bool a10, float a11) override;
    bool Plot_Line(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, void (*drawer_callback)(Point2D&)) override;
    int Draw_Dashed_Line(Point2D const& startpoint, Point2D const& endpoint, int color, bool pattern[], int offset) override;
    int entry_48(Point2D const& startpoint, Point2D const& endpoint, int color, bool pattern[], int offset, bool a6) override;
    bool entry_4C(Point2D const& startpoint, Point2D const& endpoint, int color, bool a4 = false) override;
    bool Draw_Rect(Rect const& rect, int color) override;
    bool Draw_Rect(Rect const& cliprect, Rect const& rect, int color) override;
    void* Lock(Point2D point = Point2D(0, 0)) const override;
    bool Unlock() const override;
    bool Is_Locked() const override;
    bool Is_Direct_Draw() const override;
    bool entry_84(Point2D const& point, int color, Rect const& rect) override;
    int entry_88(Point2D const& point, Rect const& rect) const override;

    void Fill_Circle(Point2D center, unsigned radius, Rect rect, int color);

    bool Copy_From_Alpha(Surface& fromsurface, Surface& alphasurface, int x_offset = 0, int y_offset = 0);
    bool Copy_From_Spritesheet(Surface& fromsurface, int sprite_width, int sprite_height, int x_offset, int y_offset);
    bool Copy_From_Spritesheet_Alpha(Surface& fromsurface, Surface& alphasurface, int sprite_width, int sprite_height, int x_offset, int y_offset);

public:
    mutable int LockCount;
};
