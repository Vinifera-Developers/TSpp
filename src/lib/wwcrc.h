/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWCRC.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Westwood CRC engine.
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


class WWCRCEngine
{
    public:
        WWCRCEngine(long initial = 0) :
            CRC(initial),
            Index(0)
        {
            StagingBuffer.Composite = 0;
        }

        operator long() const { return Value(); }

        long operator()() const { return Value(); }

        void operator()(char datum);
        void operator()(bool datum) { (*this)((char)datum); }
        void operator()(unsigned char datum) { (*this)((char)datum); }
        void operator()(short datum) { (*this)(&datum, sizeof(short)); }
        void operator()(unsigned short datum) { (*this)(&datum, sizeof(unsigned short)); }
        void operator()(long datum) { (*this)(&datum, sizeof(long)); }
        void operator()(unsigned long datum) { (*this)(&datum, sizeof(unsigned long)); }
        void operator()(int datum) { (*this)(&datum, sizeof(int)); }
        void operator()(unsigned int datum) { (*this)(&datum, sizeof(unsigned int)); }
        void operator()(float datum) { (*this)(&datum, sizeof(float)); }
        void operator()(double datum) { (*this)(&datum, sizeof(double)); }

        void operator()(const char *string);
        long operator()(const void *buffer, int length);

        long CRC_Value() const { return CRC; }

        /**
         *  Calculates standard CRC32 value.
         */
        static long Calculate_CRC32(void *buffer, int length);

    protected:
        long Value() const;

    protected:
        long CRC;
        int Index;
        union {
            long Composite;
            char Buffer[sizeof(long)];
        } StagingBuffer;
};
