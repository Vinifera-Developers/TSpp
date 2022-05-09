/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STATICHEAP.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Static fixed heap container.
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
#include "tspp_assert.h"


template<typename T, int Size>
class StaticHeapClass
{
    public:
        StaticHeapClass();
        ~StaticHeapClass();

        T * operator [] (int index) { TSPP_ASSERT(index < Avail()); return &Buffer[index]; }
        T const * operator [] (int index) const { TSPP_ASSERT(index < Avail()); return &Buffer[index]; }

        int Count() const { return ActiveCount; }
        int Length() const { return Size; }
        int Avail() const { return Size-ActiveCount; }

        void Reset() { ActiveCount = 0; }
        T * Get_Free_Block() const;

    private:
        /**
         *  Pointer to the heap's memory buffer.
         */
        T Buffer[Size];

        /**
         *  This is the total blocks allocated out of the heap.
         */
        int ActiveCount;

    private:
        StaticHeapClass & operator = (StaticHeapClass const &);
        StaticHeapClass(StaticHeapClass const &);
};


template<typename T, int Size>
inline StaticHeapClass<T, Size>::StaticHeapClass() :
    Buffer(),
    ActiveCount(0)
{
}


template<typename T, int Size>
inline StaticHeapClass<T, Size>::~StaticHeapClass()
{
}


template<typename T, int Size>
inline T * StaticHeapClass<T, Size>::Get_Free_Block() const
{
    // #BUGFIX: Added check to heap size to stop overrun.
    if (ActiveCount++ == Size) {
        TSPP_ASSERT_FATAL_PRINT(true, "No free blocks available!");
        return nullptr;
    }

    return &Buffer[ActiveCount];
}
