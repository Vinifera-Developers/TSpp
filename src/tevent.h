/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEVENT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Map trigger events.
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

#include "abstract.h"
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class NoInitClass;
class ObjectClass;
class TechnoClass;
class TeamTypeClass;


class DECLSPEC_UUID("4F0EC393-0A55-11D2-ACA7-006008055BB5")
TEventClass : public AbstractClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

    public:
        TEventClass();
        TEventClass(TEventType event);
        TEventClass(const NoInitClass &noinit);
        ~TEventClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = false) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        void Read_INI();
        void Build_INI_Entry(char* buffer) const;
        
        bool Is_Temporal() const;
        bool Has_Memory() const;

        bool operator () (TEventType event, HouseClass* house, const ObjectClass* object, CDTimerClass<FrameTimerClass>& timer, bool& is_perm, TechnoClass* source);

        static const char *Event_Name(TEventType event);
        static const char *Event_Description(TEventType event);

    public:
        int HeapID;
        TEventClass *Next;
        TEventType Event;
        TeamTypeClass *Team;

        union {
            StructType Structure;
            UnitType Unit;
            InfantryType Infantry;
            AircraftType Aircraft;
            HousesType House;
            float Float;
            long Value;
        } Data;

    private:
        struct EventDescriptionStruct
        {
            char const *Name;
            char const *Description;
        };

        static EventDescriptionStruct EventDescriptions[TEVENT_COUNT];
};

NeedType Event_Needs(TEventType event);
AttachType Attaches_To(TEventType event);

