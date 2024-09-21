/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IPXMGR.H
 *
 *  @author        Bill Randolph (see notes below)
 *
 *  @contributors  ZivDero
 *
 *  @brief         This is the Connection Manager for IPX network communications.
 *                 It creates, manages, & orchestrates multiple IPX connections,
 *                 as well as the "global" connection ("Global Channel"),
 *                 which can talk to any system on the net.
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

#include "ipxconn.h"
#include "ipxgconn.h"
#include "ipxaddr.h"
#include "connmgr.h"

#define	VIRGIN_SOCKET		0x8813
#define	CONNECT_MAX			7


class IPXManagerClass : public ConnManClass
{
    public:
        /**
         *  Constructor/destructor.
         */
        IPXManagerClass(int glb_maxlen, int pvt_maxlen, int glb_num_packets,
            int pvt_num_packets, unsigned short socket, unsigned short product_id);
        virtual ~IPXManagerClass();	// stop listening

        /**
         *  Initialization routines.
         */
        int Init ();
        int Is_IPX();
        virtual void Set_Timing(unsigned long retrydelta, unsigned long maxretries,
            unsigned long timeout, bool global = true);
        virtual void Set_External_Timing(unsigned long retrydelta, unsigned long maxretries,
            unsigned long timeout);
        void Set_Bridge(NetNumType bridge);

        /**
         *  These routines control creation of the "Connections" (data queues) for
         *  each remote system.
         */
        int Create_Connection(int id, char *name, IPXAddressClass *address);
        int Delete_Connection(int id);
        virtual int Num_Connections();
        virtual int Connection_ID(int index);
        char *Connection_Name(int id);
        IPXAddressClass * Connection_Address(int id);
        virtual int Connection_Index(int id);
        void Set_Connection_Parms(int index, int id, char *name);

        /**
         *  This is how the application sends & receives messages.
         */
        int Send_Global_Message(void *buf, int buflen, int ack_req = 0,
            IPXAddressClass *address = NULL);
        int Get_Global_Message(void *buf, int *buflen, IPXAddressClass *address,
            unsigned short *product_id);

        virtual int Send_Private_Message(void *buf, int buflen,
            int ack_req = 1, int conn_id = CONNECTION_NONE);
        virtual int Get_Private_Message(void *buf, int *buflen, int *conn_id);

        /**
         *  The main polling routine; should be called as often as possible.
         */
        virtual int Service ();

        /**
         *  This routine reports which connection has an error on it.
         */
        int Get_Bad_Connection();

        /**
          *  Queue utility routines.  The application can determine how many
          *  messages are in the send/receive queues.
          */
        virtual int Global_Num_Send();
        virtual int Global_Num_Receive();
        virtual int Private_Num_Send(int id = CONNECTION_NONE);
        virtual int Private_Num_Receive(int id = CONNECTION_NONE);

        /**
         *  This routine changes the socket ID assigned the IPX Manager when it
         *  was constructed.  Do not call this function after calling Init()!
         *  The Socket ID should be known by both ends of the communications before
         *  any packets are sent.
         */
        void Set_Socket(unsigned short socket);

        /**
         *  Routines to return the largest average queue response time, and to
         *  reset the response time for all queues.
         */
        virtual unsigned long Response_Time();
        unsigned long Global_Response_Time();
        virtual void Reset_Response_Time(bool zero);

        virtual unsigned long Avg_Response_Time(int index);
        virtual void Store_Multiplayer_Stats();

        /**
         *  This routine returns a pointer to the oldest non-ACK'd buffer I've sent.
         */
        void * Oldest_Send();

        /**
         *  Debug routines
         */
        virtual void Configure_Debug(int index, int type_offset, int type_size,
            char **names, int namestart, int namecount);
        virtual void Mono_Debug_Print(int index, int refresh = 0);

        void Multiplayer_Debug_Print();

    protected:
        /**
         *  These routines allocate & free the DOS Real-mode memory block.
         */
        // int Alloc_RealMode_Mem();
        // int Free_RealMode_Mem();

        /**
         *  Misc variables
         */
        bool IPXStatus;		                        // 0 = no IPX, 1 = IPX found
        bool Listening;		                        // 1 = Listening is on
        bool RealMemAllocd;	                        // 1 = Real-mode memory has been alloc'd

        /**
         *  Packet Sizes, used for allocating real-mode memory
         */
        int Glb_MaxPacketLen;				        // Global Channel maximum packet size
        int Glb_NumPackets;					        // # Global send/receive packets
        int Pvt_MaxPacketLen;				        // Private Channel maximum packet size
        int Pvt_NumPackets;					        // # Private send/receive packets

        /**
         *  The ProductID is used in the Global Channel's packet header, and it's
         *  used for the Private Channels' Magic Number.
         */
        unsigned short ProductID;			        // product ID

        /**
         *  The Socket ID, and local Novell Connection Number
         */
        unsigned short Socket;				        // Our socket ID for sending/receiving
        int ConnectionNum;					        // local connection #, 0=not logged in

        /**
         *  Array of connection queues
         */
        IPXConnClass * Connection[CONNECT_MAX];     // array of connection object ptrs
        int NumConnections;						    // # connection objects in use
        IPXGlobalConnClass *GlobalChannel;	        // the Global Channel

        /**
         *  Current queue for polling for received packets
         */
        int CurConnection;

        /**
         *  Timing parameters for all connections
         */
        unsigned long RetryDelta;
        unsigned long MaxRetries;
        unsigned long Timeout;

        /**
         *  This is a structure that mirrors data in real-mode memory:
         */
        typedef struct {
            short Marker1;							// the byte ID marker
            ECBType ListenECB;					    // the Listening ECB
            short NumBufs;							// # of buffers we're giving to the handler
            char *BufferFlags;					    // array of buffer-avail flags
            short PacketSize;						// size of packet including IPX header
            IPXHeaderType *FirstPacketBuf;	        // ptr to 1st packet buffer
            short CurIndex;						    // handler's current packet index
            IPXHeaderType *CurPacketBuf;		    // handler's current packet buf
            short FuncOffset;						// contains offset of code
            char Semaphore;						    // prevents re-entrancy
            short ReEntrantCount;				    // times we've been called re-entrantly
            short StackPtr;						    // real-mode stack pointer
            short StackSeg;						    // real-mode stack segment
            short StackPtr_int;					    // internal stack pointer
            short StackSeg_int;					    // internal stack segment
            short StackCheck;						// stack check value (0x1234)
            short Stack[256];						// actual stack space
            short StackSpace;						// label for top of stack
            short Marker2;							// the byte ID marker
        } RealModeDataType;

        /**
         *  The number & size of packet buffers in low memory
         */
        int NumBufs;								// # packet buffers allocated
        int PacketLen;								// size of packet without IPX header
        int FullPacketLen;						    // size of packet including IPX header

        /**
         *  ptr to the 1st header & data buffers in the packet buffer array
         */
        IPXHeaderType *FirstHeaderBuf;		        // array of packet headers & buffers
        char *FirstDataBuf;						    // 1st data buffer area

        /**
         *  Current packet index & ptrs for parsing packets
         */
        int CurIndex;								// Current packet index, for reading
        IPXHeaderType *CurHeaderBuf;			    // Current packet ptr, for reading
        char *CurDataBuf;							// Current actual data ptr

        /**
         *  ECB, header, & buffer for sending
         */
        ECBType *SendECB;							// ECB for sending
        IPXHeaderType *SendHeader;				    // Header for sending
        char *SendBuf;								// buffer for sending

        /**
         *  Flags indicating whether a buffer contains data or not (1 = full)
         *  The IPXManager must clear this flag; the real-mode routine will set it.
         */
        char *BufferFlags;						    // array of rx-buffer-avail flags

        /**
         *  Various Statistics
         */
        int SendOverflows;
        int ReceiveOverflows;
        int BadConnection;
};
