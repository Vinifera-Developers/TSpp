/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base class for all type objects.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "abstract.h"
#include "stringid.h"


class CCINIClass;


class AbstractTypeClass : public AbstractClass
{
public:
    AbstractTypeClass(const char* ini_name = nullptr);
    AbstractTypeClass(const NoInitClass& noinit);
    virtual ~AbstractTypeClass();

    bool operator==(const char* their_name) const { return IniName == their_name; }
    bool operator!=(const char* their_name) const { return IniName == their_name; }

    /**
     *  AbstractClass
     */
    virtual void Object_CRC(CRCEngine& crc) const override;

    /**
     *  AbstractTypeClass
     */
    virtual void entry_64();
    virtual bool Read_INI(CCINIClass& ini);
    virtual bool Write_INI(CCINIClass& ini) const;

    char const* Name() const { return IniName.c_str(); }
    char const* Full_Name() const { return GivenName.c_str(); }

public:
    TStringID<24> IniName;
    TStringID<48> GivenName;

private:
    // Copy and assignment not implemented; prevent their use by declaring as private.
    AbstractTypeClass(const AbstractTypeClass&);
    AbstractTypeClass& operator=(const AbstractTypeClass&);
};
