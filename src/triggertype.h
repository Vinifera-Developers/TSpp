/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TRIGGERTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for trigger types.
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

#include "abstracttype.h"
#include "tibsun_defines.h"


class TEventClass;
class TActionClass;
class HouseTypeClass;


class DECLSPEC_UUID("C02D1591-0A2A-11D2-ACA7-006008055BB5")
TriggerTypeClass : public AbstractTypeClass
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
        TriggerTypeClass(const char *ini_name = nullptr);
        TriggerTypeClass(const NoInitClass &noinit);
        virtual ~TriggerTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;
        virtual bool Write_INI(CCINIClass &ini) const override;

        // 00649F30
        // 00649F50
        // 00649F70
        // 00649F90
        // 00649FB0
        // 00649FF0
        AttachType Attaches_To() const;
        bool Remove_Action(TActionClass *action);
        bool Remove_Event(TEventClass *event);

        static void Read_Scenario_INI(CCINIClass &ini);
        static void Write_Scenario_INI(CCINIClass &ini);

        static const TriggerTypeClass &As_Reference(TriggerType type);
        static const TriggerTypeClass *As_Pointer(TriggerType type);
        static const TriggerTypeClass &As_Reference(const char *name);
        static const TriggerTypeClass *As_Pointer(const char *name);
        static TriggerType From_Name(const char *name);
        static const char *Name_From(TriggerType type);
        static const TriggerTypeClass *Find_Or_Make(const char *name);

    public:
        TriggerType Type;
        bool field_64;
        bool Easy;
        bool Normal;
        bool Hard;
        PersistantType IsPersistant;
        HouseTypeClass *House;
        TriggerTypeClass *Next;
        TEventClass *Event;
        TActionClass *Action;
};
