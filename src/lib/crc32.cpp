/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CRC32.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Standard CRC32 routines.
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
#include "crc32.h"
#include <cstring>


uint32_t CRC32Table[256] = { 0 };

static const uint32_t CRC32_POLY = 0xEDB88320;
static bool CRC32TableGenerated = false;


static void Generate_CRC32_Table()
{
    for (uint32_t i = 0; i < ARRAY_SIZE(CRC32Table); ++i) {
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


uint32_t CRC32_Memory(const void *data, uint32_t bytes, uint32_t prev_crc)
{
    if (!CRC32TableGenerated) {
        Generate_CRC32_Table();
    }

    uint32_t crc = ~prev_crc;

    if (bytes > 0) {
        const uint8_t *buf = static_cast<const uint8_t *>(data);
        uint32_t i = bytes;
        while (i > 0) {
            crc = CRC32Table[uint8_t(*buf) ^ uint8_t(crc)] ^ (crc >> 8);
            ++buf;
            --i;
        }
    }
    return ~crc;
}


uint32_t CRC32_String(const char *string, uint32_t prev_crc)
{
    if (!CRC32TableGenerated) {
        Generate_CRC32_Table();
    }

    uint32_t crc = ~prev_crc;

    for (const uint8_t *buf = reinterpret_cast<const uint8_t *>(string); buf[0] != 0; ++buf) {
        crc = CRC32Table[uint8_t(*buf) ^ uint8_t(crc)] ^ (crc >> 8);
    }

    return ~crc;
}
