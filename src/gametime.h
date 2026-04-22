/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  GameTime class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

class GameTimeClass
{
private:
    unsigned long game_start_time;

public:
    GameTimeClass();
    unsigned long Get_Time();
};


extern GameTimeClass& Game_Time;

extern unsigned long Get_Game_Time();
extern unsigned long Get_Game_Time_60Hz();
