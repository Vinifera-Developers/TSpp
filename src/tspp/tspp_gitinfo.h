/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Globals for accessing git version information from the build
 *          system.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


const char* TSPP_Git_Hash();
const char* TSPP_Git_Hash_Short();
const char* TSPP_Git_Author();
const char* TSPP_Git_Branch();
const char* TSPP_Git_DateTime();
bool TSPP_Git_Uncommitted_Changes();
const char* TSPP_Git_Version_String();
