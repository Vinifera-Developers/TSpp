/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VQA.H
 *
 *  @authors       CCHyper
 *
 *  @brief         VQA playback class.
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
struct VQAHandle { char pad[0x7DC]; };


typedef enum VQAErrorType
{
    VQAERR_NOERROR = 0,

    VQAERR_NONE = -(1),
    VQAERR_EOF = -(2),
    VQAERR_OPEN = -(3),
    VQAERR_READ = -(4),
    VQAERR_WRITE = -(5),
    VQAERR_SEEK = -(6),
    VQAERR_NOTVQA = -(7),
    VQAERR_NOMEM = -(8),
    VQAERR_NOBUFFER = -(9),
    VQAERR_NOT_TIME = -(10),
    VQAERR_SLEEPING = -(11),
    VQAERR_VIDEO = -(12),
    VQAERR_AUDIO = -(13),
    VQAERR_PAUSED = -(14),
    VQAERR_NOTIMER = -(15),
    VQAERR_NORATE = -(16),
    VQAERR_NOCONFIG = -(17),
    VQAERR_NOAUDSIZ = -(18),
    VQAERR_AUDSYNC = -(19),
    VQAERR_BADBLOCK = -(20),
    VQAERR_NOAHANDL = -(21),
    VQAERR_SKIPDRAW = -(22),
    VQAERR_SETLOOP = -(23),
    VQAERR_SETBUFFR = -(24),
    VQAERR_FORCEDRW = -(25),
} VQAErrorType;


typedef enum VQAOptionType
{
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
    OPTION_NO_STRETCH,
    OPTION_16,
    OPTION_17,
} VQAOptionType;


class VQAClass
{
    public:
        VQAClass(const char *filename, int flags, int framecount, int lockfunc, int unlockfunc, int frame_rate, int draw_rate);
        ~VQAClass();

        void func_66B780(void *a1);
        void func_66B7B0();
        bool Open();
        int func_66B830();
        void Set_Volume(int volume);
        bool Play(int a1, int a2);
        bool func_66B8A0(int start_frame, int end_frame, int a3);
        void Seek_To_Frame(int frame);
        bool func_66B920();
        int func_66B960(int frame, bool a2);
        void func_66BBC0(int frame);
        bool Advance_Frame(bool &a1);
        void Pause();
        void Resume();
        void Close();
        void func_66BE60();
        int func_66BE70() const;
        bool Set_Draw_Buffer(void *buffer, int width, int height, int xpos, int ypos);
        void func_66BEF0(int a1);
        void func_66BF00(int a1, int a2);
        int Get_Width() const;
        int Get_Height() const;
        void Lock_Surface();
        void Unlock_Surface();

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

void VQA_Init_Option();
void VQA_Set_Option(VQAOptionType option);
void VQA_Clear_Option(VQAOptionType option);
bool VQA_Get_Option(VQAOptionType option);
bool VQA_Flip_Option(VQAOptionType option);
