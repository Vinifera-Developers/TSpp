/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game options and settings.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include "wwkeyboard.h"


typedef enum SidebarSide : unsigned char {
    SIDEBAR_SIDE_LEFT,
    SIDEBAR_SIDE_RIGHT
} SidebarSide;


class OptionsClass
{
public:
    OptionsClass();
    ~OptionsClass() {}

    void One_Time();

    void Set_Socket();
    void Set_Shuffle(bool on);
    void Set_Repeat(bool on);
    void Set_Score_Volume(double volume, bool feedback);
    void Set_Sound_Volume(double volume, bool feedback);
    void Set_Voice_Volume(double volume, bool feedback);

    int Normalize_Delay(int delay) const;
    int Normalize_Volume(int volume) const;

    void Load_Settings();
    void Save_Settings();

    void Set();

public:
    unsigned int GameSpeed;
    DiffType Difficulty;
    int ScrollMethod;
    int ScrollRate;
    bool IsAutoScroll;
    int DetailLevel;
    SidebarSide SidebarSide;
    bool SidebarCameoText;
    bool ActionLines;
    bool ToolTips;
    int ScreenWidth;
    int ScreenHeight;
    bool StretchMovies;
    bool AllowHiResModes;
    float SoundVolume;
    float VoiceVolume;
    float ScoreVolume;
    bool IsScoreRepeat;
    bool IsScoreShuffle;
    short SoundLatency;
    short Socket;
    int NetCard;
    char DestNet[64];
    KeyNumType KeyForceMove1;
    KeyNumType KeyForceMove2;
    KeyNumType KeyForceAttack1;
    KeyNumType KeyForceAttack2;
    KeyNumType KeySelect1;
    KeyNumType KeySelect2;
    KeyNumType KeyQueueMove1;
    KeyNumType KeyQueueMove2;
};
