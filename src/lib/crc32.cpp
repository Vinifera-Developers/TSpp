/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Standard CRC32 routines.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "crc32.h"
#include <iterator>


uint32_t CRC32Table[256] = {0};

static const uint32_t CRC32_POLY = 0xEDB88320;
static bool CRC32TableGenerated = false;


static void Generate_CRC32_Table()
{
    for (uint32_t i = 0; i < std::size(CRC32Table); ++i) {
        uint32_t crc = i;

        for (size_t j = 0; j < 8; ++j) {

            /**
             *  Is current coefficient set?
             */
            if (crc & 1) {

                /**
                 *  Yes, then assume it gets zero'd (by implied x^32 coefficient of dividend).
                 */
                crc >>= 1;

                /**
                 *  And then add rest of the divisor.
                 */
                crc ^= CRC32_POLY;

            } else {

                /**
                 *  No, then move to next coefficient.
                 */
                crc >>= 1;
            }
        }

        CRC32Table[i] = crc;
    }

    CRC32TableGenerated = true;
}


uint32_t CRC32_Memory(const void* data, uint32_t bytes, uint32_t prev_crc)
{
    if (!CRC32TableGenerated) {
        Generate_CRC32_Table();
    }

    uint32_t crc = ~prev_crc;

    if (bytes > 0) {
        const uint8_t* buf = static_cast<const uint8_t*>(data);
        uint32_t i = bytes;
        while (i > 0) {
            crc = CRC32Table[uint8_t(*buf) ^ uint8_t(crc)] ^ (crc >> 8);
            ++buf;
            --i;
        }
    }
    return ~crc;
}


uint32_t CRC32_String(const char* string, uint32_t prev_crc)
{
    if (!CRC32TableGenerated) {
        Generate_CRC32_Table();
    }

    uint32_t crc = ~prev_crc;

    for (const uint8_t* buf = reinterpret_cast<const uint8_t*>(string); buf[0] != 0; ++buf) {
        crc = CRC32Table[uint8_t(*buf) ^ uint8_t(crc)] ^ (crc >> 8);
    }

    return ~crc;
}
