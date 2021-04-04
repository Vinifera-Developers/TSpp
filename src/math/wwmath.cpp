/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWMATH.CPP
 *
 *  @authors       CCHyper, tomsons26, OmniBlade
 *
 *  @brief         Floating and double point math functions.
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
const Array<float, ARC_TABLE_SIZE> _FastAcosTable = Calculate_Fast_Table<float,ARC_TABLE_SIZE>(WWMath::Acosf, true);
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
