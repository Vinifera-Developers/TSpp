/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RADIO.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Radio contact between game objects.
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

#include "mission.h"


extern long &LParam;


/*******************************************************************************
 *	Radio contact is controlled by this class. It handles the mundane chore
 *	of keeping the radio contact alive as well as broadcasting messages
 *	to the receiving radio. Radio contact is primarily used when one object
 *	is in "command" of another.
 */
class RadioClass : public MissionClass
{
    public:
        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);

	public:
		RadioClass();
		RadioClass(const NoInitClass &noinit);
		virtual ~RadioClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = false) override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

		/**
		 *  ObjectClass
		 */
		virtual bool Limbo() override;
		virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param) override;

		/**
		 *  RadioClass
		 */
		virtual RadioMessageType Transmit_Message(RadioMessageType message, long &param = LParam, RadioClass *to = nullptr);
		virtual RadioMessageType Transmit_Message(RadioMessageType message, RadioClass *to);

		bool In_Radio_Contact() const { return Radio != nullptr; }
		TechnoClass *Contact_With_Whom() { return reinterpret_cast<TechnoClass *>(Radio); }
		void Radio_Off() { Radio = nullptr; }

	private:

		/**
		 *  This is a record of the last message received by this receiver.
		 */
		RadioMessageType Old[3];

		/**
		 *  This is the object that radio communication has been established
		 *  with. Although is is only a one-way reference, it is required that
		 *  the receiving radio is also tuned to the object that contains this
		 *  radio set.
		 */
		RadioClass *Radio;
};
