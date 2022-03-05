/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_FUNCTIONS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Global and uncategorised functions.
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
#include "wwkeyboard.h"
#include "tibsun_defines.h"


class FileClass;
class Rect;
class XSurface;
class PaletteClass;
class ObjectClass;


void *Load_Alloc_Data(char const *name, int flags = 0 /* MEM_NORMAL */);
void *Load_Alloc_Data(FileClass &file);

void Call_Back();
void Load_Keyboard_Hotkeys();
bool VQA_Movie_Message_Loop();
bool Parse_Command_Line(int argc, char *argv[]);
int Create_Main_Window(HINSTANCE hInstance, int command_show, int width, int height);
void Prep_Direct_Draw();
bool Set_Video_Mode(HWND hWnd, int w, int h, int bits_per_pixel);
void Reset_Video_Mode();
bool Allocate_Surfaces(Rect *common_rect, Rect *composite_rect, Rect *tile_rect, Rect *sidebar_rect, bool alloc_hidden_surf = false);
void Wait_Blit();
void Set_DD_Palette(void *rpalette);
LRESULT CALLBACK Main_Window_Procedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
bool func_6A83E0(Rect &torect, const Rect &toarea, Rect &fromrect, const Rect &fromarea);
void Unselect_All();
void Unselect_All_Except(ObjectClass *object);
bool Prep_For_Side(SideType side);
bool Prep_Speech_For_Side(SideType side);
void Shake_The_Screen(int shakes);
long Owner_From_Name(const char *name);
bool Main_Loop();
void Keyboard_Process(KeyNumType &input);
void Load_Title_Screen(const char *name, XSurface *video_page, PaletteClass *palette);
void Init_Random();
void Init_Campaigns();
bool Init_Game(int argc, char *argv[]);
void Focus_Loss();
void Focus_Restore();
bool Is_Firestorm_Enabled();

LayerType Layer_From_Name(const char *name);
const char *Name_From_Layer(LayerType layer);