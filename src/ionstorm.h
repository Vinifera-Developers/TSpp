/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Ion storm functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
HRESULT IonStorm_Save(IStream* pStm);
HRESULT IonStorm_Load(IStream* pStm);

extern bool& IonStorm_IsActive;
// 007F50E8 countdown?
extern int& IonStorm_StaticLoopCounter;
extern int& IonStorm_StartFrame;
extern int& IonStorm_Duration;
extern ThemeType& IonStorm_RestoreTheme;
