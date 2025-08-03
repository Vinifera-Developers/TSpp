/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONTROL.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         The gui region tracking class.
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

#include "gadget.h"


class ControlClass : public GadgetClass
{
public:
    ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags = LEFTPRESS | RIGHTPRESS, bool sticky = false);
    ControlClass(const ControlClass& control);
    ControlClass(const NoInitClass& x);

    virtual void Make_Peer(GadgetClass& gadget);
    virtual bool Draw_Me(bool forced = false) override;
    virtual unsigned Get_ID() const override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

public:
    unsigned ID;
    GadgetClass* Peer;
};
