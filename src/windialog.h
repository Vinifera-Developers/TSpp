/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Functions for handling the games owner draw dialogs.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


namespace WinDialogClass
{

void Display_Dialog(HWND hWnd);
void End_Dialog(HWND hWnd);
HWND Do_Message_Box(const char* button1, const char* button2, bool* state);
bool Center_Window(HWND dialog);
bool Center_Window_Within(HWND dialog, HWND window);

extern HWND& CurrentWindowHandle;

}; // namespace WinDialogClass

extern int& WSDialogCount;
