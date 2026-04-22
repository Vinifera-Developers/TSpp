/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Message loop.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include <windows.h>

// Main message handler.
void Windows_Message_Handler();

// Modeless dialog box support routines.
void Remove_Modeless_Dialog(HWND dialog);
void Add_Modeless_Dialog(HWND dialog);
HWND Get_Modeless_Dialog_From_Name(const char* name);

// Accelerator keys support routines.
void Add_Accelerator(HWND window, HACCEL accelerator);
void Remove_Accelerator(HACCEL accelerator);

// General purpose message intercept handler.
extern bool (*Message_Intercept_Handler)(MSG& msg);
