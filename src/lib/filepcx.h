/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FILEPCX.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Reading and writing of PCX image files to buffers.
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


class Surface;
class FileClass;


typedef enum PCX_MANF_ID {
    PCX_ZSOFT = 10
};


typedef enum PCX_VERSION {
    PCX_VER25 = 0,
    PCX_VER28_PAL = 2,
    PCX_VER28_NPAL = 3,
    PCX_FOR_WIN = 4,
    PCX_VER30 = 5
};


typedef enum PCX_ENCODING {
    PCX_ENC_RLE = 1
};


typedef enum PCX_BITSPERPIXEL {
    PCX_BPP_MONO = 1,
    PCX_BPP_COLOR = 8,
};


typedef enum PCX_PAL_INFO {
    PCX_PAL_INFO_COLOR = 1,
    PCX_PAL_INFO_GREYSCALE = 2
};


typedef enum PCX_PLANES {
    PCX_PLANES_1 = 1, // packed.
    PCX_PLANES_3 = 3  // 3 rows. r, g, b.
};


typedef struct PCX_HEADER {
    char Id;                /*  00h     Manufacturer ID        */
    char Version;           /*  01h     Version                */
    char Encoding;          /*  02h     Encoding Scheme        */
    char BitsPixelPlane;    /*  03h     Bits/Pixel/Plane       */
    short Xmin;             /*  04h     X Start (upper left)   */
    short Ymin;             /*  06h     Y Start (top)          */
    short Xmax;             /*  08h     X End (lower right)    */
    short Ymax;             /*  0Ah     Y End (bottom)         */
    short Xres;             /*  0Ch     Horizontal Resolution  */
    short Yres;             /*  0Eh     Vertical Resolution    */
    char EgaPalette[48];    /*  10h     16-Color EGA Palette   */
    char ReservedByte;      /*  40h     Reserved               */
    char NumberOfPlanes;    /*  41h     Number of Color Planes */
    short BytesLinePlane;   /*  42h     Bytes/Line/Plane       */
    short PaletteInfo;      /*  44h     Palette Interpretation */
    short HScreenSize;      /*  46h     Horizontal Screen Size */
    short VScreenSize;      /*  48h     Vertical Screen Size   */
    char ReservedBlock[54]; /*  4Ah     Reserved               */
};


Surface* Read_PCX_File(FileClass* file, unsigned char* palette = nullptr, void* buff = nullptr, long size = 0);
bool Write_PCX_File(FileClass* file, Surface& pic, unsigned char* palette);
