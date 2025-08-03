/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONNECT.H
 *
 *  @author        Bill Randolph (see notes below)
 *
 *  @contributors  ZivDero
 *
 *  @brief         This class represents a single "connection" with
 *                 another system. It's a pure virtual base class
 *                 that acts as a framework for other classes.
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

#include "combuf.h"


#define CONN_DEBUG 0

/**
 *  This structure is the header prefixed to any packet sent by the application.
 *  MagicNumber:	This is a number unique to the application; it's up to the
 *                      Receive_Packet routine to check this value, to be sure we're
 *                      not getting data from some other product.  This value should
 *                      be unique for each application.
 *  Code:				This will be one of the below-defined codes.
 *  PacketID:		This is a unique numerical ID for this packet.  The Connection
 *                      sets this ID on all packets sent out.
 */
typedef struct {
    unsigned short MagicNumber;
    unsigned char Code;
    unsigned long PacketID;
} CommHeaderType;


class ConnectionClass
{
public:
    /**
     *  These are the possible values for the Code field of the CommHeaderType:
     */
    enum ConnectionEnum {
        PACKET_DATA_ACK,   // this is a data packet requiring an ACK
        PACKET_DATA_NOACK, // this is a data packet not requiring an ACK
        PACKET_ACK,        // this is an ACK for a packet
        PACKET_COUNT       // for computational purposes
    };

    /**
     *  Constructor/destructor.
     */
    ConnectionClass(int numsend, int numrecieve, int maxlen, unsigned short magicnum, unsigned long retry_delta, unsigned long max_retries, unsigned long timeout, int extralen = 0);
    virtual ~ConnectionClass();

    /**
     *  Initialization.
     */
    virtual void Init();

    /**
     *  Send/Receive routines.
     */
    virtual int Send_Packet(void* buf, int buflen, int ack_req);
    virtual int Receive_Packet(void* buf, int buflen);
    virtual int Get_Packet(void* buf, int* buflen);

    /**
     *  The main polling routine for the connection.  Should be called as often
     *  as possible.
     */
    virtual int Service();

    /**
     *  This routine is used by the retry logic; returns the current time in
     *  60ths of a second.
     */
    static unsigned long Time();

    /**
     *  Utility routines.
     */
    unsigned short Magic_Num() { return (MagicNum); }
    unsigned long Retry_Delta() { return (RetryDelta); }
    void Set_Retry_Delta(unsigned long delta) { RetryDelta = delta; }
    unsigned long Max_Retries() { return (MaxRetries); }
    void Set_Max_Retries(unsigned long retries) { MaxRetries = retries; }
    unsigned long Time_Out() { return (Timeout); }
    void Set_TimeOut(unsigned long t) { Timeout = t; }
    unsigned long Max_Packet_Len() { return (MaxPacketLen); }
    static char* Command_Name(int command);

    /**
     *  The packet "queue"; this non-sequenced version isn't really much of
     *  a queue, but more of a repository.
     */
    CommBufferClass* Queue;

    /*
    -------------------------- Protected Interface ---------------------------
    */
protected:
    /**
     *  Routines to service the Send & Receive queues.
     */
    virtual int Service_Send_Queue();
    virtual int Service_Receive_Queue();

    /**
     *  This routine actually performs a hardware-dependent data send.  It's
     *  pure virtual, so it must be defined by a derived class.  The routine
     *  is protected; it's only called by the ACK/Retry logic, not the
     *  application.
     */
    virtual int Send(char* buf, int buflen, void* extrabuf, int extralen) = 0;

    /**
     *  This is the maximum packet length, including our own internal header.
     */
    int MaxPacketLen;

    /**
     *  Packet staging area; this is where the CommHeaderType gets tacked onto
     *  the application's packet before it's sent.
     */
    char* PacketBuf;

    /**
     *  This is the magic number assigned to this connection.  It is the first
     *  few bytes of any transmission.
     */
    unsigned short MagicNum;

    /**
     *  This value determines the time delay before a packet is re-sent.
     */
    unsigned long RetryDelta;

    /**
     *  This is the maximum number of retries allowed for a packet; if this
     *  value is exceeded, the connection is probably broken.
     */
    unsigned long MaxRetries;

    /**
     *  This is the total timeout for this connection; if this time is exceeded
     *  on a packet, the connection is probably broken.
     */
    unsigned long Timeout;

    /**
     *  Running totals of # of packets we send & receive which require an ACK,
     *  and those that don't.
     */
    unsigned long NumRecNoAck;
    unsigned long NumRecAck;
    unsigned long NumSendNoAck;
    unsigned long NumSendAck;

    /**
     *  This is the ID of the last consecutively-received packet; anything older
     *  than this, we know is a resend.  Anything newer than this MUST be lying
     *  around in the Queue for us to detect it as a resend.
     */
    unsigned long LastSeqID;

    /**
     *  This is the ID of the PACKET_DATA_ACK packet we read last; it ensures
     *  that the application reads that type of packet in order.
     */
    unsigned long LastReadID;

    /**
     *  Names of all packet commands
     */
    static char* Commands[PACKET_COUNT];
};
