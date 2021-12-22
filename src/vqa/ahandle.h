/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AHANDLE.H
 *
 *  @authors       CCHyper
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
#include "dsaudio.h"


struct VQAHandle;


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


class AHandle
{
    public:
        //AHandle();
        //~AHandle()

    public:
        bool field_0; // is allocated?
        int Volume;
        short field_8; // samples per sec?
        char field_A; // channels?
        char field_B; // bits per sample?
        int field_C; // 
        int field_10; // 
        int field_14; // 
        int field_18; // 
        int field_1C; // pause adjust?
        int field_20; // paused frame?
        int field_24; // 
        int field_28; // flags?
        int field_2C; // 
        int field_30; // 
        int field_34; // 
        int field_38; // 
        int field_3C; // 
        int field_40; // 
        int field_44; // 
        int field_48; // pointer
        int field_4C; // 
        int field_50; // 
        int field_54; // 
        int field_58; // 
        int field_5C; // 
        UINT TimerHandle;
        DSBUFFERDESC_6 BufferDesc;
        WAVEFORMATEX_6 BuffFormat;
        LPDIRECTSOUNDBUFFER BufferPtr;
        int field_90; // buffer size?
        int field_94;
        int field_98;
        int field_9C; // write cursor?
        CRITICAL_SECTION CriticalSection;
        int field_B8; // lock level?
        bool field_BC;
};
