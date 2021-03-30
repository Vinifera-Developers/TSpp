/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_DEFINITIONS.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file for the TS++ project.
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
#include "tspp.h"

#include "pipe.h"
#include "straw.h"


/**
 *  #NOTE:
 *  Any constructors defined here are because they are inlined in the games binary and
 *  redefining them in TS++ will cause the game to use the new virtual table, so to get
 *  around this we need to define the constructor then immediately override the virtual
 *  table pointer with the games table.
 *  
 */


/**
 *  Function definitions
 */
//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Pipe::Pipe(), 0x);
Pipe::Pipe() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long *)this) = (unsigned long)0x006CDC84; }
DEFINE_IMPLEMENTATION(Pipe::~Pipe(), 0x005A9430);

//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Straw::Straw(), 0x);
Straw::Straw() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long *)this) = (unsigned long)0x006CDC5C; }
DEFINE_IMPLEMENTATION(Straw::~Straw(), 0x0060AFC0);
