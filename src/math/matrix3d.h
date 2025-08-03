/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MATRIX3D.H
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
#pragma once

#include "vector3.h"
#include "vector4.h"


class Matrix3D
{
public:
    Matrix3D() : Row() {}
    Matrix3D(bool init) : Row() { if (init) Make_Identity(); }
    Matrix3D(float m[12]);
    Matrix3D(const Matrix3D& m);
    Matrix3D(const Vector3& x, const Vector3& y, const Vector3& z, const Vector3& pos);
    Matrix3D(const Vector3& axis, float angle);
    Matrix3D(const Vector3& axis, float s, float c);
    Matrix3D(float val1, float val2);
    Matrix3D(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34);

    void Set(const Vector3& x, const Vector3& y, const Vector3& z, const Vector3& pos);
    void Set(const Vector3& axis, float angle);
    void Set(const Vector3& axis, float s, float c);
    void Set(float val1, float val2);
    void Set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34);

    void Set(const Vector3& position);

    inline Matrix3D& operator=(const Matrix3D& m);

    Vector4& operator[](int i) { return Row[i]; }
    const Vector4& operator[](int i) const { return Row[i]; }

    Vector3 Get_Translation() const { return Vector3(Row[0][3], Row[1][3], Row[2][3]); }
    void Get_Translation(Vector3* set) const { set->X = Row[0][3]; set->Y = Row[1][3]; set->Z = Row[2][3]; }
    void Set_Translation(const Vector3& t) { Row[0][3] = t[0]; Row[1][3] = t[1]; Row[2][3] = t[2]; }

    inline float Get_X_Translation(void) const { return Row[0][3]; }
    inline float Get_Y_Translation(void) const { return Row[1][3]; }
    inline float Get_Z_Translation(void) const { return Row[2][3]; }

    inline void Adjust_Translation(const Vector3& t) { Row[0][3] += t[0]; Row[1][3] += t[1]; Row[2][3] += t[2]; }
    inline void Adjust_X_Translation(float x) { Row[0][3] += x; }
    inline void Adjust_Y_Translation(float y) { Row[1][3] += y; }
    inline void Adjust_Z_Translation(float z) { Row[2][3] += z; }

    void Make_Identity();
    void Translate(float x, float y, float z);
    void Translate(const Vector3& t);
    void Translate_X(float x);
    void Translate_Y(float y);
    void Translate_Z(float z);
    void Rotate_X(float theta);
    void Rotate_Y(float theta);
    void Rotate_Z(float theta);
    void Rotate_X(float s, float c);
    void Rotate_Y(float s, float c);
    void Rotate_Z(float s, float c);

    void Scale(float scale);
    void Scale(float x, float y, float z);
    void Scale_X(float scale);
    void Scale_Y(float scale);
    void Scale_Z(float scale);
    void Scale(Vector3& scale);

    void Shear_YZ(float y, float z);
    void Shear_XY(float x, float y);
    void Shear_XZ(float x, float z);

    void Pre_Rotate_X(float theta);
    void Pre_Rotate_Y(float theta);
    void Pre_Rotate_Z(float theta);
    void Pre_Rotate_X(float s, float c);
    void Pre_Rotate_Y(float s, float c);
    void Pre_Rotate_Z(float s, float c);
    void In_Place_Pre_Rotate_X(float theta);
    void In_Place_Pre_Rotate_Y(float theta);
    void In_Place_Pre_Rotate_Z(float theta);
    void In_Place_Pre_Rotate_X(float s, float c);
    void In_Place_Pre_Rotate_Y(float s, float c);
    void In_Place_Pre_Rotate_Z(float s, float c);

    float Get_X();
    float Get_Y();
    float Get_Z();

    float Get_X_Rotation() const;
    float Get_Y_Rotation() const;
    float Get_Z_Rotation() const;

    inline Vector3 Get_X_Vector() const { return Vector3(Row[0][0], Row[1][0], Row[2][0]); }
    inline Vector3 Get_Y_Vector() const { return Vector3(Row[0][1], Row[1][1], Row[2][1]); }
    inline Vector3 Get_Z_Vector() const { return Vector3(Row[0][2], Row[1][2], Row[2][2]); }
    inline void Get_X_Vector(Vector3* set_x) const { set_x->Set(Row[0][0], Row[1][0], Row[2][0]); }
    inline void Get_Y_Vector(Vector3* set_y) const { set_y->Set(Row[0][1], Row[1][1], Row[2][1]); }
    inline void Get_Z_Vector(Vector3* set_z) const { set_z->Set(Row[0][2], Row[1][2], Row[2][2]); }

    Vector3 Rotate_Vector(const Vector3& vect) const;

    void Look_At_1(Vector3& p, Vector3& t, float roll);
    void Look_At_2(Vector3& p, Vector3& t, float roll);

    static void Multiply(const Matrix3D& A, const Matrix3D& B, Matrix3D* set_result);
    static void Transform_Vector(const Matrix3D& tm, const Vector3& in, Vector3* out);
    static void Rotate_Vector(const Matrix3D& tm, const Vector3& in, Vector3* out);

    static void Inverse_Transform_Vector(const Matrix3D& tm, const Vector3& in, Vector3* out);
    static void Inverse_Rotate_Vector(const Matrix3D& tm, const Vector3& in, Vector3* out);

public:
    static const Matrix3D Identity;
    static const Matrix3D RotateX90;
    static const Matrix3D RotateX180;
    static const Matrix3D RotateX270;
    static const Matrix3D RotateY90;
    static const Matrix3D RotateY180;
    static const Matrix3D RotateY270;
    static const Matrix3D RotateZ90;
    static const Matrix3D RotateZ180;
    static const Matrix3D RotateZ270;

protected:
    Vector4 Row[3];

private:
    friend Vector3 operator*(const Matrix3D& A, const Vector3& a);
};


Matrix3D operator*(const Matrix3D& A, const Matrix3D& B);


inline Matrix3D& Matrix3D::operator=(const Matrix3D& m)
{
    Row[0] = m.Row[0];
    Row[1] = m.Row[1];
    Row[2] = m.Row[2];
    return *this;
}


// Some sort of inverse?
Matrix3D func_555D30(Matrix3D& A);
