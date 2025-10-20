/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DSAUDIO.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Direct Sound audio interface.
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


/**
 *  Define the DirectSound interface version.
 */
#undef DIRECTSOUND_VERSION
#define DIRECTSOUND_VERSION 0x1000 // TibSun uses an older version, but we only use pointers here.


#include "always.h"
#include "soscodec.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>


class FileClass;


/**
 *  Define the different type of sound compression available.
 */
typedef enum SCompressType {
    SCOMP_NONE = 0, // No compression -- raw data.

    SCOMP_WESTWOOD = 1, // Special sliding window delta compression.
    SCOMP_SOS = 99      // SOS frame compression.
} SCompressType;


typedef enum DSAudioEnums {
    PRIORITY_MIN = 0,
    PRIORITY_MAX = 255,
    VOLUME_MIN = 0,
    VOLUME_MAX = 255,

    INVALID_AUDIO_HANDLE = -1,

    MAX_SFX = 5,

    MUTEX_COUNT = 1 + MAX_SFX,
    MUTEX_TIMEOUT = 10000, // 10 milliseconds
    SECONDARY_BUFFER_SIZE = 1024 * 32,
    STREAM_BUFFER_COUNT = 16,

    TARGET_TIMER_RESOLUTION = 10, // 1-millisecond target resolution
    WORST_TIMER_RESOLUTION = 25,

    MAINTENANCE_RATE = 40, // 30 times per sec plus a safety margin
    STREAM_BUFFER_SIZE = (128L * 1024L),
    STREAM_CUSHION_BLOCKS = 4,
    LARGEST_SONARC_BLOCK = 2048,
} DSAudioEnums;


typedef struct tSampleTrackerType {
    tSampleTrackerType() :
        Active(false),
        Loading(false),
        IsScore(false),
        Original(nullptr),
        PlayBuffer(nullptr),
        PlaybackRate(0),
        BitSize(0),
        Stereo(0),
        DataLength(0),
        DestPtr(nullptr),
        MoreSource(false),
        field_25(false),
        OneShot(false),
        field_27(false),
        Source(nullptr),
        Remainder(0),
        Priority(0),
        Handle(0),
        Volume(0),
        DSVolume(0),
        Reducer(0),
        Compression(0),
        Service(0),
        Callback(),
        QueueBuffer(nullptr),
        QueueSize(0),
        Odd(0),
        FilePending(0),
        FilePendingSize(0),
        FileHandle(nullptr),
        FileBuffer(nullptr),
        sSOSInfo()
    {
    }

    ~tSampleTrackerType()
    {
        Original = nullptr;
        DestPtr = nullptr;
        Source = nullptr;
        PlayBuffer = nullptr;
        QueueBuffer = nullptr;
        FileHandle = nullptr;
        FileBuffer = nullptr;
    }

    bool Active;
    bool Loading;
    BOOL IsScore;
    const void* Original;
    LPDIRECTSOUNDBUFFER PlayBuffer;
    int PlaybackRate;
    int BitSize;
    int Stereo;
    int DataLength;
    void* DestPtr;
    bool MoreSource;
    bool field_25;
    bool OneShot;
    bool field_27;
    void* Source;
    int Remainder;
    int Priority;
    int Handle;
    int Volume;
    int DSVolume;
    int Reducer;
    int Compression;
    bool Service;
    bool (*Callback)(short, short*, void**, int*);
    void* QueueBuffer;
    int QueueSize;
    short Odd;
    int FilePending;
    int FilePendingSize;
    FileClass* FileHandle;
    void* FileBuffer;
    _tagCOMPRESS_INFO2 sSOSInfo;

} SampleTrackerType;


class DirectSoundAudioClass
{
public:
    DirectSoundAudioClass();
    ~DirectSoundAudioClass();

    bool Init(HWND hWnd, int bits_per_sample, bool stereo, int rate);
    void End();

    bool Is_Available() const { return SoundObject != nullptr && !AudioDone; }

    void Stop_Sample(int handle);
    bool Sample_Status(int handle);
    bool Is_Sample_Playing(const void* sample);
    void Stop_Sample_Playing(const void* sample);
    int Play_Sample(const void* sample, int priority = PRIORITY_MAX, int volume = VOLUME_MAX);
    int File_Stream_Sample_Vol(char const* filename, int volume, bool real_time_start = false);
    void Fade_Sample(int handle, int ticks);
    int Get_Playing_Sample_Handle(const void* sample);

    bool Lock_Global_Mutex();
    bool Unlock_Global_Mutex();
    bool Lock_Mutex();
    bool Unlock_Mutex();

    bool Set_Primary_Buffer_Format(void);
    void Restore_Sound_Buffers(void);

    int Set_Volume_All(int vol);
    int Adjust_Volume_All(int vol_percent);

    void Set_Handle_Volume(int handle, int volume);
    void Set_Sample_Volume(const void* sample, int volume);

    int Set_Sound_Vol(int volume);
    int Set_Score_Vol(int volume);

    void sub_48A250(int handle, int volume);
    void sub_48A340(int handle);

    bool Start_Primary_Sound_Buffer(bool forced = false);
    void Stop_Primary_Sound_Buffer();

    void Sound_Callback();

    LPDIRECTSOUND Get_Sound_Object() const { return SoundObject; }
    LPDIRECTSOUNDBUFFER Get_Primary_Buffer() const { return PrimaryBufferPtr; }

public:
    void (*Audio_Focus_Loss_Function)();
    bool StreamLowImpact;
    unsigned int MagicNumber;
    void* UncompBuffer;
    void* FileStreamBuffer;
    int StreamBufferSize;
    int SoundVolume;
    SampleTrackerType SampleTracker[MAX_SFX];
    HANDLE TimerMutex;
    HANDLE GlobalAudioMutex;
    HANDLE SecondaryBufferMutexes[MAX_SFX];
    bool field_380;
    LPDIRECTSOUND SoundObject;
    LPDIRECTSOUNDBUFFER PrimaryBufferPtr;
    UINT AudioTimerHandle;
    UINT AudioTimerResolution;
    bool AudioDone;
    LPWAVEFORMATEX PrimaryBuffFormat;
    LPDSBUFFERDESC PrimaryBufferDesc;
};


int Convert_HMI_To_Direct_Sound_Volume(int vol);
void* Audio_Add_Long_To_Pointer(void const* ptr, long size);
void Print_Sound_Error(char const* sound_error, HWND window);
long Simple_Copy(void** source, long* ssize, void** alternate, long* altsize, void** dest, long size);
long Sample_Copy(SampleTrackerType* st, void** source, long* ssize, void** alternate, long* altsize, void* dest, long size, SCompressType scomp);
