/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          NETDLG2.H
 *
 *  @authors       tomsons26, ZivDero
 *
 *  @brief         Network dialog.
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

struct GlobalPacketType;
class IPXAddressClass;

int NAKFirstFreeColor(int reqcolor, int index);
bool NAKCallback();
void NAKDisplayUsers();
bool NAKInit_Network();
void NAKShutdown_Network();
void NAKEncodeGameopt(char* out);
void NAKSetAccept(char* who, int status);
int NAKGetAccept(char* who);
int NAKSetHouseAndColor(char* who, int house, int color);
bool Decrypt_Serial(char* number);
bool NAKRemote_Connect();
bool Process_Global_Packet(GlobalPacketType* packet, IPXAddressClass* address);
