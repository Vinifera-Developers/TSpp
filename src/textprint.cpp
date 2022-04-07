/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEXTPRINT.CPP
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
#include "textprint.h"
#include "xsurface.h"
#include "dsurface.h"
#include "point.h"
#include "rgb.h"
#include "wwfont.h"
#include "tspp_assert.h"


/**
 *  Simple_Text_Print that takes a raw rgb color value for the foreground.
 * 
 *  @authors: CCHyper, tomsons26
 */
Point2D Simple_Text_Print(const char *text, XSurface *surface, Rect *rect, Point2D *xy, ConvertClass *drawer, unsigned fore, unsigned back, TextPrintType flag, int a8)
{
    TSPP_ASSERT(surface != nullptr);
    TSPP_ASSERT(rect != nullptr);
    TSPP_ASSERT(xy != nullptr);
    TSPP_ASSERT(a8 < 16);

    if (!text || *text == '\0') {
        return *xy;
    }

    Rect fillrect;
    Point2D pt;
    WWFontClass *font = nullptr;    // Font to use.
    unsigned char fontpalette[16];	// Working font palette array.

    int xpos = xy->X;
    int ypos = xy->Y;

    /**
     *  Get the desired font.
     */
    font = Font_Ptr(flag);
    TSPP_ASSERT(font != nullptr);
    if (!font) {
        return pt;
    }

    /**
     *  Init the font palette to the given background color
     */
    std::memset(&fontpalette[0], back, sizeof(fontpalette));

    int forecolor = fore;

    Rect fontrect;
    font->String_Pixel_Rect(text, &fontrect);

    /**
     *  A gradient font always requires special fixups for the palette
     */
    int point = (flag & 0x000F);
    if (point == TPF_6PT_GRAD || point == TPF_METAL12 || point == TPF_EFNT) {

        /**
         *	Use the foreground color as the entire font remap color as a default.
         */
        forecolor = fore;
        std::memset(&fontpalette[4], fore, (16-4));

        /**
         *  Medium color: Set all font colors to a medium value. This flag
         *  overrides any gradient effects.
         */
        if ((flag & TPF_MEDIUM_COLOR) != 0) {
            forecolor = fore;
            std::memset(&fontpalette[4], fore, (16-4));
        }

        /**
         *  Bright color: Set all font colors to a bright value. This flag
         *  overrides any gradient effects.
         */
        if ((flag & TPF_BRIGHT_COLOR) != 0) {
            forecolor = fore;
            std::memset(&fontpalette[4], fore, (16-4));
        }
    }

	/**
	 *	Change the current font palette according to the dropshadow flags.
	 */
	int shadow = (flag & (TPF_NOSHADOW|TPF_DROPSHADOW|TPF_FULLSHADOW|TPF_LIGHTSHADOW));
	switch (shadow) {

		/**
		 *  The text is rendered plain.
		 */
		case TPF_NOSHADOW:
			fontpalette[2] = back;
			fontpalette[3] = back;
			break;

		/**
		 *  The text is rendered with a simple
		 *  drop shadow.
		 */
		case TPF_DROPSHADOW:
			fontpalette[2] = COLOR_BLACK;
			fontpalette[3] = back;
			break;

		/**
		 *  Special engraved text look for the options
		 *  dialog system.
		 */
		case TPF_LIGHTSHADOW:
			fontpalette[2] = ((14 * 16) + 7)+1;
			fontpalette[3] = back;
			break;

		/**
		 *  Each letter is surrounded by black. This is used
		 *  when the text will be over a non-plain background.
		 */
		case TPF_FULLSHADOW:
			fontpalette[2] = COLOR_BLACK;
			fontpalette[3] = COLOR_BLACK;
			break;

		default:
			break;
	}

    /**
     *  Set the text alignment (default alignment is left).
     */
    int align = flag & (/*TPF_LEFT|*/TPF_CENTER|TPF_RIGHT);
    switch (align) {
        case TPF_CENTER:
            xpos -= font->String_Pixel_Width(text) / 2;
            break;

        case TPF_RIGHT:
            xpos -= font->String_Pixel_Width(text);
            break;

        default:
            break;
    };

	/**
     *  #NEW: Copied over from Red Alert 2 / Yuri's Revenge.
     * 
	 *  Draw a background according to the fill flags.
	 */
    fillrect.X = xpos - 1;
    fillrect.Y = ypos - 1;
    fillrect.Width = fontrect.Width + 2;
    fillrect.Height = fontrect.Height + 2;

	int fill = (flag & (TPF_SOLIDBLACK_BG|TPF_TRANSBLACK_BG));
    switch (fill) {

        /**
         *  Draw a solid black background behind the text.
         */
        case TPF_SOLIDBLACK_BG:
            surface->Fill_Rect(fillrect, DSurface::RGB_To_Pixel(0,0,0)); // Black
            break;

        /**
         *  Draw a semi transparent black background behind the text.
         */
        case TPF_TRANSBLACK_BG:
        {
            surface->Fill_Rect_Trans(fillrect, RGBClass(0,0,0), 60); // Black, 60%
            break;
        }

        default:
            break;
    };

    fontpalette[0] = back;
    fontpalette[a8] = fore;

    Point2D text_xy;
    text_xy.X = xpos;
    text_xy.Y = ypos;

    /**
     *  Draw the text to the surface.
     */
    pt = font->Print(text, surface, rect, &text_xy, drawer, fontpalette);

    return pt;
}
