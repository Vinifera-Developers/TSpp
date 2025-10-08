/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          NULLMGR.H
 *
 *  @author        Bill Randolph (see notes below)
 *
 *  @contributors  tomsons26, ZivDero
 *
 *  @brief         This is the Connection Manager for a NULL-Modem connection.
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
 *  @note          This file contains modified code for C&C Red Alert released
 *                 by Electronic Arts under the GPL3 license. Source:
 *                 https://github.com/electronicarts/CnC_Red_Alert
 *
 ******************************************************************************/
#pragma once

/*
********************************* Includes **********************************
*/
#include "connmgr.h"
#include "nullconn.h"
#include "session.h"
#include "special.h"
class GadgetClass;
class ModemRegistryEntryClass;

/*
***************************** Class Declaration *****************************
*/
class NullModemClass : public ConnManClass
{
    /*
    ---------------------------- Public Interface ----------------------------
    */
public:
    enum SendModemEnum {
        MODEM_CMD_TIMEOUT = 0,
        MODEM_CMD_1,
        MODEM_CMD_OK,
        MODEM_CMD_0,
        MODEM_CMD_ERROR
    };

    char* BuildBuf;
    int MaxLen;

    char* EchoBuf;
    int EchoSize;
    int EchoCount;

    int OldIRQPri;

    int ModemVerboseOn;
    int ModemEchoOn;
    int ModemWaitCarrier;
    // int ModemCarrierDetect;
    // int ModemCarrierLoss;
    int ModemHangupDelay;
    int ModemGuardTime;
    char ModemEscapeCode;

    static void (*OrigAbortModemFunc)(int);
    static KeyNumType Input;
    static GadgetClass* Commands; // button list

    /*
    **	Constructor/destructor.
    */
    NullModemClass(int numsend, int numreceive, int maxlen, unsigned short magicnum);
    virtual ~NullModemClass();

    /*
    **	This is the main initialization routine.
    */
    int Init(int port, int irq, char* dev_name, int baud, char parity, int wordlength, int stopbits);
    int Delete_Connection();
    virtual int Num_Connections();
    virtual int Connection_ID(int) { return (0); }
    virtual int Connection_Index(int) { return (0); }
    int Init_Send_Queue();
    void Shutdown();

    virtual void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, bool bool1 = true);
    virtual void Set_External_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout) { Set_Timing(retrydelta, maxretries, timeout, true); }

    /*
    **	This is how the application sends & receives messages.
    */
    int Send_Message(void* buf, int buflen, int ack_req = 1);
    int Get_Message(void* buf, int* buflen);

    /*
    ** These are for compatibility
    */
    virtual int Send_Private_Message(void* buf, int buflen, int ack_req = 1, int = CONNECTION_NONE) { return (Send_Message(buf, buflen, ack_req)); }
    virtual int Get_Private_Message(void* buf, int* buflen, int*) { return (Get_Message(buf, buflen)); }

    /*
    **	The main polling routine; should be called as often as possible.
    */
    virtual int Service();

    /*
    **	Queue utility routines.  The application can determine how many
    **	messages are in the send/receive queues, and the queue's average
    **	response time (in clock ticks).
    */
    int Num_Send();
    int Num_Receive();
    virtual unsigned long Response_Time();
    virtual void Reset_Response_Time(bool zero);
    void* Oldest_Send();
    virtual void Configure_Debug(int index, int type_offset, int type_size, char** names, int namestart, int namecount);
#ifdef CHEAT_KEYS
    virtual void Mono_Debug_Print(int index, int refresh = 0);
#endif

    /*
    ** These are for compatibility
    */
    virtual int Global_Num_Send() { return (Num_Send()); }
    virtual int Global_Num_Receive() { return (Num_Receive()); }
    virtual int Private_Num_Send(int = CONNECTION_NONE) { return (Num_Send()); }
    virtual int Private_Num_Receive(int = CONNECTION_NONE) { return (Num_Receive()); }

    DetectPortType Detect_Port(SerialSettingsType* settings);
    bool Detect_Modem(SerialSettingsType* settings, bool reconnect = 0);
    DialStatusType Dial_Modem(char* string, DialMethodType method, bool reconnect = 0);
    DialStatusType Answer_Modem(bool reconnect = 0);
    bool Hangup_Modem();
    void Setup_Modem_Echo(void (*func)(char c));
    void Remove_Modem_Echo();
    void Print_EchoBuf();
    void Reset_EchoBuf();
    static int Abort_Modem(/*PORT*/void*);
    void Setup_Abort_Modem();
    void Remove_Abort_Modem();

    int Change_IRQ_Priority(int irq);
    int Get_Modem_Status();
    int Send_Modem_Command(char* command, char terminator, char* buffer, int buflen, int delay, int retries);
    int Verify_And_Convert_To_Int(char* buffer);

    /*
    **	Private Interface.
    */
private:
    ModemRegistryEntryClass* ModemRegistry;

    /*
    **	This is a pointer to the NULL-Modem Connection object.
    */
    NullModemConnClass* Connection;
    int NumConnections; // # connection objects in use

    /*
    ** This is the Win95 port handle
    */
    HANDLE PortHandle;

    int NumSend;
    int NumReceive;
    unsigned short MagicNum;

    /*
    **	This is the staging buffer for parsing incoming packets.
    **	RXSize is the allocated size of the RX buffer.
    **	RXCount is the # of characters we currently have in our buffer.
    */
    char* RXBuf;
    int RXSize;
    int RXCount;

    /*.....................................................................
    Timing parameters for all connections
    .....................................................................*/
    unsigned long RetryDelta;
    unsigned long MaxRetries;
    unsigned long Timeout;

    /*
    **	Various Statistics
    */
    int SendOverflows;
    int ReceiveOverflows;
    int CRCErrors;
};

/*************************** end of nullmgr.h ******************************/
