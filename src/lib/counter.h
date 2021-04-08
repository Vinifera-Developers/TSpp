/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COUNTER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Encapsulated vector for handling a list of counted indexes.
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

#include "vector.h"
#include <objidl.h>


class CounterClass : public VectorClass<int>
{
	// Required for GCC.
    using VectorClass<int>::Vector;
    using VectorClass<int>::VectorMax;
    using VectorClass<int>::IsAllocated;

    public:
        CounterClass();
        virtual ~CounterClass();

        virtual void Clear() override;

        int Increment(int index);
        int Decrement(int index);
        bool Grow(int size);
        int Count_Of(int index);
        int Total();

        HRESULT Load(IStream *pStm);
        HRESULT Save(IStream *pStm);
};


template<typename T>
class TCounterClass : CounterClass
{
    public:
        TCounterClass() : CounterClass() {}
        virtual ~TCounterClass() {}

        int Increment(T index) { return CounterClass::Increment((int)index); }
        int Decrement(T index) { return CounterClass::Decrement((int)index); }
        int Count_Of(T index) { return CounterClass::Count((int)index); }
};
