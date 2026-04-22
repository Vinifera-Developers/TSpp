/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for ai trigger types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    AITriggerTypeClass(const char* ini_name = nullptr);
    AITriggerTypeClass(const NoInitClass& noinit);
    virtual ~AITriggerTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;
    virtual bool Write_INI(CCINIClass& ini) const override;

    bool Process(HouseClass* house, HouseClass* enemy, bool a4);         // 00410840
    bool Check_Enemy_Owns(HouseClass* house, HouseClass* enemy);         // 00410BD0
    bool Check_House_Owns(HouseClass* house, HouseClass* enemy);         // 00410D70
    bool Check_Enemy_Yellow_Power(HouseClass* house, HouseClass* enemy); // 00410F10
    bool Check_Enemy_Red_Power(HouseClass* house, HouseClass* enemy);    // 00410F60
    bool Check_Enemy_Money(HouseClass* house, HouseClass* enemy);        // 00410FB0
    void Set_Condition_Object(TechnoTypeClass* technotype);              // 00411A40
    void Set_First_TeamType(TeamTypeClass* teamtype);                    // 00411A50
    void Set_Second_TeamType(TeamTypeClass* teamtype);                   // 00411A60
    void Record_Success();                                               // 00411A70
    void Record_Fail();                                                  // 00411B30

    static void Read_Scenario_INI(CCINIClass& ini, int a2);
    static void Write_Scenario_INI(CCINIClass& ini, int a2);

    static AITriggerType From_Name(const char* name);
    static const char* Name_From(AITriggerType type);
    static AITriggerTypeClass* Find_Or_Make(const char* name);

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
    TechnoTypeClass* ConditionObject;
    TeamTypeClass* TeamOne;
    TeamTypeClass* TeamTwo;

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
