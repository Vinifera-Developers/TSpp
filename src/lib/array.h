/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Simple array container.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


template<typename T, int N>
class Array
{
public:
    inline Array() {}

    inline Array(T val)
    {
        for (int i = 0; i < N; ++i) Data[i] = val;
    }

    inline const int Size() const { return N; }

    inline T& operator[](int idx) { return Data[idx]; }

    inline T operator[](int idx) const { return Data[idx]; }

private:
    T Data[N];
};
