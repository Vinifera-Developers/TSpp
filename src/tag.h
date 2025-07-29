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

        void Mark_To_Die();
        bool Is_Marked_To_Die() const;

        bool Is_Horizontal_Cross() const;
        __declspec(property(get = Is_Horizontal_Cross)) bool IsHorizontalCross;

        bool Is_Vertical_Cross() const;
        __declspec(property(get = Is_Vertical_Cross)) bool IsVerticalCross;

        bool Is_Enters_Zone() const;
        __declspec(property(get = Is_Enters_Zone)) bool IsEntersZone;

        bool Is_Allow_Win() const;
        __declspec(property(get = Is_Allow_Win)) bool IsAllowWin;

        bool Is_Transferable() const;
        __declspec(property(get = Is_Transferable)) bool IsTransferable;

        void Timer_Global_Reset(int global);
        void Timer_Local_Reset(int local);

        bool Is_Trigger_Attached(TriggerClass* trig) const;
        bool Spring(TEventType event = TEVENT_ANY, ObjectClass* object = nullptr, Cell cell = CELL_NONE, bool forced = false, TechnoClass* source = nullptr);

        Cell Get_Position() const;
        void Set_Position(Cell cell);

        static void All_Timer_Global_Reset(int global);
        static void All_Timer_Local_Reset(int local);

        void Link(TriggerClass* trigger);
        bool Unlink(TriggerClass* trigger);

        bool Is_One_Of_A_Kind();

    public:
        TagTypeClass *Class;
        TriggerClass *Trigger;
        int AttachCount;
        Cell CellID;
        bool IsToDie;
        bool IsSprung;
};
