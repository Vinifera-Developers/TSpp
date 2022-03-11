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
#ifdef OUTPUT_IDA_NAMES
#define OUTPUT_IDA_NAME(address, name) __pragma(message("    MakeName(" #address ", " "\"" name "\"" ");"))
#else
#define OUTPUT_IDA_NAME(address, name) 
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


/**
 *  Helper macros for defining hooks to various arrays.
 * 
 *  @author: OmniBlade, duncanspumpkin
 */
#define ARRAY_DEC(type, var, size) extern type(&var)[size];
#define ARRAY_DEF(address, type, var, size) type(&var)[size] = Make_Global<type[size]>(address);
#define ARRAY2D_DEC(type, var, x, y) extern type(&var)[x][y];
#define ARRAY2D_DEF(address, type, var, x, y) type(&var)[x][y] = Make_Global<type[x][y]>(address);
