/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MIXFILE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Interface for loading files from mixfiles.
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

#include "listnode.h"


class PKey;
class Buffer;


class MixFileClass : public Node<MixFileClass *>
{
    public:
        MixFileClass(const char *filename, const PKey * key);
        virtual ~MixFileClass();

        void Free();
        static bool Free(const char *filename);

        bool Cache(const Buffer * buffer = nullptr);
        static bool Cache(const char *filename, Buffer const * buffer = nullptr);

        static bool Offset(const char *filename, void ** realptr = nullptr, MixFileClass ** mixfile = nullptr, long * offset = nullptr, long * size = nullptr);
        static const void * Retrieve(const char *filename);

    private:
        static MixFileClass * Finder(const char * filename);

    public:
        char * Filename;

    private:
        bool IsDigest;
        bool IsEncrypted;
        bool IsAllocated;

        typedef struct {
            short count;
            long size;
        } FileHeader;

        int Count;
        long DataSize;
        long DataStart;

        struct SubBlock
        {
            long CRC;
            long Offset;
            long Size;

            int operator < (SubBlock & that) const { return (CRC < that.CRC); }
            int operator > (SubBlock & that) const { return (CRC > that.CRC); }
            int operator == (SubBlock & that) const { return (CRC == that.CRC); }
            int operator != (SubBlock & that) const { return (CRC != that.CRC); }
        };

        SubBlock * HeaderBuffer;
        void * Data;
};
