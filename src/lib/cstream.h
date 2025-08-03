/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CSTREAM.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Compressed data stream class.
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
#include "ilinkstream.h"
#include <comdef.h>
#include <comip.h>


_COM_SMARTPTR_TYPEDEF(IStream, __uuidof(IStream));
_COM_SMARTPTR_TYPEDEF(ILinkStream, __uuidof(ILinkStream));


class DECLSPEC_UUID("B48FA168-646F-11D2-9B74-00104B972FE8")
CStreamClass : public IStream, public ILinkStream
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  ISequentialStream
     */
    IFACEMETHOD(Read)(void* pv, ULONG cb, ULONG* pcbRead);
    IFACEMETHOD(Write)(const void* pv, ULONG cb, ULONG* pcbWritten);

    /**
     *  IStream
     */
    IFACEMETHOD(Seek)(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER* plibNewPosition);
    IFACEMETHOD(SetSize)(ULARGE_INTEGER libNewSize);
    IFACEMETHOD(CopyTo)(IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER* pcbRead, ULARGE_INTEGER* pcbWritten);
    IFACEMETHOD(Commit)(DWORD grfCommitFlags);
    IFACEMETHOD(Revert)();
    IFACEMETHOD(LockRegion)(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
    IFACEMETHOD(UnlockRegion)(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
    IFACEMETHOD(Stat)(STATSTG* pstatstg, DWORD grfStatFlag);
    IFACEMETHOD(Clone)(IStream** ppstm);

    /**
     *  ILinkStream
     */
    IFACEMETHOD(Link_Stream)(IUnknown* stream);
    IFACEMETHOD(Unlink_Stream)(IUnknown** stream);

public:
    CStreamClass();
    virtual ~CStreamClass();

    HRESULT Compress(void* in_buffer, ULONG length);
    HRESULT Compress();

private:
    IStreamPtr field_8;
    LONG RefCount;
    bool field_10;
    bool field_11;
    int Counter;
    unsigned char* Buffer;
    unsigned char* Buffer2;
    void* Dictionary;
    struct {
        unsigned int CompCount;
        unsigned int UncompCount;
    } Header;
};
