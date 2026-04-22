/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Network dialog.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
