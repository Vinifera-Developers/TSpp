/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TAG.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Cell tag trigger object class.
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
#include "tibsun_defines.h"


class TagTypeClass;
class ObjectClass;
class TriggerClass;


class DECLSPEC_UUID("54F6E432-09ED-11D2-ACA5-006008055BB5")
TagClass : public AbstractClass
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
        TagClass(TagTypeClass *classof = nullptr);
        TagClass(const NoInitClass &noinit);
        virtual ~TagClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        bool Spring(TEventType event = TEVENT_ANY, ObjectClass *object = nullptr, Cell cell = INVALID_CELL, bool a4 = false, ObjectClass *source = nullptr);
        // 0061E750
        // 0061E7B0
        Cell Get_Cell() const; // 0061E810
        // 0061E820
        // 0061E830
        // 0061E840
        // 0061E850
        bool Is_Trigger_Attached(TriggerClass* trig);
        void Set_Cell(Cell cell); // 0061EA10
        // 0061EA20
        // 0061EA50
        // 0061EA60
        void Link_Trigger(TriggerClass *trig); // 0061EA70
        bool Unlink_Trigger(TriggerClass *trig); // 0061EA80
        // 0061EC60
        // 0061EC80
        // 0061ECB0
        // 0061ECE0

        TagTypeClass *const Class_Of() const { return Class; }
        
        const char *Name() const;

    public:
        TagTypeClass *Class;
        TriggerClass *AttachedTrigger;
        int AttachCount;
        Cell Location;
        bool IsDestroyed;
        bool IsSprung;
};
