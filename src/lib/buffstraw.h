/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUFFSTRAW.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         Data buffer straw.
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


class BufferStraw : public Straw
{
    public:
        BufferStraw(const Buffer &buffer) : BufferPtr(buffer), Index(0) {}
        BufferStraw(const void *buffer, int length) : BufferPtr((void*)buffer, length), Index(0) {}

        virtual int Get(void *source, int slen) override;

    private:
        bool Is_Valid() { return BufferPtr.Is_Valid(); }

    private:
        Buffer BufferPtr;
        int Index;

    private:
        BufferStraw(BufferStraw &) = delete;
        BufferStraw & operator = (const BufferStraw &) = delete;
};
