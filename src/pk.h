/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PK.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Public Key Cryptography.
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


class Straw;


class PKey
{
    public:
        PKey() : Modulus(), Exponent(), BitPrecision(0) { std::memset(Modulus, 0, 256); std::memset(Exponent, 0, 256); }

    private:
        char Modulus[256];         // BigInt
        char Exponent[256];        // BigInt
        int BitPrecision;
};
