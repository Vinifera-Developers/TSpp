/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEXTPRINT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Functions for printing text using custom fonts.
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
#include "tibsun_defines.h"


class WWFontClass;
class XSurface;
class HSVClass;
class ColorScheme;
class ConvertClass;


/**
 *  Common palette colors (first 16 entries).
 */
typedef enum ColorType
{
    COLOR_TBLACK,

    COLOR_PURPLE,
    COLOR_CYAN,
    COLOR_GREEN,
    COLOR_LTGREEN,
    COLOR_YELLOW,
    COLOR_PINK,
    COLOR_BROWN,
    COLOR_RED,
    COLOR_LTCYAN,
    COLOR_LTBLUE,
    COLOR_BLUE,
    COLOR_BLACK,
    COLOR_GREY,
    COLOR_LTGREY,
    COLOR_WHITE,

    /**
     *  These defines handle the various names given to the same color.
     */
    COLOR_DKGREEN = COLOR_GREEN,
    COLOR_DKBLUE = COLOR_BLUE,
    COLOR_DKGREY = COLOR_GREY,

    COLOR_PADDING = 0x1000
} ColorType;
DEFINE_ENUMERATION_OPERATORS(ColorType);


/**
 *  These are the control flags for Fancy_Text_Print function.
 */
typedef enum TextPrintType
{
    TPF_NONE = 0,

    /**
     *  Font type.
     */
    TPF_6POINT = 0x0001,		// Use 6 point font.
    TPF_8POINT = 0x0002,		// Use 8 point font.
    TPF_3POINT = 0x0003,		// Use 3 point font.
    TPF_LED = 0x0004,		    // Use LED font.
    TPF_VCR = 0x0005,		    // Use VCR font.
    TPF_6PT_GRAD = 0x0006,		// Use 6 point gradient font.
    TPF_MAP = 0x0007,		    // Font used for pop-up help text.
    TPF_METAL12 = 0x0008,       // Use 12 point tab font
    TPF_EFNT = 0x0009,		    // Use scenario editor font.
    TPF_TYPE = 0x000A,		    // Use teletype font
    TPF_SCORE = 0x000B,		    // Use score screen font.

    /**
     *  Style type.
     */
    TPF_NOSHADOW = 0x0010,		// Don't have any shadow.
    TPF_DROPSHADOW = 0x0020,	// Use a simple drop shadow.
    TPF_FULLSHADOW = 0x0040,	// Use a full outline shadow.
    TPF_LIGHTSHADOW = 0x0080,	// Use engraved drop 'shadow' color.

    /**
     *  Text alignment.
     */
    //TPF_LEFT = 0x0000,		// Left justify text.
    TPF_CENTER = 0x0100,		// Center about the X axis.
    TPF_RIGHT = 0x0200,		    // Right justify text.

    /**
     *  Background fill.
     */
    TPF_SOLIDBLACK_BG = 0x400,

    /**
     *  Gradient flags.
     */
    TPF_MEDIUM_COLOR = 0x1000,	// Use medium color for all text gradient
    TPF_BRIGHT_COLOR = 0x2000,	// Use bright color for all text gradient
    TPF_USE_GRAD_PAL = 0x4000,	// Use a gradient palette based on fore color

    /**
     *  Transparent background fill.
     */
    TPF_TRANSBLACK_BG = 0x8000,

} TextPrintType;
DEFINE_ENUMERATION_OPERATORS(TextPrintType);
DEFINE_ENUMERATION_BITWISE_OPERATORS(TextPrintType);


int Format_Window_String(char *string, WWFontClass *font, int maxlinelen, int &width, int &height);

Point2D Simple_Text_Print(const char *text, XSurface *surface, Rect *rect, Point2D *xy, ColorScheme *fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, int a8 = 1);

Point2D Plain_Text_Print(int text, XSurface *surface, Rect *rect, Point2D *xy, unsigned fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, ColorSchemeType a8 = COLORSCHEME_FIRST, int a9 = 1);
Point2D Plain_Text_Print(char const *text, XSurface *surface, Rect *rect, Point2D *xy, unsigned fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, ColorSchemeType a8 = COLORSCHEME_FIRST, int a9 = 1);

Point2D Fancy_Text_Print(int text, XSurface *surface, Rect *rect, Point2D *xy, ColorScheme *fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, ...);
Point2D Fancy_Text_Print(const char *text, XSurface *surface, Rect *rect, Point2D *xy, ColorScheme *fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, ...);

Point2D Conquer_Clip_Text_Print(const char *text, XSurface *surface, Rect *rect, Point2D *xy, ColorScheme *fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, int width = -1, const int *tabs = nullptr);


Point2D Simple_Text_Print(const char *text, XSurface *surface, Rect *rect, Point2D *xy, ConvertClass *drawer, unsigned fore, unsigned back = COLOR_TBLACK, TextPrintType flag = TPF_8POINT|TPF_DROPSHADOW, int a8 = 1);
