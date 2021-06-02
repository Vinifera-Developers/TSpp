/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_GLOBALS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file which contains all the games globals.
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


struct VQAConfig { char pad[0x88]; };


typedef enum VQAOptionType {
    OPTION_USE_MIX_HANDLER,
    OPTION_1,
    OPTION_2,
    OPTION_AUDIO_DISABLED,
    OPTION_4,
    OPTION_5,
    OPTION_6,
    OPTION_7,
    OPTION_8,
    OPTION_9,
    OPTION_10,
    OPTION_11,
    OPTION_12,
    OPTION_13,
    OPTION_14,
    OPTION_15,
    OPTION_16,
    OPTION_17,
} VQAOptionType;


void VQA_Init_Option();
void VQA_Set_Option(VQAOptionType option);
void VQA_Clear_Option(VQAOptionType option);
bool VQA_Get_Option(VQAOptionType option);
bool VQA_Flip_Option(VQAOptionType option);


class VQAClass
{
    public:
        VQAClass(const char *filename, int flags, int framecount, int lockfunc, int unlockfunc, int frame_rate, int draw_rate);
        ~VQAClass();

    public:
        CCFileClass File;
        bool field_64;
        char Filename[263];
        VQAConfig Config;
        void * Handle;
        char Palette[768];
        int CurrentFrame;
        int TotalFrames;
        int field_500;
        int field_504;
        bool IsOpen;
        int Width;
        int Height;
        int field_514;
        int field_518;
        bool field_51C;
        int field_520;
        int field_524;
        int field_528;
        int field_52C;
        int field_530;
        void *field_534;
        void *field_538;
        void *field_53C;
        int field_540;
        bool field_544;
        bool field_545;
};
