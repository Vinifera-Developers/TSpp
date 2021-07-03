/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TOGGLE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Gadgets that behave like the Windows buttons.
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

#include "control.h"


class ToggleClass : public ControlClass
{
    public:
        ToggleClass(unsigned id, int x, int y, int w, int h);
        ~ToggleClass();

        virtual bool Action(unsigned flags, KeyNumType &key) override;

        void Turn_On();
        void Turn_Off();

    public:
        bool IsPressed;
        bool IsOn;
        bool IsToggleType;
};
