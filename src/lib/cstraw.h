/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CSTRAW.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         Cached straw.
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
#include "buff.h"


class CacheStraw : public Straw
{
    public:
        CacheStraw(const Buffer &buffer) : BufferPtr(buffer), Index(0), Length(0) {}
        CacheStraw(int length = 4096) : BufferPtr(length), Index(0), Length(0) {}
        virtual ~CacheStraw() {}

        virtual int Get(void *source, int slen) override;

    private:
        bool Is_Valid() { return BufferPtr.Is_Valid(); }

    private:
        Buffer BufferPtr;
        int Index;
        int Length;

    private:
        CacheStraw(const CacheStraw &) = delete;
        CacheStraw & operator = (const CacheStraw &) = delete;
};
