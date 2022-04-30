/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ISOTILE.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Isometric tile objects.
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
#include "tibsun_defines.h"


class IsometricTileTypeClass;


class DECLSPEC_UUID("0E272DC0-9C0F-11D1-B709-00A024DDAFD1")
IsometricTileClass : public ObjectClass
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
        IsometricTileClass(IsometricTileType type, Cell &cell);
        IsometricTileClass(const NoInitClass &noinit);
        virtual ~IsometricTileClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;

        /**
         *  ObjectClass
         */
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(Coordinate &coord, DirType dir = DIR_N) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        
        operator IsometricTileType () const;

    public:
        IsometricTileTypeClass *Class;
};
