/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Installable functions for overriding audio calls in TS++.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "tspp_audio_intercept.h"
#include "tibsun_globals.h"


int (*TSPP_Play_Sample_Function_Ptr)(const void* sample, int priority, int volume) = nullptr;
bool (*TSPP_Is_Sample_Playing_Function_Ptr)(const void* sample) = nullptr;


int TSPP_Play_Sample(const void* sample, int priority, int volume)
{
    if (TSPP_Play_Sample_Function_Ptr) {
        return TSPP_Play_Sample_Function_Ptr(sample, priority, volume);
    } else {
        return Audio.Play_Sample(sample, priority, volume);
    }
}


bool TSPP_Is_Sample_Playing(const void* sample)
{
    if (TSPP_Is_Sample_Playing_Function_Ptr) {
        return TSPP_Is_Sample_Playing_Function_Ptr(sample);
    } else {
        return Audio.Is_Sample_Playing(sample);
    }
}
