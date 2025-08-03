#include "random.h"


template<class T>
static int Pick_Random_Number(T& generator, int minval, int maxval)
{
    if (minval == maxval) return minval;

    if (minval > maxval) {
        int temp = minval;
        minval = maxval;
        maxval = temp;
    }

    int magnitude = maxval - minval;
    int highbit = T::SIGNIFICANT_BITS - 1;
    while ((magnitude & (1 << highbit)) == 0 && highbit > 0) {
        highbit--;
    }

    int mask = ~((~0L) << (highbit + 1));

    int pick = magnitude + 1;
    while (pick > magnitude) {
        pick = generator() & mask;
    }

    return pick + minval;
}


// Period parameters
#define N          624
#define M          397
#define MATRIX_A   0x9908b0df // constant vector a
#define UPPER_MASK 0x80000000 // most significant w-r bits
#define LOWER_MASK 0x7fffffff // least significant r bits

// Tempering parameters
#define TEMPERING_MASK_B     0x9d2c5680
#define TEMPERING_MASK_C     0xefc60000
#define TEMPERING_SHIFT_U(y) (y >> 11)
#define TEMPERING_SHIFT_S(y) (y << 7)
#define TEMPERING_SHIFT_T(y) (y << 15)
#define TEMPERING_SHIFT_L(y) (y >> 18)


Random4Class::Random4Class(unsigned int seed)
{
    if (!seed) {
        seed = 4375;
    }

    mt[0] = seed & 0xffffffff;

    for (mti = 1; mti < N; mti++) {
        mt[mti] = (69069 * mt[mti - 1]) & 0xffffffff;
    }
}

int Random4Class::operator()()
{
    unsigned int y;
    static unsigned int mag01[2] = {0x0, MATRIX_A};

    if (mti >= N) {
        int kk;

        for (kk = 0; kk < N - M; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (; kk < N - 1; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1];

        mti = 0;
    }

    y = mt[mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

    int* x = (int*)&y;

    return *x;
}

int Random4Class::operator()(int minval, int maxval)
{
    return Pick_Random_Number(*this, minval, maxval);
}

float Random4Class::Get_Float()
{
    int x = (*this)();
    unsigned int* y = (unsigned int*)&x;

    return (*y) * 2.3283064370807973754314699618685e-10f;
}
