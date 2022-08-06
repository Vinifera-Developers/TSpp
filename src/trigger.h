/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TRIGGER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Trigger game object class.
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
#include "tevent.h"
#include "ttimer.h"
#include "ftimer.h"


class ObjectClass;
class TechnoClass;
class TriggerTypeClass;


class DECLSPEC_UUID("C02D1590-0A2A-11D2-ACA7-006008055BB5")
TriggerClass : public AbstractClass
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
        TriggerClass();
        TriggerClass(TriggerTypeClass *classof);
        TriggerClass(const NoInitClass &noinit);
        virtual ~TriggerClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        bool Spring(TEventType event = TEVENT_ANY, ObjectClass *object = nullptr, bool a4 = false, bool a5 = false, ObjectClass *source = nullptr);
        void Reset();
        // 006495E0
        // 00649290
        // 006492D0
        // 00649310
        // 00649350
        // 00649390
        // 006493E0
        // 00649410
        void Set_Tripped(int event_index);
        void Clear_Tripped(int event_index);
        bool Is_Tripped(int event_index);
        // 00649730
        // 00649790
        void Enable();
        void Disable();

        TriggerTypeClass *const Class_Of() const { return Class; }
        
        const char *Name() const;

    public:
        TriggerTypeClass *Class;
        TriggerClass *Next;
        bool IsDestroyed;
        TDEventClass Event;
        int IsTripped;
        bool IsEnabled;
};
