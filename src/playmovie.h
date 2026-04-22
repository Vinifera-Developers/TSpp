/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Functions for playing movies.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"

struct VQHandle;


void Play_Movie(char const* name, ThemeType theme = THEME_NONE, bool clear_before = true, bool stretch_allowed = true, bool clear_after = true);
void Play_Movie(VQType name, ThemeType theme = THEME_NONE, bool clear_screen = true, bool stretch_allowed = false);
void Play_Fullscreen_Movie(char const* name, ThemeType theme);
void Play_Ingame_Movie(char const* name);
void Play_Ingame_Movie(VQType name);
void End_Ingame_Movie();
bool Movie_Is_Playing();
void Movie_Update_Visible_Surface();
void Movie_Queue_Ingame(VQHandle* handle);
