/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SLIDER.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Like a Windows Slider structure.
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

#include "gauge.h"


class ShapeButtonClass;


class SliderClass : public GaugeClass
{
    public:
        SliderClass(unsigned id, int x, int y, int w, int h, bool belong_to_list = false);
        virtual ~SliderClass();

        virtual void Peer_To_Peer(unsigned flags, KeyNumType &key, ControlClass &whom) override;
        virtual bool Draw_Me(bool forced = false) override;
        virtual bool Action(unsigned flags, KeyNumType &key) override;

        virtual int Set_Maximum(int value);
        virtual int Set_Value(int value);
        virtual int Thumb_Pixels();
        virtual void Draw_Thumb();
        virtual void Set_Thumb_Size(int value);
        virtual int Bump(bool up);
        virtual int Step(bool up);

        void Recalc_Thumb();

    protected:
        ShapeButtonClass *PlusGadget;
        ShapeButtonClass *MinusGadget;
        bool BelongToList;
        int Thumb;
        int ThumbSize;
        int ThumbStart;
};
