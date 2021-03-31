/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_DEFINES.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file which contains all the games types.
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


/**
 *  This head contains all the game enums, structs and primitive types.
 */


typedef enum DiffType : int
{
	DIFF_EASY,
	DIFF_NORMAL,
	DIFF_HARD,

	DIFF_COUNT,
	DIFF_FIRST = 0
};


typedef enum FacingType
{
    FACING_N,
    FACING_NE,
    FACING_E,
    FACING_SE,
    FACING_S,
    FACING_SW,
    FACING_W,
    FACING_NW,

    FACING_COUNT,

    FACING_NONE = -1,
    FACING_FIRST = 0
} FacingType;
DEFINE_ENUMERATION_OPERATORS(FacingType);


typedef enum DirType {} DirType;
typedef enum MPHType {} MPHType;
typedef enum CrateType {} CrateType;
typedef enum VocType {} VocType;


typedef unsigned long LEPTON;


#pragma pack(1)
struct _rgb_struct
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
};
#pragma pack()


/**
 *  Shape file format header.
 */
#pragma pack(4)
struct ShapeFileHeaderStruct
{
    int16_t Type; // -1, 0
    int16_t Width; // Width of the shape in bytes.
    int16_t Height; // Height of the shape in scan lines.
    int16_t FrameCount; // Number of shapes in the file.
};
#pragma pack()


/**
 *  Shape file format frame struct.
 */
#pragma pack(4)
struct ShapeFileFrameStruct
{
    Rect Get_Frame_Dimensions() const { return Rect(FrameXPos, FrameYPos, FrameWidth, FrameHeight); }

    int16_t FrameXPos;
    int16_t FrameYPos;
    int16_t FrameWidth;
    int16_t FrameHeight;
    int32_t Flags; 
    _rgb_struct Color;
    uint8_t field_F[5];
    int32_t FrameOffset;
};
#pragma pack()


/**
 *  Shape file format struct. Define pointers to loaded shapes with this
 *  struct instead of casting raw pointers to access header information.
 */
#pragma pack(4)
struct ShapeFileStruct
{
    public:
        operator void *() const { return (*this); } // This allows the struct to be passed implicitly as a raw pointer.

        ShapeFileFrameStruct *Get_Frame_Data(int index)
        {
            return &(&FrameData)[index * sizeof(ShapeFileFrameStruct)];
        }

        int Get_Width() const { return Header.Width; }
        int Get_Height() const { return Header.Height; }
        int Get_Frame_Count() const { return Header.FrameCount; }

    private:
        ShapeFileHeaderStruct Header;

        /**
         *  This is an instance of the first frame in the shape file, use Get_Frame_Data
         *  to get the frame information, do not access this directly!
         */
        ShapeFileFrameStruct FrameData;
};
#pragma pack()
