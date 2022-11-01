/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IPXADDR.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Game session values.
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

#include <always.h>
#include "ipx.h"


class IPXAddressClass
{
    public:
        IPXAddressClass();
        IPXAddressClass(NetNumType net, NetNodeType node);
        IPXAddressClass(IPXHeaderType *header);
        ~IPXAddressClass();

        void Set_Address(NetNumType net, NetNodeType node);
        void Set_Address(IPXHeaderType *header);

        void Get_Address(NetNumType net, NetNodeType node) const;
        void Get_Address(IPXHeaderType *header) const;

        bool Is_Broadcast() const;

        bool operator == (IPXAddressClass &addr) const;
        bool operator != (IPXAddressClass &addr) const;
        bool operator > (IPXAddressClass &addr) const;
        bool operator < (IPXAddressClass &addr) const;
        bool operator >= (IPXAddressClass &addr) const;
        bool operator <= (IPXAddressClass &addr) const;

        const char *As_String() const;

    public:
        NetNumType NetworkNumber;
        NetNodeType NodeAddress;
};
