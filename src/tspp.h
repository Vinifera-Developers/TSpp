/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file for the TS++ project.
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
#include <cstdio>


/**
 *  Outputs the address and mangled name to the debug output window.
 */
#define OUTPUT_IDA_NAMES
#ifdef OUTPUT_IDA_NAMES
#define OUTPUT_IDA_NAME(address, name) __pragma(message("    MakeName(" #address ", " "\"" name "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_NAME(address, name) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@@UAEPAXI@Z" "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_NAMESPACE_NAME(address, namespace_name, name) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@@UAEPAXI@Z" "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_NAMESPACE_NESTED_NAME(address, namespace_name, nested_name, name) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@@UAEPAXI@Z" "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_NAME(address, name, _typename) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@V" _typename "@@@@UAEPAXI@Z" "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_PTR_STRUCT_NAME(address, name, _typename) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@PAU" _typename "@@@@UAEPAXI@Z" "\"" ");"))
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_PTR_CLASS_NAME(address, name, _typename) __pragma(message("    MakeName(" #address ", " "\"" "??_G" name "@PAU" _typename "@@@@UAEPAXI@Z" "\"" ");"))
#else
#define OUTPUT_IDA_NAME(address, name)
#define OUTPUT_IDA_SCALAR_DTOR_NAME(address, name)
#define OUTPUT_IDA_SCALAR_DTOR_NAMESPACE_NAME(address, namespace_name, name)
#define OUTPUT_IDA_SCALAR_DTOR_NAMESPACE_NESTED_NAME(address, namespace_name, nested_name, name)
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_NAME(address, name)
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_PTR_STRUCT_NAME(address, name)
#define OUTPUT_IDA_SCALAR_DTOR_TEMPLATE_PTR_CLASS_NAME(address, name)
#endif


/**
 *  Define a empty implementation of a function.
 * 
 *  In;
 *    - DLL Builds: This will define a jump back to the binary implementation.
 * 
 *  Example;
 *    DEFINE_IMPLEMENTATION(void Func(void *Arg1, void *Arg2), 0x12345678);
 *    DEFINE_IMPLEMENTATION(EnumType Func(void *Arg1, void *Arg2), 0x12345678, EnumType());
 * 
 *  WARNING: If you use this, the definition(s) must be after everything else in the module
 *           otherwise you will get 'unreachable code' warnings!
 */
#define DEFINE_IMPLEMENTATION(prototype, address, ...) \
    /*[[ noreturn ]]*/ __declspec(noinline) __declspec(naked) \
    prototype \
    { \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }

#define DEFINE_IMPLEMENTATION_INLINE(prototype, address, ...) \
    /*[[ noreturn ]]*/ inline __declspec(naked) \
    prototype \
    { \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }

#define DEFINE_IMPLEMENTATION_UNWIND(prototype, address, ...) \
    /*[[ noreturn ]]*/ \
    prototype \
    { \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }


/**
 *  For constructor jumps, we need to adjust the stack before we
 *  make the jump to the address, otherwise the stack will be smashed.
 */
#ifndef NDEBUG
#define CONSTRUCTOR_EPILOG \
	_asm { pop edi } \
	_asm { pop esi } \
	_asm { pop ebx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }
#else
// RelWithDebInfo produces the same epilog as Debug.
#define CONSTRUCTOR_EPILOG \
	_asm { pop edi } \
	_asm { pop esi } \
	_asm { pop ebx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }

/*
#define CONSTRUCTOR_EPILOG \
	_asm { pop ecx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }
*/
#endif

#if 0
#define DEFINE_IMPLEMENTATION_CONSTRUCTOR(prototype, address, ...) \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype \
    { \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        _asm { mov ecx, this } \
	    _asm { mov esp, ebp } \
	    _asm { pop ebp } \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }
#endif

#if 0
// For classes with a base class that has no default constructor available.
#define DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(prototype, base, address, ...) \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype : base(NoInitClass()) \
    { \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        _asm { mov ecx, this } \
	    _asm { mov esp, ebp } \
	    _asm { pop ebp } \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }
#endif


/**
 *  For deconstructor jumps, we need to adjust the stack before we
 *  make the jump to the address, otherwise the stack will be smashed.
 */
#ifndef NDEBUG
#define DESTRUCTOR_EPILOG \
	_asm { pop edi } \
	_asm { pop esi } \
	_asm { pop ebx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }
#else
// RelWithDebInfo produces the same epilog as Debug.
#define DESTRUCTOR_EPILOG \
	_asm { pop edi } \
	_asm { pop esi } \
	_asm { pop ebx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }

/*
#define DESTRUCTOR_EPILOG \
	_asm { pop ecx } \
	_asm { mov esp, ebp } \
	_asm { pop ebp }
*/
#endif

#if 0
#define DEFINE_IMPLEMENTATION_DESTRUCTOR(prototype, address, ...) \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype \
    { \
        __pragma(message(__FUNCDNAME__)) \
        OUTPUT_IDA_NAME(address, __FUNCDNAME__) \
        DESTRUCTOR_EPILOG; \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }
#endif


/**
 *  Use Make_Global to access global variables in the original exe once you know
 *  the correct type and address. This should not change from run to run if the
 *  exe loads at a standard base address.
 *  
 *  Typical use will be to use define to create a friendly name, e.g:
 *    #define SomeGlobalVar (Make_Global<bool>(0x00FF00FF))
 *
 *  allows you to use SomeGlobalVar as though it was a bool you declared, though
 *  it will reflect the value the original exe sees at address 0x00FF00FF.
 */
template<typename T>
__forceinline T &Make_Global(const uintptr_t address)
{
    return *reinterpret_cast<T *>(address);
}

template<typename T>
__forceinline T *Make_Pointer(const uintptr_t address)
{
    return reinterpret_cast<T *>(address);
}


template<typename T, const int size>
class ArrayHelper
{
    public:
        operator T *() { return (T *)this; }
        operator const T *() const { return (T *)this; }
        T *operator&() { return (T *)this; }
        const T *operator&() const { return (T *)this; }
        T &operator[](int index) { return ((T *)this)[index]; }
        const T &operator[](int index) const { return ((T *)this)[index]; }

    protected:
        char _dummy[size * sizeof(T)];
};

template<typename T, const int y, const int x>
class ArrayHelper2D
{
    public:
        operator ArrayHelper<T, x> *() { return (ArrayHelper<T, x> *)this; }
        operator const ArrayHelper<T, x> *() const { return (ArrayHelper<T, x> *)this; }
        ArrayHelper<T, x> *operator&() { return (ArrayHelper<T, x> *)this; }
        const ArrayHelper<T, x> *operator&() const { return (ArrayHelper<T, x> *)this; }
        ArrayHelper<T, x> &operator[](int index) { return _dummy[index]; }
        const ArrayHelper<T, x> &operator[](int index) const { return _dummy[index]; }

    protected:
        ArrayHelper<T, x> _dummy[y];
};

/**
 *  Helper macros for defining hooks to various arrays.
 * 
 *  @author: OmniBlade
 */
#define ARRAY_DEC(type, var, size) extern ArrayHelper<type, size> &var
#define ARRAY_DEF(address, type, var, size) ArrayHelper<type, size> &var = Make_Global<ArrayHelper<type, size>>(address);
#define ARRAY2D_DEC(type, var, x, y) extern ArrayHelper2D<type, x, y> &var
#define ARRAY2D_DEF(address, type, var, x, y) ArrayHelper2D<type, x, y> &var = Make_Global<ArrayHelper2D<type, x, y>>(address);
