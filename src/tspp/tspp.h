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
#include <vector>
#include <string>
#include <algorithm>
#include <dbghelp.h>


//#define OUTPUT_MANGLED_NAMES 1


/**
 *  Outputs the address and mangled name to the debug output window.
 */
#ifdef OUTPUT_MANGLED_NAMES
#define OUTPUT_MANGLED_NAME(address, name) __pragma(message("    MakeName(" #address ", " "\"" name "\"" ");"))
#else
#define OUTPUT_MANGLED_NAME(address, name) 
#endif


extern DWORD64 TSPP_GAME_EXE_START;
extern DWORD64 TSPP_GAME_EXE_END;


struct TSPP_SymbolEntry
{
    DWORD64 address;      // Absolute address of the symbol
    std::string name;     // Symbol name
};

struct TSPP_ModuleEntry
{
    DWORD64 start;        // Start address of the module
    DWORD64 end;          // End address of the module
    std::string name;     // Module name
};


// List of declared and known symbols from the target exe.
extern std::vector<TSPP_SymbolEntry> TSPP_Symbols;
extern std::vector<TSPP_ModuleEntry> TSPP_Modules;


/**
 *  Handy little struct that allows us to populate a vector of known symbols while also declaring them!
 */
struct TSPP_AutoSymbolRegister
{
    TSPP_AutoSymbolRegister(DWORD64 addr, /*const*/ char * name, bool undecorate = false)
    {
        if (undecorate) {
            static char unmangled[512];
            UnDecorateSymbolName(name, unmangled, sizeof(unmangled), UNDNAME_COMPLETE);
            name = unmangled;
        }

        Register(addr, name);
    }

    inline void Register(DWORD64 addr, const char * name)
    {
        TSPP_Symbols.push_back({ addr, name });
    }

    // Sort by address for binary search
    static void Sort()
    {
        std::sort(TSPP_Symbols.begin(), TSPP_Symbols.end(),
              [](const TSPP_SymbolEntry& a, const TSPP_SymbolEntry& b) { return a.address < b.address; });
    }
};

struct TSPP_ModuleRegister
{
    TSPP_ModuleRegister(DWORD64 start, DWORD64 end, const char * name)
    {
        Register(start, end, name);
    }

    inline void Register(DWORD64 start, DWORD64 end, const char * name)
    {
        TSPP_Modules.push_back({ start, end, name });
    }

    // Sort by address for binary search
    static void Sort()
    {
        std::sort(TSPP_Modules.begin(), TSPP_Modules.end(),
              [](const TSPP_ModuleEntry& a, const TSPP_ModuleEntry& b) { return a.start < b.start; });
    }
};


// Macro used to register the declerations from tspp_defs.asm manually.
#define REGISTER_ASM_SYMBOL(prototype, addr) \
    static TSPP_AutoSymbolRegister _tspp_asm_reg_##addr(addr, prototype, true);

#define REGISTER_MODULE(start, end, name) \
    static TSPP_ModuleRegister _tspp_module_reg_##start##_##end(start, end, name);


/**
 *  DEFINE_IMPLEMENTATION(prototype, address)
 *
 *  This macro defines a naked function that jumps to a hardcoded address, and automatically
 *  registers the symbol (address + mangled name) for debugging or stack tracing tools.
 *
 *  Requirements:
 *  - The function `prototype` must already be declared (e.g., in a class or header).
 *  - Must be used in a `.cpp` source file, outside any class body.
 *
 *  Parameters:
 *  - prototype: The full function prototype including namespace/class (e.g., int Pipe::Flush()).
 *  - address:   The absolute memory address the function should jump to.
 *
 *  Behavior:
 *  - Defines a naked function that jumps to `address`.
 *  - Registers the mangled function name (__FUNCDNAME__) with TSPP_AutoSymbolRegister at global init.
 *
 *  Example:
 *      class Pipe { public: int Flush(); };
 *      DEFINE_IMPLEMENTATION(int Pipe::Flush(), 0x005A94E0);
 * 
 *  WARNING: If you use this, the definition(s) must be after everything else in the module
 *           otherwise you will get 'unreachable code' warnings!
 *
 */
#define DEFINE_IMPLEMENTATION(prototype, address) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ __declspec(noinline) __declspec(naked) prototype \
    { \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }

#define DEFINE_IMPLEMENTATION_INLINE(prototype, address, ...) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ inline __declspec(naked) \
    prototype \
    { \
        OUTPUT_MANGLED_NAME(address, __FUNCDNAME__) \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }

#define DEFINE_IMPLEMENTATION_UNWIND(prototype, address, ...) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ \
    prototype \
    { \
        OUTPUT_MANGLED_NAME(address, __FUNCDNAME__) \
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

#define DEFINE_IMPLEMENTATION_CONSTRUCTOR(prototype, address, ...) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype \
    { \
        OUTPUT_MANGLED_NAME(address, __FUNCDNAME__) \
        _asm { mov ecx, this } \
	    _asm { mov esp, ebp } \
	    _asm { pop ebp } \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }

// For classes with a base class that has no default constructor available.
#define DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(prototype, base, address, ...) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype : base(NoInitClass()) \
    { \
        OUTPUT_MANGLED_NAME(address, __FUNCDNAME__) \
        _asm { mov ecx, this } \
	    _asm { mov esp, ebp } \
	    _asm { pop ebp } \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }


/**
 *  For destructor jumps, we need to adjust the stack before we
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

#define DEFINE_IMPLEMENTATION_DESTRUCTOR(prototype, address, ...) \
    namespace { \
        static struct TSPP_AutoRegister_##address { \
            TSPP_AutoRegister_##address() { \
                TSPP_AutoSymbolRegister(address, #prototype); \
            } \
        } _tspp_auto_register_##address; \
    } \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype \
    { \
        __pragma(message(__FUNCDNAME__)) \
        OUTPUT_MANGLED_NAME(address, __FUNCDNAME__) \
        DESTRUCTOR_EPILOG; \
        _asm { mov eax, address } \
        _asm { jmp eax } \
    }


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
#define ARRAY_MEMBER_DEC(type, var, size) type(&var)[size];
#define ARRAY_DEC(type, var, size) extern type(&var)[size];
#define ARRAY_DEF(address, type, var, size) type(&var)[size] = Make_Global<type[size]>(address);
#define ARRAY2D_DEC(type, var, x, y) extern type(&var)[x][y];
#define ARRAY2D_DEF(address, type, var, x, y) type(&var)[x][y] = Make_Global<type[x][y]>(address);
