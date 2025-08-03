/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_GITINFO.H
 *
 *  @authors       OmniBlade, CCHyper
 *
 *  @brief         Globals for accessing git version information from the build system.
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


const char* TSPP_Git_Hash();
const char* TSPP_Git_Hash_Short();
const char* TSPP_Git_Author();
const char* TSPP_Git_Branch();
const char* TSPP_Git_DateTime();
bool TSPP_Git_Uncommitted_Changes();
const char* TSPP_Git_Version_String();
