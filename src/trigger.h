/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TRIGGER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Trigger game object class.
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
#include "ftimer.h"
#include "textprint.h"
#include "tibsun_globals.h"
#include "ttimer.h"


class ObjectClass;
class TechnoClass;
class TriggerTypeClass;


class DECLSPEC_UUID("C02D1590-0A2A-11D2-ACA7-006008055BB5")
TriggerClass : public AbstractClass
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
    TriggerClass();
    TriggerClass(TriggerTypeClass* classof);
    TriggerClass(const NoInitClass& noinit);
    virtual ~TriggerClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    bool Fire(ObjectClass* object = nullptr, Cell cell = CELL_NONE);
    bool Is_Triggered(TEventType event = TEVENT_ANY, ObjectClass* object = nullptr, bool forced = false, bool isperm = false, TechnoClass* source = nullptr);

    void Enable();
    void Disable();
    void Enable_Control(bool val)
    {
        if (val)
            Enable();
        else
            Disable();
    }
    bool Is_Enabled() const { return IsActive; }
    __declspec(property(get = Is_Enabled, put = Enable_Control)) bool IsEnabled;

    void Draw_It(int, int x, int y, int width, int height, bool selected, TextPrintType flags) const;
    void Timer_Global_Reset(int global);
    void Timer_Local_Reset(int local);
    void Reset_Timer_Events();

    bool Is_Horizontal_Cross() const;
    __declspec(property(get = Is_Horizontal_Cross)) bool IsHorizontalCross;

    bool Is_Vertical_Cross() const;
    __declspec(property(get = Is_Vertical_Cross)) bool IsVerticalCross;

    bool Is_Enters_Zone() const;
    __declspec(property(get = Is_Enters_Zone)) bool IsEntersZone;

    bool Is_Allow_Win() const;
    __declspec(property(get = Is_Allow_Win)) bool IsAllowWin;

    bool Is_Tied_To_Global(int global) const;
    __declspec(property(get = Is_Tied_To_Global)) bool IsTiedToGlobal[];

    void Mark_Event_Sprung(int event);
    void Mark_Event_Unsprung(int event);
    bool Is_Event_Sprung(int event);

    void Mark_To_Die();
    bool Is_Marked_To_Die() const;

public:
    TriggerTypeClass* Class;
    TriggerClass* LinkedTo;
    bool IsToDie;
    CDTimerClass<FrameTimerClass> Timer;
    int TrippedFlags;
    bool IsActive;
};
