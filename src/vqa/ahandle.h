/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AHANDLE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         VQA Audio handler
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
#include <windows.h>
#include "dsaudio.h"


#define VQAHandle   unsigned char
#define VQAHandleP  unsigned char
#define VQAConfig   unsigned char

struct AhandleInitParams
{
    unsigned short SampleRate;
    unsigned char Channels;
    unsigned char BitsPerSample;
    unsigned long Flags;	// 1 is used to flip left and right channels
    void* field_8;
    void* field_C;
};

#define AHANDLEF_IS_PAUSED (1 << 0)

struct Ahandle {

    enum {
        MAX_HANDLES = 1,
        MAX_BUFFERS = 2,
    };

    bool Used;
    int Volume;
    unsigned short SampleRate;
    unsigned char Channels;
    unsigned char BitsPerSample;
    char field_C[8];
    unsigned long LastPlaybackPosition;
    unsigned long LastTimerTick;
    unsigned long PauseAdjust;
    unsigned long TickCount;
    unsigned long InitFlags;
    unsigned long Flags;
    char field_2C[20];
    int AudioBufReadIndex;
    int AudioBufWriteIndex;
    BOOL AudioBufInUse[MAX_BUFFERS];
    void* AudioBuf[MAX_BUFFERS];
    unsigned long AudioBufSize[MAX_BUFFERS];
    UINT TimerHandle;
    DSBUFFERDESC BufferDesc;
    WAVEFORMATEX DsBuffFormat;
    LPDIRECTSOUNDBUFFER SecondaryBufferPtr;
    unsigned long SecondaryBufferSize;
    unsigned long ChunksMovedToAudioBuffer;
    unsigned long LastChunkPosition;
    unsigned long EndLastAudioChunk;
    CRITICAL_SECTION CriticalSection;
    LONG SuspendAudioCallback;
};

unsigned long __cdecl Simple_Timer_Callback_Audio_Handler(VQAHandle* vqa);
unsigned long __cdecl Timer_Callback_Audio_Handler(VQAHandle* vqa);

long __cdecl Lock_Audio_Handler();
long __cdecl Unlock_Audio_Handler();
long __cdecl Stream_Audio_Handler(VQAHandle* vqa, long action, void* buffer, long nbytes);

typedef long(__cdecl* AHANDLE_CALLBACK_1)(VQAHandle* vqa);
typedef long(__cdecl* AHANDLE_CALLBACK_2)(VQAHandle* vqa, void* buffer);

long __cdecl Open_Audio_Handler(VQAHandleP* vqap, AhandleInitParams* params, long);
long __cdecl Close_Audio_Handler(VQAHandleP* vqap);
long __cdecl Start_Audio_Handler(VQAHandleP* vqap);
long __cdecl Stop_Audio_Handler(VQAHandleP* vqap);
long __cdecl Play_Audio_Handler(VQAHandleP* vqap);
long __cdecl Pause_Audio_Handler(VQAHandleP* vqap);
long __cdecl Load_Audio_Handler(VQAHandleP* vqap, void* buffer, long nbytes);
void CALLBACK AudioCallback(UINT event_id, UINT res1, DWORD user, DWORD res2, DWORD res3);
