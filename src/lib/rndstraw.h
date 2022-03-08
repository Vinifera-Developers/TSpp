/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RNDSTRAW.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         Straw for generating random numbers.
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
#include "random.h"
#include "sha.h"
#include "tspp_assert.h"
#include <cstring>
#include <algorithm>


template<class RNG>
class RandomStraw : public Straw
{
    public:
        RandomStraw();
        virtual ~RandomStraw();

        virtual int Get(void *buffer, int length) override;

        void Reset();
        void Seed_Bit(int seed);
        void Seed_Byte(char seed);
        void Seed_Short(short seed);
        void Seed_Long(long seed);

        int Seed_Bits_Needed() const;

    private:
        void Scramble_Seed();

    private:
        int SeedBits;
        int Current;
        RNG Random[32];

    private:
        RandomStraw(RandomStraw &) = delete;
        RandomStraw & operator = (const RandomStraw &) = delete;
};


template<class RNG>
RandomStraw<RNG>::RandomStraw() :
    SeedBits(0),
    Current(0),
    Random()
{
    Reset();
}


template<class RNG>
RandomStraw<RNG>::~RandomStraw()
{
    Reset();
}


template<class RNG>
void RandomStraw<RNG>::Reset()
{
    SeedBits = 0;
    Current = 0;

    std::memset(&Random, 0, sizeof(Random));
}


template<class RNG>
int RandomStraw<RNG>::Get(void *buffer, int length)
{
    TSPP_ASSERT(buffer != nullptr);
    TSPP_ASSERT(length > 0);

    if (buffer == NULL || length < 1) {
        return Straw::Get(buffer, length);
    }

    int total = 0;
    while (length > 0) {
        *(char *)buffer = (char)Random[Current++];
        Current = Current % (sizeof(Random) / sizeof(Random[0]));
        buffer = (char*)buffer + sizeof(char);
        length--;
        total++;
    }
    return total;
}


template<class RNG>
int RandomStraw<RNG>::Seed_Bits_Needed() const
{
    const int total = sizeof(Random) * CHAR_BIT;
    if (SeedBits < total) {
        return total - SeedBits;
    }
    return 0;
}


template<class RNG>
void RandomStraw<RNG>::Scramble_Seed()
{
    SHAEngine sha;

    for (int index = 0; index < sizeof(Random); index++) {
        char digest[20];
        sha.Hash(&Random[0], sizeof(Random));
        sha.Result(digest);
        int tocopy = sizeof(digest) < (sizeof(Random)-index) ? sizeof(digest) : (sizeof(Random)-index);
        std::memmove(((char *)&Random[0]) + index, digest, tocopy);
    }
}


template<class RNG>
void RandomStraw<RNG>::Seed_Bit(int seed)
{
    char * ptr = ((char *)&Random[0]) + ((SeedBits / CHAR_BIT) % sizeof(Random));
    char frac = (char)(1 << (SeedBits & (CHAR_BIT-1)));

    if (seed & 0x01) {
        *ptr ^= frac;
    }

    SeedBits++;

    if (SeedBits == (sizeof(Random) * CHAR_BIT)) {
        Scramble_Seed();
    }
}


template<class RNG>
void RandomStraw<RNG>::Seed_Byte(char seed)
{
    for (int index = 0; index < CHAR_BIT; index++) {
        Seed_Bit(seed);
        seed >>= 1;
    }
}


template<class RNG>
void RandomStraw<RNG>::Seed_Short(short seed)
{
    for (int index = 0; index < (sizeof(seed)*CHAR_BIT); index++) {
        Seed_Bit(seed);
        seed >>= 1;
    }
}


template<class RNG>
void RandomStraw<RNG>::Seed_Long(long seed)
{
    for (int index = 0; index < (sizeof(seed)*CHAR_BIT); index++) {
        Seed_Bit(seed);
        seed >>= 1;
    }
}
