/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SHA.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         Implementation of the Secure Hash Algorithm.
 *
 *  @license       ProjectTSYR is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 ProjectTSYR is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include <new>


class SHAEngine
{
    private:
        typedef union {
            unsigned long Long[5];
            unsigned char Char[20];
        } SHADigest;

        enum : unsigned
        {
            SRC_BLOCK_SIZE=16*sizeof(long),
            PROC_BLOCK_SIZE=80*sizeof(long)
        };
    public:
        SHAEngine();

        void Init() {
            new ((void*)this) SHAEngine;
        };

        int Result(void * result) const;
        void Hash(void const * data, long length);
        void Process_Block(void const * source, SHADigest & acc) const;
        void Process_Partial(void const * & data, long & length);

        static int Digest_Size() { return sizeof(SHADigest); }

    private:
        bool IsCached;
        SHADigest FinalResult;
        SHADigest Acc;
        long Length;
        int PartialCount;
        char Partial[SRC_BLOCK_SIZE];
};
