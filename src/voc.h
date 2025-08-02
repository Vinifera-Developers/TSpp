/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOC.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for playing sound effects.
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

#include "tibsun_defines.h"
#include "tibsun_globals.h"
#include "tspp_audio_intercept.h"
#include "dsaudio.h"


class CCINIClass;


class VocClass
{
    public:
        VocClass(const char *filename);
        ~VocClass();

        void Read_INI(CCINIClass &ini);

        bool Can_Play() const;

        bool Is_Playing() const
        {
            return TSPP_Is_Sample_Playing(FilePtr);
        }

        int Play(float volume, int a2);
        int Play(float volume);

        static void Process(CCINIClass &ini);
        static void Clear();
        static VocType VocType_From_Voc(VocClass *voc);
        static VocType From_Name(const char *name);
        static VocClass *Voc_From_Name(const char *name);
        static const char *INI_Name_From(VocType type);

    public:
        char Filename[256];
        int Priority;
        float Volume;
        void *FilePtr;
};


/**
 *  General purpose sound player, subject to Options.SoundVolume.
 */
int Sound_Effect(VocType voc, float volume = 1.0f, int a3 = 0);

/**
 *  General purpose sound player, not subject to Options.SoundVolume.
 */
int Voice_Sound_Effect(VocType voc, float volume = 1.0f);

/**
 *  Plays a sound effect in the tactical map.
 */
void Static_Sound(VocType voc, const Coord& coord);


/**
 *  Query if the sound effect is currently playing.
 */
inline bool Is_Sound_Effect_Playing(VocType type)
{
    if (type < VOC_FIRST || type >= Vocs.Count()) {
        return false;
    }
    return Vocs[type]->Is_Playing();
}
