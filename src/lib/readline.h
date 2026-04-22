/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Utility functions for reading lines from FileClass and Straw
 *          interfaces.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class FileClass;
class Straw;


int Read_Line(FileClass& file, char* buffer, int len, bool& eof);
int Read_Line(Straw& file, char* buffer, int len, bool& eof);
