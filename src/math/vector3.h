/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VECTOR3.H
 *
 *  @authors       tomsons26
 *
 *  @brief         A 3D Vector with floating point coordinates, used for
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


class Vector3
{
public:
    Vector3() { X = 0; Y = 0; Z = 0; }
    Vector3(const Vector3& v) { X = v.X; Y = v.Y; Z = v.Z; }
    Vector3(float x, float y, float z) { X = x; Y = y; Z = z; }
    Vector3(const float vector[3]) { X = vector[0]; Y = vector[1]; Z = vector[2]; }

    Vector3& operator=(const Vector3& v) { X = v.X; Y = v.Y; Z = v.Z; return *this; }
    void Set(float x, float y, float z) { X = x; Y = y; Z = z; }
    void Set(const Vector3& that) { X = that.X; Y = that.Y; Z = that.Z; }

    float& operator[](int i) { return (&X)[i]; }
    const float& operator[](int i) const { return (&X)[i]; }
    
    inline void Normalize();
    inline float Length() const;
    inline float Length2() const;
    inline float Quick_Length() const;
    inline void Scale(const Vector3& scale);
    
    inline void Rotate_X(float angle);
    inline void Rotate_X(float s_angle, float c_angle);
    inline void Rotate_Y(float angle);
    inline void Rotate_Y(float s_angle, float c_angle);
    inline void Rotate_Z(float angle);
    inline void Rotate_Z(float s_angle, float c_angle);

    Vector3 operator-() const { return (Vector3(-X, -Y, -Z)); }
    Vector3 operator+() const { return *this; }

    Vector3& operator+=(const Vector3& v) { X += v.X; Y += v.Y; Z += v.Z; return *this; }
    Vector3& operator-=(const Vector3& v) { X -= v.X; Y -= v.Y; Z -= v.Z; return *this; }
    Vector3& operator*=(float k) { X = X * k; Y = Y * k; Z = Z * k; return *this; }
    Vector3& operator/=(float k) { float ook = 1.0f / k; X = X * ook; Y = Y * ook; Z = Z * ook; return *this; }

    inline friend Vector3 operator*(const Vector3& a, float k);
    inline friend Vector3 operator*(float k, const Vector3& a);
    inline friend Vector3 operator/(const Vector3& a, float k);

    inline friend Vector3 operator+(const Vector3& a, const Vector3& b);
    inline friend Vector3 operator-(const Vector3& a, const Vector3& b);

    inline friend bool operator==(const Vector3& a, const Vector3& b);
    inline friend bool operator!=(const Vector3& a, const Vector3& b);
    inline friend bool Equal_Within_Epsilon(const Vector3& a, const Vector3& b, float epsilon);

    inline friend float operator*(const Vector3& a, const Vector3& b);
    inline static float Dot_Product(const Vector3& a, const Vector3& b);

    inline static Vector3 Cross_Product(const Vector3& a, const Vector3& b);
    inline static void Cross_Product(const Vector3& a, const Vector3& b, Vector3* result);
    inline static float Cross_Product_X(const Vector3& a, const Vector3& b);
    inline static float Cross_Product_Y(const Vector3& a, const Vector3& b);
    inline static float Cross_Product_Z(const Vector3& a, const Vector3& b);

    inline static void Add(const Vector3& a, const Vector3& b, Vector3* c);
    inline static void Subtract(const Vector3& a, const Vector3& b, Vector3* c);

    inline static float Find_X_At_Y(float y, const Vector3& p1, const Vector3& p2);
    inline static float Find_X_At_Z(float z, const Vector3& p1, const Vector3& p2);
    inline static float Find_Y_At_X(float x, const Vector3& p1, const Vector3& p2);
    inline static float Find_Y_At_Z(float z, const Vector3& p1, const Vector3& p2);
    inline static float Find_Z_At_X(float x, const Vector3& p1, const Vector3& p2);
    inline static float Find_Z_At_Y(float z, const Vector3& p1, const Vector3& p2);

    inline void Update_Min(const Vector3& a);
    inline void Update_Max(const Vector3& a);
    inline void Cap_Absolute_To(const Vector3& a);

    inline bool Is_Valid() const;

    inline static float Quick_Distance(const Vector3& p1, const Vector3& p2);
    inline static float Distance(const Vector3& p1, const Vector3& p2);

    inline static void Lerp(const Vector3& a, const Vector3& b, float alpha, Vector3* set_result);

public:
    float X;
    float Y;
    float Z;
};


inline Vector3 operator*(const Vector3& a, float k)
{
    return Vector3((a.X * k), (a.Y * k), (a.Z * k));
}


inline Vector3 operator*(float k, const Vector3& a)
{
    return Vector3((a.X * k), (a.Y * k), (a.Z * k));
}


inline Vector3 operator/(const Vector3& a, float k)
{
    float ook = 1.0f / k;
    return Vector3((a.X * ook), (a.Y * ook), (a.Z * ook));
}


inline Vector3 operator+(const Vector3& a, const Vector3& b)
{
    return Vector3(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
}


inline Vector3 operator-(const Vector3& a, const Vector3& b)
{
    return Vector3(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
}


inline float operator*(const Vector3& a, const Vector3& b)
{
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}


float Vector3::Dot_Product(const Vector3& a, const Vector3& b)
{
    return a * b;
}


inline bool operator==(const Vector3& a, const Vector3& b)
{
    return ((a.X == b.X) && (a.Y == b.Y) && (a.Z == b.Z));
}


inline bool operator!=(const Vector3& a, const Vector3& b)
{
    return ((a.X != b.X) || (a.Y != b.Y) || (a.Z != b.Z));
}


inline bool Equal_Within_Epsilon(const Vector3& a, const Vector3& b, float epsilon)
{
    return ((WWMath::Fabs(a.X - b.X) < epsilon) && (WWMath::Fabs(a.Y - b.Y) < epsilon) && (WWMath::Fabs(a.Z - b.Z) < epsilon));
}


Vector3 Vector3::Cross_Product(const Vector3& a, const Vector3& b)
{
    return Vector3((a.Y * b.Z - a.Z * b.Y), (a.Z * b.X - a.X * b.Z), (a.X * b.Y - a.Y * b.X));
}


void Vector3::Cross_Product(const Vector3& a, const Vector3& b, Vector3* set_result)
{
    TSPP_ASSERT(set_result != &a);
    set_result->X = (a.Y * b.Z - a.Z * b.Y);
    set_result->Y = (a.Z * b.X - a.X * b.Z);
    set_result->Z = (a.X * b.Y - a.Y * b.X);
}


float Vector3::Cross_Product_X(const Vector3& a, const Vector3& b)
{
    return a.Y * b.Z - a.Z * b.Y;
}


float Vector3::Cross_Product_Y(const Vector3& a, const Vector3& b)
{
    return a.Z * b.X - a.X * b.Z;
}


float Vector3::Cross_Product_Z(const Vector3& a, const Vector3& b)
{
    return a.X * b.Y - a.Y * b.X;
}


void Vector3::Normalize()
{
    float len2 = Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(Length2());
        X *= oolen;
        Y *= oolen;
        Z *= oolen;
    }
}


inline Vector3 Normalize(const Vector3& vec)
{
    float len2 = vec.Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(len2);
        return vec * oolen;
    }
    return vec;
}


float Vector3::Length() const
{
    return WWMath::Sqrt(Length2());
}


float Vector3::Length2() const
{
    return X * X + Y * Y + Z * Z;
}


float Vector3::Quick_Length() const
{
    float max = WWMath::Fabs(X);
    float mid = WWMath::Fabs(Y);
    float min = WWMath::Fabs(Z);
    float tmp;

    if (max < mid) {
        tmp = max;
        max = mid;
        mid = tmp;
    }
    if (max < min) {
        tmp = max;
        max = min;
        min = tmp;
    }
    if (mid < min) {
        tmp = mid;
        mid = min;
        min = mid;
    }
    return max + (11.0f / 32.0f) * mid + (1.0f / 4.0f) * min;
}


inline void Swap(Vector3& a, Vector3& b)
{
    Vector3 tmp(a);
    a = b;
    b = tmp;
}


inline Vector3 Lerp(const Vector3& a, const Vector3& b, float alpha)
{
    return Vector3((a.X + (b.X - a.X) * alpha), (a.Y + (b.Y - a.Y) * alpha), (a.Z + (b.Z - a.Z) * alpha));
}


inline void Lerp(const Vector3& a, const Vector3& b, float alpha, Vector3* set_result)
{
    TSPP_ASSERT(set_result != nullptr);
    set_result->X = (a.X + (b.X - a.X) * alpha);
    set_result->Y = (a.Y + (b.Y - a.Y) * alpha);
    set_result->Z = (a.Z + (b.Z - a.Z) * alpha);
}


void Vector3::Lerp(const Vector3& a, const Vector3& b, float alpha, Vector3* set_result)
{
    TSPP_ASSERT(set_result != nullptr);
    set_result->X = (a.X + (b.X - a.X) * alpha);
    set_result->Y = (a.Y + (b.Y - a.Y) * alpha);
    set_result->Z = (a.Z + (b.Z - a.Z) * alpha);
}


void Vector3::Add(const Vector3& a, const Vector3& b, Vector3* set_result)
{
    TSPP_ASSERT(set_result != nullptr);
    set_result->X = a.X + b.X;
    set_result->Y = a.Y + b.Y;
    set_result->Z = a.Z + b.Z;
}


void Vector3::Subtract(const Vector3& a, const Vector3& b, Vector3* set_result)
{
    TSPP_ASSERT(set_result != nullptr);
    set_result->X = a.X - b.X;
    set_result->Y = a.Y - b.Y;
    set_result->Z = a.Z - b.Z;
}


void Vector3::Update_Min(const Vector3& a)
{
    if (a.X < X) X = a.X;
    if (a.Y < Y) Y = a.Y;
    if (a.Z < Z) Z = a.Z;
}


void Vector3::Update_Max(const Vector3& a)
{
    if (a.X > X) X = a.X;
    if (a.Y > Y) Y = a.Y;
    if (a.Z > Z) Z = a.Z;
}


void Vector3::Cap_Absolute_To(const Vector3& a)
{
    if (X > 0) {
        if (a.X < X) {
            X = a.X;
        }
    } else {
        if (-a.X > X) {
            X = -a.X;
        }
    }

    if (Y > 0) {
        if (a.Y < Y) {
            Y = a.Y;
        }
    } else {
        if (-a.Y > Y) {
            Y = -a.Y;
        }
    }

    if (Z > 0) {
        if (a.Z < Z) {
            Z = a.Z;
        }
    } else {
        if (-a.Z > Z) {
            Z = -a.Z;
        }
    }
}


void Vector3::Scale(const Vector3& scale)
{
    X *= scale.X;
    Y *= scale.Y;
    Z *= scale.Z;
}


void Vector3::Rotate_X(float angle)
{
    Rotate_X(WWMath::Sinf(angle), WWMath::Cosf(angle));
}


void Vector3::Rotate_X(float s_angle, float c_angle)
{
    float tmp_y = Y;
    float tmp_z = Z;

    Y = c_angle * tmp_y - s_angle * tmp_z;
    Z = s_angle * tmp_y + c_angle * tmp_z;
}


void Vector3::Rotate_Y(float angle)
{
    Rotate_X(WWMath::Sinf(angle), WWMath::Cosf(angle));
}


void Vector3::Rotate_Y(float s_angle, float c_angle)
{
    float tmp_x = X;
    float tmp_z = Z;

    X = c_angle * tmp_x + s_angle * tmp_z;
    Z = -s_angle * tmp_x + c_angle * tmp_z;
}


void Vector3::Rotate_Z(float angle)
{
    Rotate_X(WWMath::Sinf(angle), WWMath::Cosf(angle));
}


void Vector3::Rotate_Z(float s_angle, float c_angle)
{
    float tmp_x = X;
    float tmp_y = Y;

    X = c_angle * tmp_x - s_angle * tmp_y;
    Y = s_angle * tmp_x + c_angle * tmp_y;
}


bool Vector3::Is_Valid() const
{
    return (WWMath::Is_Valid_Float(X) && WWMath::Is_Valid_Float(Y) && WWMath::Is_Valid_Float(Z));
}


float Vector3::Find_X_At_Y(float y, const Vector3& p1, const Vector3& p2)
{
    return (p1.X + ((y - p1.Y) * ((p2.X - p1.X) / (p2.Y - p1.Y))));
}


float Vector3::Find_X_At_Z(float z, const Vector3& p1, const Vector3& p2)
{
    return (p1.X + ((z - p1.Z) * ((p2.X - p1.X) / (p2.Z - p1.Z))));
}


float Vector3::Find_Y_At_X(float x, const Vector3& p1, const Vector3& p2)
{
    return (p1.Y + ((x - p1.X) * ((p2.Y - p1.Y) / (p2.X - p1.X))));
}


float Vector3::Find_Y_At_Z(float z, const Vector3& p1, const Vector3& p2)
{
    return (p1.Y + ((z - p1.Z) * ((p2.Y - p1.Y) / (p2.Z - p1.Z))));
}


float Vector3::Find_Z_At_X(float x, const Vector3& p1, const Vector3& p2)
{
    return (p1.Z + ((x - p1.X) * ((p2.Z - p1.Z) / (p2.X - p1.X))));
}


float Vector3::Find_Z_At_Y(float y, const Vector3& p1, const Vector3& p2)
{
    return (p1.Z + ((y - p1.Y) * ((p2.Z - p1.Z) / (p2.Y - p1.Y))));
}


float Vector3::Distance(const Vector3& p1, const Vector3& p2)
{
    Vector3 temp;
    temp = p1 - p2;
    return temp.Length();
}


float Vector3::Quick_Distance(const Vector3& p1, const Vector3& p2)
{
    Vector3 temp;
    temp = p1 - p2;
    return temp.Quick_Length();
}
