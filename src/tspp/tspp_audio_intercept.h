/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_AUDIO_INTERCEPT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Installable functions for overriding audio calls in TS++.
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
#include "dsaudio.h"


extern int (*TSPP_Play_Sample_Function_Ptr)(const void *sample, int priority, int volume);
extern bool (*TSPP_Is_Sample_Playing_Function_Ptr)(const void *sample);


int TSPP_Play_Sample(const void *sample, int priority = PRIORITY_MAX, int volume = VOLUME_MAX);
bool TSPP_Is_Sample_Playing(const void *sample);
