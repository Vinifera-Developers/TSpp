/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTHIST.H
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
#include "vectorcursor.h"
#include "refptr.h"

#include "wdtconflict.h"


namespace WorldDominationTour
{
    class History
    {
        public:
            History();
            ~History(); // non virtual class

        protected:
            int field_0;
            bool field_4;
            RefPtr<void *> field_8;
            DynamicVectorClass<Conflict *> Conflicts; // TODO confirm
            int CampaignID;
            int Previous;
            int PlayerFaction;
            char Name[64];
    };

};
