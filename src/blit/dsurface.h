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
#include "rgb.h"
#include "xsurface.h"


#define DIRECTDRAW_VERSION 0x0100 // Use DirectDraw 1.0
#include <ddraw.h>


class DSurface : public XSurface
{
public:
    DSurface();
    DSurface(int width, int height, bool system_memory = false);
    DSurface(LPDIRECTDRAWSURFACE surface);
    virtual ~DSurface();

    virtual bool Blit_From(Rect const& dcliprect, Rect const& destrect, Surface const& source, Rect const& scliprect, Rect const& sourcerect, bool trans = false, bool a7 = true) override;
    virtual bool Blit_From(Rect const& destrect, Surface const& source, Rect const& sourcerect, bool trans = false, bool a5 = true) override;
    virtual bool Blit_From(Surface const& source, bool trans = false, bool a3 = true) override;
    virtual bool Fill_Rect(Rect const& rect, unsigned color) override;
    virtual bool Fill_Rect(Rect const& cliprect, Rect const& fillrect, unsigned color) override;
    virtual bool Fill_Rect_Trans(Rect const& rect, RGBClass const& color, unsigned opacity) override;
    virtual bool Draw_Line_entry_34(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int color, int a5, int a6, bool a7 = false) override;
    virtual bool Draw_Line_entry_38(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, int a4, int a5, int a6, bool a7 = false) override;
    virtual bool Draw_Line_entry_3C(Rect const& cliprect, Point2D const& startpoint, Point2D const& endpoint, RGBClass const& color, int a5, int a6, bool a7, bool a8, bool a9, bool a10, float a11) override;
    virtual int entry_48(Point2D const& startpoint, Point2D const& endpoint, int color, bool pattern[], int offset, bool a6) override;
    virtual bool entry_4C(Point2D const& startpoint, Point2D const& endpoint, int color, bool a4 = false) override;
    virtual void* Lock(Point2D point = Point2D(0, 0)) override;
    virtual bool Unlock() override;
    virtual bool Can_Lock(int x = 0, int y = 0) const override;
    virtual int Bytes_Per_Pixel() const override;
    virtual int Stride() const override;
    virtual bool Is_Direct_Draw() const override;

    virtual bool entry_90(Rect& area, Point2D& start, Point2D& end, RGBClass& a4, RGBClass& a5, float& a6, float& a7);
    virtual bool Can_Blit() const;

    bool In_Video_Ram() const { return IsVideoRam; }

    LPDIRECTDRAWSURFACE Get_DD_Surface() { return SurfacePtr; }

    static DSurface* Create_Primary(DSurface** backsurface1 = nullptr);

    static unsigned Build_Hicolor_Pixel(unsigned r, unsigned g, unsigned b) { return (unsigned((b >> BlueRight) << BlueLeft) | unsigned((r >> RedRight) << RedLeft) | unsigned((g >> GreenRight) << GreenLeft)); }
    static unsigned Build_Hicolor_Pixel(RGBClass& rgb) { return (unsigned((rgb.Blue >> BlueRight) << BlueLeft) | unsigned((rgb.Red >> RedRight) << RedLeft) | unsigned((rgb.Green >> GreenRight) << GreenLeft)); }

    static void Build_Locolor_Pixel(unsigned pixel, unsigned* red, unsigned* green, unsigned* blue)
    {
        *red = (unsigned char)(pixel >> RedLeft << RedRight);
        *green = (unsigned char)(pixel >> GreenLeft << GreenRight);
        *blue = (unsigned char)(pixel >> BlueLeft << BlueRight);
    }

    static unsigned Get_Red_Left() { return RedLeft; }
    static unsigned Get_Red_Right() { return RedRight; }

    static unsigned Get_Green_Left() { return GreenLeft; }
    static unsigned Get_Green_Right() { return GreenRight; }

    static unsigned Get_Blue_Left() { return BlueLeft; }
    static unsigned Get_Blue_Right() { return BlueRight; }

public:

    /*
    **  Convenient copy of the bytes per pixel value to speed accessing it. It
    **  gets accessed frequently.
    */
    mutable int BytesPerPixel;

    /*
    **  Lock count and pointer values. This is used to keep track of the levels
    **  of locking the graphic data. This is only here because DirectDraw prohibits
    **  the blitter from working on a surface that has been locked.
    */
    mutable void* LockPtr;

    /*
    **  If this surface object represents the one that is visible and associated
    **  with the system GDI, then this flag will be true.
    */
    bool IsPrimary;

    /*
    **  Is this surface represented in video ram?
    */
    mutable bool IsVideoRam;

    /*
    **  Direct draw specific data.
    */
    LPDIRECTDRAWSURFACE SurfacePtr;
    DDSURFACEDESC* Description;

    /*
    **  Pointer to the clipper object that is attached to the primary
    **  surface.
    */
    static LPDIRECTDRAWCLIPPER& Clipper;

    /*
    **  Pixel format of primary surface.
    */
    static DDPIXELFORMAT& PixelFormat;

public:
    static unsigned& RedRight;
    static unsigned& RedLeft;
    static unsigned& GreenRight;
    static unsigned& GreenLeft;
    static unsigned& BlueRight;
    static unsigned& BlueLeft;

    static bool& AllowStretchBlits;
    static int& PrimaryColorMode;
    static bool& AllowHWFill;
    static bool& OverlappedVideoBlits; // Can video driver blit overlapped regions?

    static unsigned short& HalfbrightMask;
    static unsigned short& QuarterbrightMask;
    static unsigned short& EighthbrightMask;
};
