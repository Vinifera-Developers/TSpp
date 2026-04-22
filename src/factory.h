/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Production manager class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "stage.h"
#include "vector.h"
#include "techno.h"


class TechnoTypeClass;
class HouseClass;


class DECLSPEC_UUID("34ECD9A8-0AB0-11D2-ACA7-006008055BB5")
FactoryClass : public AbstractClass, public StageClass
{
public:
    enum FactoryClassEnum {
        STEP_COUNT = 54
    };

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
    FactoryClass();
    FactoryClass(const NoInitClass& x);
    virtual ~FactoryClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    bool Abandon();
    bool Completed();
    bool Has_Changed();
    bool Has_Completed();
    bool Set(const TechnoTypeClass& type, HouseClass& house, bool a3 = false);
    bool Set(TechnoClass& object);
    bool Start(bool suspend = false);
    bool Suspend(bool onhold = true);
    int Completion();
    TechnoClass* Get_Object() const;
    int Get_Special_Item() const;
    void Resume_Queue(); // 004978D0
    bool Remove_From_Queue(const TechnoTypeClass& object);
    bool Is_Queued(const TechnoTypeClass& object);
    int Total_Queued(const TechnoTypeClass& object);
    int Cost_Per_Tick() const;
    int Build_Rate() const;
    bool Is_Building() const { return StageClass::Fetch_Rate() != 0 && !IsSuspended; }
    HouseClass* Get_House() { return House; }
    int Queued_Object_Count() { return QueuedObjects.Count(); }

    bool Has_Production_Target() const
    {
        if (Object != nullptr) return true;
        if (QueuedObjects.Count() > 0) return true;
        return false;
    }

    bool Is_Currently_Producing(const TechnoTypeClass* type) const
    {
        if (Object == nullptr) return false;
        if (Object->TClass == nullptr) return true;
        if (Object->TClass == type) return true;
        return false;
    }

    const char* Name() const;

    static void Recalculate_Times(HouseClass* house);
    static FactoryClass* Find_By_Owner_And_Product(const HouseClass* house, const TechnoTypeClass* item);

public:
    DynamicVectorClass<const TechnoTypeClass*> QueuedObjects;
    TechnoClass* Object;
    bool IsDifferent;
    int Balance;
    int OriginalBalance;
    int SpecialItem;
    HouseClass* House;
    bool IsSuspended;
    bool IsOnHold;
};
