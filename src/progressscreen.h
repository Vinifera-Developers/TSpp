/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PROGRESSSCREEN.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Loading screen progress.
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
#include "tibsun_defines.h"


class Rect;
struct ShapeFileStruct;


class ProgressScreenClass
{
	public:
		ProgressScreenClass();
		~ProgressScreenClass();

		void Init(double start_progress, int player_count, bool do_dialog);
		void Reset();
		void Draw_Graphics(const ShapeFileStruct *progress_bar_shape, const char *background_image, const char *string, int text_xpos, int text_ypos);
		double Get_Total_Progress();
		void Draw_Bars_And_Text(int xpos, int ypos);
		Rect Get_Bar_Dimensions();
		void Update_Progress(int player_index, double value, int xpos, int ypos);
		void Add_Progress(int player_index, double value, int xpos, int ypos);

		void Init_Dialog();
		void Destroy_Dialog();

		static LRESULT CALLBACK Dialog_Proc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

	public:
		double PlayerProgress[MAX_PLAYERS];
		double MainProgress;
		const char *String;
		ShapeFileStruct *ProgressShape;
		const char *BackgroundImage;
		bool field_54;
		char field_55;
		HWND Handle;
		int XPos;
		int YPos;
		int field_64;
};
