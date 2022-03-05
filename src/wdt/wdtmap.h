/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTMAP.H
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
#include "vector.h"
#include "wdtterr.h"


namespace WorldDominationTour
{

    class Centroid
    {
        public:
            Centroid();
            ~Centroid();

            // 0067CB60
            bool operator == (const Centroid & that) const
            {
                return field_0 == that.field_0
                    && field_4 == that.field_4
                    && field_8 == that.field_8;
            }

            bool operator != (const Centroid & that) const
            {
                return field_0 != that.field_0
                    && field_4 != that.field_4
                    && field_8 != that.field_8;
            }

            // 0067CAE0
            // 0067CB10

        protected:
            int field_0;
            int field_4;
            int field_8;
    };

    class Map
    {
        public:
            Map(); // 006774B0
            virtual ~Map(); // 006774F0

            void Read_INI(); // 00677590

        protected:
            BOOL field_4;   // TODO: needs confirming, looks like it.
            DynamicVectorClass<Territory *> Territories;
    };

};
