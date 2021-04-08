/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUFF.H
 *
 *  @authors       CCHyper
 *
 *  @brief         A general purpose buffer object.
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


class Buffer
{
    public:
        Buffer(char *ptr, long size = 0);
        Buffer(void *ptr = nullptr, long size = 0);
        Buffer(const void * ptr, long size = 0);
        Buffer(long size);
        Buffer(const Buffer & buffer);
        ~Buffer();

        Buffer & operator = (const Buffer & buffer);

        operator void * () const { return BufferPtr; }
        operator char * () const { return (char *)BufferPtr; }

        void Reset();
        void * Get_Buffer() const { return BufferPtr; }
        long Get_Size() const { return Size; }
        bool Is_Valid() const { return BufferPtr != nullptr; }

    protected:
        void * BufferPtr;
        long Size;
        bool IsAllocated;
};
