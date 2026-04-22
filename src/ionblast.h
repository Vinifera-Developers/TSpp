/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Ion cannon blast handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "tibsun_defines.h"


class IonBlastClass
{
public:
    IonBlastClass(Coord coord);
    ~IonBlastClass();

    void AI();
    void Draw_It();

    static void Update_All();
    static void Draw_All();
    static void One_Time();
    static void Clear_All();

public:
    Coord Position;
    int Lifetime;
};
