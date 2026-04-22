/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  PCX image button.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "toggle.h"


class BSurface;


class PCXButtonClass : public ToggleClass
{
public:
    PCXButtonClass();
    PCXButtonClass(unsigned id, const char* image_fname, int x, int y, int w = -1, int h = -1);
    ~PCXButtonClass();

    virtual bool Draw_Me(bool forced = false) override;

    bool Load_Image(const char* filename);

public:
    BSurface* ImageSurface;
};
