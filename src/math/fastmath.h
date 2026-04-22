/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic math functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
