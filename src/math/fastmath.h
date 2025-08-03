/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FASTMATH.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Basic math functions.
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


namespace FastMath
{

float __cdecl Sqrt(double val);
float __cdecl Sin(double val);
float __cdecl Cos(double val);
float __cdecl Tan(double val);
float __cdecl Asin(double val);
float __cdecl Acos(double val);
float __cdecl Atan(double val);
float __cdecl Atan2(double y, double x);

float __stdcall Sqrtf(float val);
float __stdcall Sinf(float val);
float __stdcall Cosf(float val);
float __stdcall Tanf(float val);
float __stdcall Asinf(float val);
float __stdcall Acosf(float val);
float __stdcall Atanf(float val);
float __stdcall Atan2f(float y, float x);

// int __cdecl ftol(double f);
//__int64 __cdecl ftol64(double f);

}; // namespace FastMath
