/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WORLDDOM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header for the World Domination Tour system.
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


/**
 *  Include the World Domination Tour modules.
 */
#include "wdtgameoptions.h"
#include "wdthist.h"
#include "wdtmap.h"
#include "wdtprops.h"
#include "wdtsel.h"
#include "wdtstate.h"
#include "wdtterr.h"



//
// packet info
//

// C == Cycle?

// NACK  - acknowlegement?
// TOTK
// CRTK  - State::NumTicks
// CYLN  - State::field_14
// CMID  - State::MapID
// CYID  - State::CycleID
// TICC  - State::TickTime
// SDSC  - State::ShortDesc
// LDSC  - State::LongDesc
// WURL  - State::LongDesc[4]
// MPVC
// HSVC
