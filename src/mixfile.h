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
#include "wwcrc.h"


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

        static bool Offset_Within(const char *filename, const char *mix_filename, void **realptr, long *offset = nullptr, long *size = nullptr)
        {
            if (!filename || !mix_filename) {
                return false;
            }

            /**
             *  Create the key block that will be used to binary search for the file.
             */
            char filename_upper[_MAX_PATH];
            std::strcpy(filename_upper, filename);
            strupr(filename_upper);
            long crc = WWCRCEngine()(filename_upper, std::strlen(filename_upper));

            SubBlock key;
            key.CRC = crc;

            /**
             *  Find the mix file in the loaded list.
             */
            MixFileClass *mix = Finder(mix_filename);
            if (!mix || !mix->Count) {
                return false;
            }

            /**
             *  Binary search for the file in this mixfile. If it is found, then extract the
             *  appropriate information and store it in the locations provided and then return.
             */
            SubBlock *block = (SubBlock *)std::bsearch(&key, mix->HeaderBuffer, mix->Count, sizeof(SubBlock), mix_compfunc);
            if (block != nullptr) {

                /**
                 *  Make sure the output pointer is null? I guess it just makes sure if
                 *  it isn't set below that it will be NULL.
                 */
                if (realptr != nullptr) *realptr = nullptr;

                /**
                 *  If we have specified a destination for the size, set it.
                 */
                if (size != nullptr) *size = block->Size;

                /**
                 *  If we have specified a destination for the offset, set it.
                 */
                if (offset != nullptr) *offset = block->Offset;

                /**
                 *  If the Mix is cached and we were provided a pointer for the files
                 *  position in memory, we set it here.
                 */
                if (realptr != nullptr && mix->Data != nullptr) {
                    *realptr = (char *)mix->Data + block->Offset;
                }

                /**
                 *  If the Mix isn't cached and we have a pointer for the offset in the
                 *  file, add the offset to the start of the Mix file in the actual file
                 *  stored on disk (handles nested Mix files).
                 */
                if (mix->Data == nullptr && offset != nullptr) {
                    *offset += mix->DataStart;
                }

                /**
                 *  File found, return success.
                 */
                return true;
            }

            //TSPP_ASSERT(true);

            /**
             *  File was not found within the mix file, return with the non success flag.
             */
            return false;
        }

        static const void *Retrieve_Within(const char *filename, const char *mix_filename)
        {
            TSPP_ASSERT(filename != nullptr);
            TSPP_ASSERT(mix_filename != nullptr);

            void *ptr = nullptr;
            Offset_Within(filename, mix_filename, &ptr);
            return ptr;
        }

    private:
        static int __cdecl mix_compfunc(const void * ptr1, const void * ptr2)
        {
            if (*(long const *)ptr1 < *(long const *)ptr2) return -1;
            if (*(long const *)ptr1 > *(long const *)ptr2) return 1;
            return 0;
        }

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
