/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          XMP.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         
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


class Straw;


typedef uint32_t  xmp_digit;
typedef int32_t   xmp_signeddigit;
typedef uint16_t  xmp_digit16;
typedef int16_t   xmp_signeddigit16;


#define LOG_UNITSIZE          5
#define UNITSIZE              32
#define UPPER_MOST_BIT        0x80000000L
#define SEMI_UPPER_MOST_BIT   0x8000
#define SEMI_MASK             ((unsigned short)~0)
#define MAX_BIT_PRECISION     2048
#define MAX_UNIT_PRECISION    (MAX_BIT_PRECISION/UNITSIZE)
#define PRIME_TABLE_SIZE      3511


int XMP_Significance(const xmp_digit * r, int precision);
void XMP_Inc(xmp_digit * r, int precision);
void XMP_Dec(xmp_digit * r, int precision);
void XMP_Neg(xmp_digit * r, int precision);
void XMP_Abs(xmp_digit * r, int precision);
void XMP_Shift_Right_Bits(xmp_digit * r1, int bits, int precision);
void XMP_Shift_Left_Bits(xmp_digit * r1, int bits, int precision);
bool XMP_Rotate_Left(xmp_digit * r1, bool carry, int precision);
void XMP_Not(xmp_digit * xmp_digit_ptr, int precision);
void XMP_Init(xmp_digit * r, xmp_digit value, int precision);
unsigned XMP_Count_Bits(const xmp_digit * r, int precision);
int XMP_Count_Bytes(const xmp_digit * r, int precision);
void XMP_Move(xmp_digit * dest, xmp_digit const * source, int precision);
int XMP_Compare(const xmp_digit * r1, const xmp_digit * r2, int precision);
bool XMP_Add(xmp_digit * result, const xmp_digit * r1, const xmp_digit * r2, bool carry, int precision);
bool XMP_Add_Int(xmp_digit * result, const xmp_digit * r1, xmp_digit r2, bool carry, int precision);
bool XMP_Sub(xmp_digit * result, const xmp_digit * r1, const xmp_digit * r2, bool borrow, int precision);
bool XMP_Sub_Int(xmp_digit * result, const xmp_digit * r1, xmp_digit16 r2, bool borrow, int precision);
int XMP_Unsigned_Mult(xmp_digit * prod, const xmp_digit * multiplicand, const xmp_digit * multiplier, int precision);
int XMP_Unsigned_Mult_Int(xmp_digit * prod, const xmp_digit * multiplicand, xmp_signeddigit16 multiplier, int precision);
int XMP_Signed_Mult_Int(xmp_digit * prod, const xmp_digit * multiplicand, xmp_signeddigit16 multiplier, int precision);
int XMP_Signed_Mult(xmp_digit * prod, const xmp_digit * multiplicand, const xmp_digit * multiplier, int precision);
xmp_digit16 XMP_Unsigned_Div_Int(xmp_digit * quotient, xmp_digit const * dividend, xmp_digit16 divisor, int precision);
int XMP_Unsigned_Div(xmp_digit * remainder, xmp_digit * quotient, xmp_digit const * dividend, xmp_digit const * divisor, int precision);
void XMP_Signed_Div(xmp_digit * remainder, xmp_digit * quotient, xmp_digit const * dividend, xmp_digit const * divisor, int precision);
int XMP_Reciprocal(xmp_digit * quotient, const xmp_digit * divisor, int precision);
void XMP_Decode_ASCII(char const * str, xmp_digit * mpn, int precision);
void xmp_single_mul(xmp_digit16 * prod, xmp_digit16 * multiplicand, xmp_digit16 multiplier, int precision);
void XMP_Double_Mul(xmp_digit * prod, const xmp_digit * multiplicand, const xmp_digit * multiplier, int precision);
int xmp_stage_modulus(const xmp_digit * n_modulus, int precision);
int XMP_Mod_Mult(xmp_digit * prod, const xmp_digit * multiplicand, const xmp_digit * multiplier, int precision);
void XMP_Mod_Mult_Clear(int precision);
xmp_digit16 xmp_quo_digit(xmp_digit16 * dividend);
int xmp_exponent_mod(xmp_digit * expout, const xmp_digit * expin, const xmp_digit * exponent_ptr, const xmp_digit * modulus, int precision);
bool XMP_Is_Small_Prime(const xmp_digit * candidate, int precision);
bool XMP_Small_Divisors_Test(const xmp_digit * candidate, int precision);
bool XMP_Fermat_Test(const xmp_digit * candidate_prime, unsigned rounds, int precision);
void XMP_Inverse_A_Mod_B(xmp_digit * result, xmp_digit const * number, xmp_digit const * modulus, int precision);
void XMP_Signed_Decode(xmp_digit * result, const unsigned char * from, int frombytes, int precision);
void XMP_Unsigned_Decode(xmp_digit * result, const unsigned char * from, int frombytes, int precision);
unsigned XMP_Encode(unsigned char * to, xmp_digit const * from, int precision);
unsigned XMP_Encode_Bounded(unsigned char * to, unsigned tobytes, xmp_digit const * from, int precision);
void XMP_Randomize(xmp_digit * result, Straw & rng, int nbits, int precision);
void XMP_Randomize_Bounded(xmp_digit * result, Straw & rng, xmp_digit const * min, xmp_digit const * max, int precision);
bool XMP_Is_Prime(xmp_digit const * prime, int precision);
bool XMP_Rabin_Miller_Test(Straw & rng, xmp_digit const * w, int rounds, int precision);
int XMP_DER_Length_Encode(unsigned long length, unsigned char * output);
int XMP_DER_Encode(xmp_digit const * from, unsigned char * output, int precision);
void XMP_DER_Decode(xmp_digit * result, unsigned char const * input, int precision);

xmp_digit16 *XMP_Fetch_Prime_Table();
int XMP_Prime_Table_Size();

inline int XMP_Digits_To_Bits(int xmp_digits)
{
    return xmp_digits << LOG_UNITSIZE;
}

inline int XMP_Bits_To_Digits(int bits)
{
    return (bits + (UNITSIZE-1)) / UNITSIZE;
}

inline xmp_digit XMP_Bits_To_Mask(int bits)
{
    if (!bits) return 0;
    return 1 << ((bits-1) % UNITSIZE);
}

inline bool XMP_Is_Negative(const xmp_digit * r, int precision)
{
    return (xmp_signeddigit) *(r + (precision-1)) < 0;
}

inline bool XMP_Test_Eq_Int(xmp_digit const * r, int i, int p)
{
    return (*r == (xmp_digit)i) && XMP_Significance(r,p) <= 1;
}

inline void XMP_Set_Bit(xmp_digit * r, unsigned bit)
{
    r[bit >> LOG_UNITSIZE] |= ((xmp_digit)1 << (bit & (UNITSIZE-1)));
}

inline bool XMP_Test_Bit(const xmp_digit * r, unsigned bit)
{
    return (r[bit >> LOG_UNITSIZE] & ((xmp_digit)1 << (bit & (UNITSIZE-1))));
}
