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
#define DIRECTSOUND_VERSION 0x0700 // Use DirectSound 7.0


#include "always.h"
#include "soscodec.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>


class FileClass;


enum {
    PRIORITY_MIN = 0,
    PRIORITY_MAX = 255,
    VOLUME_MIN = 0,
    VOLUME_MAX = 255,

    INVALID_AUDIO_HANDLE = -1,

    MAX_SFX = 5
};


typedef struct tSampleTrackerType
{
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
    const void *Original;
    LPDIRECTSOUNDBUFFER PlayBuffer;
    int PlaybackRate;
    int BitSize;
    int Stereo;
    int DataLength;
    void *DestPtr;
    bool MoreSource;
    bool field_25;
    bool OneShot;
    bool field_27;
    void *Source;
    int Remainder;
    int Priority;
    int Handle;
    int Volume;
    int DSVolume;
    int Reducer;
    int Compression;
    bool Service;
    bool (*Callback)(short, short *, void **, int *);
    void *QueueBuffer;
    int QueueSize;
    short Odd;
    int FilePending;
    int FilePendingSize;
    FileClass *FileHandle;
    void *FileBuffer;
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
        bool Is_Sample_Playing(const void *sample);
        void Stop_Sample_Playing(const void *sample);
        int Play_Sample(const void *sample, int priority = PRIORITY_MAX, int volume = VOLUME_MAX);
        int File_Stream_Sample_Vol(char const *filename, int volume, bool real_time_start = false);
        void Fade_Sample(int handle, int ticks);
        int Get_Playing_Sample_Handle(const void *sample);

        bool Lock_Global_Mutex();
        bool Unlock_Global_Mutex();
        bool Lock_Mutex();
        bool Unlock_Mutex();

        int Set_Volume_All(int vol);
        void Adjust_Volume_All(int vol_percent);

        void Set_Handle_Volume(int handle, int volume);
        void Set_Sample_Volume(const void *sample, int volume);

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
        void (*AudioFocusLossFunction)();
        bool StreamLowImpact;
        unsigned int MagicNumber;
        void *UncompBuffer;
        void *FileStreamBuffer;
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
