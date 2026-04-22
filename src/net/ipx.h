/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  General values for the IPX protocol.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];


/**
 *  This is the IPX Packet structure. It's followed by the data itself, which
 *  can be up to 546 bytes long.  Annotation of 'IPX' means IPX will set this
 *  field; annotation of 'APP' means the application must set the field.
 *  NOTE: All header fields are ordered high-byte,low-byte.
 */
typedef struct IPXHEADER {
    unsigned short CheckSum;              // IPX: Not used; always 0xffff
    unsigned short Length;                // IPX: Total size, incl header & data
    unsigned char TransportControl;       // IPX: # bridges message crossed
    unsigned char PacketType;             // APP: Set to 4 for IPX (5 for SPX)
    unsigned char DestNetworkNumber[4];   // APP: destination Network Number
    unsigned char DestNetworkNode[6];     // APP: destination Node Address
    unsigned short DestNetworkSocket;     // APP: destination Socket Number
    unsigned char SourceNetworkNumber[4]; // IPX: source Network Number
    unsigned char SourceNetworkNode[6];   // IPX: source Node Address
    unsigned short SourceNetworkSocket;   // IPX: source Socket Number
} IPXHeaderType;

/**
 *  This is the IPX Event Control Block.  It serves as a communications area
 *  between IPX and the application for a single IPX operation.  You should set
 *  up a separate ECB for each IPX operation you perform.
 */
typedef struct ECB {
    void* Link_Address;
    void (*Event_Service_Routine)(); // APP: event handler (NULL=none)
    unsigned char InUse;             // IPX: 0 = event complete
    unsigned char CompletionCode;    // IPX: event's return code
    unsigned short SocketNumber;     // APP: socket to send data through
    unsigned short ConnectionID;     // returned by Listen (???)
    unsigned short RestOfWorkspace;
    unsigned char DriverWorkspace[12];
    unsigned char ImmediateAddress[6]; // returned by Get_Local_Target
    unsigned short PacketCount;
    struct {
        void* Address;
        unsigned short Length;
    } Packet[2];
} ECBType;
