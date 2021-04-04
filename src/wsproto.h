/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WSPROTO.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Class to provide an interface to Winsock protocols.
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

#include "always.h"
#include "vector.h"
#include <winsock2.h>


#define WS_RECEIVE_BUFFER_LEN	640
#define WS_NUM_BUFFERS			128
#define SOCKET_BUFFER_SIZE		1024*128

#define WM_IPXASYNCEVENT		(WM_USER + 115)	// IPX socket Async event
#define WM_UDPASYNCEVENT		(WM_USER + 116)	// UDP socket Async event


/**
 *  Enum to identify the protocols supported by the Winsock interface.
 */
typedef enum tProtocolEnum {
	PROTOCOL_NONE,
	PROTOCOL_IPX,
	PROTOCOL_UDP
} ProtocolEnum;


class WinsockInterfaceClass
{
	public:
		WinsockInterfaceClass();
		virtual ~WinsockInterfaceClass();

		bool Init();
		void Close();

		virtual void Close_Socket();
		virtual int Read(void *buffer, int &buffer_len, void *address, int &address_len);
		virtual void WriteTo(void *buffer, int buffer_len, void *address);
		virtual void Broadcast(void *buffer, int buffer_len);
		virtual void Discard_In_Buffers();
		virtual void Discard_Out_Buffers();
		virtual bool Start_Listening();
		virtual void Stop_Listening();
		virtual void Clear_Socket_Error(SOCKET socket);
		virtual bool Set_Socket_Options();
		virtual void Set_Broadcast_Address(void *addr);
		virtual void Clear_Broadcast_Addresses() {}
		virtual ProtocolEnum Get_Protocol();
		virtual int Protocol_Event_Message();
		virtual bool Open_Socket(SOCKET socket);
	 	virtual LRESULT Message_Handler(HWND hWnd, UINT uMsg, UINT wParam, LONG lParam);
		virtual bool Get_Host_Name(char *name, int name_len) const;
		virtual int Local_Addresses_Count() const;
		virtual unsigned char * Get_Local_Address(int i) const;
		virtual void Set_NetCard(int netcard);

		typedef enum ConnectStatusEnum {
			CONNECTED_OK = 0,
			NOT_CONNECTING,
			CONNECTING,
			UNABLE_TO_CONNECT_TO_SERVER,
			CONTACTING_SERVER,
			SERVER_ADDRESS_LOOKUP_FAILED,
			RESOLVING_HOST_ADDRESS,
			UNABLE_TO_ACCEPT_CLIENT,
			UNABLE_TO_CONNECT,
			CONNECTION_LOST
		} ConnectStatusEnum;

		inline ConnectStatusEnum Get_Connection_Status() { return ConnectStatus; }

	protected:
		typedef struct tWinsockPacketType {
			unsigned int CRC;
			unsigned char Buffer[768];		// Buffer to store packet in.
		} WinsockPacketType;

		typedef struct tWinsockBufferType {
			unsigned char Address[64];		// Address. IN_ADDR, IPAddressClass etc.
			int BufferLen;					// Length of data in buffer
			bool IsBroadcast;				// Flag to broadcast this packet
			bool InUse;						// Is this buffer currently in use?
			bool Allocated;					// Clean up buffer if allocated.
			WinsockPacketType PacketData;	// Buffer to store packet in.
		} WinsockBufferType;

	protected:
		virtual void Build_Packet_CRC(WinsockBufferType *packet);
		virtual bool Passes_CRC_Check(WinsockBufferType *packet) const;

		WinsockBufferType *Get_New_Out_Buffer();
		WinsockBufferType *Get_New_In_Buffer();

	protected:
		DynamicVectorClass <WinsockBufferType *> InBuffers;
		DynamicVectorClass <WinsockBufferType *> OutBuffers;
		WinsockBufferType StaticInBuffers[WS_NUM_BUFFERS];
		WinsockBufferType StaticOutBuffers[WS_NUM_BUFFERS];
		int StaticInBufferPos;
		int StaticOutBufferPos;
		int StaticInBuffersInUse;
		int StaticOutBuffersInUse;
		bool WinsockInitialised;
		SOCKET Socket;
		unsigned char ReceiveBuffer[WS_RECEIVE_BUFFER_LEN];
		ConnectStatusEnum ConnectStatus;
		int NetCard;
};
