/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Compressed data stream class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
