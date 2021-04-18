/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CRITSECTION.CPP
 *
 *  @authors       OmniBlade, CCHyper
 *
 *  @brief         Classes providing critical section behavior.
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
