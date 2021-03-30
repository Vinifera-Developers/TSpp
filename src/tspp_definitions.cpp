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
#include "rawfile.h"


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

DEFINE_IMPLEMENTATION_CONSTRUCTOR(RawFileClass::RawFileClass(const char *), 0x005BE310);
DEFINE_IMPLEMENTATION(RawFileClass::~RawFileClass(), 0x005BE290);
DEFINE_IMPLEMENTATION(const char* RawFileClass::File_Name() const, 0x005BDE00);
DEFINE_IMPLEMENTATION(const char* RawFileClass::Set_Name(const char *), 0x005BDE10);
DEFINE_IMPLEMENTATION(bool RawFileClass::Create(), 0x005BDB90);
DEFINE_IMPLEMENTATION(bool RawFileClass::Delete(), 0x005BDBB0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Available(bool), 0x005BDBD0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Open() const, 0x005BDBE0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(const char *, FileAccessType), 0x005BDBF0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(FileAccessType), 0x005BDC00);
DEFINE_IMPLEMENTATION(long RawFileClass::Read(void *, int), 0x005BDC50);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Seek(off_t, FileSeekType), 0x005BDCD0);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Size(), 0x005BDD50);
DEFINE_IMPLEMENTATION(long RawFileClass::Write(const void *, int), 0x005BDD60);
DEFINE_IMPLEMENTATION(void RawFileClass::Close(), 0x005BDDF0);
DEFINE_IMPLEMENTATION(LONG RawFileClass::Get_Date_Time() const, 0x005BDE20);
DEFINE_IMPLEMENTATION(bool RawFileClass::Set_Date_Time(LONG), 0x005BDE30);
DEFINE_IMPLEMENTATION(void RawFileClass::Error(FileErrorType, bool, const char *), 0x005BDE40);
DEFINE_IMPLEMENTATION(void RawFileClass::Bias(off_t, int), 0x005BEB20);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Raw_Seek(off_t, FileSeekType), 0x005BEB90);
