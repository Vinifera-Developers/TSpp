/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Graphic menu instance class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "msengine.h"
#include "vector.h"


class GraphicMenuItem;


class GraphicMenu
{
public:
    GraphicMenu();
    virtual ~GraphicMenu();

public:
    MSEngine Engine;
    char* Background;
    char* Theme;
    int field_54;
    DynamicVectorClass<GraphicMenuItem*> Items;
};
