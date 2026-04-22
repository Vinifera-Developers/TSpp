/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Pseudo-random number generators.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class RandomClass
{
public:
    RandomClass(unsigned seed = 0);

    operator int() { return operator()(); }
    int operator()();
    int operator()(int minval, int maxval);
    template<typename T>
    T operator()(T minval, T maxval)
    {
        return (T)(*this)(int(minval), int(maxval));
    }

protected:
    unsigned long Seed;
};


class Random2Class
{
public:
    Random2Class(unsigned seed = 0);

    operator int() { return operator()(); }
    int operator()();
    int operator()(int minval, int maxval);
    template<typename T>
    T operator()(T minval, T maxval)
    {
        return (T)(*this)(int(minval), int(maxval));
    }

protected:
    int Index1;
    int Index2;
    int Table[250];
};


class Random3Class
{
public:
    Random3Class(unsigned seed1 = 0, unsigned seed2 = 0);

    operator int() { return operator()(); }
    int operator()();
    int operator()(int minval, int maxval);
    template<typename T>
    T operator()(T minval, T maxval)
    {
        return T(*this)(int(minval), int(maxval));
    }

protected:
    int Seed;
    int Index;

private:
    static unsigned Mix1[20];
    static unsigned Mix2[20];
};

class Random4Class
{
public:
    Random4Class(unsigned int seed = 4357);

    operator int() { return operator()(); }
    int operator()();
    int operator()(int minval, int maxval);
    template<typename T>
    T operator()(T minval, T maxval)
    {
        return T(*this)(int(minval), int(maxval));
    }

    float Get_Float();

    enum {
        SIGNIFICANT_BITS = 32 // Random number bit significance.
    };

protected:
    unsigned int mt[624]; // state vector
    int mti;              // index
};
