/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VECTOR4.H
 *
 *  @authors       tomsons26
 *
 *  @brief         A 4D Vector with floating point coordinates, used for
 *                 storing normals and all sorts of other 3D graphics operations.
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
#include "tspp_assert.h"
#include "wwmath.h"


class Vector4
{
public:
    Vector4() { X = 0; Y = 0; Z = 0; W = 0; }
    Vector4(const Vector4& v) { X = v.X; Y = v.Y; Z = v.Z; W = v.W; }
    Vector4(float x, float y, float z, float w) { X = x; Y = y; Z = z; W = w; }
    Vector4(const float vector[4]) { X = vector[0]; Y = vector[1]; Z = vector[2]; W = vector[3]; }

    Vector4& operator=(const Vector4& v) { X = v.X; Y = v.Y; Z = v.Z; W = v.W; return *this; }
    void Set(float x, float y, float z, float w) { X = x; Y = y; Z = z; W = w; }

    float& operator[](int i) { return (&X)[i]; }
    const float& operator[](int i) const { return (&X)[i]; }

    inline void Normalize();
    inline float Length() const;
    inline float Length2() const;

    Vector4 operator-() const { return Vector4(-X, -Y, -Z, -W); }
    Vector4 operator+() const { return *this; }

    Vector4& operator+=(const Vector4& v) { X += v.X; Y += v.Y; Z += v.Z; W += v.W; return *this; }
    Vector4& operator-=(const Vector4& v) { X -= v.X; Y -= v.Y; Z -= v.Z; W += v.W; return *this; }
    Vector4& operator*=(float k) { X = X * k; Y = Y * k; Z = Z * k; W = W * k; return *this; }
    Vector4& operator/=(float k) { k = 1.0f / k; X = X * k; Y = Y * k; Z = Z * k; W = W * k; return *this; }

    inline friend Vector4 operator*(const Vector4& a, float k);
    inline friend Vector4 operator*(float k, const Vector4& a);
    inline friend Vector4 operator/(const Vector4& a, float k);

    inline friend Vector4 operator+(const Vector4& a, const Vector4& b);
    inline friend Vector4 operator-(const Vector4& a, const Vector4& b);

    inline friend float operator*(const Vector4& a, const Vector4& b);
    inline static float Dot_Product(const Vector4& a, const Vector4& b);

    inline friend bool operator==(const Vector4& a, const Vector4& b);
    inline friend bool operator!=(const Vector4& a, const Vector4& b);

    inline static Vector4 Lerp(const Vector4& a, const Vector4& b, float alpha);
    inline static void Lerp(const Vector4& a, const Vector4& b, float alpha, Vector4* set_result);

    inline bool Is_Valid() const;

public:
    float X;
    float Y;
    float Z;
    float W;
};


inline Vector4 operator*(const Vector4& a, float k)
{
    return Vector4((a.X * k), (a.Y * k), (a.Z * k), (a.W * k));
}


inline Vector4 operator*(float k, const Vector4& a)
{
    return a * k;
}


inline Vector4 operator/(const Vector4& a, float k)
{
    float ook = 1.0f / k;
    return Vector4((a[0] * ook), (a[1] * ook), (a[2] * ook), (a[3] * ook));
}


inline Vector4 operator+(const Vector4& a, const Vector4& b)
{
    return Vector4(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}


inline Vector4 operator-(const Vector4& a, const Vector4& b)
{
    return Vector4(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}


inline float operator*(const Vector4& a, const Vector4& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}


float Vector4::Dot_Product(const Vector4& a, const Vector4& b)
{
    return a * b;
}


inline bool operator==(const Vector4& a, const Vector4& b)
{
    return ((a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]) && (a[3] == b[3]));
}


inline bool operator!=(const Vector4& a, const Vector4& b)
{
    return ((a[0] != b[0]) || (a[1] != b[1]) || (a[2] != b[2]) || (a[3] != b[3]));
}


void Vector4::Normalize()
{
    float len2 = Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(len2);
        X *= oolen;
        Y *= oolen;
        Z *= oolen;
        W *= oolen;
    }
}


inline Vector4 Normalize(const Vector4& vec)
{
    float len2 = vec.Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(len2);
        return vec * oolen;
    }
    return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}


float Vector4::Length() const
{
    return WWMath::Sqrtf(Length2());
}


float Vector4::Length2() const
{
    return X * X + Y * Y + Z * Z + W * W;
}


inline void Swap(Vector4& a, Vector4& b)
{
    Vector4 tmp(a);
    a = b;
    b = tmp;
}


inline Vector4 Lerp(const Vector4& a, const Vector4& b, float alpha)
{
    return Vector4((a.X + (b.X - a.X) * alpha), (a.Y + (b.Y - a.Y) * alpha), (a.Z + (b.Z - a.Z) * alpha), (a.W + (b.W - a.W) * alpha));
}


Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float alpha)
{
    return Vector4((a.X + (b.X - a.X) * alpha), (a.Y + (b.Y - a.Y) * alpha), (a.Z + (b.Z - a.Z) * alpha), (a.W + (b.W - a.W) * alpha));
}


void Vector4::Lerp(const Vector4& a, const Vector4& b, float alpha, Vector4* set_result)
{
    set_result->X = (a.X + (b.X - a.X) * alpha);
    set_result->Y = (a.Y + (b.Y - a.Y) * alpha);
    set_result->Z = (a.Z + (b.Z - a.Z) * alpha);
    set_result->X = (a.W + (b.W - a.W) * alpha);
}


bool Vector4::Is_Valid() const
{
    return (WWMath::Is_Valid_Float(X) && WWMath::Is_Valid_Float(Y) && WWMath::Is_Valid_Float(Z) && WWMath::Is_Valid_Float(W));
}
