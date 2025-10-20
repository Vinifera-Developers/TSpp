/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OPTIONS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Game options and settings.
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
