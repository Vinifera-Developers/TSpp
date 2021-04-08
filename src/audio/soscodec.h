/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SOSCODEC.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Routines for decompressing/compressing digital sounds.
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


/**
 *  Compression types.
 */
enum {
	_ADPCM_TYPE_1,
};


/**
 *  Mono compression structure.
 */
#pragma pack(push, 1)
typedef struct _tagCOMPRESS_INFO
{
    uint8_t *lpSource;       // buffers for compressed data
    uint8_t *lpDest;         // buffer for uncompressed data
    uint32_t dwCompSize;     // compressed size
    uint32_t dwUnCompSize;   // uncompressed size

    uint32_t dwSampleIndex;  // sample to decompress location
    uint32_t dwPredicted;    // next predicted sample
    int32_t dwDifference;    // difference from last sample
    uint16_t wCodeBuf;       // code buffer (tokens), holds 2 nibbles for decompression
    uint16_t wCode;          // current 4 bit nibble code
    uint16_t wStep;          // step value in table
    uint16_t wIndex;         // index into step table
    uint16_t wBitSize;       // type of sample to uncompress

} _SOS_COMPRESS_INFO;
#pragma pack(pop)


/**
 *  Stereo compression structure.
 */
#pragma pack(push, 1)
typedef struct _tagCOMPRESS_INFO2
{
    uint8_t *lpSource;       // buffers for compressed data
    uint8_t *lpDest;         // buffer for uncompressed data
    uint32_t dwCompSize;     // compressed size
    uint32_t dwUnCompSize;   // uncompressed size

    uint32_t dwSampleIndex;  // sample to decompress location
    uint32_t dwPredicted;    // next predicted sample
    int32_t dwDifference;    // difference from last sample
    uint16_t wCodeBuf;       // code buffer (tokens), holds 2 nibbles for decompression
    uint16_t wCode;          // current 4 bit nibble code
    uint16_t wStep;          // step value in table
    uint16_t wIndex;         // index into step table

    uint32_t dwSampleIndex2; // these duplicate entries are for the second channel
    uint32_t dwPredicted2;
    int32_t dwDifference2;
    uint16_t wCodeBuf2;
    uint16_t wCode2;
    uint16_t wStep2;
    uint16_t wIndex2;

    uint16_t wBitSize;      // type of sample to uncompress
    uint16_t wChannels;     // number of sources supported

} _SOS_COMPRESS_INFO_2;
#pragma pack(pop)


/**
 *  Compressed file type header.
 */
#pragma pack(push, 1)
typedef struct _tagCOMPRESS_HEADER
{
    uint32_t dwType;             // type of compression
    uint32_t dwCompressedSize;   // compressed file size
    uint32_t dwUnCompressedSize; // uncompressed file size
    uint32_t dwSourceBitSize;    // original bit size
    char szName[16];             // file type, for error checking
} _SOS_COMPRESS_HEADER;
#pragma pack(pop)
