/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOX.H
 *
 *  @authors       CCHyper
 *
 *  @brief         EVA speech.
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

#include "ttimer.h"
#include "stimer.h"
#include "tibsun_defines.h"


void Speak(VoxType voice, bool a2 = false);
void Speak_AI();
void Stop_Speaking();
bool Is_Speaking();
void Set_Speech_Volume(int vol);


extern int &SpeechVolume;
extern bool &IsSpeechAllowed;

extern CDTimerClass<SystemTimerClass> &SpeakTimer;

extern void **SpeechBuffer; // [2]
extern VoxType *SpeechRecord; // [2]
extern VoxType &SpeakQueue;
extern VoxType &CurrentVoice;
