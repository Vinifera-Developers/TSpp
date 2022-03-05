/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTSTATE.H
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
#include "msanim.h"


namespace WorldDominationTour
{
    
    class Voices
    {
        class Sample
        {
            public:
                Sample();
                ~Sample(); // non-virtual class.
        };

        class Anim : public MSAnim
        {
            public:
                Anim();
                virtual ~Anim();
        };

        public:
            Voices();
            ~Voices(); // non-virtual class.

        protected:
            DynamicVectorClass<void *> field_3C4[2];
            DynamicVectorClass<void *> field_3F4;

    };

};
