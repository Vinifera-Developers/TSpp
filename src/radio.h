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
        virtual void Detach(AbstractClass * target, bool all = false) override;
        virtual void Object_CRC(CRCEngine &crc) const override;

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

    public:
        RadioMessageType Old[3];
        RadioClass *Radio;
};
