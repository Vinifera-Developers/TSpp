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
 *  MSVC++ Stack Frames
 */
#define PROLOG_THISCALL \
    _asm { push ecx } \
    _asm { push esp, ebp } \
    _asm { push ebp }

#define PROLOG_STDCALL \
    _asm { mov esp, ebp } \
    _asm { push ebp }
 
#define EPILOG_THISCALL \
    _asm { pop ecx } \
    _asm { mov esp, ebp } \
    _asm { pop ebp }

#define EPILOG_STDCALL \
    _asm { mov esp, ebp } \
    _asm { pop ebp }


/**
 *  Jumps
 */
#define JMP(address) \
    _asm { mov eax, address } \
    _asm { jmp eax }

#define JMP_THIS(address) \
    { \
        EPILOG_THISCALL; \
        JMP(address); \
    }

#define JMP_STD(address) \
    { \
        EPILOG_STDCALL; \
        JMP(address); \
    }


/**
 *  Calls
 */
#define CALL(p_func) \
    _asm { mov eax, p_func }\
    _asm { call eax }

#define CALL_VT(vt_offs) \
    _asm { mov eax, [ecx] }\
    _asm { call dword ptr [eax+vt_offs] }

#define THISCALL(p_func) \
    _asm { mov ecx, this }\
    _asm { mov eax, p_func }\
    _asm { call eax }

#define THISCALL_EX(p_this, p_func) \
    _asm { mov ecx, p_this }\
    _asm { mov eax, p_func }\
    _asm { call eax }

#define THISCALL_VT(vt_offs) \
    _asm { mov ecx, this }\
    _asm { mov eax, [ecx] }\
    _asm { call dword ptr [eax+vt_offs] }

#define THISCALL_EX_VT(p_this, vt_offs) \
    _asm { mov ecx, p_this }\
    _asm { mov edx, [ecx] }\
    _asm { call dword ptr [edx+vt_offs] }


/**
 *  Get/Set register to a variable
 */
#define GET_REGISTER(dst, reg) _asm { mov dst, reg }
#define SET_REGISTER(reg, src) _asm { mov reg, src }


/**
 *   
 */
#define ZERO_REG(reg) _asm { xor reg, reg }


/**
 *  Basic stack pointer operations.
 */
#define ADD_ESP(i) _asm { add esp, i }
#define SUB_ESP(i) _asm { sub esp, i }


/**
 *  Pushes
 */
// Push immediate value
#define PUSH_IMM(i) _asm { push i }

// Push / Pop a register
#define PUSH_REG(r) _asm { push r }
#define POP_REG(r) _asm { pop r }

// Push a pointer to a variable
#define PUSH_PTR(var) \
    _asm { lea eax, var }\
    _asm { push eax }

// Push 8bit variable
#define PUSH_VAR8(var) \
    _asm { movzx eax, var }\
    _asm { push eax }

// Push 16bit variable
#define PUSH_VAR16(var) \
    _asm { movzx eax, var }\
    _asm { push eax }
	
// Push 32bit variable
#define PUSH_VAR32(var) \
    _asm { mov eax, var }\
    _asm { push eax }

// Push 64bit variable
#define PUSH_VAR64(var) \
    _asm { mov eax, var }\
    _asm { mov ecx, [eax+4] }\
    _asm { mov eax, [eax] }\
    _asm { push ecx }\
    _asm { push eax }


/**
 *  Read and Write to memory.
 */
#define MEM_READ8(dst, mem) \
    _asm { mov dl, byte ptr ds:mem }\
    _asm { mov dst, dl }

#define MEM_WRITE8(mem, src) \
    _asm { mov dl, src }\
    _asm { mov byte ptr ds:mem, dl }

#define MEM_READ16(dst, mem) \
    _asm { mov dx, word ptr ds:mem }\
    _asm { mov dst, dx }

#define MEM_WRITE16(mem, src) \
    _asm { mov dx, src }\
    _asm { mov word ptr ds:mem, dx }

#define MEM_READ32(dst, mem) \
    _asm { mov edx, dword ptr ds:mem }\
    _asm { mov dst, edx }

#define MEM_WRITE32(mem, src) \
    _asm { mov edx, src }\
    _asm { mov dword ptr ds:mem, edx }

#define MEM_WRITEIMM8(mem, imm)	 \
    _asm { mov byte ptr ds:mem, imm }

#define MEM_WRITEIMM16(mem, imm)	 \
    _asm { mov word ptr ds:mem, imm }

#define MEM_WRITEIMM32(mem, imm)	 \
    _asm { mov dword ptr ds:mem, imm }


/**
 *  Fetch the value of a register into a C variable.
 */
#define VAR32_REG(type, name, reg) \
    type name; _asm { mov name, reg }

#define VAR8_REG(type, name, reg) \
    type name; _asm { mov name, reg }


/**
 *  Define a empty implementation of a function.
 * 
 *  In;
 *    - DLL Builds: This will define a jump back to the binary implementation.
 *    - Standalone: This will create an empty stub function, use the variadic argument
 *                  of these macros to define the return type or value if required.
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
        _asm { mov eax, address } \
        _asm { jmp eax } \
        _asm { _emit 0xCC } /* Align the jump */ \
        _asm { _emit 0xCC } \
    }

#define DEFINE_IMPLEMENTATION_INLINE(prototype, address, ...) \
    /*[[ noreturn ]]*/ inline __declspec(naked) \
    prototype \
    { \
        _asm { mov eax, address } \
        _asm { jmp eax } \
        _asm { _emit 0xCC } /* Align the jump */ \
        _asm { _emit 0xCC } \
    }

#define DEFINE_IMPLEMENTATION_UNWIND(prototype, address, ...) \
    /*[[ noreturn ]]*/ \
    prototype \
    { \
        _asm { mov eax, address } \
        _asm { jmp eax } \
        _asm { _emit 0xCC } /* Align the jump */ \
        _asm { _emit 0xCC } \
    }

#define DEFINE_IMPLEMENTATION_CONSTRUCTOR(prototype, address, ...) \
    /*[[ noreturn ]]*/ __declspec(noinline) \
    prototype \
    { \
        _asm { mov eax, address } \
        _asm { jmp eax } \
        _asm { _emit 0xCC } /* Align the jump */ \
        _asm { _emit 0xCC } \
    }


//
// Declare a patch hook.
//
#define DECLARE_PATCH(name) \
    [[ noreturn ]] __declspec(noinline) __declspec(naked) void name()


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
 *  Get the memory address of a function.
 */
template<typename T>
uintptr_t Get_Func_Address(T func)
{
    return reinterpret_cast<uintptr_t>((void*&)func);
}
