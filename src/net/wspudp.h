/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WSPUDP.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Class to provide an interface to Winsock UDP protocol.
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
 ******************************************************************************/
#pragma once

#include "vector.h"
#include "wsproto.h"


class UDPInterfaceClass : public WinsockInterfaceClass
{
public:
    UDPInterfaceClass();
    virtual ~UDPInterfaceClass();

    virtual void Broadcast(void* buffer, int buffer_len) override;
    virtual void Set_Broadcast_Address(void* address) override;
    virtual void Clear_Broadcast_Addresses() override;
    virtual ProtocolEnum Get_Protocol() override;
    virtual int Protocol_Event_Message() override;
    virtual bool Open_Socket(SOCKET socketnum) override;
    virtual LRESULT Message_Handler(HWND hWnd, UINT uMsg, UINT wParam, LONG lParam) override;
    virtual int Local_Addresses_Count() const override;
    virtual unsigned char* Get_Local_Address(int index) const override;

private:
    DynamicVectorClass<unsigned char*> BroadcastAddresses;
    DynamicVectorClass<unsigned char*> LocalAddresses;
};
