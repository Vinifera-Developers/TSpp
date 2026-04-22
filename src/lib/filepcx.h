/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Reading and writing of PCX image files to buffers.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
