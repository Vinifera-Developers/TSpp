/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWFILE.H
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
#pragma once

#include "always.h"
#include <errno.h>


/**
 *  Helper macros for converting DateTime to MSDOS timestamp.
 */
#define YEAR(dt)     (((dt & 0xFE000000) >> (9 + 16)) + 1980)
#define MONTH(dt)    ((dt & 0x01E00000) >> (5 + 16))
#define DAY(dt)      ((dt & 0x001F0000) >> (0 + 16))
#define HOUR(dt)     ((dt & 0x0000F800) >> 11)
#define MINUTE(dt)   ((dt & 0x000007E0) >> 5)
#define SECOND(dt)   ((dt & 0x0000001F) << 1)


enum FileAccessType
{
    FILE_ACCESS_CLOSED,       // Default state, file close.
    FILE_ACCESS_READ,         // Open for reading access.
    FILE_ACCESS_WRITE,        // Open for writing access.
    FILE_ACCESS_READ_WRITE,   // Combination of reading and writing access.
    FILE_ACCESS_APPEND,       // When writing, it will keep the existing data
                              // and set the file pointer to the end of the
                              // existing data.
};
DEFINE_ENUMERATION_OPERATORS(FileAccessType);
DEFINE_ENUMERATION_BITWISE_OPERATORS(FileAccessType);


enum FileSeekType
{
    FILE_SEEK_START,   // Seek to position relative to the start of file.
    FILE_SEEK_CURRENT, // Seek to position relative to the current offset.
    FILE_SEEK_END      // Seek to position relative to the end of file.
};
DEFINE_ENUMERATION_OPERATORS(FileSeekType);
DEFINE_ENUMERATION_BITWISE_OPERATORS(FileSeekType);


enum FileErrorType
{
    /**
     *  This is a duplicate of the error numbers. The error handler for the
     *  RawFileClass handles these errors. If the error routine is overridden
     *  and additional errors are defined, then use numbers starting with 100.
     *  Note that these errors here are listed in numerical order. These errors
     *  are defined in the standard header file <errno.h>.
     */
    FILE_ERROR_ZERO = 0,                    // Non-error.
    FILE_ERROR_PERM = EPERM,                // Operation not permitted.
    FILE_ERROR_NOENT = ENOENT,              // No such file or directory.
    FILE_ERROR_SRCH = ESRCH,                // No such process.
    FILE_ERROR_INTR = EINTR,                // Interrupted function call.
    FILE_ERROR_IO = EIO,                    // Input/output error.
    FILE_ERROR_NXIO = ENXIO,                // No such device or address.
    FILE_ERROR_2BIG = E2BIG,                // Argument list too long.
    FILE_ERROR_NOEXEC = ENOEXEC,            // Exec format error.
    FILE_ERROR_BADF = EBADF,                // Bad file descriptor.
    FILE_ERROR_CHILD = ECHILD,              // No child processes.
    FILE_ERROR_AGAIN = EAGAIN,              // Resource temporarily unavailable.
    FILE_ERROR_NOMEM = ENOMEM,              // Not enough space/cannot allocate memory.
    FILE_ERROR_ACCES = EACCES,              // Permission denied.
    FILE_ERROR_FAULT = EFAULT,              // Bad address.
    FILE_ERROR_BUSY = EBUSY,                // Device or resource busy.
    FILE_ERROR_EXIST = EEXIST,              // File exists.
    FILE_ERROR_XDEV = EXDEV,                // Improper link.
    FILE_ERROR_NODEV = ENODEV,              // No such device.
    FILE_ERROR_NOTDIR = ENOTDIR,            // Not a directory.
    FILE_ERROR_ISDIR = EISDIR,              // Is a directory.
    FILE_ERROR_INVAL = EINVAL,              // Invalid argument.
    FILE_ERROR_NFILE = ENFILE,              // Too many open files in system.
    FILE_ERROR_MFILE = EMFILE,              // Too many open files.
    FILE_ERROR_NOTTY = ENOTTY,              // Inappropriate I/O control operation.
    FILE_ERROR_FBIG = EFBIG,                // File too large.
    FILE_ERROR_NOSPC = ENOSPC,              // No space left on device.
    FILE_ERROR_SPIPE = ESPIPE,              // Invalid seek.
    FILE_ERROR_ROFS = EROFS,                // Read-only filesystem.
    FILE_ERROR_MLINK = EMLINK,              // Too many links.
    FILE_ERROR_PIPE = EPIPE,                // Broken pipe.
    FILE_ERROR_DOM = EDOM,                  // Mathematics argument out of domain of function.
    FILE_ERROR_RANGE = ERANGE,              // Result too large.
    FILE_ERROR_DEADLK = EDEADLK,            // Resource deadlock avoided.
    FILE_ERROR_NAMETOOLONG = ENAMETOOLONG,  // Filename too long.
    FILE_ERROR_NOLCK = ENOLCK,              // No locks available.
    FILE_ERROR_NOSYS = ENOSYS,              // Function not implemented.
    FILE_ERROR_NOTEMPTY = ENOTEMPTY,        // Directory not empty.
    FILE_ERROR_ILSEQ = EILSEQ,              // Invalid or incomplete multibyte or wide character.
};


class FileClass
{
    public:
        FileClass() {}
        virtual ~FileClass() {}

        operator const char *() { return File_Name(); }

        virtual const char *File_Name() const = 0;
        virtual const char *Set_Name(const char *filename) = 0;
        virtual bool Create() = 0;
        virtual bool Delete() = 0;
        virtual bool Is_Available(bool forced = false) = 0;
        virtual bool Is_Open() const = 0;
        virtual bool Open(const char *filename, FileAccessType rights = FILE_ACCESS_READ) = 0;
        virtual bool Open(FileAccessType rights = FILE_ACCESS_READ) = 0;
        virtual long Read(void *buffer, int length) = 0;
        virtual off_t Seek(off_t offset, FileSeekType whence = FILE_SEEK_CURRENT) = 0;
        virtual off_t Size() = 0;
        virtual long Write(const void *buffer, int length) = 0;
        virtual void Close() = 0;
        virtual LONG Get_Date_Time() const = 0;
        virtual bool Set_Date_Time(LONG date_time) = 0;
        virtual void Error(FileErrorType error, bool can_retry = false, const char *filename = nullptr) = 0;

    protected:
        static const char *File_Error_To_String(FileErrorType error);
};
