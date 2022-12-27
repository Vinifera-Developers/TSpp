/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AITRIGTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for ai trigger types.
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


class TechnoTypeClass;
class TeamTypeClass;


class DECLSPEC_UUID("BA093524-4CF4-11D2-BC26-00104B8FB04D")
AITriggerTypeClass : public AbstractTypeClass
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
        AITriggerTypeClass(const char *ini_name = nullptr);
        AITriggerTypeClass(const NoInitClass &noinit);
        virtual ~AITriggerTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;
        virtual bool Write_INI(CCINIClass &ini) const override;

        bool Process(HouseClass *house, HouseClass *enemy, bool a4); // 00410840
        bool Check_Enemy_Owns(HouseClass *house, HouseClass *enemy); // 00410BD0
        bool Check_House_Owns(HouseClass *house, HouseClass *enemy); // 00410D70
        bool Check_Enemy_Yellow_Power(HouseClass *house, HouseClass *enemy); // 00410F10
        bool Check_Enemy_Red_Power(HouseClass *house, HouseClass *enemy); // 00410F60
        bool Check_Enemy_Money(HouseClass *house, HouseClass *enemy); // 00410FB0
        void Set_Condition_Object(TechnoTypeClass *technotype); // 00411A40
        void Set_First_TeamType(TeamTypeClass *teamtype); //  00411A50
        void Set_Second_TeamType(TeamTypeClass *teamtype); //  00411A60
        void Record_Success(); // 00411A70
        void Record_Fail(); // 00411B30

        static void Read_Scenario_INI(CCINIClass &ini, int a2);
        static void Write_Scenario_INI(CCINIClass &ini, int a2);

        static const AITriggerTypeClass &As_Reference(AITriggerType type);
        static const AITriggerTypeClass *As_Pointer(AITriggerType type);
        static const AITriggerTypeClass &As_Reference(const char *name);
        static const AITriggerTypeClass *As_Pointer(const char *name);
        static AITriggerType From_Name(const char *name);
        static const char *Name_From(AITriggerType type);
        static const AITriggerTypeClass *Find_Or_Make(const char *name);

	public:
        AITriggerEventType Type;
        int field_64;
        AITriggerHouseType OwnerHouseType;
        bool IsEnabled;
        HousesType House;
        SideType MultiSide;
        int TechLevel;
        double Weight;
        double MinWeight;
        double MaxWeight;
        bool IsForSkirmish;
        bool IsForBaseDefense;
        bool EnabledInEasy;
        bool EnabledInMedium;
        bool EnabledInHard;
        TechnoTypeClass *ConditionObject;
        TeamTypeClass *TeamOne;
        TeamTypeClass *TeamTwo;

        typedef struct ParameterStruct {
            int Number;
            AITriggerComparatorType Comparator;
        };

        union ParameterUnion {
            ParameterStruct Parameters;
            char Value[32];
        } Data;

        int SuccessCount;
        int ExecutionCount;
};
