/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ALPHASHAPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Alpha shape object class.
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
#include "rect.h"


class DECLSPEC_UUID("623C7584-74E7-11D2-B8F5-006008C809ED")
AlphaShapeClass : public AbstractClass
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
        AlphaShapeClass();
        AlphaShapeClass(AbstractClass * target, int width, int height);
        AlphaShapeClass(NoInitClass &noinit);
        virtual ~AlphaShapeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool a1 = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        // 0x00412A90
        // 0x00412B40
        // 0x00412F70
        // 0x004132D0

    public:
        AbstractClass * AttachedTo;
        Rect Size;
        ShapeFileStruct *Image;
        bool field_2C;
};
