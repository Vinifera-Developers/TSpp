/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IONSTORM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Ion storm functions.
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


struct IStream;


void IonStorm_Set_Active(bool active);
bool IonStorm_Is_Active();
void IonStorm_Start(int duration, int warning = 0);
void IonStorm_Stop();
void IonStorm_AI();
void IonStorm_Lightning_Strike_At(Cell where);
void IonStorm_Do_Screen_Static();
void IonStorm_Init(bool start = false);
void IonStorm_Init_Clear();
HRESULT IonStorm_Save(IStream *pStm);
HRESULT IonStorm_Load(IStream *pStm);

extern bool &IonStorm_IsActive;
// 007F50E8 countdown?
extern int &IonStorm_StaticLoopCounter;
extern int &IonStorm_StartFrame;
extern int &IonStorm_Duration;
extern ThemeType &IonStorm_RestoreTheme;
