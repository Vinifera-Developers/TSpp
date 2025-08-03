/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONNPOINT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         ConnectionPointClass and EnumConnectionPointsClass.
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
#include <ocidl.h> // for IConnectionPointContainer.


/**
 *  VectorClass throws a fuss as it can't find these operators for CONNECTDATA, so we need to define them.
 */
__inline bool operator==(const CONNECTDATA& a, const CONNECTDATA& b)
{
    return !std::memcmp(&a, &b, sizeof(CONNECTDATA));
}

__inline bool operator!=(const CONNECTDATA& a, const CONNECTDATA& b)
{
    return std::memcmp(&a, &b, sizeof(CONNECTDATA));
}


class ConnectionPointClass : public IConnectionPoint
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IConnectionPoint
     */
    IFACEMETHOD(GetConnectionInterface)(IID* pIID);
    IFACEMETHOD(GetConnectionPointContainer)(IConnectionPointContainer** ppCPC);
    IFACEMETHOD(Advise)(IUnknown* pUnkSink, DWORD* pdwCookie);
    IFACEMETHOD(Unadvise)(DWORD dwCookie);
    IFACEMETHOD(EnumConnections)(IEnumConnections** ppEnum);

public:
    ConnectionPointClass(REFIID riid, IUnknown* a2);
    ~ConnectionPointClass();

private:
    CLSID field_0;
    int RefCount;
    IUnknown* field_18;
    DynamicVectorClass<CONNECTDATA> field_1C;
};


class EnumConnectionsClass : public IEnumConnections
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IEnumConnection
     */
    IFACEMETHOD(Next)(ULONG cConnections, LPCONNECTDATA rgcd, ULONG* pcFetched);
    IFACEMETHOD(Skip)(ULONG cConnections);
    IFACEMETHOD(Reset)();
    IFACEMETHOD(Clone)(IEnumConnections** ppEnum);

public:
    EnumConnectionsClass(const DynamicVectorClass<CONNECTDATA>& vec);
    EnumConnectionsClass(const EnumConnectionsClass& that);
    ~EnumConnectionsClass();

private:
    DynamicVectorClass<CONNECTDATA> ConnectData;
    int Current;
    int RefCount;
};


class EnumConnectionPointsClass : public IEnumConnectionPoints
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IEnumConnectionPoints
     */
    IFACEMETHOD(Next)(ULONG cConnections, LPCONNECTIONPOINT* ppCP, ULONG* pcFetched);
    IFACEMETHOD(Skip)(ULONG cConnections);
    IFACEMETHOD(Reset)();
    IFACEMETHOD(Clone)(IEnumConnectionPoints** ppEnum);

public:
    EnumConnectionPointsClass();
    EnumConnectionPointsClass(const DynamicVectorClass<LPCONNECTIONPOINT>& vec);
    ~EnumConnectionPointsClass();

private:
    int Current;
    int RefCount;
    DynamicVectorClass<LPCONNECTIONPOINT> ConnectionPoints;
};
