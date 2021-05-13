/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SMUGETYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for smudge types.
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

#include "objecttype.h"
#include "tibsun_defines.h"


class DECLSPEC_UUID("5AF2CE78-0634-11D2-ACA4-006008055BB5")
SmudgeTypeClass : public ObjectTypeClass
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
        SmudgeTypeClass(const char *ini_name = nullptr);
        SmudgeTypeClass(const NoInitClass &noinit);
        virtual ~SmudgeTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;

        /**
         *  SmudgeTypeClass
         */
		virtual void Draw_It(Point2D &xy, Rect &a2, int index, int a4, Cell &cell) const;

        bool Can_Place_Here(Cell &cell, bool a3);
        void Place(Cell &cell);

        static bool Create_Scorch(Coordinate &coord, int width, int height, bool a4);
        static bool Create_Crater(Coordinate &coord, int width, int height, bool a4);
        static void Init(TheaterType theater = THEATER_TEMPERATE);

        static const SmudgeTypeClass &As_Reference(SmudgeType type);
        static const SmudgeTypeClass *As_Pointer(SmudgeType type);
        static const SmudgeTypeClass &As_Reference(const char *name);
        static const SmudgeTypeClass *As_Pointer(const char *name);
        static SmudgeType From_Name(const char *name);
        static const char *Name_From(SmudgeType type);
        static const SmudgeTypeClass *Find_Or_Make(const char *name);

    public:
		SmudgeType Type;
		int Width;
		int Height;
        bool IsCrater;
        bool IsScorch;
};
