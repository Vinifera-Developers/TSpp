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
 *  @brief         This is the Connection Class for a NULL-Modem connection.
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
#include "connect.h"
#include "windows.h"

/*
********************************** Defines **********************************
*/
#define PACKET_SERIAL_START  0xDABD
#define PACKET_SERIAL_VERIFY 0xDEAF

#define PACKET_SERIAL_OVERHEAD_SIZE (sizeof(SerialHeaderType) + sizeof(SerialCRCType))

typedef struct {
    unsigned short MagicNumber;
    unsigned short Length;
    unsigned short MagicNumber2;
} SerialHeaderType;

typedef struct {
    int SerialCRC;
} SerialCRCType;


/*
***************************** Class Declaration *****************************
*/
class NullModemConnClass : public ConnectionClass
{
    /*
    ---------------------------- Public Interface ----------------------------
    */
public:
    /*.....................................................................
    Constructor/destructor.
    .....................................................................*/
    NullModemConnClass(int numsend, int numrecieve, int maxlen, unsigned short magicnum);
    virtual ~NullModemConnClass();

    /*.....................................................................
    Initialization.
    .....................................................................*/
    void Init(HANDLE port_handle);

    virtual void Init();

    /*.....................................................................
    Utility routines.
    .....................................................................*/
    unsigned long Actual_Max_Packet() { return (MaxPacketLen + (sizeof(SerialHeaderType)) + sizeof(int) + sizeof(char)); }

    /*.....................................................................
    This routine computes a CRC value for the given buffer.
    .....................................................................*/
    static int Compute_CRC(char* buf, int buflen);

    /*.....................................................................
    This routine returns the number of bytes extra added the packet
    for communication.
    .....................................................................*/
    static int Packet_Overhead_Size();

    /*
    --------------------------- Private Interface ----------------------------
    */
protected:
    /*.....................................................................
    This routine actually performs a hardware-dependent data send.
    .....................................................................*/
    virtual int Send(char* buf, int buflen, void* extrabuf, int extralen);

    /*
    ** This is the winsoze port handle
    */
    HANDLE PortHandle;

    /*.....................................................................
    This buffer is a staging area for data sent out; it includes the
    packet sent by the parent class (which includes the application's
    packet, plus the CommHeaderType header), plus:
    - 2-byte buffer start ID
    - 2-byte length
    - 4-byte CRC value (at the end of the buffer)
    This is the actual packet that gets sent across the serial line.
    .....................................................................*/
    char* SendBuf;
};

/************************** end of nullconn.h ******************************/
