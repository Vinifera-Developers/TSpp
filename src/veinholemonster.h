/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VEINHOLEMONSTER.H
 *
 *  @author        CCHyper, tomsons26
 *
 *  @brief         Veinhole monster instance.
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
#include "object.h"
#include "priorityqueue.h"
#include "ttimer.h"
#include "ftimer.h"


class DECLSPEC_UUID("5192D06A-C632-11D2-B90B-006008C809ED")
VeinholeMonsterClass : public ObjectClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

    public:
        VeinholeMonsterClass(Cell cell);
        VeinholeMonsterClass(const NoInitClass &noinit);
        virtual ~VeinholeMonsterClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual LayerType In_Which_Layer() const override;
        virtual const ObjectTypeClass * Class_Of() const override;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false) override;

        static VeinholeMonsterClass* Fetch_At(const Cell& cell);
        // 00661380
        // 00661A30
        // 00661C10
        // 00661D60
        // 00662170
        static void Place_Veinhole_Monsters(bool clear);
        // 00662650
        // 006626F0
        // 00662BA0
        // 00662D50
        // 00662D70
        // 00662DE0
        // 00662EE0
        // 006633C0

        static bool Load_All(IStream *pStm);
        static bool Save_All(IStream *pStm);
        // 006619F0
        static void Init_Clear();
        static void Draw_All();
        static void Update_All();

    public:
        int field_4C;
        PriorityQueueClass<Cell, float> *VeinCellQueue;
        PriorityQueueClassNode<Cell, float> *VeinCellNodes;
        CDTimerClass<FrameTimerClass> field_58; // growth rate timer?
        int field_64;
        int field_68;
        int field_6C;
        int field_70;
        CDTimerClass<FrameTimerClass> field_74;
        int field_80;
        int field_84;
        CDTimerClass<FrameTimerClass> field_88;
        Cell MonsterCell;
        int ShapeFrame;
        bool IsToShrink;
        bool IsToPuffGas;
        int field_A0;
};
