/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COMBUF.H
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

/**
 *  This is one output queue entry
 */
typedef struct {
    unsigned int IsActive	: 1;	    // 1 = this entry is ready to be processed
    unsigned int IsACK		: 1;	    // 1 = ACK received for this packet
    unsigned long FirstTime;		    // time this packet was first sent
    unsigned long LastTime;			    // time this packet was last sent
    unsigned long SendCount;		    // # of times this packet has been sent
    int BufLen;							// size of the packet stored in this entry
    char *Buffer;						// the data packet
    int ExtraLen;						// size of extra data
    char *ExtraBuffer;				    // extra data buffer
} SendQueueType;

/**
 *  This is one input queue entry
 */
typedef struct {
    unsigned int IsActive	: 1;	    // 1 = this entry is ready to be processed
    unsigned int IsRead		: 1;	    // 1 = caller has read this entry
    unsigned int IsACK		: 1;	    // 1 = ACK sent for this packet
    int BufLen;							// size of the packet stored in this entry
    char *Buffer;						// the data packet
    int ExtraLen;						// size of extra data
    char *ExtraBuffer;				    // extra data buffer
} ReceiveQueueType;


class CommBufferClass
{
    public:
        /**
         *  Constructor/Destructor
         */
        CommBufferClass(int numsend, int numrecieve, int maxlen, 
            int extralen = 0);
        virtual ~CommBufferClass();
        void Init();
        void Init_Send_Queue();

        /**
         *  Send Queue routines
         */
        int Queue_Send(void *buf, int buflen, void *extrabuf = nullptr,
            int extralen = 0);
        int UnQueue_Send(void *buf, int *buflen, int index, 
            void *extrabuf = nullptr, int *extralen = nullptr);
        int Num_Send() {return (SendCount);}		                        // # entries in queue
        int Max_Send() { return (MaxSend);}		                            // max # send queue entries
        SendQueueType * Get_Send(int index);		                        // random access to queue
        unsigned long Send_Total() {return (SendTotal);}

        /**
         *  Receive Queue routines
         */
        int Queue_Receive(void *buf, int buflen, void *extrabuf = nullptr,
            int extralen = 0);
        int UnQueue_Receive(void *buf, int *buflen, int index, 
            void *extrabuf = nullptr, int *extralen = nullptr);
        int Num_Receive() {return (ReceiveCount);}	                        // # entries in queue
        int Max_Receive() { return (MaxReceive); }	                        // max # recv queue entries
        ReceiveQueueType * Get_Receive(int index);	                        // random access to queue
        unsigned long Receive_Total() {return (ReceiveTotal);}

        /**
         *  Response time routines
         */
        void Add_Delay(unsigned long delay);	                            // accumulates response time
        unsigned long Avg_Response_Time();	                                // gets mean response time
        unsigned long Max_Response_Time();	                                // gets max response time
        void Reset_Response_Time();			                                // resets computations

        /**
         *  Debug output routines
         */
        void Configure_Debug(int type_offset, int type_size, char **names, 
            int namestart, int namecount);
        void Mono_Debug_Print(int refresh = 0);
        void Mono_Debug_Print2(int refresh = 0);

    private:
        /**
         *  Limiting variables
         */
        int MaxSend;							    // max # send queue entries
        int MaxReceive;						        // max # receive queue entries
        int MaxPacketSize;					        // max size of a packet, in bytes
        int MaxExtraSize;						    // max size of extra bytes

        /**
         *  Response time variables
         */
        unsigned long DelaySum;				        // sum of last 4 delay times
        unsigned long NumDelay;				        // current # delay times summed
        unsigned long MeanDelay;			        // current average delay time
        unsigned long MaxDelay;				        // max delay ever for this queue

        /**
         *  Send Queue variables
         */
        SendQueueType * SendQueue;			        // incoming packets
        int SendCount; 						        // # packets in the queue
        unsigned long SendTotal;			        // total # added to send queue
        int *SendIndex;						        // array of Send entry indices

        /**
         *  Receive Queue variables
         */
        ReceiveQueueType * ReceiveQueue;		    // outgoing packets
        int ReceiveCount;							// # packets in the queue
        unsigned long ReceiveTotal;			        // total # added to receive queue
        int *ReceiveIndex;						    // array of Receive entry indices

        /**
         *  Debugging Variables
         */
        int DebugOffset;							// offset into app's packet for ID
        int DebugSize;								// size of app's ID
        char **DebugNames;						    // ptr to array of app-specific names
        int DebugNameStart;						    // number of 1st ID
        int DebugNameCount;						    // # of names in array
};
