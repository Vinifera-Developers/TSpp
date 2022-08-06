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
#include "dsaudio.h"
#include "ccfile.h"


class VQAClass;


/**
 *  We need to redefine these as DSAudio uses pointers and here we use instances.
 */
typedef struct tWAVEFORMATEX_6
{
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
} WAVEFORMATEX_6, *PWAVEFORMATEX_6, NEAR *NPWAVEFORMATEX_6, FAR *LPWAVEFORMATEX_6;

typedef struct _DSBUFFERDESC_6
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwBufferBytes;
    DWORD dwReserved;
    LPWAVEFORMATEX_6 lpwfxFormat;
} DSBUFFERDESC_6, *LPDSBUFFERDESC_6;


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


// NEEDS CONFIRMING
#pragma pack(push, 1)
typedef struct VQAHeader
{
    unsigned short Version;
    unsigned short Flags;
    unsigned short Frames;
    unsigned short ImageWidth;
    unsigned short ImageHeight;
    unsigned char BlockWidth;
    unsigned char BlockHeight;    
    unsigned char FPS;
    unsigned char GroupSize;
    unsigned short Num1Colors;
    unsigned short CBEntries;
    unsigned short XPos;
    unsigned short YPos;
    unsigned short MaxFrameSize;
    unsigned short SampleRate;
    unsigned char Channels;
    unsigned char BitsPerSample;
    unsigned char AltSampleRate;
    unsigned char AltChannels;
    unsigned char AltBitsPerSample;
    unsigned char ColorMode;
    unsigned char field_21;
    unsigned long MaxCBFZSize;
    unsigned long field_26;
} VQAHeader;
#pragma pack(pop)


// MATCHES SIZE
typedef struct VQAConfig
{
    void *StreamHandler;
    void *MemoryHandler;
    void *PaletteHandler;
    void *DrawerCallback;
    void *TimerHandler;
    long field_14;
    long AudioHandler;
    unsigned char *ImageBuf;
    long ImageWidth;
    long ImageHeight;
    long X1;
    long Y1;
    long FrameRate;
    long DrawRate;
    long RefreshRate;
    long TimerMethod;
    long DrawFlags;
    long OptionFlags;
    long NumFrameBufs;
    long NumCBBufs;
    unsigned char *VocFile;
    unsigned char *AudioBuf;
    long AudioBufSize;
    long HMIBufSize;
    long AudioRate;
    long Volume;
    long field_68;
    long field_6C;
    long field_70;
    long field_74;
    long DigiHandle;
    long field_7C;
    long field_80;
    long LatencyAdjustment;
} VQAConfig;


// CONFIRMED
typedef struct VQAInfo
{
    long NumFrames;
    long ImageWidth;
    long ImageHeight;
} VQAInfo;


// CONFIRMED
typedef struct VQAChunkHeader
{
    unsigned long ID;
    unsigned long Size;
} VQAChunkHeader;


// CONFIRMED
typedef struct VQACacheHeader
{
    unsigned long FileOffset;
    unsigned long FileSize;
} VQACacheHeader;


// CONFIRMED
typedef struct VQACBNode
{
    unsigned char *Buffer;
    VQACBNode *Next;
    VQACBNode *Prev;
    unsigned long Flags;
    unsigned long CBOffset;
    unsigned long Size;
} VQACBNode;


// CONFIRMED
typedef struct VQAFrameNode
{
    unsigned char *Polongers;
    VQACBNode *Codebook;
    unsigned char *Palette;
    VQAFrameNode *Next;
    VQAFrameNode *Prev;
    unsigned long Flags;
    unsigned long PrevFlags;
    long FrameNum;
    long PtrOffset;
    long PalOffset;
    long PaletteSize;
} VQAFrameNode;


typedef struct VQALoader
{
    VQACBNode *CurCB;
    VQACBNode *FullCB;
long __CurCodebook;                    // Whats this?
    VQAFrameNode *CurFrame;
    long NumPartialCB;
    long PartialCBSize;
    long CurFrameNum;            // __PartialCBSizeMax?
    long LastCBFrame;            // __NextFrameNum?
    long LastFrameNum;
    long WaitsOnDrawer;
    long WaitsOnAudio;
    long FrameSize;
    long MaxFrameSize;
} VQALoader;


typedef struct VQAStatistics
{
    long StartTime;
    long EndTime;
    long FramesLoaded;
    long FramesDrawn;
    long FramesSkipped;
    long MaxFrameSize;
    unsigned long SamplesPlayed;
    unsigned long MemUsed;
} VQAStatistics;


// NEEDS CONFIRMING
typedef struct VQAAudio
{
    unsigned char *Buffer;
    unsigned long AudBufPos;
    short *IsLoaded;
    unsigned long NumAudBlocks;



    unsigned char *TempBuf;
    unsigned long TempBufSize;
    unsigned long TempBufLen;
    unsigned long Flags;
    unsigned long PlayPosition;
    unsigned long SamplesPlayed;
    unsigned long NumSkipped;
    unsigned short SampleRate;
    unsigned char Channels;
    unsigned char BitsPerSample;

    _tagCOMPRESS_INFO2 sSOSInfo;
    unsigned long SoundTimerHandle;    

    //TODO

    WAVEFORMATEX_6 WaveFormat;
    DSBUFFERDESC_6 BufferDesc;

    long field_AC;
    long field_B0;
    long field_B4;
    long field_C8;
    long field_BC;
    long field_C0;
} VQAAudio;


// CONFIRMED
typedef struct VQAClipper
{
    unsigned long Width;
    unsigned long Height;
} VQAClipper;


// CONFIRMED
typedef struct VQAFlipper
{
    VQAFrameNode *CurFrame;
    long LastFrameNum;
} VQAFlipper;


typedef struct VQADrawer
{
    VQAFrameNode *CurFrame;
    unsigned long Flags;
    unsigned char *ImageBuf;
    long ImageWidth;
    long ImageHeight;
    long X1;
    long Y1;
//    long X2;
//    long Y2;
    long ScreenOffset;
    long CurPalSize;
    char Palette_24[768];
    char Palette_15[512];
    long BlocksPerRow;
    long NumRows;
    long NumBlocks;
//    long MaskStart;            // Where did these come from?
//    long MaskWidth;
//    long MaskHeight;
//    long LastTime;             // Where did these come from?
//    long LastFrame;
//    long LastFrameNum;
    long DesiredFrame;
//    long NumSkipped;           // ?
    long WaitsOnFlipper;
    long WaitsOnLoader;
} VQADrawer;


typedef struct VQAData
{
    void *Draw_Frame;
    void *Page_Flip;
    void *UnVQ;
    VQAFrameNode *FrameData;
    VQACBNode *CBData;
    VQAAudio Audio;
    VQALoader Loader;
    VQADrawer Drawer;
    VQAFlipper Flipper;
    unsigned long Flags;
    long *Foff;
    long VBIBit;
    long Max_CB_Size;
    long Max_Pal_Size;
    long Max_Ptr_Size;
    long LoadedFrames;
    long DrawnFrames;
    long StartTime;
    long EndTime;
    long MemUsed;
} VQAData;


typedef struct VQAHandle
{
    unsigned long VQAStream;
    void *StreamHandler;
    VQAData *VQABuf;
    VQAConfig Config;
    VQAClass *Class;
    VQAHeader Header;
    long vocfh;
} VQAHandle;


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
        VQAHandle *Handle;
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


/**
 *  VQA library functions.
 */

void VQA_Init_Option();
void VQA_Set_Option(VQAOptionType option);
void VQA_Clear_Option(VQAOptionType option);
bool VQA_Get_Option(VQAOptionType option);
bool VQA_Flip_Option(VQAOptionType option);

unsigned long VQA_GetTime(VQAHandle *handle);
