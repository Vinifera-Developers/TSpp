/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Floating and double point math functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "wwmath.h"
#include <fenv.h>


/**
 *  Helper function for calculating the tables at runtime..
 */
template<typename T, int N>
inline Array<T, N> Calculate_Fast_Table(T (*func)(T), bool arc)
{
    Array<T, N> table;
    for (int a = 0; a < N; ++a) {
        float cv = arc ? (a - N / T(2)) * (T(1) / (N / T(2))) : T(a) * 2.0f * WWMATH_PI / SIN_TABLE_SIZE;

        table[a] = func(cv);
    }
    return table;
}


/**
 *  Calculate all tables at compile time.
 */
const Array<float, ARC_TABLE_SIZE> _FastAcosTable = Calculate_Fast_Table<float, ARC_TABLE_SIZE>(WWMath::Acosf, true);
const Array<float, ARC_TABLE_SIZE> _FastAsinTable = Calculate_Fast_Table<float, ARC_TABLE_SIZE>(WWMath::Asinf, true);
const Array<float, SIN_TABLE_SIZE> _FastSinTable = Calculate_Fast_Table<float, SIN_TABLE_SIZE>(WWMath::Sinf, false);
const Array<float, SIN_TABLE_SIZE> _FastInvSinTable = Calculate_Fast_Table<float, SIN_TABLE_SIZE>(WWMath::Inv_Sin, false);


static void __cdecl WWMath_Shutdown()
{
    WWMath::Shutdown();
}

void WWMath::Init()
{
    static bool _onetime = false;
    if (!_onetime) {
        std::atexit(WWMath_Shutdown);
        _onetime = true;
    }

    /**
     *  Set the FPU mode to match the game (rounding towards zero [chop mode]).
     */
    _set_controlfp(_RC_CHOP, _MCW_RC);

    /**
     *  And this is required for the std c++ lib.
     */
    fesetround(FE_TOWARDZERO);
}


void WWMath::Shutdown()
{
}
