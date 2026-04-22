/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Representation of a cell on the game world map.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ccfile.h"


class NewMenuClass
{
public:
    NewMenuClass();
    //~NewMenuClass();

    static void Blit();
    static NewMenuClass* Get();

    bool Is_Loaded() const { return Mix != nullptr; }
    const char* Background_Image() const { return BackgroundImage; }

public:
    MFCD* Mix;
    int GameMode;
    const char* BackgroundImage;
};
