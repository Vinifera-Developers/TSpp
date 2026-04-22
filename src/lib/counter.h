/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Encapsulated vector for handling a list of counted indexes.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
    int Value(int index) const;
    int Total() const;

    HRESULT Load(IStream* pStm);
    HRESULT Save(IStream* pStm);
};


template<typename T>
class TCounterClass : public CounterClass
{
public:
    TCounterClass() : CounterClass() {}
    virtual ~TCounterClass() {}

    int Increment(T index) { return CounterClass::Increment((int)index); }
    int Decrement(T index) { return CounterClass::Decrement((int)index); }
    int Value(T index) const { return CounterClass::Value((int)index); }
};
