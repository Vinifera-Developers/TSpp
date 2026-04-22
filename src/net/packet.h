/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  This module defines the functions for the PacketClass. The packet
 *          process packets. class is used to create a linked list of field
 *          entries which can be converted to a linear packet in a COMMS API
 *          compatible format.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
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
