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


/**
 *  The installable assertion function pointer.
 */
void (*TSPP_Assertion_Handler_Ptr)(const char *expr, const char *file, int line, const char *msg);


/**
 *  Installs the custom assertion handler that will handle all
 *  assertions in the TS++ codebase.
 */
void TSPP_Install_Assertion_Handler(void (*handler_ptr)(const char *, const char *, int, const char *))
{
	TSPP_Assertion_Handler_Ptr = handler_ptr;
}
