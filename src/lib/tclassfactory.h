/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TCLASSFACTORY.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class Factory for the COM Server.
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
#include "tspp_assert.h"
#include "vector.h"
#include <unknwn.h>


/**
 *  Register a class-object with OLE.
 */
#define REGISTER_CLASS(_class)                                                                                                    \
    {                                                                                                                             \
        DWORD dwRegister = 0;                                                                                                     \
        TClassFactory<_class>* ptr = new TClassFactory<_class>();                                                                 \
        HRESULT hr = CoRegisterClassObject(__uuidof(_class), ptr, CLSCTX_INPROC_SERVER, REGCLS_MULTIPLEUSE, &dwRegister);         \
        if (FAILED(hr)) {                                                                                                         \
            std::printf("CoRegisterClassObject(TClassFactory<" #_class ">) failed with error code %d.\n", GetLastError());        \
        } else {                                                                                                                  \
            std::printf(#_class " factory registered.\n");                                                                        \
        }                                                                                                                         \
        ClassFactories.Add(dwRegister);                                                                                           \
    }


/**
 *  Register a class-object with OLE (pre-created factory).
 */
#define REGISTER_FACT_CLASS(_class, _fact)                                                                                        \
    {                                                                                                                             \
        DWORD dwRegister = 0;                                                                                                     \
        IClassFactory* ptr = _fact;                                                                                               \
        HRESULT hr = CoRegisterClassObject(__uuidof(_class), ptr, CLSCTX_INPROC_SERVER, REGCLS_MULTIPLEUSE, &dwRegister);         \
        if (FAILED(hr)) {                                                                                                         \
            std::printf("CoRegisterClassObject(TClassFactory<" #_class ">) failed with error code %d.\n", GetLastError());        \
        } else {                                                                                                                  \
            std::printf(#_class " factory registered.\n");                                                                        \
        }                                                                                                                         \
        ClassFactories.Add(dwRegister);                                                                                           \
    }


/**
 *
 */
template<class T>
class TClassFactory : public IClassFactory
{
public:
    TClassFactory() : m_cRef(0) {}
    //~TClassFactory() {}

    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IClassFactory
     */
    IFACEMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, PVOID* ppvObj);
    IFACEMETHOD(LockServer)(BOOL fLock);

public:
    ULONG m_cRef;
};


/**
 *  TClassFactory::QueryInterface
 *
 *  Retrieves pointers to the supported interfaces on an object.
 *
 *  @param      riid    The interface to this object being queried for.
 *
 *  @param      ppvObj  Buffer to fill with obtained interface.
 *
 *  @return     S_OK if interface obtained; E_NOINTERFACE otherwise.
 */
template<class T>
HRESULT STDMETHODCALLTYPE TClassFactory<T>::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
    /**
     *  Always set out parameter to NULL, validating it first.
     */
    if (ppvObj == nullptr) {
        return E_POINTER;
    }
    *ppvObj = nullptr;

    if (riid == __uuidof(IUnknown)) {
        *ppvObj = static_cast<IUnknown*>(this);
    }

    if (riid == __uuidof(IClassFactory)) {
        *ppvObj = static_cast<IClassFactory*>(this);
    }

    if (*ppvObj == nullptr) {
        return E_NOINTERFACE;
    }

    /**
     *  Increment the reference count and return the pointer.
     */
    reinterpret_cast<IUnknown*>(*ppvObj)->AddRef();

    return S_OK;
}


/**
 *  TClassFactory::AddRef
 *
 *  Increments the reference count for an interface pointer to a COM object.
 */
template<class T>
ULONG STDMETHODCALLTYPE TClassFactory<T>::AddRef()
{
    return InterlockedIncrement(&m_cRef);
}


/**
 *  TClassFactory::Release
 *
 *  Decrements the reference count for an interface on a COM object.
 */
template<class T>
ULONG STDMETHODCALLTYPE TClassFactory<T>::Release()
{
    ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0) {
        delete this;
    }
    return cRef;
}


/**
 *  TClassFactory::CreateInstance
 *
 *  Creates an uninitialized object.
 *
 *  @param      pUnkOuter  If the object is being created as part of an aggregate, specify a
 *                         pointer to the controlling IUnknown interface of the aggregate.
 *
 *  @param      riid       A reference to the identifier of the interface to be used to
 *                         communicate with the newly created object.
 *
 *  @param      ppvObj     The address of pointer variable that receives the interface
 *                         pointer requested in riid.
 *
 *  @return     S_OK if interface obtained; E_NOINTERFACE otherwise.
 */
template<class T>
HRESULT STDMETHODCALLTYPE TClassFactory<T>::CreateInstance(IUnknown* pUnkOuter, REFIID riid, PVOID* ppvObj)
{
    if (ppvObj == nullptr) {
        return E_INVALIDARG;
    }

    *ppvObj = nullptr;
    if (pUnkOuter != nullptr) {
        return CLASS_E_NOAGGREGATION;
    }

    T* obj = new T();
    if (obj == nullptr) {
        return E_OUTOFMEMORY;
    }

    /**
     *  Query the specified interface.
     */
    HRESULT hr = obj->QueryInterface(riid, ppvObj);
    if (FAILED(hr)) {
        obj->~T();
    }

    return hr;
}


/**
 *  TClassFactory::CreateInstance
 *
 *  Locks an object application open in memory.
 */
template<class T>
HRESULT STDMETHODCALLTYPE TClassFactory<T>::LockServer(BOOL fLock)
{
    if (fLock) {
        ++m_cRef;
    } else {
        --m_cRef;
    }
    return S_OK;
}
