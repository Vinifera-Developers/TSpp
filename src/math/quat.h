/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          QUAT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         General-purpose quaternion.
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

#include "vector3.h"
#include "wwmath.h"


class Matrix3D;


class Quaternion
{
    public:
        inline Quaternion() : X(0.0), Y(0.0), Z(0.0), W(0.0) {}
        inline Quaternion(bool init) : X(0.0), Y(0.0), Z(0.0), W(0.0) { if (init) { X = 0.0f; Y = 0.0f; Z = 0.0f; W = 1.0f; } }
        Quaternion(float x, float y, float z, float w);
        inline Quaternion(const Vector3 &axis, float angle)
        {
	        float s = WWMath::Sinf(angle/2);
	        float c = WWMath::Cosf(angle/2);
	        X = s * axis.X;
	        Y = s * axis.Y;
	        Z = s * axis.Z;
	        W = c;
        }

        void Set(float a = 0.0, float b = 0.0, float c = 0.0, float d = 1.0);
        inline void Make_Identity() { Set(); };
        void Scale(float s);

        float & operator[](int i);
        const float & operator[](int i) const;

        Quaternion operator=(const Quaternion &source);

	    Quaternion operator-() const { return Quaternion(-X, -Y, -Z, -W); } 
	    Quaternion operator+() const { return *this; } 

	    inline float Length2() const { return (X*X + Y*Y + Z*Z + W*W); }
	    inline float Length() const { return WWMath::Sqrt(Length2()); }

        void Normalize();

        inline void Rotate_X(float theta);
        inline void Rotate_Y(float theta);
        inline void Rotate_Z(float theta);

	    bool Is_Valid() const;

        Quaternion & func_5AFFA0(Quaternion &a);

    public:
        float X;
        float Y;
        float Z;
        float W;
};


inline bool Quaternion::Is_Valid() const
{
    return (WWMath::Is_Valid_Float(X) && 
			WWMath::Is_Valid_Float(Y) && 
			WWMath::Is_Valid_Float(Z) &&
			WWMath::Is_Valid_Float(W));
}


// "operator*" ?
Quaternion Quaternion_5B0110(Quaternion &a, Quaternion &b);


// "operator/" ?
Quaternion Quaternion_5B0280(Quaternion &a, Quaternion &b);


Quaternion Inverse(const Quaternion &a);
Quaternion Conjugate(const Quaternion &a);


inline Quaternion operator + (const Quaternion & a,const Quaternion & b)
{
	return Quaternion(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}


inline Quaternion operator - (const Quaternion & a,const Quaternion & b)
{
	return Quaternion(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}


inline Quaternion operator * (float scl, const Quaternion & a)
{
	return Quaternion(scl*a[0], scl*a[1], scl*a[2], scl*a[3]);
}


inline Quaternion operator * (const Quaternion & a, float scl)
{
	return scl*a;
}


inline Quaternion operator * (const Quaternion & a,const Quaternion & b)
{
	return Quaternion
	(
		a.W * b.X + b.W * a.X + (a.Y * b.Z - b.Y * a.Z),
		a.W * b.Y + b.W * a.Y - (a.X * b.Z - b.X * a.Z),
		a.W * b.Z + b.W * a.Z + (a.X * b.Y - b.X * a.Y),
		a.W * b.W - (a.X * b.X + a.Y * b.Y + a.Z * b.Z)
	);
}


inline Quaternion operator / (const Quaternion & a,const Quaternion & b)
{
	return a * Inverse(b);
}


Quaternion Trackball(float x0, float y0, float x1, float y1, float sphsize);
Quaternion Axis_To_Quat(const Vector3 &a, float angle);
Quaternion Slerp(Quaternion &a, Quaternion &b, float alpha);
Quaternion Build_Quaternion(const Matrix3D &mat);
Matrix3D Build_Matrix3D(const Quaternion &q);


inline void Quaternion::Rotate_X(float theta)
{
    *this = (*this) * Quaternion(Vector3(1,0,0),theta);
}


inline void Quaternion::Rotate_Y(float theta)
{
    *this = (*this) * Quaternion(Vector3(0,1,0),theta);
}


inline void Quaternion::Rotate_Z(float theta)
{
    *this = (*this) * Quaternion(Vector3(0,0,1),theta);
}
