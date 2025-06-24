/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBERIUM.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for tiberium types.
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

#include "abstracttype.h"
#include "priorityqueue.h"
#include "typelist.h"
#include "ttimer.h"
#include "ftimer.h"


class OverlayTypeClass;
class AnimTypeClass;


class DECLSPEC_UUID("C53DD373-151E-11D2-8175-006008055BB5")
TiberiumClass : public AbstractTypeClass
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
        IFACEMETHOD(GetSizeMax)(ULARGE_INTEGER *pcbSize);

    public:
        TiberiumClass(const char *ini_name = nullptr);
        TiberiumClass(const NoInitClass &noinit);
        virtual ~TiberiumClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        void Spread();
        // 006458F0
        // 00645A30
        // 00645BA0
        // 00645C30
        void Add_Spread_Cell(Cell &cell);

        // 00646080
        // 006463D0
        // 00646510
        // 00646680
        void Add_Growth_Cell(Cell &cell);

        static void Process(CCINIClass &ini);

        static void Spread_AI();
        static void Spread_Init_Clear();

        static void Growth_Init_Clear();
        static void Growth_AI();
        static void Grow();

        static void Init_Cells();
        static void Init();

        static const TiberiumClass &As_Reference(TiberiumType type);
        static const TiberiumClass *As_Pointer(TiberiumType type);
        static const TiberiumClass &As_Reference(const char *name);
        static const TiberiumClass *As_Pointer(const char *name);
        static TiberiumType From_Name(const char *name);
        static const char *Name_From(TiberiumType type);
        static const TiberiumClass* Find_Or_Make(const char* name);

    public:
        TiberiumType HeapID;
        int SpreadDelay;
        double SpreadPercentage;
        int GrowthDelay;
        double GrowthPercentage;
        int CreditValue;
        int Power;
        int Color;
        TypeList<AnimTypeClass *> Debris;
        OverlayTypeClass *Overlay;
        int FrameCount;
        int Variety;
        int RampVariety;
        int SpreadCount;
        PriorityQueueClass<Cell, float> *SpreadQueue;
        bool *SpreadState;
        PriorityQueueClassNode<Cell, float> *SpreadNodes;
        CDTimerClass<FrameTimerClass> SpreadTimer;
        int GrowthCount;
        PriorityQueueClass<Cell, float> *GrowthQueue;
        bool *GrowthState;
        PriorityQueueClassNode<Cell, float> *GrowthNodes;
        CDTimerClass<FrameTimerClass> GrowthTimer;
};
