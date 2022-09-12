/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DSURFACE.H
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
#pragma once

#include "always.h"
#include "xsurface.h"
#include "rgb.h"


#define DIRECTDRAW_VERSION 0x0100 // Use DirectDraw 1.0
#include <ddraw.h>


class DSurface : public XSurface
{
    public:
        DSurface();
        DSurface(int width, int height, bool system_mem = false);
        DSurface(LPDIRECTDRAWSURFACE surface);
        virtual ~DSurface();

        virtual bool Copy_From(Rect &toarea, Rect &torect, Surface &fromsurface, Rect &fromarea, Rect &fromrect, bool trans_blit = false, bool a7 = true) override;
        virtual bool Copy_From(Rect &torect, Surface &fromsurface, Rect &fromrect, bool trans_blit = false, bool a5 = true) override;
        virtual bool Copy_From(Surface &fromsurface, bool trans_blit = false, bool a3 = true) override;
        virtual bool Fill_Rect(Rect &rect, unsigned color) override;
        virtual bool Fill_Rect(Rect &area, Rect &rect, unsigned color) override;
        virtual bool Fill_Rect_Trans(Rect &rect, const RGBClass &color, unsigned opacity) override;
        virtual bool Draw_Line_entry_34(Rect &area, Point2D &start, Point2D &end, unsigned color, int a5, int a6, bool z_only = false) override;
        virtual bool Draw_Line_entry_38(Rect &area, Point2D &start, Point2D &end, int a4, int a5, int a6, bool a7 = false) override;
        virtual bool Draw_Line_entry_3C(Rect &area, Point2D &start, Point2D &end, RGBClass &color, int a5, int a6, bool a7, bool a8, bool a9, bool a10, float a11) override;
        virtual int entry_48(Point2D &start, Point2D &end, unsigned color, bool pattern[], int offset, bool a6) override;
        virtual bool entry_4C(Point2D &start, Point2D &end, unsigned color, bool a4 = false) override;
        virtual void *Lock(int x = 0, int y = 0) override;
        virtual bool Unlock() override;
        virtual bool Can_Lock(int x = 0, int y = 0) const override;
        virtual int Get_Bytes_Per_Pixel() const override;
        virtual int Get_Pitch() const override;
        virtual bool entry_80() const override { return true; }

        virtual bool Draw_Line_entry_90(Rect &area, Point2D &start, Point2D &end, RGBClass &a4, RGBClass &a5, float &a6, float &a7);
        virtual bool Can_Blit() const;

        bool Draw_Triangle(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, unsigned color);
        bool Fill_Triangle(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, unsigned color);
        bool Fill_Triangle_Trans(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, RGBClass &rgb, unsigned opacity);

        bool Draw_Quad(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, Point2D &point4, unsigned color);
        bool Fill_Quad(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, Point2D &point4, unsigned color);
        bool Fill_Quad_Trans(Rect &rect, Point2D &point1, Point2D &point2, Point2D &point3, Point2D &point4, RGBClass &rgb, unsigned opacity);

        void Draw_Circle(const Point2D center, unsigned radius, Rect rect, unsigned color);
        void Fill_Circle(const Point2D center, unsigned radius, Rect rect, unsigned color);
        void Fill_Circle_Trans(const Point2D center, unsigned radius, Rect rect, RGBClass &rgb, unsigned opacity);
        
        bool Fill_Ellipse(Point2D point, int radius_x, int radius_y, Rect clip, unsigned color);
        bool Fill_Ellipse_Trans(Point2D point, int radius_x, int radius_y, Rect clip, RGBClass &rgb, unsigned opacity);
        bool Put_Pixel_Trans(Point2D &point, RGBClass &rgb, unsigned opacity);

        void *Get_Buffer_Ptr(int x = 0, int y = 0) { return (unsigned char *)(BufferPtr) + (x * Get_Bytes_Per_Pixel()) + (y * Get_Pitch()); }

        bool In_Video_Ram() const { return InVideoRam; }

        LPDIRECTDRAWSURFACE Get_DD_Surface() { return VideoSurfacePtr; }

        static DSurface *Create_Primary(DSurface **backbuffer_surface = nullptr);

        static unsigned RGB_To_Pixel(unsigned r, unsigned g, unsigned b)
        {
            return (unsigned((b >> BlueRight) << BlueLeft)
                  | unsigned((r >> RedRight) << RedLeft)
                  | unsigned((g >> GreenRight) << GreenLeft));
        }

        static unsigned RGB_To_Pixel(RGBClass &rgb)
        {
            return (unsigned((rgb.Red >> BlueRight) << BlueLeft)
                  | unsigned((rgb.Green >> RedRight) << RedLeft)
                  | unsigned((rgb.Blue >> GreenRight) << GreenLeft));
        }

        static void Pixel_To_RGB(unsigned pixel, unsigned *red, unsigned *green, unsigned *blue)
        {
            *red = (unsigned char)(pixel >> RedLeft << RedRight);
            *green = (unsigned char)(pixel >> GreenLeft << GreenRight);
            *blue = (unsigned char)(pixel >> BlueLeft << BlueRight);
        }

        static int Get_RGB_Pixel_Format() { return RGBPixelFormat; }

        static unsigned Get_Red_Left() { return RedLeft; }
        static unsigned Get_Red_Right() { return RedRight; }

        static unsigned Get_Green_Left() { return GreenLeft; }
        static unsigned Get_Green_Right() { return GreenRight; }

        static unsigned Get_Blue_Left() { return BlueLeft; }
        static unsigned Get_Blue_Right() { return BlueRight; }

    public:
        void *BufferPtr;
        bool IsAllocated;
        bool InVideoRam;
        LPDIRECTDRAWSURFACE VideoSurfacePtr;
        LPDDSURFACEDESC VideoSurfaceDescription;

    public:
        static unsigned &RedLeft;
        static unsigned &RedRight;
        static unsigned &GreenLeft;
        static unsigned &GreenRight;
        static unsigned &BlueLeft;
        static unsigned &BlueRight;

        static int &RGBPixelFormat;

        static bool &AllowStretchBlits;
        static bool &AllowHardwareBlitFills;

        static unsigned short &ColorGrey;
        static unsigned short &ColorMidGrey;
        static unsigned short &ColorDarkGrey;
};
