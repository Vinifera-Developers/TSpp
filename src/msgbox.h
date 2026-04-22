/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Message boxes that use the game ui.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "language.h"
#include "tibsun_defines.h"


class WWMessageBox
{
public:
    WWMessageBox(int caption = TXT_NONE);

    int Process(const char* msg, int a2, const char* b1txt, const char* b2txt = nullptr, const char* b3txt = nullptr, bool preserve = false);
    int Process(int msg, int a2, int b1txt = TXT_OK, int b2txt = TXT_NONE, int b3txt = TXT_NONE, bool preserve = false);
    int Process(char const* msg, int a2, int b1txt = TXT_OK, int b2txt = TXT_NONE, int b3txt = TXT_NONE, bool preserve = false);

private:
    int Caption;
};
