/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game session values.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ipx.h"


class IPXAddressClass
{
public:
    IPXAddressClass();
    IPXAddressClass(NetNumType net, NetNodeType node);
    IPXAddressClass(IPXHeaderType* header);
    ~IPXAddressClass();

    void Set_Address(NetNumType net, NetNodeType node);
    void Set_Address(IPXHeaderType* header);

    void Get_Address(NetNumType net, NetNodeType node) const;
    void Get_Address(IPXHeaderType* header) const;

    bool Is_Broadcast() const;

    bool operator==(IPXAddressClass& addr) const;
    bool operator!=(IPXAddressClass& addr) const;
    bool operator>(IPXAddressClass& addr) const;
    bool operator<(IPXAddressClass& addr) const;
    bool operator>=(IPXAddressClass& addr) const;
    bool operator<=(IPXAddressClass& addr) const;

    const char* As_String() const;

public:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};
