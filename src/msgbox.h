/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MSGBOX.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Message boxes that use the game ui.
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

#include "tibsun_defines.h"


class WWMessageBox
{
	public:
		WWMessageBox(int caption = TXT_NONE);

		int Process(const char *msg, const char *b1txt, const char *b2txt = nullptr, const char *b3txt = nullptr, bool preserve = false);
		int Process(int msg, int b1txt = TXT_OK, int b2txt = TXT_NONE, int b3txt = TXT_NONE, bool preserve = false);
		int Process(char const *msg, int b1txt = TXT_OK, int b2txt = TXT_NONE, int b3txt = TXT_NONE, bool preserve = false);

	private:
		int Caption;
};

