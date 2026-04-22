/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Installable functions for overriding audio calls in TS++.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "dsaudio.h"


extern int (*TSPP_Play_Sample_Function_Ptr)(const void* sample, int priority, int volume);
extern bool (*TSPP_Is_Sample_Playing_Function_Ptr)(const void* sample);


int TSPP_Play_Sample(const void* sample, int priority = PRIORITY_MAX, int volume = VOLUME_MAX);
bool TSPP_Is_Sample_Playing(const void* sample);
