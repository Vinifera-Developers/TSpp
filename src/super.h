/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SUPER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Special weapon handler.
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
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class HouseClass;
class SuperWeaponTypeClass;


class DECLSPEC_UUID("D7F754C6-391C-11D2-9B64-00104B972FE8")
SuperClass : public AbstractClass
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

        /**
         *  IRTTITypeInfo
         */
        IFACEMETHOD_(int, What_Am_I)();

	public:
		SuperClass();
		SuperClass(const SuperWeaponTypeClass *classof, HouseClass *house);
		SuperClass(const NoInitClass & x);
		virtual ~SuperClass();

		/**
		 *  AbstractClass
		 */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

		bool AI(bool player = false);

		bool Suspend(bool on);
		bool Enable(bool onetime = false, bool player = false, bool quiet = false);
		void Forced_Charge(bool player = false);
		bool Remove();
		bool Recharge(bool player = false);
		void Impatient_Click() const;
		int Anim_Stage() const;
		bool Discharged(bool player, Cell *cell);
		const char *Ready_String() const;
		bool Is_Ready() const;
		void Set_Readiness(bool ready) { IsReady = ready; }
		bool Is_Present() const { return IsPresent; }
		bool Is_One_Time() const { return IsOneTime && IsPresent; }
		bool Is_Powered() const;
		/*bool Time_To_Redraw() const
		{
			if (Class->IsUseChargeDrain) {
				return true;
			}
			return !IsReady;
		}*/
		/*void Set_Recharge_Time(int time)
		{
			if (IsPresent) {
				if (time >= 0 && time <= 100) {
					int rate = Class->RechargeTime - (time * 0.010f * Class->RechargeTime);
					if (!rate) {
						IsReady = true;
					}
					Control = rate;
				}
			}
		}*/

		void Place(Cell *cell, bool player = false);

	public:
		SuperWeaponTypeClass *Class;
		HouseClass *House;
		CDTimerClass<FrameTimerClass> Control;
		bool field_28;
		bool IsPresent;
		bool IsOneTime;
		bool IsReady;
		bool IsSuspended;
		int OldStage;
		int field_34;
};
