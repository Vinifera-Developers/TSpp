/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Classes providing critical section behavior.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "critsection.h"


SimpleCriticalSectionClass::SimpleCriticalSectionClass() :
    Handle()
{
    InitializeCriticalSection(&Handle);
}


SimpleCriticalSectionClass::~SimpleCriticalSectionClass()
{
    DeleteCriticalSection(&Handle);
}


void SimpleCriticalSectionClass::Enter()
{
    EnterCriticalSection(&Handle);
}


bool SimpleCriticalSectionClass::Try_Enter()
{
    return TryEnterCriticalSection(&Handle) != FALSE;
}


void SimpleCriticalSectionClass::Leave()
{
    LeaveCriticalSection(&Handle);
}


CriticalSectionClass::CriticalSectionClass() :
    Handle(),
    Locked(0)
{
    InitializeCriticalSection(&Handle);
}


CriticalSectionClass::~CriticalSectionClass()
{
    DeleteCriticalSection(&Handle);
}


/**
 *  Performs the lock when entering a critical section of code. Private and is only called from the Lock object.
 */
void CriticalSectionClass::Lock()
{
    EnterCriticalSection(&Handle);

    ++Locked;
}


/**
 *  Removes the lock when leaving a critical section of code. Private and is only called from the Lock object.
 */
void CriticalSectionClass::Unlock()
{
    LeaveCriticalSection(&Handle);

    --Locked;
}


/**
 *  Performs the lock when entering a critical section of code. Private and is only called from the Lock object.
 */
void FastCriticalSectionClass::Thread_Safe_Set_Flag()
{
    while (Flag.test_and_set(std::memory_order_seq_cst)) {

        /**
         *  Yield the thread if no lock acquired.
         */
        Sleep(1);
    }
}


/**
 *  Removes the lock when leaving a critical section of code. Private and is only called from the Lock object.
 */
void FastCriticalSectionClass::Thread_Safe_Clear_Flag()
{
    Flag.clear();
}
