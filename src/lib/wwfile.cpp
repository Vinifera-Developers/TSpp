/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWFILE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Abstract file class.
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
#include "wwfile.h"


const char* FileClass::File_Error_To_String(FileErrorType error)
{
    const char* error_str = nullptr;
    switch (error) {
    case FILE_ERROR_ZERO:
        error_str = "Non-error.";
        break;
    case FILE_ERROR_PERM:
        error_str = "Operation not permitted.";
        break;
    case FILE_ERROR_NOENT:
        error_str = "No such file or directory.";
        break;
    case FILE_ERROR_SRCH:
        error_str = "No such process.";
        break;
    case FILE_ERROR_INTR:
        error_str = "Interrupted function call.";
        break;
    case FILE_ERROR_IO:
        error_str = "Input/output error.";
        break;
    case FILE_ERROR_NXIO:
        error_str = "No such device or address.";
        break;
    case FILE_ERROR_2BIG:
        error_str = "Argument list too long.";
        break;
    case FILE_ERROR_NOEXEC:
        error_str = "Exec format error.";
        break;
    case FILE_ERROR_BADF:
        error_str = "Bad file descriptor.";
        break;
    case FILE_ERROR_CHILD:
        error_str = "No child processes.";
        break;
    case FILE_ERROR_AGAIN:
        error_str = "Resource temporarily unavailable.";
        break;
    case FILE_ERROR_NOMEM:
        error_str = "Not enough space/cannot allocate memory.";
        break;
    case FILE_ERROR_ACCES:
        error_str = "Permission denied.";
        break;
    case FILE_ERROR_FAULT:
        error_str = "Bad address.";
        break;
    case FILE_ERROR_BUSY:
        error_str = "Device or resource busy.";
        break;
    case FILE_ERROR_EXIST:
        error_str = "File exists.";
        break;
    case FILE_ERROR_XDEV:
        error_str = "Improper link.";
        break;
    case FILE_ERROR_NODEV:
        error_str = "No such device.";
        break;
    case FILE_ERROR_NOTDIR:
        error_str = " Not a directory.";
        break;
    case FILE_ERROR_ISDIR:
        error_str = "Is a directory.";
        break;
    case FILE_ERROR_INVAL:
        error_str = "Invalid argument.";
        break;
    case FILE_ERROR_NFILE:
        error_str = "Too many open files in system.";
        break;
    case FILE_ERROR_MFILE:
        error_str = "Too many open files.";
        break;
    case FILE_ERROR_NOTTY:
        error_str = "Inappropriate I/O control operation.";
        break;
    case FILE_ERROR_FBIG:
        error_str = "File too large.";
        break;
    case FILE_ERROR_NOSPC:
        error_str = "No space left on device.";
        break;
    case FILE_ERROR_SPIPE:
        error_str = "Invalid seek.";
        break;
    case FILE_ERROR_ROFS:
        error_str = "Read-only filesystem.";
        break;
    case FILE_ERROR_MLINK:
        error_str = "Too many links.";
        break;
    case FILE_ERROR_PIPE:
        error_str = "Broken pipe.";
        break;
    case FILE_ERROR_DOM:
        error_str = "Mathematics argument out of domain of function.";
        break;
    case FILE_ERROR_RANGE:
        error_str = "Result too large.";
        break;
    case FILE_ERROR_DEADLK:
        error_str = "Resource deadlock avoided.";
        break;
    case FILE_ERROR_NAMETOOLONG:
        error_str = "Filename too long.";
        break;
    case FILE_ERROR_NOLCK:
        error_str = "No locks available.";
        break;
    case FILE_ERROR_NOSYS:
        error_str = "Function not implemented.";
        break;
    case FILE_ERROR_NOTEMPTY:
        error_str = "Directory not empty.";
        break;
    case FILE_ERROR_ILSEQ:
        error_str = "Invalid or incomplete multibyte or wide character.";
        break;
    default:
        error_str = "Unknown error.";
        break;
    };

    return error_str;
}
