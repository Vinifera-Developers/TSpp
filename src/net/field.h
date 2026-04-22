/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  This module takes care of maintaining the field list used to
 *          process network packets.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "always.h"


class PacketClass;


class FieldClass
{
    friend class PacketClass;

public:
    FieldClass();
    FieldClass(char* id, char data);
    FieldClass(char* id, unsigned char data);
    FieldClass(char* id, short data);
    FieldClass(char* id, unsigned short data);
    FieldClass(char* id, long data);
    FieldClass(char* id, unsigned long data);
    FieldClass(char* id, char* data);
    FieldClass(char* id, void* data, int length);
    ~FieldClass();

    void Host_To_Net();
    void Net_To_Host();

private:
    char ID[4];
    unsigned short DataType;
    unsigned short Size;
    void* Data;
    FieldClass* Next;
};
