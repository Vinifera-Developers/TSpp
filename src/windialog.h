/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WINDIALOG.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Functions for handling the games owner draw dialogs.
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

#include "always.h"


namespace WinDialogClass
{

void End_Dialog(HWND hWnd);
bool Dialog_Move(HWND hWnd, WPARAM wParam, LPARAM lParam, UINT uMsg);
bool Center_Window_Within(HWND dialog, HWND window);

extern HWND &CurrentWindowHandle;

};
