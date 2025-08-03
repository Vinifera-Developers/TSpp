/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PK.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include "int.h"


class Straw;


class PKey
{
public:
    PKey();
    PKey(void const* exponent, void const* modulus);

    int Encrypt(void const* source, int slen, void* dest) const;
    int Decrypt(void const* source, int slen, void* dest) const;

    int Plain_Block_Size() const;
    int Crypt_Block_Size() const;
    int Block_Count(int plaintext_length) const;

    int Encode_Modulus(void* buffer) const;
    int Encode_Exponent(void* buffer) const;

    void Decode_Modulus(void* buffer);
    void Decode_Exponent(void* buffer);

    static long Fast_Exponent();

    static void Generate(Straw& random, int bits, PKey& fastkey, PKey& slowkey);

private:
    BigInt Modulus;
    BigInt Exponent;
    int BitPrecision;
};
