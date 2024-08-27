/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWFONT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Westwood font file handler.
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
#include "rect.h"
#include "point.h"
#include "textprint.h"


class Surface;
class ConvertClass;
class PaletteClass;


#pragma pack(1)
typedef struct WWFontHeader
{
	unsigned short FontLength;			// Size of the file.
	unsigned char FontCompress;			// Compression method.
	unsigned char FontDataBlocks;		// Number of blocks that are gonna follow.
	unsigned short InfoBlockOffset;		// Offset to WWFontInfoBlock.
	unsigned short OffsetBlockOffset;	// Offset to array of data offsets.
	unsigned short WidthBlockOffset;	// Offset to array of character widths.
	unsigned short DataBlockOffset;		// Offset to array of offsets to data for each character.
	unsigned short HeightOffset;	    // Offset to array of WWFontHeightBlock for each character.
};
#pragma pack()


#pragma pack(1)
typedef struct  WWFontInfoBlock
{
	unsigned char field_0;				// unknown and unused by code.
	unsigned char field_1;
	unsigned short NumChars;
	unsigned char MaxHeight;
	unsigned char MaxWidth;
};
#pragma pack()


#pragma pack(1)
typedef struct WWFontHeightBlock
{
	unsigned char Row;
	unsigned char Height;
};
#pragma pack()


#pragma pack(1)
typedef struct WWFontFileStruct
{
	WWFontHeader Header;
};
#pragma pack()


class WWFontClass
{
	public:
		WWFontClass(const void *font, bool a2 = false, int a3 = 0);
		virtual ~WWFontClass();

		virtual int Char_Pixel_Width(char chr) const;
		virtual int String_Pixel_Width(const char *string) const;
		virtual void String_Pixel_Rect(const char *string, Rect *rect) const;

		virtual int Get_Char_Width() const;
		virtual int Get_Char_Height() const;
		virtual Point2D Print(const char *string, Surface *surface, Rect *a3, Point2D *a4, ConvertClass *drawer, unsigned char palette[] = nullptr);
		virtual int Set_X_Spacing(int xspace);
		virtual int Set_Y_Spacing(int yspace);

		int Get_Char_Count() const
		{
			return Info_Block_Ptr()->NumChars;
		}

		int Get_Font_Width() const
		{
			return Info_Block_Ptr()->MaxWidth;
		}

		int Get_Font_Height() const
		{
			return Info_Block_Ptr()->MaxHeight;
		}

		int Get_X_Spacing() const { return XSpacing; }
		int Get_Y_Spacing() const { return YSpacing; }

	private:
		WWFontFileStruct * Font_Ptr() const { return reinterpret_cast<WWFontFileStruct *>(FontPtr); }
		WWFontInfoBlock * Info_Block_Ptr() const { return (WWFontInfoBlock *)(reinterpret_cast<unsigned char *>(FontPtr) + FontPtr->Header.InfoBlockOffset); }

	public:
		bool field_4;
		int field_8;
		int XSpacing;
		int YSpacing;
		WWFontFileStruct *FontPtr;
};


WWFontClass *Font_Ptr(TextPrintType flag);
