/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Loading screen progress.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include "tspp.h"


class ShapeSet;


class ProgressScreenClass
{
public:
    ProgressScreenClass();
    ~ProgressScreenClass();

    void Initialize(double start_progress, int player_count, bool do_dialog = false);
    void End();
    void Set_Graphic_Data(const char* progress_bar_shape, const char* background_image, const char* string, Point2D text_pos = Point2D(-1, -1));
    double Get_Current_Progress();
    void Display_Progress(Point2D pt = Point2D(-1, -1));
    int Get_Bar_Width();
    void Set_Progress_Percent(int player_index, double value, Point2D pt = Point2D(-1, -1));
    void Add_Progress_Percent(int player_index, double value, Point2D pt = Point2D(-1, -1));

    void Begin_Dialog();
    void End_Dialog();

    static LRESULT CALLBACK Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);

public:
    double PlayerProgress[MAX_PLAYERS];
    double MainProgress;
    const char* String;
    ShapeSet* Shape;
    const char* Background;
    bool Initialized;
    char PlayerCount;
    HWND Dialog;
    int XPos;
    int YPos;
    int Percentage;
};


typedef struct ProgressTextStruct {
    int Progress;
    int TextID;
} ProgressTextStruct;

ARRAY_DEC(ProgressTextStruct, ProgressText, 8);
