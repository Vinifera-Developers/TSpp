/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VECTOR2.H
 *
 *  @authors       tomsons26
 *
 *  @brief         A 2D Vector with floating point coordinates, used for
 *                 storing 2D translations, mouse movements, and
 *                 screen-space vectors.
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


class Vector2
{
public:
    Vector2() { X = 0; Y = 0; }
    Vector2(const Vector2& v) { X = v.X; Y = v.Y; }
    Vector2(float x, float y) { X = x; Y = y; }
    Vector2(const float vector[2]) { X = vector[0]; Y = vector[1]; }

    Vector2& operator=(const Vector2& v) { X = v[0]; Y = v[1]; return *this; }
    void Set(float x, float y) { X = x; Y = y; }
    void Set(const Vector2& v) { X = v.X; Y = v.Y; }

    float& operator[](int i) { return (&X)[i]; }
    const float& operator[](int i) const { return (&X)[i]; }

    inline void Normalize();
    inline float Length() const;
    inline float Length2() const;

    Vector2 operator-() const { return Vector2(-X, -Y); }
    Vector2 operator+() const { return *this; }

    Vector2& operator+=(const Vector2& v) { X += v.X; Y += v.Y; return *this; }
    Vector2& operator-=(const Vector2& v) { X -= v.X; Y -= v.Y; return *this; }
    Vector2& operator*=(float k) { X = X * k; Y = Y * k; return *this; }
    Vector2& operator/=(float k) { k = 1.0f / k; X *= k; Y *= k; return *this; }


    inline friend Vector2 operator*(const Vector2& a, float k);
    inline friend Vector2 operator*(float k, const Vector2& a);
    inline friend Vector2 operator/(const Vector2& a, float k);

    inline friend Vector2 operator+(const Vector2& a, const Vector2& b);
    inline friend Vector2 operator-(const Vector2& a, const Vector2& b);

    inline friend float operator*(const Vector2& a, const Vector2& b);
    inline static float Dot_Product(const Vector2& a, const Vector2& b);

    inline static float Perp_Dot_Product(const Vector2& a, const Vector2& b);

    inline friend bool operator==(const Vector2& a, const Vector2& b);
    inline friend bool operator!=(const Vector2& a, const Vector2& b);
    inline friend bool Equal_Within_Epsilon(const Vector2& a, const Vector2& b, float epsilon);

    inline void Rotate(float theta);
    inline void Rotate(float s, float c);
    inline bool Rotate_Towards_Vector(Vector2& target, float max_theta, bool& positive_turn);
    inline bool Rotate_Towards_Vector(Vector2& target, float max_s, float max_c, bool& positive_turn);

    inline bool Is_Valid() const;

    inline void Update_Min(const Vector2& a);
    inline void Update_Max(const Vector2& a);
    inline void Scale(float a, float b);
    inline void Scale(const Vector2& a);

    inline static float Distance(const Vector2& p1, const Vector2& p2);
    inline static float Quick_Distance(const Vector2& p1, const Vector2& p2);

    inline static void Lerp(const Vector2& a, const Vector2& b, float t, Vector2* set_result);

public:
    union {
        float X;
        float U;
    };

    union {
        float Y;
        float V;
    };
};


inline Vector2 operator*(const Vector2& a, float k)
{
    float a0k(a[0] * k);
    float a1k(a[1] * k);
    return Vector2(a0k, a1k);
}


inline Vector2 operator*(float k, const Vector2& a)
{
    float a0k(a[0] * k);
    float a1k(a[1] * k);
    return Vector2(a0k, a1k);
}


inline Vector2 operator/(const Vector2& a, float k)
{
    float ook = 1.0f / k;
    float a0ook(a[0] * ook);
    float a1ook(a[1] * ook);
    return Vector2(a0ook, a1ook);
}


inline Vector2 operator+(const Vector2& a, const Vector2& b)
{
    return Vector2(a.X + b.X, a.Y + b.Y);
}


inline Vector2 operator-(const Vector2& a, const Vector2& b)
{
    return Vector2(a.X - b.X, a.Y - b.Y);
}


inline float operator*(const Vector2& a, const Vector2& b)
{
    return a.X * b.X + a.Y * b.Y;
}


float Vector2::Dot_Product(const Vector2& a, const Vector2& b)
{
    return a * b;
}


float Vector2::Perp_Dot_Product(const Vector2& a, const Vector2& b)
{
    return a.X * -b.Y + a.Y * b.X;
}


inline bool operator==(const Vector2& a, const Vector2& b)
{
    bool a0b0(a[0] == b[0]);
    bool a1b1(a[1] == b[1]);
    return (a0b0 & a1b1);
}


inline bool operator!=(const Vector2& a, const Vector2& b)
{
    bool a0b0(a[0] != b[0]);
    bool a1b1(a[1] != b[1]);
    return (a0b0 | a1b1);
}


inline bool Equal_Within_Epsilon(const Vector2& a, const Vector2& b, float epsilon)
{
    return (WWMath::Fabs(a.X - b.X) < epsilon) && (WWMath::Fabs(a.Y - b.Y) < epsilon);
}


void Vector2::Normalize()
{
    float len2 = Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(len2);
        X *= oolen;
        Y *= oolen;
    }
}


inline Vector2 Normalize(const Vector2& vec)
{
    float len2 = vec.Length2();
    if (len2 != 0.0f) {
        float oolen = WWMath::Inv_Sqrtf(len2);
        return vec / oolen;
    }
    return Vector2(0.0f, 0.0f);
}


float Vector2::Length() const
{
    return WWMath::Sqrtf(Length2());
}


float Vector2::Length2() const
{
    return (X * X + Y * Y);
}


void Vector2::Rotate(float theta)
{
    Rotate(WWMath::Sin(theta), WWMath::Cos(theta));
}


void Vector2::Rotate(float s, float c)
{
    float new_x = X * c + Y * -s;
    float new_y = X * s + Y * c;
    X = new_x;
    Y = new_y;
}


bool Vector2::Rotate_Towards_Vector(Vector2& target, float max_theta, bool& positive_turn)
{
    return Rotate_Towards_Vector(target, WWMath::Sin(max_theta), WWMath::Cos(max_theta), positive_turn);
}


bool Vector2::Rotate_Towards_Vector(Vector2& target, float max_s, float max_c, bool& positive_turn)
{
    bool return_value = false;

    positive_turn = Vector2::Perp_Dot_Product(target, *this) > 0.0f;

    if (Vector2::Dot_Product(*this, target) >= max_c) {
        Set(target);
        return_value = true;

    } else {

        if (positive_turn) {
            Rotate(max_s, max_c);
        } else {
            Rotate(-max_s, max_c);
        }
    }

    return return_value;
}


inline void Swap(Vector2& a, Vector2& b)
{
    Vector2 tmp(a);
    a = b;
    b = tmp;
}


bool Vector2::Is_Valid() const
{
    return (WWMath::Is_Valid_Float(X) && WWMath::Is_Valid_Float(Y));
}


void Vector2::Update_Min(const Vector2& a)
{
    if (a.X < X) X = a.X;
    if (a.Y < Y) Y = a.Y;
}


void Vector2::Update_Max(const Vector2& a)
{
    if (a.X > X) X = a.X;
    if (a.Y > Y) Y = a.Y;
}


void Vector2::Scale(float a, float b)
{
    X *= a;
    Y *= b;
}


void Vector2::Scale(const Vector2& a)
{
    X *= a.X;
    Y *= a.Y;
}


inline float Quick_Distance(float x1, float y1, float x2, float y2)
{
    float x_diff = x1 - x2;
    float y_diff = y1 - y2;

    WWMath::Fabs(x_diff);
    WWMath::Fabs(y_diff);

    if (x_diff > y_diff) {
        return (y_diff / 2) + x_diff;
    } else {
        return (x_diff / 2) + y_diff;
    }
}


float Vector2::Quick_Distance(const Vector2& a, const Vector2& b)
{
    return ::Quick_Distance(a.X, a.Y, b.X, b.Y);
}


float Vector2::Distance(const Vector2& a, const Vector2& b)
{
    Vector2 temp;
    temp = a - b;

    return temp.Length();
}


inline float Distance(float x1, float y1, float x2, float y2)
{
    float x_diff = x1 - x2;
    float y_diff = y1 - y2;

    return WWMath::Sqrtf((x_diff * x_diff) + (y_diff * y_diff));
}


void Vector2::Lerp(const Vector2& a, const Vector2& b, float t, Vector2* set_result)
{
    TSPP_ASSERT(set_result != nullptr);
    set_result->X = (a.X + (b.X - a.X) * t);
    set_result->Y = (a.Y + (b.Y - a.Y) * t);
}
