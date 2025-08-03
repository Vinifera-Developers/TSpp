/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEXTFILE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Text file i/o class.
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
#include "textfile.h"
#include "readline.h"
#include "tspp_assert.h"


int TextFileClass::Read_Line(char* string, bool& eof)
{
    TSPP_ASSERT(string != nullptr);

    char buffer[MAX_LINE_LENGTH];
    eof = false; // Reset

    int total = ::Read_Line(*this, buffer, sizeof(buffer), eof);
    std::strcpy(string, buffer);

    return total;
}


int TextFileClass::Write_Line(char* string)
{
    TSPP_ASSERT(string != nullptr);

    int len = std::strlen(string);

    int total = RawFileClass::Write(string, len);
    if (total == len) {
        return total;
    }

    return -1;
}


int TextFileClass::Write_Line_Format(char* format, ...)
{
    TSPP_ASSERT(format != nullptr);

    char buffer[MAX_LINE_LENGTH];

    va_list args;
    va_start(args, format);

    std::vsnprintf(buffer, sizeof(buffer), format, args);

    va_end(args);

    int len = std::strlen(buffer);

    int total = RawFileClass::Write(buffer, len);
    if (total == len) {
        return total;
    }

    return -1;
}
