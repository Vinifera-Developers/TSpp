/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FFACTORY.CPP
 *
 *  @authors       CCHyper, OmniBlade
 *
 *  @brief         Basic file factories.
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
#include "ffactory.h"
#include "rawfile.h"
#include "bfiofile.h"
#include "tspp_assert.h"


/**
 *  Default instances of the factory's.
 */
SimpleFileFactoryClass DefaultFileFactory;
RawFileFactoryClass DefaultWritingFileFactory;

FileFactoryClass *TheFileFactory = &DefaultFileFactory;
RawFileFactoryClass *TheWritingFileFactory = &DefaultWritingFileFactory;


SimpleFileFactoryClass::SimpleFileFactoryClass() :
    SubDirectory(),
    Mutex(),
    IsStripPath(false)
{
}


FileClass *SimpleFileFactoryClass::Get_File(char const *filename)
{
    CriticalSectionClass::LockClass lock(Mutex);

    char new_name[MAX_PATH];
    char stripped_name[MAX_PATH];

    std::strncpy(stripped_name, filename, sizeof(stripped_name));

    if (IsStripPath) {
        const char *separator = nullptr;
        if ((separator = std::strrchr(filename, '/')) != nullptr || (separator = std::strrchr(filename, '\\')) != nullptr) {
            // Copy string from after the separator.
            std::strncpy(stripped_name, (separator + 1), sizeof(stripped_name));
        }
    }

    BufferIOFileClass *file = new BufferIOFileClass;
    TSPP_ASSERT(file != nullptr);

    if (file == nullptr) {
        return nullptr;
    }

    if (!Is_Full_Path(stripped_name)) {

        if (std::strlen(SubDirectory) > 0) {

            if (std::strchr(SubDirectory, ';')) {

                for (const char *token = std::strtok(SubDirectory, ";"); token; token = std::strtok(nullptr, ";")) {
                    std::snprintf(new_name, sizeof(new_name), "%s%s", token, stripped_name);
                    file->Set_Name(new_name);
                    if (file->Is_Available()) {
                        break;
                    }
                }

            } else {
                std::snprintf(new_name, sizeof(new_name), "%s%s", SubDirectory, stripped_name);
            }

        }

    } else {
        std::strncpy(new_name, stripped_name, sizeof(new_name));
    }

    file->Set_Name(new_name);

    return file;
}


void SimpleFileFactoryClass::Return_File(FileClass *file)
{
    if (file != nullptr) {
        delete file;
    }
}


void SimpleFileFactoryClass::Get_Sub_Directory(char *new_dir)
{
    CriticalSectionClass::LockClass lock(Mutex);

    if (new_dir != nullptr) {
        std::strncpy(new_dir, SubDirectory, sizeof(SubDirectory));
    }
}


void SimpleFileFactoryClass::Set_Sub_Directory(const char *sub_directory)
{
    TSPP_ASSERT(sub_directory != nullptr);

    CriticalSectionClass::LockClass lock(Mutex);

    if (sub_directory != nullptr) {
        std::strncpy(SubDirectory, sub_directory, sizeof(SubDirectory));
    }
}


/**
 *  Prepends a sub directory to the list of paths to search so it is searched first.
 */
void SimpleFileFactoryClass::Prepend_Sub_Directory(const char *sub_directory)
{
    TSPP_ASSERT(sub_directory != nullptr);

    char temp_sub_dir[1024];

    if (sub_directory == nullptr) {
        return;
    }

    int subdir_len = std::strlen(sub_directory);

    if ( subdir_len <= (sizeof(temp_sub_dir) - 3) && subdir_len >= 1 ) {

        std::strcpy(temp_sub_dir, sub_directory);

        if (temp_sub_dir[subdir_len - 1] != '\\' && temp_sub_dir[subdir_len - 1] != '/') {
            temp_sub_dir[subdir_len++] = '/';
            temp_sub_dir[subdir_len] = '\0';
        }

        temp_sub_dir[subdir_len++] = ';';
        temp_sub_dir[subdir_len] = '\0';

        // Enter.
        CriticalSectionClass::LockClass lock(Mutex);

        std::strncat(temp_sub_dir, SubDirectory, sizeof(temp_sub_dir));
        std::strcpy(SubDirectory, temp_sub_dir);

        // Exit.
    }
}


/**
 *  Performs some simple tests on a path to check if it is fully qualified.
 */
void SimpleFileFactoryClass::Append_Sub_Directory(char const *sub_directory)
{
    TSPP_ASSERT(sub_directory != nullptr);

    char temp_sub_dir[1024];

    if (sub_directory == nullptr) {
        return;
    }

    int subdir_len = std::strlen(sub_directory);

    if (subdir_len <= (sizeof(temp_sub_dir) - 2) && subdir_len >= 1) {

        std::strcpy(temp_sub_dir, sub_directory);

        if (temp_sub_dir[subdir_len - 1] != '\\' && temp_sub_dir[subdir_len - 1] != '/') {
            temp_sub_dir[subdir_len++] = '/';
            temp_sub_dir[subdir_len] = '\0';
        }

        CriticalSectionClass::LockClass lock(Mutex);

        // Add ';' at the end if it doesn't already have one as the delimiter.
        if (std::strlen(SubDirectory) > 0 && SubDirectory[std::strlen(SubDirectory)- 1] != ';') {
            std::strncat(SubDirectory, ";", sizeof(SubDirectory));
        }

        std::strncat(SubDirectory, temp_sub_dir, sizeof(SubDirectory));
    }
}


/**
 *  Performs some simple tests on a path to check if it is fully qualified.
 */
bool SimpleFileFactoryClass::Is_Full_Path(const char *path)
{
    if (path == nullptr) {
        return false;
    }

    return path[1] == ':' || (path[0] == '\\' && path[1] == '\\') || path[0] == '/';
}


FileClass *RawFileFactoryClass::Get_File(char const *filename)
{
    RawFileClass *file = new RawFileClass(filename);
    TSPP_ASSERT(file != nullptr);
    return file;
}


void RawFileFactoryClass::Return_File(FileClass *file)
{
    if (file != nullptr) {
        delete file;
    }
}


FileAutoPtr::FileAutoPtr() : 
    Ptr(nullptr),
    Fac(nullptr)
{
}


FileAutoPtr::FileAutoPtr(FileFactoryClass *fac, char const *filename) : 
    Ptr(nullptr),
    Fac(fac)
{
    TSPP_ASSERT(Fac != nullptr);

    Ptr = fac->Get_File(filename);

    if (Ptr == nullptr) {
        Ptr = new BufferIOFileClass(filename);
        TSPP_ASSERT(Ptr != nullptr);
    }
}


FileAutoPtr::~FileAutoPtr()
{
    Fac->Return_File(Ptr);
}
