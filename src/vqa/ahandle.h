/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  VQA Audio handler
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "dsaudio.h"
#include "vqa.h"
#include <windows.h>


struct AhandleInitParams {
    unsigned short SampleRate;
    unsigned char Channels;
    unsigned char BitsPerSample;
    unsigned long Flags; // 1 is used to flip left and right channels
    long(__cdecl* Callback1)(VQAHandle*);
    long(__cdecl* Callback2)(VQAHandle*, void*);
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
