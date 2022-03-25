/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INT.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         An arbitrary precision integer class.
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
#include "xmp.h"
#include "straw.h"
#include <memory>


template<int PRECISION>
class Int
{
    public:
        Int() { XMP_Init(&reg[0], 0, PRECISION); }
        Int(unsigned long value) { XMP_Init(&reg[0], value, PRECISION); }

        void Randomize(Straw & rng, int bitcount) { XMP_Randomize(&reg[0], rng, bitcount, PRECISION); }
        void Randomize(Straw & rng, const Int & minval, const Int & maxval) { XMP_Randomize_Bounded(&reg[0], rng, minval, maxval, PRECISION); reg[0] |= 1; }

        operator xmp_digit * () { return &reg[0]; }
        operator const xmp_digit * () const { return &reg[0]; }

        bool operator[](unsigned bit) const { return XMP_Test_Bit(&reg[0], bit); }

        Int & operator ++ () { XMP_Inc(&reg[0], PRECISION); return (*this); }
        Int & operator -- () { XMP_Dec(&reg[0], PRECISION); return (*this); }
        int operator ! () const { return XMP_Test_Eq_Int(&reg[0], 0, PRECISION); }
        Int operator ~ () { XMP_Not(&reg[0], PRECISION); return (*this); }
        Int operator - () const { Int a = *this; a.Negate(); return a; }

        int ByteCount() const { return XMP_Count_Bytes(&reg[0], PRECISION); }
        int BitCount() const { return XMP_Count_Bits(&reg[0], PRECISION); }
        bool Is_Negative() const { return XMP_Is_Negative(&reg[0], PRECISION); }
        unsigned MaxBitPrecision() const { return PRECISION*(sizeof(unsigned long)*CHAR_BIT); }
        bool IsSmallPrime() const { return XMP_Is_Small_Prime(&reg[0], PRECISION); }
        bool SmallDivisorsTest() const { return XMP_Small_Divisors_Test(&reg[0], PRECISION); }
        bool FermatTest(unsigned rounds) const { return XMP_Fermat_Test(&reg[0], rounds, PRECISION); }
        bool IsPrime() const { return XMP_Is_Prime(&reg[0], PRECISION); }
        bool RabinMillerTest(Straw & rng, unsigned int rounds) const { return XMP_Rabin_Miller_Test(rng, &reg[0], rounds, PRECISION); }

        Int & operator += (const Int & number) { Carry = XMP_Add(&reg[0], &reg[0], number, 0, PRECISION); return (*this); }
        Int & operator -= (const Int & number) { Borrow = XMP_Sub(&reg[0], &reg[0], number, 0, PRECISION); return (*this); }
        Int & operator *= (const Int & multiplier) { Remainder = *this; Error = XMP_Signed_Mult(&reg[0], Remainder, multiplier, PRECISION); return (*this); }
        Int & operator /= (const Int & t) { *this = (*this) / t; return (*this); }
        Int & operator %= (const Int & t) { *this = (*this) % t; return (*this); }
        Int & operator <<= (int bits) { XMP_Shift_Left_Bits(&reg[0], bits, PRECISION); return (*this); }
        Int & operator >>= (int bits) { XMP_Shift_Right_Bits(&reg[0], bits, PRECISION); return (*this); }

        Int operator + (const Int & number) const { Int term; Carry = XMP_Add(term, &reg[0], number, 0, PRECISION); return (term); }
        Int operator + (unsigned short b) const { Int result; Carry = XMP_Add_Int(result, &reg[0], b, 0, PRECISION); return (result); }
//		friend Int<PRECISION> operator + (digit b, const Int<PRECISION> & a) { return (Int<PRECISION>(b) + a); }
        Int operator - (const Int & number) const { Int term; Borrow = XMP_Sub(term, &reg[0], number, 0, PRECISION); return (term); }
        Int operator - (unsigned short b) const { Int result; Borrow = XMP_Sub_Int(result, &reg[0], b, 0, PRECISION); return (result); }
//		friend Int<PRECISION> operator - (digit b, const Int<PRECISION> & a) { return (Int<PRECISION>(b) - a); }
        Int operator * (const Int & multiplier) const { Int result; Error = XMP_Signed_Mult(result, &reg[0], multiplier, PRECISION); return result; }
        Int operator * (unsigned short b) const { Int result; Error = XMP_Unsigned_Mult_Int(result, &reg[0], b, PRECISION);return (result); }
//		friend Int<PRECISION> operator * (digit b, const Int<PRECISION> & a) { return (Int<PRECISION>(b) * a); }
        Int operator / (const Int & divisor) const { Int quotient = *this; XMP_Signed_Div(Remainder, quotient, &reg[0], divisor, PRECISION);return (quotient); }
        Int operator / (unsigned long b) const { return (*this / Int<PRECISION>(b)); }
        Int operator / (unsigned short divisor) const { Int quotient; Error = XMP_Unsigned_Div_Int(quotient, &reg[0], divisor, PRECISION);return quotient; }
//		friend Int<PRECISION> operator / (digit a, const Int<PRECISION> & b) { return (Int<PRECISION>(a) / b); }
        Int operator % (const Int & divisor) const { Int remainder; XMP_Signed_Div(remainder, Remainder, &reg[0], divisor, PRECISION); return remainder; }
        Int operator % (unsigned long b) const { return (*this % Int<PRECISION>(b)); }
        unsigned short operator % (unsigned short divisor) const { return XMP_Unsigned_Div_Int(Remainder, &reg[0], divisor, PRECISION); }
//		friend Int<PRECISION> operator % (digit a, const Int<PRECISION> & b) { return (Int<PRECISION>(a) % b); }

        Int operator >> (int bits) const { Int result = *this; XMP_Shift_Right_Bits(result, bits, PRECISION); return result; }
        Int operator << (int bits) const { Int result = *this; XMP_Shift_Left_Bits(result, bits, PRECISION); return result; }

        int operator == (const Int &b) const { return memcmp(&reg[0], &b.reg[0], (MAX_BIT_PRECISION / CHAR_BIT)) == 0; }
        int operator != (const Int& b) const { return !(*this == b);}
        int operator > (const Int & number) const { return XMP_Compare(&reg[0], number, PRECISION) > 0; }
        int operator >= (const Int & number) const { return XMP_Compare(&reg[0], number, PRECISION) >= 0; }
        int operator < (const Int & number) const { return XMP_Compare(&reg[0], number, PRECISION) < 0; }
        int operator <= (const Int & number) const { return XMP_Compare(&reg[0], number, PRECISION) <= 0; }

        void Negate() { XMP_Neg(&reg[0], PRECISION); }
        Int Abs() { XMP_Abs(&reg[0], PRECISION); return (*this); }
        Int times_b_mod_c(Int const & multiplier, Int const & modulus) const
        {
            Int result;
            Error = xmp_stage_modulus(modulus, PRECISION);
            Error = XMP_Mod_Mult(result, &reg[0], multiplier, PRECISION);
            XMP_Mod_Mult_Clear(PRECISION);
            return result;
        }

        Int exp_b_mod_c(const Int & e, const Int & m) const
        {
            Int result;
            Error = xmp_exponent_mod(result, &reg[0], e, m, PRECISION);
            return result;
        }

        static Int Unsigned_Mult(Int const & multiplicand, Int const & multiplier) { Int product; Error = XMP_Unsigned_Mult(&product.reg[0], &multiplicand.reg[0], &multiplier.reg[0], PRECISION); return product; }
        static void Unsigned_Divide(Int & remainder, Int & quotient, const Int & dividend, const Int & divisor) { Error = XMP_Unsigned_Div(remainder, quotient, dividend, divisor, PRECISION); }
        static void Signed_Divide(Int & remainder, Int & quotient, const Int & dividend, const Int & divisor) { XMP_Signed_Div(remainder, quotient, dividend, divisor, PRECISION); }
        Int Inverse(const Int & modulus) const { Int result;XMP_Inverse_A_Mod_B(result, &reg[0], modulus, PRECISION); return result; }

        static Int Decode_ASCII(char const * string) { Int result; XMP_Decode_ASCII(string, result, PRECISION); return result; }
        int Encode(unsigned char *output) const {return XMP_Encode(output, &reg[0], PRECISION); }
        int Encode(unsigned char * output, unsigned length) const { return XMP_Encode_Bounded(output, length, &reg[0], PRECISION); }
        void Signed_Decode(const unsigned char * from, int frombytes) { XMP_Signed_Decode(&reg[0], from, frombytes, PRECISION); }
        void Unsigned_Decode(const unsigned char * from, int frombytes) { XMP_Unsigned_Decode(&reg[0], from, frombytes, PRECISION); }

        int DEREncode(unsigned char * output) const { return XMP_DER_Encode(&reg[0], output, PRECISION); }
        void DERDecode(const unsigned char *input) { XMP_DER_Decode(&reg[0], input, PRECISION); }

        friend Int<PRECISION> Generate_Prime(Straw & rng, int pbits, Int<PRECISION> const *dummy = nullptr);
        friend Int<PRECISION> Gcd(const Int<PRECISION> & a, const Int<PRECISION> & b);
//		friend bool NextPrime(Int<PRECISION> & p, const Int<PRECISION> & max, bool blumInt = false);
//		friend Int<PRECISION> a_exp_b_mod_pq(const Int<PRECISION> & a, const Int<PRECISION> & ep, const Int<PRECISION> & eq, const Int<PRECISION> & p, const Int<PRECISION> & q, const Int<PRECISION> & u);

    public:
        static int Error;
        static bool Carry;
        static bool Borrow;
        static Int Remainder;

    private:
        xmp_digit reg[PRECISION];

    private:
        struct RemainderTable
        {
            public:
                RemainderTable(const Int<PRECISION> & p) : HasZeroEntry(false)
                {
                    for (unsigned i = 0; i < XMP_Prime_Table_Size(); i++) {
                        table[i] = p % XMP_Fetch_Prime_Table()[i];
                    }
                }
                bool HasZero() const { return HasZeroEntry; }
                void Increment(unsigned short increment = 1)
                {
                    HasZeroEntry = false;
                    for (unsigned int i = 0; i < XMP_Prime_Table_Size(); i++) {
                        table[i] += increment;
                        while (table[i] >= XMP_Fetch_Prime_Table()[i]) {
                            table[i] -= XMP_Fetch_Prime_Table()[i];
                        }
                        HasZeroEntry = (HasZeroEntry || !table[i]);
                    }
                }
                void Increment(const RemainderTable & rtQ)
                {
                    HasZeroEntry = false;
                    for (unsigned int i = 0; i < XMP_Prime_Table_Size(); i++) {
                        table[i] += rtQ.table[i];
                        if (table[i] >= XMP_Fetch_Prime_Table()[i]) {
                            table[i] -= XMP_Fetch_Prime_Table()[i];
                        }
                        HasZeroEntry = (HasZeroEntry || !table[i]);
                    }
                }

            public:
                bool HasZeroEntry;
                unsigned short table[PRIME_TABLE_SIZE];
        };
};


template<class T>
T Gcd(const T & a, const T & n)
{
    T g[3] = {n, a, 0UL};

    unsigned int i = 1;
    while (!!g[i % 3]) {
        g[(i+1) % 3] = g[(i-1) % 3] % g[i % 3];
        i++;
    }
    return g[(i-1) % 3];
}


template<class T>
T Generate_Prime(Straw & rng, int pbits, T const *dummy)
{
    T minQ = (T(1UL) << (unsigned short)(pbits-(unsigned short)2));
    T maxQ = ((T(1UL) << (unsigned short)(pbits-(unsigned short)1)) - (unsigned short)1);

    T q;
    T p;

    do {
        q.Randomize(rng, minQ, maxQ);
        p = (q*2) + (unsigned short)1;

        T::RemainderTable rtQ(q);
        T::RemainderTable rtP(p);

        while (rtQ.HasZero() || rtP.HasZero() || !q.IsPrime() || !p.IsPrime()) {
            q += 2;
            p += 4;
            if (q > maxQ) break;

            rtQ.Increment(2);
            rtP.Increment(4);
        }
    } while (q > maxQ);

    return (p);
}


typedef Int<MAX_UNIT_PRECISION>	BigInt;

//BigInt Gcd(const BigInt & a, const BigInt & n);
//BigInt Generate_Prime(RandomNumberGenerator & rng, int pbits, const BigInt * dummy);
