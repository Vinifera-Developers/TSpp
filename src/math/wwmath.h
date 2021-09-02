/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWMATH.H
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
#pragma once

#include "always.h"
#include "array.h"
#include <cmath>
#include "tspp_assert.h"


/**
 *  Math constants.
 */
#define WWMATH_EPSILON 0.0001f // percentage epsilon
#define WWMATH_SHORT_EPSILON 0.1f // round integer epsilon
#define WWMATH_LONG_EPSILON 0.00000001f // arbitrary 8 digit epsilon
#define WWMATH_EPSILON2 WWMATH_EPSILON * WWMATH_EPSILON

#define WWMATH_FLOAT_MAX (FLT_MAX)
#define WWMATH_FLOAT_MIN (FLT_MIN)
#define WWMATH_FLOAT_TINY (1.0e-37f)

#define WWMATH_SQRT2 1.41421356237309504880f
#define WWMATH_SQRT3 1.73205080756887719318f // sqrt(3)
#define WWMATH_OOSQRT2 0.7071067811865475244008442f
#define WWMATH_OOSQRT3 0.5773502691896257645091489f
#define WWMATH_OOSQRT6 0.4082482904638630163662140f

#define WWMATH_E 2.71828182845904523536f // Holds the value for "e": Euler's number or Napier's constant, to 15 significant figures. This is a mathematically useful number.
#define WWMATH_LOG2E 1.44269504088896340736f
#define WWMATH_LOG10E 0.434294481903251827651f
#define WWMATH_LN2 0.693147180559945309417f
#define WWMATH_LN10 2.30258509299404568402f
#define WWMATH_PI 3.14159265358979323846f // Holds the value for PI. Only up to 16 significant figures.
#define WWMATH_P2 1.57079632679489661923f // Holds the value for PI / 2 OR 90 degrees. Only up to 17 significant figures.
#define WWMATH_P4 0.785398163397448309616f // Holds the value for PI / 4 OR 45 degrees. Only up to 16 significant figures.
#define WWMATH_P8 0.39269908169872413f // Holds the value for PI / 8 OR 22.5 degrees. Only up to 17 significant figures.
#define WWMATH_P16 0.19634954084936206f // Holds the value for PI / 16 OR 11.25 degrees. Only up to 17 significant figures.

#define WWMATH_1_PI 0.318309886183790671538f
#define WWMATH_2_PI 0.636619772367581343076f
#define WWMATH_1_SQRTPI 0.564189583547756286948f
#define WWMATH_2_SQRTPI 1.12837916709551257390f

#define WWMATH_TWO_PI 6.283185307179586f // Holds the value for 3 * PI_2 OR 270 degrees. Only up to 17 significant figures.
#define WWMATH_THREE_PI_2 4.7123889803846895f // Holds the value for 3 * PI_2 OR 270 degrees. Only up to 17 significant figures.

#define WWMATH_TIGHT_CORNER_RADIUS 0.5f

#define WWMATH_RAD_TO_DEG 57.295779513082325225835265587527f // Holds the value for 180 / PI which is used to convert radians to degrees.
#define WWMATH_DEG_TO_RAD 0.017453292519943294444444444444444f // Holds the value for PI / 180 which is used to convert degrees to radians.

/**
 *  Helpful macros.
 */
#ifndef RAD_TO_DEG
#define RAD_TO_DEG(x) (((double)x) * 180.0 / WWMATH_PI)
#endif
#ifndef DEG_TO_RAD
#define DEG_TO_RAD(x) (((double)x) * WWMATH_PI / 180.0)
#endif
#ifndef RAD_TO_DEGF
#define RAD_TO_DEGF(x) (((float)x) * 180.0f / WWMATH_PI)
#endif
#ifndef DEG_TO_RADF
#define DEG_TO_RADF(x) (((float)x) * WWMATH_PI / 180.0f)
#endif

const int ARC_TABLE_SIZE = 1024;
const int SIN_TABLE_SIZE = 1024;

extern const Array<float, ARC_TABLE_SIZE> _FastAcosTable;
extern const Array<float, ARC_TABLE_SIZE> _FastAsinTable;
extern const Array<float, SIN_TABLE_SIZE> _FastSinTable;
extern const Array<float, SIN_TABLE_SIZE> _FastInvSinTable;

namespace WWMath
{
void Init();
void Shutdown();

inline double Square(double val)
{
    return double(val * val);
}

inline double Cos(double val)
{
    return std::cos(val);
}

inline double Sin(double val)
{
    return std::sin(val);
}

inline double Sqrt(double val)
{
    return std::sqrt(val);
}

inline double Atan(double val)
{
    return std::atan(val);
}

inline double Atan2(double y, double x)
{
    return std::atan2(y, x);
}

inline double Acos(double val)
{
    return std::acos(val);
}

inline double Asin(double val)
{
    return std::asin(val);
}

inline double Tan(double val)
{
    return std::tan(val);
}

inline double Sign(double val)
{
    if (val > 0.0f) {
        return +1.0f;
    }

    if (val < 0.0f) {
        return -1.0f;
    }

    return 0.0f;
}

inline double Ceil(double val)
{
    return std::ceil(val);
}

inline double Pow(double x, double y)
{
    return std::pow(x, y);
}

inline double Floor(double val)
{
    return std::floor(val);
}

inline double Wrap(double val, double min = 0.0f, double max = 1.0f)
{
    if (val >= max) {
        val -= (max - min);
    }

    if (val < min) {
        val += (max - min);
    }

    if (val < min) {
        val = min;
    }

    if (val > max) {
        val = max;
    }

    return static_cast<double>(val);
}

inline double Lerp(double a, double b, float lerp)
{
    return (a + (b - a) * lerp);
}

inline long Float_To_Long(double f)
{
    return (int)(f);
}

inline bool Is_Valid_Double(double x)
{
    uint32_t *plong = reinterpret_cast<uint32_t *>(&x) + 1;
    uint32_t exponent = ((*plong) & 0x7FF00000) >> (32 - 12);

    if (exponent == 0x7FF) {
        return false;
    }
    return true;
}

inline float Square(float val)
{
    return float(val * val);
}

inline float Fabs(float val)
{
    float tmp = val;
    uint32_t value = *reinterpret_cast<uint32_t *>(&tmp);
    value &= 0x7fffffff;
    return float(*reinterpret_cast<float *>(&value));
}

inline int Float_To_Int_Chop(const float &f)
{
    int32_t a = *reinterpret_cast<const int32_t *>(&f);
    int32_t sign = (a >> 31);
    int32_t mantissa = (a & ((1 << 23) - 1)) | (1 << 23);
    int32_t exponent = ((a & 0x7fffffff) >> 23) - 127;
    int32_t r = ((uint32_t)(mantissa) << 8) >> (31 - exponent);
    return ((r ^ (sign)) - sign) & ~(exponent >> 31);
}

inline int Float_To_Int_Floor(const float &f)
{
    int32_t a = *reinterpret_cast<const int32_t *>(&f);
    int32_t sign = (a >> 31);
    a &= 0x7fffffff;
    int32_t exponent = (a >> 23) - 127;
    int32_t expsign = ~(exponent >> 31);
    int32_t imask = ((1 << (31 - (exponent)))) - 1;
    int32_t mantissa = (a & ((1 << 23) - 1));
    int32_t r = ((uint32_t)(mantissa | (1 << 23)) << 8) >> (31 - exponent);
    r = ((r & expsign) ^ (sign)) + (((!((mantissa << 8) & imask)) & (expsign ^ ((a - 1) >> 31))) & sign);
    return r;
}

inline float Cosf(float val)
{
    return std::cosf(val);
}

inline float Sinf(float val)
{
    return std::sinf(val);
}

inline float Inv_Sin(float val)
{
    return (val > 0.0f) ? 1.0f / std::sinf(val) : WWMATH_FLOAT_MAX;
}

inline float Sqrtf(float val)
{
    return std::sqrtf(val);
}

inline float Inv_Sqrtf(float val)
{
    return float(1.0f / std::sqrtf(val));
}

inline float Acosf(float val)
{
    return std::acosf(val);
}

inline float Asinf(float val)
{
    return std::asinf(val);
}

inline float Atanf(float val)
{
    return std::atanf(val);
}

inline float Atan2f(float y, float x)
{
    return std::atan2f(y, x);
}

inline float Tanf(float val)
{
    return std::tanf(val);
}

inline float Fast_Sin(float val)
{
    val *= float(SIN_TABLE_SIZE) / (2.0f * WWMATH_PI);
    int idx0 = Float_To_Int_Floor(val);
    int idx1 = idx0 + 1;
    float frac = val - float(idx0);
    idx0 = (unsigned(idx0)) & (SIN_TABLE_SIZE - 1);
    idx1 = (unsigned(idx1)) & (SIN_TABLE_SIZE - 1);
    return (1.0f - frac) * _FastSinTable[idx0] + frac * _FastSinTable[idx1];
}

inline float Fast_Inv_Sin(float val)
{
    return float(1.0f / Fast_Sin(val));
}

inline float Fast_Cos(float val)
{
    val += (WWMATH_PI * 0.5f);
    val *= float(SIN_TABLE_SIZE) / (2.0f * WWMATH_PI);
    int idx0 = Float_To_Int_Floor(val);
    int idx1 = idx0 + 1;
    float frac = val - float(idx0);
    idx0 = (unsigned(idx0)) & (SIN_TABLE_SIZE - 1);
    idx1 = (unsigned(idx1)) & (SIN_TABLE_SIZE - 1);
    return (1.0f - frac) * _FastSinTable[idx0] + frac * _FastSinTable[idx1];
}

inline float Fast_Inv_Cos(float val)
{
    return float(1.0f / Fast_Cos(val));
}

inline float Fast_Acos(float val)
{
    /**
     *  Presumably the table method isn't accurate enough in this range.
     */
    if (Fabs(val) > 0.975f) {
        return WWMath::Acosf(val);
    }

    val *= float(ARC_TABLE_SIZE / 2);
    int idx0 = Float_To_Int_Floor(val);
    int idx1 = idx0 + 1;
    float frac = val - float(idx0);
    idx0 += ARC_TABLE_SIZE / 2;
    idx1 += ARC_TABLE_SIZE / 2;

    //TSPP_ASSERT((idx0 >= 0) && (idx0 < ARC_TABLE_SIZE), "Index out of table range");
    //TSPP_ASSERT((idx1 >= 0) && (idx1 < ARC_TABLE_SIZE), "Index out of table range");

    return (1.0f - frac) * _FastAcosTable[idx0] + frac * _FastAcosTable[idx1];
}

inline float Fast_Asin(float val)
{
    // Presumably the table method isn't accurate enough in this range.
    if (Fabs(val) > 0.975f) {
        return WWMath::Asinf(val);
    }

    val *= float(ARC_TABLE_SIZE / 2);
    int idx0 = Float_To_Int_Floor(val);
    int idx1 = idx0 + 1;
    float frac = val - float(idx0);
    idx0 += ARC_TABLE_SIZE / 2;
    idx1 += ARC_TABLE_SIZE / 2;

    //TSPP_ASSERT((idx0 >= 0) && (idx0 < ARC_TABLE_SIZE), "Index out of table range");
    //TSPP_ASSERT((idx1 >= 0) && (idx1 < ARC_TABLE_SIZE), "Index out of table range");

    return (1.0f - frac) * _FastAsinTable[idx0] + frac * _FastAsinTable[idx1];
}

inline float Sign(float val)
{
    if (val > 0.0f) {
        return +1.0f;
    }

    if (val < 0.0f) {
        return -1.0f;
    }

    return 0.0f;
}

inline float Ceilf(float val)
{
    return std::ceilf(val);
}

inline float Powf(float x, float y)
{
    return std::powf(x, y);
}

inline float Floorf(float val)
{
    return std::floorf(val);
}

inline bool Fast_Is_Float_Positive(const float &val)
{
    return ((*reinterpret_cast<uint32_t const *>(&val)) & 0x80000000) == 0;
}

inline int Fast_To_Int_Floor(float val)
{
    static const float _almost_one = 0.99999994f;

    if (!Fast_Is_Float_Positive(val)) {
        val -= _almost_one;
    }

    return std::lrintf(std::truncf(val));
}

inline float Random_Float()
{
    return float((float(std::rand() & 0xFFF)) / float(0xFFF));
}

inline float Random_Float(float min, float max)
{
    return float(Random_Float() * (max - min) + min);
}

inline float Wrap(float val, float min = 0.0f, float max = 1.0f)
{
    if (val >= max) {
        val -= (max - min);
    }

    if (val < min) {
        val += (max - min);
    }

    if (val < min) {
        val = min;
    }

    if (val > max) {
        val = max;
    }

    return float(val);
}

inline float Lerp(float a, float b, float lerp)
{
    return float(a + (b - a) * lerp);
}

inline int Lerp(int a, int b, float lerp)
{
    return (a + int((b - a) * lerp));
}

inline int Float_To_Long(float f)
{
    return int(f);
}

inline uint8_t Unit_Float_To_Byte(float f)
{
    return uint8_t(f * 255.0f);
}

inline float Byte_To_Unit_Float(unsigned char byte)
{
    return float(byte) / 255.0f;
}

inline bool Is_Valid_Float(float x)
{
    uint32_t *plong = reinterpret_cast<uint32_t *>(&x);
    uint32_t exponent = ((*plong) & 0x7F800000) >> (32 - 9);

    if (exponent == 0xFF) {
        return false;
    }
    return true;
}

inline int Signum(int val)
{
    return (val > 0) - (val < 0);
}

inline float Signum(float val)
{
    return (val > 0.0f) - (val < 0.0f);
}

inline double Signum(double val)
{
    return (val > 0.0) - (val < 0.0);
}

}; // WWMath namespace
