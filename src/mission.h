/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class that handles order assignment and tracking.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ftimer.h"
#include "object.h"
#include "ttimer.h"


class CCINIClass;
class MissionControlClass;


class MissionClass : public ObjectClass
{
public:
    MissionClass();
    MissionClass(const NoInitClass& noinit);
    virtual ~MissionClass();

    /**
     *  AbstractClass
     */
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual MissionType Get_Mission() const override;
    virtual void Assign_Mission(MissionType order) override;

    /**
     *  MissionClass
     */
    virtual bool Commence();
    virtual bool Ready_To_Commence() const;
    virtual int Mission_Sleep();
    virtual int Mission_Harmless();
    virtual int Mission_Ambush();
    virtual int Mission_Attack();
    virtual int Mission_Capture();
    virtual int Mission_Guard();
    virtual int Mission_Guard_Area();
    virtual int Mission_Harvest();
    virtual int Mission_Hunt();
    virtual int Mission_Move();
    virtual int Mission_Retreat();
    virtual int Mission_Return();
    virtual int Mission_Stop();
    virtual int Mission_Unload();
    virtual int Mission_Enter();
    virtual int Mission_Construction();
    virtual int Mission_Deconstruction();
    virtual int Mission_Repair();
    virtual int Mission_Missile();
    virtual int Mission_Open();
    virtual int Mission_Rescue();
    virtual int Mission_Patrol();
    virtual void Set_Mission(MissionType mission);
    virtual void Override_Mission(MissionType mission, AbstractClass* tarcom = nullptr, AbstractClass* navcom = nullptr);
    virtual bool Restore_Mission();
    virtual bool Has_Suspended_Mission() const; // has suspended mission?

    void Shorten_Mission_Timer() { Timer = 0; }

    const MissionControlClass& Current_Mission_Control() const;

    static bool Is_Recruitable_Mission(MissionType mission);

    static const char* Mission_Name(MissionType mission);
    static MissionType Mission_From_Name(const char* name);

public:
    MissionType CurrentMission;
    MissionType SuspendedMission;
    MissionType MissionQueue;
    int Status;
    bool field_5C; // set when closing apc door in UnitClass::Mission_Unload.	// is mission done?
    CDTimerClass<FrameTimerClass> Timer;
};


class MissionControlClass
{
public:
    MissionControlClass();
    ~MissionControlClass() {}

    const char* Name() const;

    int Normal_Delay() const { return TICKS_PER_MINUTE * Rate; }
    int AA_Delay() const { return TICKS_PER_MINUTE * AARate; }

    bool Read_INI(CCINIClass& ini);

public:
    MissionType Mission;
    bool IsNoThreat;
    bool IsZombie;
    bool IsRecruitable;
    bool IsParalyzed;
    bool IsRetaliate;
    bool IsScatter;
    double Rate;
    double AARate;
};
