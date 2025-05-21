/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OVERLAY.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Overlay game object class.
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

#include "object.h"
#include "tibsun_defines.h"


class OverlayTypeClass;
class CCINIClass;


class DECLSPEC_UUID("0E272DC7-9C0F-11D1-B709-00A024DDAFD1")
OverlayClass : public ObjectClass
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
        OverlayClass(OverlayTypeClass *classof = nullptr, Cell &pos = INVALID_CELL, HousesType house = HOUSE_NONE);
        OverlayClass(const NoInitClass &noinit);
        virtual ~OverlayClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;

        /**
         *  ObjectClass
         */
        virtual const ObjectTypeClass * Class_Of() const override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual void Placement_Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_UP_FORCED) override;

        // 0058C850
        static TiberiumType To_TiberiumType(OverlayType overlay);
        static void Place_All_Veins();

        static void Read_INI(CCINIClass &ini);
        static void Write_INI(CCINIClass &ini);

    public:
        OverlayTypeClass *Class;
};
