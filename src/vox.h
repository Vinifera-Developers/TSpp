/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  EVA speech.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "stimer.h"
#include "tibsun_defines.h"
#include "tspp.h"
#include "ttimer.h"


void Speak(VoxType voice, bool a2 = false);
void Speak_AI();
void Stop_Speaking();
bool Is_Speaking();
void Set_Speech_Volume(int vol);


extern int& SpeechVolume;
extern bool& IsSpeechAllowed;

extern CDTimerClass<SystemTimerClass>& SpeakTimer;

ARRAY_DEC(void*, SpeechBuffer, 2);
ARRAY_DEC(VoxType, SpeechRecord, 2);
extern VoxType& SpeakQueue;
extern VoxType& CurrentVoice;

ARRAY_DEC(char const*, Speech, VOX_COUNT);
