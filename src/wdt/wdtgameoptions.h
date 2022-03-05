/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTGAMEOPTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         
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


namespace WorldDominationTour
{
    
    class GameOption
    {
        public:
            GameOption();
            virtual ~GameOption();

            virtual const char *entry_4(int a1) = 0;
            virtual void entry_8(void *a1, char *buffer, int buflen) = 0;

        protected:
            int field_4;
            int field_8;    // reference counter of sorts?
    };
    
    class RangedGameOption : public GameOption
    {
        public:
            RangedGameOption();
            virtual ~RangedGameOption();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

            virtual int entry_C(int a1) = 0;

        protected:
            int field_C;
            int field_10;
            int field_14;
            int field_18;
            int field_1C;
    };

    class FlagGameOption : public GameOption
    {
        public:
            FlagGameOption();
            virtual ~FlagGameOption();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

        protected:
            int field_C;
            int field_10;
            int field_14;
    };
    
    class NumberOfPlayersGameOption : public GameOption
    {
        public:
            NumberOfPlayersGameOption();
            virtual ~NumberOfPlayersGameOption();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

        protected:
    };
    
    class MapSizeGameOption : public GameOption
    {
        public:
            MapSizeGameOption();
            virtual ~MapSizeGameOption();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

        protected:
    };
    
    template<typename T>
    class ValueGameOption : public GameOption
    {
        public:
            ValueGameOption();
            virtual ~ValueGameOption();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

        protected:
            int field_C;
            int field_10;
    };
    
    template<typename T>
    class RangedGameOptionT : public RangedGameOption
    {
        public:
            RangedGameOptionT();
            virtual ~RangedGameOptionT();

            virtual const char *entry_4(int a1) override;
            virtual void entry_8(void *a1, char *buffer, int buflen) override;

            virtual int entry_C(int a1) override;

        protected:
            int field_C;
            int field_10;
            int field_14;
            int field_18;
            int field_1C;
    };

};

