/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_ASSERT.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Custom assertion macros with installable custom handler.
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
#include "tspp_assert.h"


#ifndef NDEBUG

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
void (*TSPP_Assertion_Handler_Ptr)(TSPPAssertType type, const char *expr, const char *file, int line, const char *function, volatile bool *ignore, volatile bool *allow_break, volatile bool *exit, const char *msg, ...) = nullptr;


/**
 *  Installs the custom assertion handler that will handle all
 *  assertions in the TS++ codebase.
 */
void TSPP_Install_Assertion_Handler(void (*handler_ptr)(TSPPAssertType, const char *, const char *, int, const char *, volatile bool *, volatile bool *, volatile bool *, const char *, ...))
{
	TSPP_Assertion_Handler_Ptr = handler_ptr;
}

#endif
