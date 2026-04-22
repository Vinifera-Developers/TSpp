/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Custom assertion macros with installable custom handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "tspp_assert.h"


/**
 *  Ignore all assertions, even under DEBUG builds.
 */
bool TSPP_IgnoreAllAsserts = false;

/**
 *  Should asserts fire but not report?
 */
bool TSPP_SilentAsserts = false;

/**
 *  Force exit application any assertion?
 */
bool TSPP_ExitOnAssert = false;


/**
 *  The installable assertion function pointer.
 */
void (*TSPP_Assertion_Handler_Ptr)(TSPPAssertType type, const char* expr, const char* file, int line, const char* function, volatile bool* ignore, volatile bool* allow_break, volatile bool* exit, const char* msg, ...) = nullptr;


/**
 *  Installs the custom assertion handler that will handle all
 *  assertions in the TS++ codebase.
 */
void TSPP_Install_Assertion_Handler(void (*handler_ptr)(TSPPAssertType, const char*, const char*, int, const char*, volatile bool*, volatile bool*, volatile bool*, const char*, ...))
{
    TSPP_Assertion_Handler_Ptr = handler_ptr;
}
