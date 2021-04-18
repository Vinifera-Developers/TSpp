/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CRITSECTION.H
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
#pragma once

#include "always.h"
#include <atomic>
#include <Windows.h>


/*******************************************************************************
 *  @class   SimpleCriticalSectionClass
 *
 *  @brief   Simple critical sections are a thin cross platform wrapper around WinAPI
 *           critical sections or pthreads recursive mutexes which perform the same
 *           function and behave similarly. Create a SimpleCriticalSectionClass object
 *           that can be access by the threads that need shared access to some resource
 *           and have them call Enter to get a lock before manipulating the shared
 *           resource and then call Leave after it is done. Try_Enter can be used to
 *           test for a lock and selectively manipulate shared data based on if the lock
 *           is available.
 */
class SimpleCriticalSectionClass
{
    public:
        SimpleCriticalSectionClass();
        virtual ~SimpleCriticalSectionClass();

        void Enter();
        bool Try_Enter();
        void Leave();

    protected:
        SimpleCriticalSectionClass &operator=(const SimpleCriticalSectionClass &that) { return *this; }

    private:
        CRITICAL_SECTION Handle;
};


class ScopedCriticalSectionClass
{
    public:
        ScopedCriticalSectionClass(SimpleCriticalSectionClass *cs) :
            CritSection(cs)
        {
            if (cs != nullptr) {
                //printf("Entering CriticalSection from scoped lock\n");
                CritSection->Enter();
            }
        }

        virtual ~ScopedCriticalSectionClass()
        {
            if (CritSection != nullptr) {
                //printf("Leaving CriticalSection from scoped lock\n");
                CritSection->Leave();
            }
        }

    private:
        SimpleCriticalSectionClass *CritSection;
};


/*******************************************************************************
 *  @class   CriticalSectionClass
 *
 *  @brief   Critical section wraps WinAPI critical sections or pthreads recursive
 *           mutexes to create an automatically unlocking lock that can allow safe
 *           sharing of data between threads. To obtain a lock, a lock object is created
 *           with the a shared critical section object being passed to it. The lock
 *           object constructor will perform the lock and then the destructor will unlock
 *           it automatically when the lock object goes out of scope or the destructor
 *           is called manually as per RAII programming methodology.
 */
class CriticalSectionClass
{
    public:
        CriticalSectionClass();
        ~CriticalSectionClass();

        class LockClass
        {
        public:
            // In order to enter a critical section create a local instance of LockClass with critical section as a parameter.
            LockClass(CriticalSectionClass &critical_section) : CriticalSection(critical_section) { CriticalSection.Lock(); }
            ~LockClass() { CriticalSection.Unlock(); }

        private:
            LockClass &operator=(const LockClass &that) { return *this; }
            CriticalSectionClass &CriticalSection;
        };

        friend class LockClass;

    private:
        // Lock and unlock are private, you have to create a
        // CriticalSectionClass::LockClass object to call them instead.
        void Lock();
        void Unlock();

        bool Is_Locked() { return Locked > 0; }

    private:
        CRITICAL_SECTION Handle;
        unsigned int Locked;
};


/*******************************************************************************
 *  @class   FastCriticalSectionClass
 *
 *  @brief   Fast critical section uses compiler intrinsics to create an automatically
 *           unlocking lock that can allow safe sharing of data between threads. It is
 *           used the same as the normal CriticalSectionClass but can only lock once
 *           and is an acquisition barrier only.
 */
class FastCriticalSectionClass
{
    public:
        FastCriticalSectionClass() { Flag.clear(); }
        ~FastCriticalSectionClass() {}

        class LockClass
        {
        public:
            LockClass(FastCriticalSectionClass &critical_section) : CriticalSection(critical_section)
            {
                CriticalSection.Thread_Safe_Set_Flag();
            }

            ~LockClass() { CriticalSection.Thread_Safe_Clear_Flag(); }

        private:
            LockClass &operator=(const LockClass &that) { return *this; }
            FastCriticalSectionClass &CriticalSection;
        };

        friend class LockClass;

    private:
        void Thread_Safe_Set_Flag();
        void Thread_Safe_Clear_Flag();

    private:
        std::atomic_flag Flag;
};
