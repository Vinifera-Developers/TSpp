/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Radio contact between game objects.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "mission.h"


extern long& LParam;


class RadioClass : public MissionClass
{
public:
    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);

public:
    RadioClass();
    RadioClass(const NoInitClass& noinit);
    virtual ~RadioClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass* target, bool all = false) override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    /**
     *  ObjectClass
     */
    virtual bool Limbo() override;
    virtual RadioMessageType Receive_Message(RadioClass* from, RadioMessageType message, long& param) override;

    /**
     *  RadioClass
     */
    virtual RadioMessageType Transmit_Message(RadioMessageType message, long& param = LParam, RadioClass* to = nullptr);
    virtual RadioMessageType Transmit_Message(RadioMessageType message, RadioClass* to);

    bool In_Radio_Contact() const { return Radio != nullptr; }
    TechnoClass* Contact_With_Whom() { return reinterpret_cast<TechnoClass*>(Radio); }
    void Radio_Off() { Radio = nullptr; }

public:
    RadioMessageType Old[3];
    RadioClass* Radio;
};
