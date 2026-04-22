/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Shape image button.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "toggle.h"


class ConvertClass;
class ShapeSet;


class ShapeButtonClass : public ToggleClass
{
public:
    ShapeButtonClass();
    ShapeButtonClass(unsigned id, const ShapeSet* shapes, int x, int y, int w = 0, int h = 0, bool alpha = false);
    virtual ~ShapeButtonClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual void Set_Shape(const ShapeSet* data, int width = 0, int height = 0);

    const ShapeSet* Get_Shape_Data() { return ShapeData; }

public:
    bool ReflectButtonState;
    int DrawX;
    int DrawY;
    bool DrawnOnSidebarSurface;
    ConvertClass* ShapeDrawer;
    bool IsDrawn;
    bool DrawAlpha;
    const ShapeSet* ShapeData;
};
