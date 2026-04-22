/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Westwood CRC engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


class CRCEngine
{
public:
    CRCEngine(long initial = 0) : CRC(initial), Index(0) { StagingBuffer.Composite = 0; }

    operator long() const { return Value(); }

    long operator()() const { return Value(); }

    void operator()(char datum);
    void operator()(bool datum) { (*this)((char)(datum != false)); }
    void operator()(unsigned char datum) { (*this)((char)datum); }
    void operator()(short datum) { (*this)(&datum, sizeof(short)); }
    void operator()(unsigned short datum) { (*this)(&datum, sizeof(unsigned short)); }
    void operator()(long datum) { (*this)(&datum, sizeof(long)); }
    void operator()(unsigned long datum) { (*this)(&datum, sizeof(unsigned long)); }
    void operator()(int datum) { (*this)(&datum, sizeof(int)); }
    void operator()(unsigned int datum) { (*this)(&datum, sizeof(unsigned int)); }
    void operator()(float datum) { (*this)(&datum, sizeof(float)); }
    void operator()(double datum) { (*this)(&datum, sizeof(double)); }

    void operator()(const char* string);
    long operator()(const void* buffer, int length);

    long CRC_Value() const { return CRC; }

    /**
     *  Calculates standard CRC32 value.
     */
    static long CRC_Memory(const void* buffer, int length, int prev_crc);
    static long CRC_String(const char* string, int prev_crc);

protected:
    long Value() const;

    bool Buffer_Needs_Data() const { return Index != 0; };

protected:
    long CRC;
    int Index;
    union {
        long Composite;
        char Buffer[sizeof(long)];
    } StagingBuffer;
};
