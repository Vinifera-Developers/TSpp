/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MSGLOOP.H
 *
 *  @authors       tomsons26, ZivDero
 *
 *  @brief         Message loop.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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
