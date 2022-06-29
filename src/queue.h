/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          QUEUE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         FIFO queue for events.
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
#include "target.h"
#include "ttimer.h"
#include "ftimer.h"


class ConnManClass;
class EventClass;


template<class T, int size>
class QueueClass
{
    public:
        QueueClass();
        ~QueueClass() {}

        T & operator[](int index);

        T & First();
        void Init();
        int Next();
        bool Add(const T &q);

        int Get_Head();
        int Get_Tail();
        T * Get_Array();

    public:
        int Count;

    private:
        int Head;
        int Tail;
        T Array[size];
};


template<class T, int size>
inline QueueClass<T, size>::QueueClass() :
    Count(0)
{
    Init();
}


template<class T, int size>
inline void QueueClass<T, size>::Init()
{
    Count = 0;
    Head = 0;
    Tail = 0;
}


template<class T, int size>
inline bool QueueClass<T, size>::Add(const T &q)
{
    if (Count >= size) {
        //OutputDebugString("QueueClass::Add() - Failed! (Count:%d, Capacity:%d, Tail:%d, Head:%d).\n", Count, size, Tail, Head);
        return false;
    }

    if (Count < size) {
        Array[Tail] = q;
        Tail = (Tail + 1) & (size-1);
        Count = Count + 1;
        return true;
    }
    return false;
}


template<class T, int size>
inline int QueueClass<T, size>::Next()
{
    if (Count) {
        Head = (Head + 1) & (size-1);
        Count = Count - 1;
    }
    return Count;
}


template<class T, int size>
inline T & QueueClass<T, size>::operator[](int index)
{
    return Array[(Head + index) & (size-1)];
}


template<class T, int size>
inline T & QueueClass<T, size>::First()
{
    return Array[Head];
}


template<class T, int size>
inline int QueueClass<T, size>::Get_Head()
{
    return Head;
}


template<class T, int size>
inline int QueueClass<T, size>::Get_Tail()
{
    return Tail;
}


template<class T, int size>
inline T * QueueClass<T, size>::Get_Array()
{
    return Array;
}


typedef struct FrameStatsStruct
{
    long Frame;
    long Recv;
    long Send;
    long field_C;   // Timing value, set by FRAME_SYNC.
} FrameStatsStruct;

typedef enum RetcodeEnum {
    RC_NORMAL,
    RC_PLAYER_READY,
    RC_SCENARIO_MISMATCH,
    RC_DOLIST_FULL,
    RC_SERIAL_PROCESSED,
    RC_PLAYER_LEFT,
    RC_HUNG_UP,
    RC_NOT_RESPONDING,
    RC_8,
    RC_9,
} RetcodeType;


bool Queue_Mission(MissionType mission, TargetClass &target, TargetClass whom, TargetClass &destination);
bool Queue_Mission(MissionType mission, TargetClass &target, TargetClass whom, TargetClass &destination, SpeedType speed, MPHType maxspeed);
bool Queue_Options();
bool Queue_PageUser();
bool Queue_Exit();
void Queue_AI();
void Queue_AI_Multiplayer();
void Wait_To_Exit();
RetcodeType Wait_For_Players(int first_time, ConnManClass *net, int resend_delta, int dialog_time, int timeout, char *multi_packet_buf, unsigned short my_sent, FrameStatsStruct *their);
unsigned short Send_Packets(ConnManClass *net, char *multi_packet_buf, int multi_packet_max, int max_ahead, unsigned short my_sent);
void Send_FrameSync(ConnManClass *net, unsigned short cmd_count);
RetcodeType Process_Receive_Packet(ConnManClass *net, char *multi_packet_buf, int id, int packetlen, FrameStatsStruct *their, CDTimerClass<SystemTimerClass> *timer);
RetcodeType Process_Serial_Packet(char *multi_packet_buf, int first_time);
void Kick_Player_Now(ConnManClass *net, int index, FrameStatsStruct *their, bool error);
void Propose_Kick_Player(HWND hDlg, int local_id);
int Handle_Timeout(ConnManClass *net, FrameStatsStruct *their);
int Add_Compressed_Events(void *buf, int bufsize, int frame_delay, int size, int cap, int &new_size);
int Extract_Compressed_Events(void *buf, int bufsize);
int Execute_DoList(int max_houses, HousesType base_house, ConnManClass *net, CDTimerClass<FrameTimerClass> *skip_crc, FrameStatsStruct *their);
void Clean_DoList(ConnManClass *net);
void Queue_Record();
void Compute_Game_CRC();
void Add_CRC(unsigned long *crc, unsigned long val);
void Print_CRCs(EventClass *ev);
void Dump_Packet_Too_Late_Stuff(EventClass *event);
void Check_Mirror();
