/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Ingame movie tracker and player.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "rect.h"
#include "tibsun_defines.h"


class VQAClass;
class Surface;


struct VQHandle {
    VQAClass* VQA;
    int field_4;
    Surface* DrawSurface;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    Rect InitialRect;
    Rect StretchRect;
    bool field_44;
    bool field_45;
};

extern VQHandle*& CurrentVQ;
