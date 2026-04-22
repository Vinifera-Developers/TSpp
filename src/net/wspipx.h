/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class to provide an interface to Winsock IPX protocol.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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

    bool Get_Network_Card_Address(int card_number, SOCKADDR_IPX* addr);
    bool Get_Network_Card_Address_String(int card_number, char* buffer, int size);

private:
    unsigned char BroadcastNet[4];
    unsigned char BroadcastNode[6];
    unsigned char MyNode[6];
    SOCKET IPXSocketNumber;
};
