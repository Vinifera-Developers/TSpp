/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MATRIX3D.CPP
 *
 *  @authors       tomsons26
 *
 *  @brief         Represents a matrix containing 3D rotation and scale.
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
#include "matrix3d.h"
#include <iostream>


/**
 *  Some pre-initialized Matrix3's which are sometimes useful.
 */
const Matrix3D Matrix3D::Identity
(
	1.0,	0.0,	0.0,	0.0,
	0.0,	1.0,	0.0,	0.0,
	0.0,	0.0,	1.0,	0.0
);

const Matrix3D Matrix3D::RotateX90
(
	1.0,	0.0,	0.0,	0.0,
	0.0,	0.0,    -1.0,	0.0,
	0.0,	1.0,	0.0,	0.0
);

const Matrix3D Matrix3D::RotateX180
(
	1.0,	0.0,	0.0,	0.0,
	0.0,    -1.0,	0.0,	0.0,
	0.0,	0.0,    -1.0,	0.0
);

const Matrix3D Matrix3D::RotateX270
(
	1.0,	0.0,	0.0,	0.0,
	0.0,	0.0,	1.0,	0.0,
	0.0,    -1.0,	0.0,	0.0
);

const Matrix3D Matrix3D::RotateY90
(
	0.0,	0.0,	1.0,	0.0,
	0.0,	1.0,	0.0,	0.0,
    -1.0,	0.0,	0.0,	0.0
);

const Matrix3D Matrix3D::RotateY180
(
    -1.0,	0.0,	0.0,	0.0,
	0.0,	1.0,	0.0,	0.0,
	0.0,	0.0,    -1.0,	0.0
);

const Matrix3D Matrix3D::RotateY270
(
	0.0,	0.0,    -1.0,	0.0,
	0.0,	1.0,	0.0,	0.0,
	1.0,	0.0,	0.0,	0.0
);

const Matrix3D	Matrix3D::RotateZ90
(
	0.0,    -1.0,	0.0,	0.0,
	1.0,	0.0,	0.0,	0.0,
	0.0,	0.0,	1.0,	0.0
);

const Matrix3D Matrix3D::RotateZ180
(
    -1.0,	0.0,	0.0,	0.0,
	0.0,    -1.0,	0.0,	0.0,
	0.0,	0.0,	1.0,	0.0
);

const Matrix3D	Matrix3D::RotateZ270
(
	0.0,	1.0,	0.0,	0.0,
    -1.0,	0.0,	0.0,	0.0,
 	0.0,	0.0,	1.0,	0.0
);


Matrix3D::Matrix3D(float m[12])
{
	Row[0].Set(m[0],m[1],m[2],m[3]);
	Row[1].Set(m[4],m[5],m[6],m[7]);
	Row[2].Set(m[8],m[9],m[10],m[11]);
}


Matrix3D::Matrix3D(const Vector3 &x, const Vector3 &y, const Vector3 &z, const Vector3 &pos)
{
	Set(x,y,z,pos);
}


Matrix3D::Matrix3D(const Vector3 &axis, float angle)
{
    Set(axis, angle);
}


Matrix3D::Matrix3D(const Vector3 &axis, float s, float c)
{
    Set(axis, s, c);
}


Matrix3D::Matrix3D(float val1, float val2)
{
    Set(val1, val2);
}


void Matrix3D::Set(float m11, float m12, float m13, float m14,
                   float m21, float m22, float m23, float m24,
                   float m31, float m32, float m33, float m34)
{
	Row[0].Set(m11,m12,m13,m14);
	Row[1].Set(m21,m22,m23,m24);
	Row[2].Set(m31,m32,m33,m34);
}


void Matrix3D::Set(const Vector3 &axis, float s, float c)
{
	TSPP_ASSERT(WWMath::Fabs(axis.Length2() - 1.0f) < 0.001f);

	Row[0].Set(
		(float)(axis[0]*axis[0] + c*(1.0f - axis[0]*axis[0])),
		(float)(axis[0]*axis[1]*(1.0f - c) - axis[2]*s),
		(float)(axis[2]*axis[0]*(1.0f - c) + axis[1]*s),
		0.0f
	);

	Row[1].Set(
		(float)(axis[0]*axis[1]*(1.0f - c) + axis[2]*s),
		(float)(axis[1]*axis[1] + c*(1.0f - axis[1]*axis[1])),
		(float)(axis[1]*axis[2]*(1.0f - c) - axis[0]*s),
		0.0f
	);

	Row[2].Set(
		(float)(axis[2]*axis[0]*(1.0f - c) - axis[1]*s),
		(float)(axis[1]*axis[2]*(1.0f - c) + axis[0]*s),
		(float)(axis[2]*axis[2] + c*(1 - axis[2]*axis[2])),
		0.0f
	);
}


void Matrix3D::Set(const Vector3 &position)
{
	Row[0].Set(1.0f,0.0f,0.0f,position[0]);
	Row[1].Set(0.0f,1.0f,0.0f,position[1]);
	Row[2].Set(0.0f,0.0f,1.0f,position[2]);
}


void Matrix3D::Scale(Vector3 &scale)
{
	Scale(scale.X, scale.Y, scale.Z);
}


void Matrix3D::Pre_Rotate_X(float theta)
{
    float tmp1, tmp2;
    float c, s;

    s = WWMath::Sinf(theta);
    c = WWMath::Cosf(theta);

    tmp1 = Row[1][0]; tmp2 = Row[2][0];
    Row[1][0] = tmp1 * c + tmp2 * -s;
    Row[2][0] = tmp1 * s + tmp2 * c;

    tmp1 = Row[1][1]; tmp2 = Row[2][1];
    Row[1][1] = tmp1 * c + tmp2 * -s;
    Row[2][1] = tmp1 * s + tmp2 * c;

    tmp1 = Row[1][2]; tmp2 = Row[2][2];
    Row[1][2] = tmp1 * c + tmp2 * -s;
    Row[2][2] = tmp1 * s + tmp2 * c;

    tmp1 = Row[1][3]; tmp2 = Row[2][3];
    Row[1][3] = tmp1 * c + tmp2 * -s;
    Row[2][3] = tmp1 * s + tmp2 * c;
}


void Matrix3D::Pre_Rotate_Y(float theta)
{
    float tmp1, tmp2;
    float c, s;

    s = WWMath::Sinf(theta);
    c = WWMath::Cosf(theta);

    tmp1 = Row[1][0]; tmp2 = Row[2][0];
    Row[0][0] = tmp1 * c + tmp2 * s;
    Row[2][0] = tmp1 * -s + tmp2 * c;

    tmp1 = Row[0][1]; tmp2 = Row[2][1];
    Row[0][1] = tmp1 * c + tmp2 * s;
    Row[2][1] = tmp1 * -s + tmp2 * c;

    tmp1 = Row[0][2]; tmp2 = Row[2][2];
    Row[0][2] = tmp1 * c + tmp2 * s;
    Row[2][2] = tmp1 * -s + tmp2 * c;

    tmp1 = Row[0][3]; tmp2 = Row[2][3];
    Row[0][3] = tmp1 * c + tmp2 * s;
    Row[2][3] = tmp1 * -s + tmp2 * c;
}


void Matrix3D::Pre_Rotate_Z(float theta)
{
    float tmp1, tmp2;
    float c, s;

    s = WWMath::Sinf(theta);
    c = WWMath::Cosf(theta);

    tmp1 = Row[0][0]; tmp2 = Row[1][0];
    Row[0][0] = tmp1 * c + tmp2 * -s;
    Row[1][0] = tmp1 * s + tmp2 * c;

    tmp1 = Row[0][1]; tmp2 = Row[1][1];
    Row[0][1] = tmp1 * c + tmp2 * -s;
    Row[1][1] = tmp1 * s + tmp2 * c;

    tmp1 = Row[0][2]; tmp2 = Row[1][2];
    Row[0][2] = tmp1 * c + tmp2 * -s;
    Row[1][2] = tmp1 * s + tmp2 * c;

    tmp1 = Row[0][3]; tmp2 = Row[1][3];
    Row[0][3] = tmp1 * c + tmp2 * -s;
    Row[1][3] = tmp1 * s + tmp2 * c;
}


void Matrix3D::Pre_Rotate_X(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[1][0]; tmp2 = Row[2][0];
	Row[1][0] = (float)(c*tmp1 - s*tmp2);
	Row[2][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][1]; tmp2 = Row[2][1];
	Row[1][1] = (float)(c*tmp1 - s*tmp2);
	Row[2][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][2]; tmp2 = Row[2][2];
	Row[1][2] = (float)(c*tmp1 - s*tmp2);
	Row[2][2] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][3]; tmp2 = Row[2][3];
	Row[1][3] = (float)(c*tmp1 - s*tmp2);
	Row[2][3] = (float)(s*tmp1 + c*tmp2);
}


void Matrix3D::Pre_Rotate_Y(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[0][0]; tmp2 = Row[2][0];
	Row[0][0] = (float)( c*tmp1 + s*tmp2);
	Row[2][0] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[2][1];
	Row[0][1] = (float)( c*tmp1 + s*tmp2);
	Row[2][1] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[2][2];
	Row[0][2] = (float)( c*tmp1 + s*tmp2);
	Row[2][2] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][3]; tmp2 = Row[2][3];
	Row[0][3] = (float)( c*tmp1 + s*tmp2);
	Row[2][3] = (float)(-s*tmp1 + c*tmp2);
}


void Matrix3D::Pre_Rotate_Z(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[0][0]; tmp2 = Row[1][0];
	Row[0][0] = (float)(c*tmp1 - s*tmp2);
	Row[1][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[1][1];
	Row[0][1] = (float)(c*tmp1 - s*tmp2);
	Row[1][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[1][2];
	Row[0][2] = (float)(c*tmp1 - s*tmp2);
	Row[1][2] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][3]; tmp2 = Row[1][3];
	Row[0][3] = (float)(c*tmp1 - s*tmp2);
	Row[1][3] = (float)(s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_X(float theta)
{
	float tmp1, tmp2;
	float c,s;

	c = WWMath::Cosf(theta);
	s = WWMath::Sinf(theta);

	tmp1 = Row[1][0]; tmp2 = Row[2][0];
	Row[1][0] = (float)(c*tmp1 - s*tmp2);
	Row[2][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][1]; tmp2 = Row[2][1];
	Row[1][1] = (float)(c*tmp1 - s*tmp2);
	Row[2][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][2]; tmp2 = Row[2][2];
	Row[1][2] = (float)(c*tmp1 - s*tmp2);
	Row[2][2] = (float)(s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_Y(float theta)
{
	float tmp1, tmp2;
	float c,s;

	c = WWMath::Cosf(theta);
	s = WWMath::Sinf(theta);

	tmp1 = Row[0][0]; tmp2 = Row[2][0];
	Row[0][0] = (float)( c*tmp1 + s*tmp2);
	Row[2][0] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[2][1];
	Row[0][1] = (float)( c*tmp1 + s*tmp2);
	Row[2][1] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[2][2];
	Row[0][2] = (float)( c*tmp1 + s*tmp2);
	Row[2][2] = (float)(-s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_Z(float theta)
{
	float tmp1, tmp2;
	float c,s;

	c = WWMath::Cosf(theta);
	s = WWMath::Sinf(theta);

	tmp1 = Row[0][0]; tmp2 = Row[1][0];
	Row[0][0] = (float)(c*tmp1 - s*tmp2);
	Row[1][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[1][1];
	Row[0][1] = (float)(c*tmp1 - s*tmp2);
	Row[1][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[1][2];
	Row[0][2] = (float)(c*tmp1 - s*tmp2);
	Row[1][2] = (float)(s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_X(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[1][0]; tmp2 = Row[2][0];
	Row[1][0] = (float)(c*tmp1 - s*tmp2);
	Row[2][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][1]; tmp2 = Row[2][1];
	Row[1][1] = (float)(c*tmp1 - s*tmp2);
	Row[2][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[1][2]; tmp2 = Row[2][2];
	Row[1][2] = (float)(c*tmp1 - s*tmp2);
	Row[2][2] = (float)(s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_Y(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[0][0]; tmp2 = Row[2][0];
	Row[0][0] = (float)( c*tmp1 + s*tmp2);
	Row[2][0] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[2][1];
	Row[0][1] = (float)( c*tmp1 + s*tmp2);
	Row[2][1] = (float)(-s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[2][2];
	Row[0][2] = (float)( c*tmp1 + s*tmp2);
	Row[2][2] = (float)(-s*tmp1 + c*tmp2);
}


void Matrix3D::In_Place_Pre_Rotate_Z(float s, float c)
{
	float tmp1, tmp2;

	tmp1 = Row[0][0]; tmp2 = Row[1][0];
	Row[0][0] = (float)(c*tmp1 - s*tmp2);
	Row[1][0] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][1]; tmp2 = Row[1][1];
	Row[0][1] = (float)(c*tmp1 - s*tmp2);
	Row[1][1] = (float)(s*tmp1 + c*tmp2);

	tmp1 = Row[0][2]; tmp2 = Row[1][2];
	Row[0][2] = (float)(c*tmp1 - s*tmp2);
	Row[1][2] = (float)(s*tmp1 + c*tmp2);
}

void Matrix3D::Multiply(const Matrix3D &A, const Matrix3D &B, Matrix3D *set_result)
{
	TSPP_ASSERT(set_result != NULL);

	Matrix3D tmp;
	Matrix3D *Aptr;
	float tmp1, tmp2, tmp3;

	if (set_result == &A) {
		tmp = A;
		Aptr = &tmp;
	} else {
		Aptr = (Matrix3D *)&A;	
	}

	tmp1 = B[0][0];
	tmp2 = B[1][0];
	tmp3 = B[2][0];

	(*set_result)[0][0] = (*Aptr)[0][0]*tmp1 + (*Aptr)[0][1]*tmp2 + (*Aptr)[0][2]*tmp3;
	(*set_result)[1][0] = (*Aptr)[1][0]*tmp1 + (*Aptr)[1][1]*tmp2 + (*Aptr)[1][2]*tmp3;
	(*set_result)[2][0] = (*Aptr)[2][0]*tmp1 + (*Aptr)[2][1]*tmp2 + (*Aptr)[2][2]*tmp3;

	tmp1 = B[0][1];
	tmp2 = B[1][1];
	tmp3 = B[2][1];

	(*set_result)[0][1] = (*Aptr)[0][0]*tmp1 + (*Aptr)[0][1]*tmp2 + (*Aptr)[0][2]*tmp3;
	(*set_result)[1][1] = (*Aptr)[1][0]*tmp1 + (*Aptr)[1][1]*tmp2 + (*Aptr)[1][2]*tmp3;
	(*set_result)[2][1] = (*Aptr)[2][0]*tmp1 + (*Aptr)[2][1]*tmp2 + (*Aptr)[2][2]*tmp3;

	tmp1 = B[0][2];
	tmp2 = B[1][2];
	tmp3 = B[2][2];

	(*set_result)[0][2] = (*Aptr)[0][0]*tmp1 + (*Aptr)[0][1]*tmp2 + (*Aptr)[0][2]*tmp3;
	(*set_result)[1][2] = (*Aptr)[1][0]*tmp1 + (*Aptr)[1][1]*tmp2 + (*Aptr)[1][2]*tmp3;
	(*set_result)[2][2] = (*Aptr)[2][0]*tmp1 + (*Aptr)[2][1]*tmp2 + (*Aptr)[2][2]*tmp3;

	tmp1 = B[0][3];
	tmp2 = B[1][3];
	tmp3 = B[2][3];

	(*set_result)[0][3] = (*Aptr)[0][0]*tmp1 + (*Aptr)[0][1]*tmp2 + (*Aptr)[0][2]*tmp3 + (*Aptr)[0][3];
	(*set_result)[1][3] = (*Aptr)[1][0]*tmp1 + (*Aptr)[1][1]*tmp2 + (*Aptr)[1][2]*tmp3 + (*Aptr)[1][3];
	(*set_result)[2][3] = (*Aptr)[2][0]*tmp1 + (*Aptr)[2][1]*tmp2 + (*Aptr)[2][2]*tmp3 + (*Aptr)[2][3];
}


void Matrix3D::Transform_Vector(const Matrix3D &tm, const Vector3 &in, Vector3 *out)
{
	Vector3 tmp;
	Vector3 *v;

	if (out == &in) {
		tmp = in;
		v = &tmp;
	} else {
		v = (Vector3 *)&in;
	}

	out->X = (tm[0][0] * v->X + tm[0][1] * v->Y + tm[0][2] * v->Z + tm[0][3]);
	out->Y = (tm[1][0] * v->X + tm[1][1] * v->Y + tm[1][2] * v->Z + tm[1][3]);
	out->Z = (tm[2][0] * v->X + tm[2][1] * v->Y + tm[2][2] * v->Z + tm[2][3]);
}


void Matrix3D::Rotate_Vector(const Matrix3D &tm, const Vector3 &in, Vector3 *out)
{
	Vector3 tmp;
	Vector3 *v;

	if (out == &in) {
		tmp = in;
		v = &tmp;
	} else {
		v = (Vector3 *)&in;
	}

	out->X = (tm[0][0] * v->X + tm[0][1] * v->Y + tm[0][2] * v->Z);
	out->Y = (tm[1][0] * v->X + tm[1][1] * v->Y + tm[1][2] * v->Z);
	out->Z = (tm[2][0] * v->X + tm[2][1] * v->Y + tm[2][2] * v->Z);
}


void Matrix3D::Inverse_Transform_Vector(const Matrix3D &tm, const Vector3 &in, Vector3 *out)
{
	Vector3 tmp;
	Vector3 *v;

	if (out == &in) {
		tmp = in;
		v = &tmp;
	} else {
		v = (Vector3 *)&in;
	}

	Vector3 diff(v->X - tm[0][3], v->Y - tm[1][3], v->Z - tm[2][3]);
	Matrix3D::Inverse_Rotate_Vector(tm, diff, out);
}


void Matrix3D::Inverse_Rotate_Vector(const Matrix3D &tm, const Vector3 &in, Vector3 *out)
{
	Vector3 tmp;
	Vector3 *v;

	if (out == &in) {
		tmp = in;
		v = &tmp;
	} else {
		v = (Vector3 *)&in;
	}
	out->X = (tm[0][0] * v->X + tm[1][0] * v->Y + tm[2][0] * v->Z);
	out->Y = (tm[0][1] * v->X + tm[1][1] * v->Y + tm[2][1] * v->Z);
	out->Z = (tm[0][2] * v->X + tm[1][2] * v->Y + tm[2][2] * v->Z);
}
