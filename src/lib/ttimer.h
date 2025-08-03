/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TTIMER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic templated timer systems.
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


class NoInitClass;


/**
 *  This is a timer class that watches a constant rate timer.
 */
template<class T>
class BasicTimerClass
{
public:
    BasicTimerClass(long set = 0);
    BasicTimerClass(const NoInitClass& x) {}
    ~BasicTimerClass() {}

    BasicTimerClass& operator=(const BasicTimerClass& that);
    BasicTimerClass& operator=(long set);

    long Value() const;

    operator long() const;
    long operator()() const;

protected:
    long Started;
    T Timer;
};


template<class T>
inline BasicTimerClass<T>::BasicTimerClass(long set) :
    Started(Timer() - set)
{
}


template<typename T>
BasicTimerClass<T>& BasicTimerClass<T>::operator=(const BasicTimerClass<T>& that)
{
    Started = that.Started;
    return *this;
}


template<typename T>
BasicTimerClass<T>& BasicTimerClass<T>::operator=(long set)
{
    Started = Timer();
    return *this;
}


template<class T>
inline long BasicTimerClass<T>::Value() const
{
    return Timer() - Started;
}


template<class T>
inline BasicTimerClass<T>::operator long() const
{
    return Timer() - Started;
}


template<class T>
inline long BasicTimerClass<T>::operator()() const
{
    return Timer() - Started;
}


/**
 *  This timer class that can be stopped and started.
 */
template<class T>
class TTimerClass : public BasicTimerClass<T>
{
    using BasicTimerClass<T>::Started;
    using BasicTimerClass<T>::Timer;

public:
    TTimerClass(long set = 0);
    TTimerClass(const NoInitClass& x);
    ~TTimerClass() {}

    long Value() const;

    operator long() const;
    long operator()() const;

    void Stop();
    void Start();
    bool Is_Active() const;

protected:
    long Accumulated;
};


template<class T>
inline TTimerClass<T>::TTimerClass(const NoInitClass& x) :
    BasicTimerClass<T>(x)
{
}


template<class T>
inline TTimerClass<T>::TTimerClass(long set) :
    BasicTimerClass<T>(set), Accumulated(0)
{
}


template<class T>
inline long TTimerClass<T>::Value() const
{
    long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
inline TTimerClass<T>::operator long() const
{
    long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
inline long TTimerClass<T>::operator()() const
{
    long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
void TTimerClass<T>::Stop()
{
    if (Started != 0xFFFFFFFFU) {
        Accumulated += BasicTimerClass<T>::operator long();
        Started = 0xFFFFFFFFU;
    }
}


template<class T>
void TTimerClass<T>::Start()
{
    if (Started == 0xFFFFFFFFU) {
        Started = Timer();
    }
}


template<class T>
inline bool TTimerClass<T>::Is_Active() const
{
    return Started != 0xFFFFFFFFU;
}


/**
 *  This timer counts down from the specified (or constructed) value down towards zero.
 */
template<class T>
class CDTimerClass : public BasicTimerClass<T>
{
    using BasicTimerClass<T>::Started;
    using BasicTimerClass<T>::Timer;

public:
    CDTimerClass(long set = 0);
    CDTimerClass(const NoInitClass& x);
    ~CDTimerClass() {}

    CDTimerClass& operator=(const CDTimerClass& that);
    CDTimerClass& operator=(long set);

    long Value() const;

    operator long() const;
    long operator()() const;

    void Stop();
    void Start();
    bool Is_Active() const;
    bool Expired() const { return Value() == 0; }

protected:
    long DelayTime;
};


template<class T>
inline CDTimerClass<T>::CDTimerClass(const NoInitClass& x) :
    BasicTimerClass<T>(x)
{
}


template<class T>
inline CDTimerClass<T>::CDTimerClass(long set) :
    BasicTimerClass<T>(0), DelayTime(set)
{
}


template<typename T>
CDTimerClass<T>& CDTimerClass<T>::operator=(const CDTimerClass<T>& that)
{
    BasicTimerClass<T>::operator=(that);
    DelayTime = that.DelayTime;
    return *this;
}


template<typename T>
CDTimerClass<T>& CDTimerClass<T>::operator=(long set)
{
    BasicTimerClass<T>::operator=(set);
    DelayTime = set;
    return *this;
}


template<class T>
inline long CDTimerClass<T>::Value() const
{
    long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return remain - value;
        } else {
            return 0;
        }
    }
    return remain;
}


template<class T>
inline CDTimerClass<T>::operator long() const
{
    long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return remain - value;
        } else {
            return 0;
        }
    }
    return remain;
}


template<class T>
inline long CDTimerClass<T>::operator()() const
{
    long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return remain - value;
        } else {
            return 0;
        }
    }
    return remain;
}


template<class T>
void CDTimerClass<T>::Stop()
{
    if (Started != 0xFFFFFFFFU) {
        DelayTime = *this;
        Started = 0xFFFFFFFFU;
    }
}


template<class T>
void CDTimerClass<T>::Start()
{
    if (Started == 0xFFFFFFFFU) {
        Started = Timer();
    }
}


template<class T>
inline bool CDTimerClass<T>::Is_Active() const
{
    return Started != 0xFFFFFFFFU;
}


/**
 *  This timer counts down from the specified (or constructed) value down
 *  towards zero at the rate specified.
 */
template<class T>
class ProgressTimerClass : public CDTimerClass<T>
{
    using BasicTimerClass<T>::Started;
    using BasicTimerClass<T>::Timer;

public:
    ProgressTimerClass(long set = 0, long rate = 0);
    ProgressTimerClass(const NoInitClass& x);
    ~ProgressTimerClass() {}

    ProgressTimerClass& operator=(const ProgressTimerClass& that);
    ProgressTimerClass& operator=(long set);

    long Value() const;

    float Percent_Expired() const;
    bool Expired() const { return Percent_Expired() == 1.0f; }

    long Get_Rate() const { return Rate; }

protected:
    long Rate;
};


template<class T>
inline ProgressTimerClass<T>::ProgressTimerClass(const NoInitClass& x) :
    CDTimerClass<T>(x)
{
}


template<class T>
inline ProgressTimerClass<T>::ProgressTimerClass(long set, long rate) :
    CDTimerClass<T>(set), Rate(rate)
{
}


template<typename T>
ProgressTimerClass<T>& ProgressTimerClass<T>::operator=(const ProgressTimerClass<T>& that)
{
    CDTimerClass<T>::operator=(that);
    Rate = that.Rate;
    return *this;
}


template<typename T>
ProgressTimerClass<T>& ProgressTimerClass<T>::operator=(long set)
{
    CDTimerClass<T>::operator=(set);
    Rate = set;
    return *this;
}


template<class T>
inline long ProgressTimerClass<T>::Value() const
{
    return Rate - CDTimerClass<T>::Value();
}


template<class T>
inline float ProgressTimerClass<T>::Percent_Expired() const
{
    long rate = Rate;
    if (!rate) {
        return 1.0f;
    }
    return (float)Value() / (float)rate;
}
