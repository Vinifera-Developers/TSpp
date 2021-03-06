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
        BasicTimerClass(unsigned long set = 0);
        BasicTimerClass(const NoInitClass &x) {}
        ~BasicTimerClass() {}

        BasicTimerClass & operator=(const BasicTimerClass &that);
        BasicTimerClass & operator=(unsigned long set);

        unsigned long Value() const;

        operator unsigned long() const;
        unsigned long operator () () const;

    protected:
        unsigned long Started;
        T Timer;
};


template<class T>
inline BasicTimerClass<T>::BasicTimerClass(unsigned long set) :
    Started(Timer() - set)
{
}


template<typename T>
BasicTimerClass<T> &BasicTimerClass<T>::operator=(const BasicTimerClass<T> &that)
{
    Started = that.Started;
    return *this;
}


template<typename T>
BasicTimerClass<T> &BasicTimerClass<T>::operator=(unsigned long set)
{
    Started = Timer();
    return *this;
}


template<class T>
inline unsigned long BasicTimerClass<T>::Value() const
{
    return Timer() - Started;
}


template<class T>
inline BasicTimerClass<T>::operator unsigned long() const
{
    return Timer() - Started;
}


template<class T>
inline unsigned long BasicTimerClass<T>::operator () () const
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
        TTimerClass(unsigned long set = 0);
        TTimerClass(const NoInitClass & x);
        ~TTimerClass() {}

        unsigned long Value() const;

        operator unsigned long() const;
        unsigned long operator () () const;

        void Stop();
        void Start();
        bool Is_Active() const;

    private:
        unsigned long Accumulated;
};


template<class T>
inline TTimerClass<T>::TTimerClass(const NoInitClass & x) :
    BasicTimerClass<T>(x)
{
}


template<class T>
inline TTimerClass<T>::TTimerClass(unsigned long set) :
    BasicTimerClass<T>(set),
    Accumulated(0)
{
}


template<class T>
inline unsigned long TTimerClass<T>::Value() const
{
    unsigned long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
inline TTimerClass<T>::operator unsigned long() const
{
    unsigned long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
inline unsigned long TTimerClass<T>::operator () () const
{
    unsigned long value = Accumulated;
    if (Started != 0xFFFFFFFFU) {
        value += BasicTimerClass<T>::Value();
    }
    return value;
}


template<class T>
void TTimerClass<T>::Stop()
{
    if (Started != 0xFFFFFFFFU) {
        Accumulated += BasicTimerClass<T>::operator unsigned long();
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
        CDTimerClass(unsigned long set=0);
        CDTimerClass(const NoInitClass & x);
        ~CDTimerClass() {}

        CDTimerClass & operator=(const CDTimerClass &that);
        CDTimerClass & operator=(unsigned long set);

        unsigned long Value() const;

        operator unsigned long() const;
        unsigned long operator () () const;

        void Stop();
        void Start();
        bool Is_Active() const;
        bool Expired() const { return Value() == 0; }

    protected:
        unsigned long DelayTime;
};


template<class T>
inline CDTimerClass<T>::CDTimerClass(const NoInitClass & x) :
    BasicTimerClass<T>(x)
{
}


template<class T>
inline CDTimerClass<T>::CDTimerClass(unsigned long set) :
    BasicTimerClass<T>(0),
    DelayTime(set)
{
}


template<typename T>
CDTimerClass<T> &CDTimerClass<T>::operator=(const CDTimerClass<T> &that)
{
    BasicTimerClass<T>::operator=(that);
    DelayTime = that.DelayTime;
    return *this;
}


template<typename T>
CDTimerClass<T> &CDTimerClass<T>::operator=(unsigned long set)
{
    BasicTimerClass<T>::operator=(set);
    DelayTime = set;
    return *this;
}


template<class T>
inline unsigned long CDTimerClass<T>::Value() const
{
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return remain - value;
        } else {
            return 0;
        }
    }
    return remain;
}


template<class T>
inline CDTimerClass<T>::operator unsigned long() const
{
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return remain - value;
        } else {
            return 0;
        }
    }
    return remain;
}


template<class T>
inline unsigned long CDTimerClass<T>::operator () () const
{
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
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
class RateTimerClass : public BasicTimerClass<T>
{
    using BasicTimerClass<T>::Started;
    using BasicTimerClass<T>::Timer;

    public:
        RateTimerClass(unsigned long set = 0);
        RateTimerClass(const NoInitClass & x);
        ~RateTimerClass() {}

        RateTimerClass & operator=(const RateTimerClass &that);
        RateTimerClass & operator=(unsigned long set);

        unsigned long Value() const;

        operator unsigned long() const;
        unsigned long operator () () const;

        void Stop();
        void Start();
        bool Is_Active() const;
        bool Expired() const { return Value() == 0; }
        float Percent_Expired() const;

        unsigned long Rate() const { return TimerRate; }

    protected:
        unsigned long DelayTime;
        unsigned long TimerRate;
};


template<class T>
inline RateTimerClass<T>::RateTimerClass(const NoInitClass &x) :
    BasicTimerClass<T>(x)
{
}


template<class T>
inline RateTimerClass<T>::RateTimerClass(unsigned long set) :
    BasicTimerClass<T>(0),
    DelayTime(set),
    TimerRate(set)
{
}


template<typename T>
RateTimerClass<T> &RateTimerClass<T>::operator=(const RateTimerClass<T> &that)
{
    BasicTimerClass<T>::operator=(that);
    DelayTime = that.DelayTime;
    TimerRate = that.TimerRate;
    return *this;
}


template<typename T>
RateTimerClass<T> &RateTimerClass<T>::operator=(unsigned long set)
{
    BasicTimerClass<T>::operator=(set);
    DelayTime = set;
    TimerRate = set;
    return *this;
}


template<class T>
inline unsigned long RateTimerClass<T>::Value() const
{
    unsigned long rate = TimerRate;
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return (rate - (remain - (value - Started))) / rate;
        } else {
            return 0;
        }
    }
    return (rate - remain / rate);
}


template<class T>
inline RateTimerClass<T>::operator unsigned long() const
{
    unsigned long rate = TimerRate;
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return (rate - (remain - (value - Started))) / rate;
        } else {
            return 0;
        }
    }
    return (rate - remain / rate);
}


template<class T>
inline unsigned long RateTimerClass<T>::operator () () const
{
    unsigned long rate = TimerRate;
    unsigned long remain = DelayTime;
    if (Started != 0xFFFFFFFFU) {
        unsigned long value = BasicTimerClass<T>::Value();
        if (value < remain) {
            return (rate - (remain - (value - Started))) / rate;
        } else {
            return 0;
        }
    }
    return (rate - remain / rate);
}


template<class T>
inline float RateTimerClass<T>::Percent_Expired() const
{
    unsigned long rate = TimerRate;
    if (!rate) {
        return 1.0;
    }
    return (float)(rate - Value()) / (float)rate;
}


template<class T>
void RateTimerClass<T>::Stop()
{
    if (Started != 0xFFFFFFFFU) {
        DelayTime = *this;
        Started = 0xFFFFFFFFU;
    }
}


template<class T>
void RateTimerClass<T>::Start()
{
    if (Started == 0xFFFFFFFFU) {
        Started = Timer();
    }
}


template<class T>
inline bool RateTimerClass<T>::Is_Active() const
{
    return Started != 0xFFFFFFFFU;
}
