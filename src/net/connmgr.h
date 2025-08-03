/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONNMGR.H
 *
 *  @author        Bill Randolph (see notes below)
 *
 *  @contributors  ZivDero
 *
 *  @brief         This is the Connection Manager base class. This is an
 *                 abstract base class that's just a shell for
 *                 more functional derived classes.
 *
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


class ConnManClass
{
public:
    enum IPXConnTag {
        CONNECTION_NONE = -1 // value of an invalid connection ID
    };

    /**
     *  Constructor/Destructor. These currently do nothing.
     */
    ConnManClass() {};
    virtual ~ConnManClass() {};

    /**
     *  The Service routine:
     *  - Parses incoming packets, and adds them to the Receive Queue for the
     *    Connection Class(s) for this protocol
     *  - Invokes each connection's Service routine; returns an error if the
     *    connection's Service routine indicates an error.
     */
    virtual int Service() = 0;

    /**
     *  Sending & receiving data
     */
    virtual int Send_Private_Message(void* buf, int buflen, int ack_req = 1, int conn_id = CONNECTION_NONE) = 0;
    virtual int Get_Private_Message(void* buf, int* buflen, int* conn_id) = 0;

    /**
     *  Connection management
     */
    virtual int Num_Connections() = 0;
    virtual int Connection_ID(int index) = 0;
    virtual int Connection_Index(int id) = 0;

    /**
     *  Queue utility routines
     */
    virtual int Global_Num_Send() = 0;
    virtual int Global_Num_Receive() = 0;
    virtual int Private_Num_Send(int id = CONNECTION_NONE) = 0;
    virtual int Private_Num_Receive(int id = CONNECTION_NONE) = 0;

    /**
     *  Timing management
     */
    virtual void Reset_Response_Time(bool zero) = 0;
    virtual unsigned long Response_Time() = 0;
    virtual void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, bool global = true) = 0;
    virtual void Set_External_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout);

    /**
     *  Debugging
     */
    virtual void Configure_Debug(int index, int type_offset, int type_size, char** names, int namestart, int namecount) = 0;
};
