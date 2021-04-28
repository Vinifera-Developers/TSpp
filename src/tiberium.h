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
        struct TiberiumCellHeader
        {
            CellStruct Data;
            float Key;
        };

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
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        void Process(CCINIClass &ini);

        void Spread_AI();
        void Spread_Init_Clear();
        void Spread();
        // 006458F0
        // 00645A30
        // 00645BA0
        // 00645C30
        void Add_Spread_Cell(CellStruct &cell);

        void Growth_AI();
        void Growth_Init_Clear();
        void Grow();
        // 00646080
        // 006463D0
        // 00646510
        // 00646680
        void Add_Growth_Cell(CellStruct &cell);

        static void Init_Cells();
        static void Init();

    public:
        TiberiumType Type;
        int SpreadCells;
        double SpreadPercentage;
        int GrowthCells;
        double GrowthPercentage;
        int Value;
        int Power;
        int Color;
        TypeList<AnimTypeClass *> Debris;
        OverlayTypeClass *Image;
        int NumFrames;
        int NumImages;
        int NumSlopeFacings;
        int SpreadCount;
        PriorityQueueClass<TiberiumCellHeader> *SpreadHeaps;
        bool *SpreadState;
        TiberiumCellHeader *SpreadCellData;
        CDTimerClass<FrameTimerClass> SpreadTimer;
        int GrowthCount;
        PriorityQueueClass<TiberiumCellHeader> *GrowthHeaps;
        bool *GrowthState;
        TiberiumCellHeader *GrowthCellData;
        CDTimerClass<FrameTimerClass> GrowthTimer;
};
