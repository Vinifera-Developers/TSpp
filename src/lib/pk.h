/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Public Key Cryptography.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
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
