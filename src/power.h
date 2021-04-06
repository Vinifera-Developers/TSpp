/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          POWER.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game powerbar interface.
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

#include "radar.h"
#include "ttimer.h"


class PowerClass : public RadarClass
{
    public:
        PowerClass();
        PowerClass(const NoInitClass &x);
        ~PowerClass();

        /**
         *  GScreenClass
         */
		virtual void One_Time() override;
		virtual void Init_Clear() override;
		virtual void AI(KeyNumType &input, Point2D &xy) override;
        virtual void Draw_It(bool forced = false) override;

        /**
         *  DisplayClass
         */
		virtual void Help_Text(int text) override;
        virtual void entry_84() override;

		/**
		 *  RadarClass
		 */
        virtual void Init_For_House() override;

		// 005AB100
		// 005AB140
		// 005AB1F0
		// 005AB240
		// 005AB260
		// 005AB6E0
		// 005AB750

		void Redraw_Power() { IsToRedraw = true; Flag_To_Redraw(false); }

    public:
		bool IsToRedraw;
		CDTimerClass<SystemTimerClass> FlashTimer;
		int field_1504;
		CDTimerClass<SystemTimerClass> field_1508;
		int field_1514;
		int field_1518;
		int field_151C;
		bool field_1520;
		int RecordedPower;
		int RecordedDrain;
};
