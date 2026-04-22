/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  This is the Connection Class for IPX communications. It guarantees
 *          order of delivery of packets.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/

#pragma once


#include "connect.h"
#include "ipxaddr.h"


class IPXConnClass : public ConnectionClass
{
public:
    enum IPXConnTag {
        CONN_NAME_MAX = 40 // max # chars allowed for connection name
    };

    /**
     *  Constructor/destructor.
     */
    IPXConnClass(int numsend, int numrecieve, int maxlen, unsigned short magicnum, IPXAddressClass* address, int id, char* name, int extralen = 0);
    virtual ~IPXConnClass() {};

    /**
     *  Initialization.
     */
    virtual void Init();

    /**
     *  The Configure function is for configuring all connections at once.
     *  It's static because it doesn't apply to any specific connection, but
     *  all of them.
     */
    static void Configure(unsigned short socket, int conn_num, ECBType* listen_ecb, ECBType* send_ecb, IPXHeaderType* listen_header, IPXHeaderType* send_header, char* listen_buf, char* send_buf, long handler_rm_ptr, int maxpacketlen);

    /**
     *  These routines tell IPX to start listening for packets, and to stop
     *  listening for packets.  They're static because they affect all
     *  connections at once (there's no way to turn listening on for only one
     *  connection; it's all or nothing).
     */
    static int Start_Listening();
    static int Stop_Listening();

    /**
     *  The Destination IPX Address for this connection
     */
    IPXAddressClass Address;

    /**
     *  The "Immediate" (Bridge) address for this connection, and a flag
     *  telling if the address has been precomputed.
     */
    NetNodeType ImmediateAddress;
    int Immed_Set;

    /**
     *  Each IPX Connection can have a Name & Unique numerical ID
     */
    int ID;
    char Name[CONN_NAME_MAX];

protected:
    /**
     *  This is the overloaded Send routine declared in ConnectionClass, and
     *  used in SequencedConnClass.
     */
    virtual int Send(char* buf, int buflen, void* extrabuf, int extralen);

    /**
     *  These are the routines that access IPX.  Open_Socket & Close_Socket are
     *  static because they're called by Start_Listening & Stop_Listening.
     *  Send_To & Broadcast are static since they're direct interfaces to IPX,
     *  and there's only one IPX instance running.
     */
    static int Open_Socket(unsigned short socket);
    static void Close_Socket(unsigned short socket);
    static int Send_To(char* buf, int buflen, IPXAddressClass* address, NetNodeType immed);
    static int Broadcast(char* buf, int buflen);

    /**
     *  The socket ID for this connection
     */
    static unsigned short Socket;

    /**
     *  User's local Connection # (0 = not logged in)
     */
    static int ConnectionNum;

    /**
     *  This is a static version of MaxPacketLen, which is the size of the
     *  app's packets, plus our internal CommHeaderType. It's used in the
     *  Start_Listening routine.
     */
    static int PacketLen;

    /**
     *  Variables for Listening (created by the IPXManagerClass, and passed
     *  in via Init). All IPX connections share these buffers.
     */
    static ECBType* ListenECB;
    static IPXHeaderType* ListenHeader;
    static char* ListenBuf;

    /**
     *  Variables for Sending (created by the IPXManagerClass, and passed
     *  in via Init). All IPX connections share these buffers.
     */
    static ECBType* SendECB;
    static IPXHeaderType* SendHeader;
    static char* SendBuf;

    /**
     *  This is a REAL-MODE pointer to the event-service-routine for IPX.
     *  If it's 0, IPX will operate in polled mode.  Otherwise, the high word
     *  must contain the segment, and the low word must contain the offset.
     *  CS will be the high word value when the routine is called.  (Requiring
     *  the segment/offset to be computed by the caller gives the caller
     *  control over CS.)
     */
    static long Handler;

    /**
     *  This status flag tells us if Configure() has been called or not.
     */
    static int Configured;

    /**
     *  This status flag tells us if the socket has been opened or not.
     */
    static int SocketOpen;

    /**
     *  This status flag tells us if Start_Listening() has been called or not.
     */
    static int Listening;
};
