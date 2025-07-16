/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          THEME.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class to handle music themes.
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
#include "vector.h"
#include "tibsun_defines.h"


class CCINIClass;


class ThemeClass
{
    public:
        ThemeClass();
        ~ThemeClass();

        ThemeType From_Name(const char * name) const;
        ThemeType Next_Song(ThemeType index) const;
        ThemeType What_Is_Playing() const { return Score; }
        bool Is_Allowed(ThemeType index) const;
        bool Is_Regular(ThemeType theme) const { return theme != THEME_NONE && Themes[theme]->Normal; }
        bool Is_Playable(ThemeType theme) const;
        const char *Base_Name(ThemeType index) const;
        const char *INI_Base_Name(ThemeType index) const;
        const char *Full_Name(ThemeType index) const;
        int Max_Themes() const { return Themes.Count(); }
        int Play_Song(ThemeType index);
        bool Still_Playing() const;
        int Track_Length(ThemeType index) const;
        void AI();
        void Fade_Out() { Queue_Song(THEME_QUIET); }
        void Queue_Song(ThemeType index);
        void Stop(bool fade = false);
        void Suspend();
        void Clear();
        void Set_Volume(int volume);
        int Process(CCINIClass &ini);
        const char *Theme_File_Name(ThemeType theme);
        void Scan();

        void Set_Shuffle(int on) { IsRepeat = on; }
        void Set_Repeat(int on) { IsShuffle = on; }

    public:
        typedef struct ThemeControl
        {
            ThemeControl();
            ~ThemeControl();

            bool Fill_In(CCINIClass &ini);

            char Name[256];
            char Fullname[64];
            int Scenario;
            float Duration;
            bool Normal;
            bool Repeat;
            bool Available;
            SideType Owner;
        } ThemeControl;

        int Current;
        ThemeType Score;
        ThemeType Pending;
        int Volume;
        bool IsRepeat;
        bool IsShuffle;
        DynamicVectorClass<ThemeControl *> Themes;
};


inline bool ThemeClass::Is_Playable(ThemeType theme) const
{
    if (theme != THEME_QUIET && theme != THEME_PICK_ANOTHER && theme < Themes.Count()) {
        return Themes[theme]->Normal;
    }
    return false;
}


inline const char * ThemeClass::INI_Base_Name(ThemeType theme) const
{
    if (theme != THEME_NONE && theme < Themes.Count()) {
        return Themes[theme]->Name;
    }
    return "none";
}
