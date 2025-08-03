/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PACKET.H
 *
 *  @author        Philip W. Gorrow (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         This module defines the functions for the PacketClass. The
 *                 packet process packets. class is used to create a linked list
 *                 of field entries which can be converted to a linear packet in
 *                 a COMMS API compatible format.
 *
 *                 Packets can be created empty and then have fields added to
 *                 them or can be created from an existing linear packet.
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once


#include "always.h"


class FieldClass;


class PacketClass
{
    friend class FieldClass;

public:
    PacketClass(short id = 0);
    PacketClass(char* cur_buf);
    ~PacketClass();

    void Add_Field(FieldClass* field);

    FieldClass* Find_Field(char* id);
    bool Get_Field(char* id, char& data);
    bool Get_Field(char* id, unsigned char& data);
    bool Get_Field(char* id, short& data);
    bool Get_Field(char* id, unsigned short& data);
    bool Get_Field(char* id, long& data);
    bool Get_Field(char* id, unsigned long& data);
    bool Get_Field(char* id, char* data);
    bool Get_Field(char* id, void* data, int& length);

    char* Create_Comms_Packet(int& size);

private:
    unsigned short Size;
    short ID;
    FieldClass* Head;
    FieldClass* Current;
};
