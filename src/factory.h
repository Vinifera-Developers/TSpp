/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FACTORY.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Production manager class.
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
#include "stage.h"
#include "vector.h"


class TechnoClass;
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
