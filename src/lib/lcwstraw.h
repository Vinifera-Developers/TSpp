/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LCWSTRAW.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         LCW compression straw.
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once

#include "straw.h"


class LCWStraw : public Straw
{
    public:
        typedef enum CompControl {
            COMPRESS,
            DECOMPRESS
        } CompControl;

        LCWStraw(CompControl control, int blocksize = 1024 * 8);
        virtual ~LCWStraw();

        virtual int Get(void *source, int slen) override;

    private:
        CompControl Control;
        int Counter;
        char * Buffer;
        char * Buffer2;
        int BlockSize;
        int SafetyMargin;

        struct {
            unsigned short CompCount;
            unsigned short UncompCount;
        } BlockHeader;

    private:
        LCWStraw(const LCWStraw &) = delete;
        LCWStraw & operator = (const LCWStraw &) = delete;
};
