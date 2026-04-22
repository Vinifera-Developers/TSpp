/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Functions for scenario file transfer between machines.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


bool Get_Scenario_File_From_Host(char* return_name, int gametype, bool show_progress);
bool Receive_Remote_File(const char* file_name, unsigned int file_length, int gametype, bool show_progress);
bool Send_Remote_File(const char* file_name, int gametype, bool a3, bool show_progress);
bool Find_Local_Scenario(const char* file_name, unsigned int file_length, char* digest, bool official, bool a5);
