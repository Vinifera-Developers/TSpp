/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RANDOM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Pseudo-random number generators.
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


class RandomClass
{
    public:
        RandomClass(unsigned seed = 0);

        operator int() { return operator()(); }
        int operator()();
        int operator()(int minval, int maxval);
        template<typename T> T operator()(T minval, T maxval) { return (T)(*this)(int(minval), int(maxval)); }

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
        template<typename T> T operator()(T minval, T maxval) { return (T)(*this)(int(minval), int(maxval)); }

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
        template<typename T> T operator()(T minval, T maxval) { return T(*this)(int(minval), int(maxval)); }

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
        template<typename T> T operator()(T minval, T maxval) { return T(*this)(int(minval), int(maxval)); }

        float Get_Float();

        enum {
            SIGNIFICANT_BITS = 32 // Random number bit significance.
        };
        
    protected:
        unsigned int mt[624]; // state vector
        int mti; // index
};
