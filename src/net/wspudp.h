/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class to provide an interface to Winsock UDP protocol.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
