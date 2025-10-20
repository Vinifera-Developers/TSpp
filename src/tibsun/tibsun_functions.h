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
#include "tibsun_defines.h"
#include "wwkeyboard.h"


class FileClass;
class Surface;
class PaletteClass;
class ObjectClass;
class AbstractClass;
class TechnoTypeClass;
class TechnoClass;


void* Load_Alloc_Data(char const* name, int flags = 0 /* MEM_NORMAL */);
void* Load_Alloc_Data(FileClass& file);

void Call_Back();
void Load_Keyboard_Hotkeys();
bool VQA_Movie_Message_Loop();
bool Parse_Command_Line(int argc, char* argv[]);
int Create_Main_Window(HINSTANCE hInstance, int command_show, int width, int height);
void Prep_Direct_Draw();
bool Set_Video_Mode(HWND hWnd, int w, int h, int bits_per_pixel);
void Reset_Video_Mode();
bool Allocate_Surfaces(const Rect& hidden_rect, const Rect& composite_rect, const Rect& tile_rect, const Rect& sidebar_rect, bool hidden_first = false);
void Free_Heaps();
void Wait_Blit();
void Set_DD_Palette(void* rpalette);
int Get_Video_Hardware_Capabilities();
LRESULT CALLBACK Windows_Procedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
bool Blit_Clip(Rect& torect, const Rect& toarea, Rect& fromrect, const Rect& fromarea);
void Unselect_All();
const TechnoTypeClass* Fetch_Techno_Type(RTTIType type, int id);
void Unselect_All_Except(ObjectClass* object);
bool Prep_For_Side(SideType side);
bool Prep_Speech_For_Side(SideType side);
TechnoClass* Best_Selected_Object();
void Shake_The_Screen(int shakes);
long Owner_From_Name(const char* name);
bool Main_Loop();
void Keyboard_Process(KeyNumType& input);
void Load_Title_Screen(const char* name, Surface* video_page, PaletteClass* palette);
ThemeType Get_Intro_Theme();
ThemeType Get_Maps_Theme();
void Init_Random();
void Init_Campaigns();
bool Init_Game(int argc, char* argv[]);
void Focus_Loss();
void Focus_Restore();
bool Select_Game(bool fade);
void Init_Theater(TheaterType theater);

Rect Get_Tactical_Rect(bool use_options_size = false);

Matrix3D Get_Voxel_Draw_Matrix();
Matrix3D Get_Voxel_Ramp_Matrix(TileRampType ramp);

ArmorType Armor_From_Name(const char* name);
const char* Name_From_Armor(ArmorType armor);
ActionType Action_From_Name(const char* name);
const char* Name_From_Action(ActionType action);
LayerType Layer_From_Name(const char* name);
const char* Name_From_Layer(LayerType layer);
LandType Land_From_Name(const char* name);
const char* Name_From_Land(LandType land);
FacingType Facing_From_Name(const char* name);
const char* Name_From_Facing(FacingType facing);
const char* Name_From_RadioMessage(RadioMessageType msg);

const char* Name_From_RTTI(RTTIType rtti);
RTTIType RTTI_From_Name(const char* name);

bool Is_Object(const AbstractClass* a, bool use_dynamic_cast = false);
bool Is_Foot(const AbstractClass* a, bool use_dynamic_cast = false);
bool Is_Techno(const AbstractClass* a, bool use_dynamic_cast = false);
bool Is_TypeClass(const AbstractClass* a, bool use_dynamic_cast = false);

void List_Copy(Cell const* source, int len, Cell* dest);

TechnoClass* As_TechnoClass(AbstractClass* target);
TechnoClass* As_Techno(AbstractClass* target);

bool On_WM_MOVING(HWND window, WPARAM wparam, LPARAM lparam);
