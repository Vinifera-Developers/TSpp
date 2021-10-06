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
            return Audio.Is_Sample_Playing(FilePtr);
        }

        int Play(float volume, int a2);
        int Play(float volume);

        static int Play(VocType voc, int a2, float volume = 1.0f);
        static int Play(VocType voc, float volume = 1.0f);
        static int Play(VocType voc, Coordinate &coord);
        // 00664EC0
        // 00665080
        static VocType VocType_From_Voc(VocClass *voc);
        static VocType From_Name(const char *name);
        static VocClass *Voc_From_Name(const char *name);
        static const char *INI_Name_From(VocType type);

        static const VocClass *As_Pointer(VocType type)
        {
            return type != VOC_NONE && type < Vocs.Count() ? Vocs[type] : nullptr;
        }

    public:
        char Filename[256];
        int Priority;
        int Volume;
        void *FilePtr;
};


/**
 *  General purpose sound player.
 */
inline int Sound_Effect(VocType voc, float volume = 1.0f)
{
    return VocClass::Play(voc, volume);
}


/**
 *  Plays a sound effect in the tactical map.
 */
inline void Sound_Effect(VocType voc, Coordinate &coord)
{
    VocClass::Play(voc, coord);
}


/**
 *  Query if the sound effect is currently playing.
 */
inline bool Is_Sound_Effect_Playing(VocType type)
{
    const VocClass *voc = VocClass::As_Pointer(type);
    if (voc) {
        return voc->Is_Playing();
    }
    return false;
}
