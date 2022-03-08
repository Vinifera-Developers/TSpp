/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WSPIPX.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Class to provide an interface to Winsock IPX protocol.
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

#include "wsproto.h"
#include <wsipx.h>


class IPXInterfaceClass : public WinsockInterfaceClass
{
	public:
		IPXInterfaceClass();
		virtual ~IPXInterfaceClass();

		virtual ProtocolEnum Get_Protocol() override;
		virtual int Protocol_Event_Message() override;
		virtual bool Open_Socket(SOCKET socketnum) override;
	 	virtual LRESULT Message_Handler(HWND hWnd, UINT uMsg, UINT wParam, LONG lParam) override;

		bool Get_Network_Card_Address(int card_number, SOCKADDR_IPX *addr);
		bool Get_Network_Card_Address_String(int card_number, char *buffer, int size);

	private:
		unsigned char BroadcastNet[4];
		unsigned char BroadcastNode[6];
		unsigned char MyNode[6];
		SOCKET IPXSocketNumber;
};
