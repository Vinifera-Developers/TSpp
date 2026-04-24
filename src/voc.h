/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for playing sound effects.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "dsaudio.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"


class CCINIClass;


class VocClass
{
public:
    VocClass(const char* filename);
    ~VocClass();

    void Read_INI(CCINIClass& ini);

    bool Can_Play() const;

    int Play(float volume, int a2);
    int Play(float volume);

    static void Process(CCINIClass& ini);
    static void Clear();
    static VocType VocType_From_Voc(VocClass* voc);
    static VocType From_Name(const char* name);
    static VocClass* Voc_From_Name(const char* name);
    static const char* INI_Name_From(VocType type);

public:
    char Filename[256];
    int Priority;
    float Volume;
    void* FilePtr;
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
