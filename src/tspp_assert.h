/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_ASSERT.H
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
#pragma once

#include "always.h"
#include <cassert>


extern void (*TSPP_Assertion_Handler_Ptr)(const char *expr, const char *file, int line, const char *msg);

void TSPP_Install_Assertion_Handler(void (*handler_ptr)(const char *, const char *, int, const char *));


/**
 *  Standard assert macro.
 */
#define TSPP_ASSERT(expr) \
	{ \
		if (TSPP_Assertion_Handler_Ptr && !(expr)) { \
			TSPP_Assertion_Handler_Ptr(#expr, __FILE__, __LINE__, nullptr); \
		} else { \
			assert(expr); \
		} \
	}


/**
 *  Assert macro with optional message to display.
 * 
 *  #NOTE: (if no custom handler is installed, then just the
 *         expression is passed onto the regular C assert.)
 */
#define TSPP_ASSERT_PRINT(expr, msg) \
	{ \
		if (TSPP_Assertion_Handler_Ptr && !(expr)) { \
			TSPP_Assertion_Handler_Ptr(#expr, __FILE__, __LINE__, msg); \
		} else { \
			assert(expr); \
		} \
	}
