################################################################################
#                      O P E N  S O U R C E  --  T S + +                       #
################################################################################
#
#  @project       TS++
#
#  @file          CMAKELISTS.TXT
#
#  @authors       CCHyper
#
#  @brief         Project CMake script.
#
#  @license       TS++ is free software: you can redistribute it and/or
#                 modify it under the terms of the GNU General Public License
#                 as published by the Free Software Foundation, either version
#                 3 of the License, or (at your option) any later version.
#
#                 TS++ is distributed in the hope that it will be
#                 useful, but WITHOUT ANY WARRANTY; without even the implied
#                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#                 PURPOSE. See the GNU General Public License for more details.
#
#                 You should have received a copy of the GNU General Public
#                 License along with this program.
#                 If not, see <http://www.gnu.org/licenses/>.
#
################################################################################

# Visual Studio 2017 requires at least 3.7.
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

set(CMAKE_SUPPRESS_REGENERATION true) # Remove ZERO_CHECK project.
set_property(GLOBAL PROPERTY USE_FOLDERS ON) # Organize projects into folders within the VS solution.

# Prevent incremental linking.
# This line has to go before "project"!
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" AND MSVC)
	set(MSVC_INCREMENTAL_DEFAULT OFF)
endif()

# Declare the project.
project(TSpp VERSION 1.00 LANGUAGES CXX)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW) #policy for <PackageName>_ROOT variables.
endif()

# Check supported generators
if(MSVC AND MSVC_VERSION LESS 1910)
    message(FATAL_ERROR "This version of Visual Studio is not supported: ${CMAKE_GENERATOR}.")
endif()

if(NOT MSVC)
    message(FATAL_ERROR "This project can only be built using Visual Studio!")
endif()


################################################################################
# Set a default build type if none was specified.
################################################################################

# Default to a Release build.
get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (NOT IS_MULTI_CONFIG AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
    message(STATUS "Setting build type default to Release")
endif()


################################################################################
# Configure C++ standard
################################################################################

# Require that we have at least C++14.
# We can not use C++ 17 due to a issue with MSVC and COM
# See: https://developercommunity.visualstudio.com/content/problem/297914/c-intellisense-not-working-for-com-ptr-t-with-c17.html
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#enable_language(C)
enable_language(CXX)


################################################################################
# Set custom module path.
################################################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(CMAKE_NO_SYSTEM_FROM_IMPORTED TRUE) # Needed to prevent FindDirectX screwing up a MinGW build.


################################################################################
# Hack to get around the "Debug", "Release", etc directories CMake tries to add on Windows.
################################################################################

set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Set output directory for LIB files.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

# Set output directory for DLL files.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

# Set output directory for executable files.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})


################################################################################
# We don't support in tree builds, so help people make the right choice.
################################################################################
if(CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR "Building in-source is not supported! Create a build directory and remove ${CMAKE_CURRENT_SOURCE_DIR}/CMakeCache.txt")
endif()


################################################################################
# Glob all the headers, source files and include directories.
################################################################################
include(GlobUtil)
GlobDirectories(GLOB COMMON_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)
GlobHeaders(GLOB_RECURSE COMMON_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src)
GlobSources(GLOB_RECURSE COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)


################################################################################
# Embed some git version information in the binary.
################################################################################
message(STATUS "Fetching the repository git information.")

# Locate git binary to provide information to the build environment.
# find_package(Git) # Removed, GitWatcher does this quietly.

# The following two defines are automatically picked up by GitWatcher.
set(GIT_PRE_CONFIGURE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/tspp_gitinfo.cpp.in")
set(GIT_POST_CONFIGURE_FILE "${CMAKE_CURRENT_BINARY_DIR}/generated/tspp_gitinfo.cpp")
set(GIT_STATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/tspp-git-state-hash")
set(GIT_WORKING_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

include(GitWatcher)
GitWatcher_SetupInitial()  # Running the script function again forces the file to be
					       # created locally so the file can be added to the filters.


################################################################################
# Setup project IDE filters.
################################################################################
if(MSVC OR CMAKE_GENERATOR STREQUAL "Xcode")
	message(STATUS "Setting up project file filters.")
	include(ProjectFilters)
	SetupProjectFilters("TS++" ${COMMON_HEADERS} ${COMMON_SOURCES})
	
	# Filter the configured git version source file manually.
	SetCustomProjectFilters("Generated Files" ${GIT_POST_CONFIGURE_FILE})
endif()


################################################################################
# Create the static library.
################################################################################
message(STATUS "Configuring static library for TS++.")

add_library(${PROJECT_NAME} STATIC
	${COMMON_HEADERS} ${COMMON_SOURCES}
	${GIT_POST_CONFIGURE_FILE} # Configured git version info source file.
)

target_link_libraries(${PROJECT_NAME} winmm)

target_include_directories(${PROJECT_NAME} PUBLIC
	${COMMON_INCLUDE_DIRS}
)

# Make build check state of git to check for uncommitted changes.
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_check_git)

# Set the custom project name.
set_target_properties("${PROJECT_NAME}" PROPERTIES PROJECT_LABEL "TS++")


################################################################################
# Some general Windows definitions to keep the MSVC compiler happy with our code.
################################################################################
if(WIN32)
	add_compile_definitions(__STDC_FORMAT_MACROS)
	add_compile_definitions(__STDC_LIMIT_MACROS)
	add_compile_definitions(_CRT_SECURE_NO_DEPRECATE)
	add_compile_definitions(_CRT_NONSTDC_NO_DEPRECATE)
	add_compile_definitions(_WINSOCK_DEPRECATED_NO_WARNINGS)
	add_compile_definitions(_USE_32BIT_TIME_T) # This is for ABI compatibility with a few functions.
	add_compile_definitions(WIN32_LEAN_AND_MEAN) # Go lean and mean on windows.
	add_compile_definitions(NOMINMAX) # Windows min/max clashes with std::min/max
endif()


################################################################################
# Disable warnings.
################################################################################
# Set warning level 4
add_compile_options(/W4)

# For catching unreferenced local variables, we do not need to worry about this when compiling debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /wd4189")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /wd4101")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /wd4700") # uninitialized local variable 'x' used.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244") # disable C4244: conversion from 'double' to 'float', possible loss of data
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4800") # disable C4800: 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4351") # disable C4351: "new behavior: elements of array will be default initialized"
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4514") # disable C4514: "unreferenced inline function has been removed" Yea, so what?
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4065") # disable C4065: "switch statement contains 'default' but no 'case' labels"
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4514") # disable C4514: "unreferenced inline function has been removed" Yea, so what?
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4065") # disable C4065: "switch statement contains 'default' but no 'case' labels"
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244") # disable C4244: "conversion from 'double' to 'float', possible loss of data" Yea, so what?
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4530") # disable C4530: Disable warning about exception handling not being enabled. It's used as part of STL - in a part of STL we don't use.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4056") # disable C4056: "overflow in floating-point constant arithmetic" This warning occurs even if the loss of precision is insignificant.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4710") # disable C4710: "function not inlined" This warning is typically useless. The inline keyword only serves as a suggestion to the compiler and it may or may not inline a function on a case by case basis. No need to be told of this.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4355") # disable C4355: "'this' used in base member initializer list" Using "this" in a base member initializer is valid -- no need for this warning.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4097") # disable C4097: "typedef-name used as a synonym for class-name". This is by design and should not be a warning.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4091") # disable C4091: 'typedef ': ignored on left of '' when no variable is declared
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4505") # disable C4505: Unreferenced local function removed.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4511") # disable C4511: 'copy constructor could not be generated'
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4711") # disable C4711: 'function selected for automatic inline expansion'. Cool, but since we're treating warnings as errors, don't warn us about this!
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4512") # disable C4512: 'assignment operator could not be generated' 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4100") # disable C4100: 'unreferenced formal parameter'
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4786") # disable C4786: "identifier was truncated to '255' characters in the browser information" Templates create long identifiers...
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4800") # disable C4800: 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996") # disable C4996: 'This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.'
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4324") # disable C4324: 'structure was padded due to alignment specifier.' Safe to ignore this.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4102") # disable C4102: 'unreferenced label.' Yea, so what?
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4646") # disable C4646: 'function declared with 'noreturn' has non-void return type' Yea, so what?
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4731") # disable C4731: 'frame pointer register 'ebp' modified by inline assembly code' Nothing to worry about.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4740") # disable C4740: 'flow in or out of inline asm code suppresses global optimization' Nothing to worry about.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4239") # disable C4239: 'nonstandard extension used: 'default argument': conversion from 'value' to 'value &'. Shoosh...

# disable D9035: 'option 'QIfist' has been deprecated and will be removed in a future release.' Yeah yeah, we need it for now though...
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd9035") # Not allowed to disable command line warnings.


################################################################################
# Add/Remove flags required for trying matching pre-compiled game code.
################################################################################

# Disable the random address rebasing on module load.
target_link_options(${PROJECT_NAME} PUBLIC /DYNAMICBASE:NO)

# Disable Data Execution Prevention.
target_link_options(${PROJECT_NAME} PUBLIC /NXCOMPAT:NO)

# Prevent incremental linking.
target_link_options(${PROJECT_NAME} PUBLIC /INCREMENTAL:NO)

# disable SAFESEH to avoid linker issues with 3rd party libraries.
target_link_options(${PROJECT_NAME} PUBLIC /SAFESEH:NO)

# Disable Run Time Checking.
foreach(flag_var CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS_MINSIZEREL
				 CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_MINSIZEREL)
	if(${flag_var} MATCHES "/RTC")
		string(REGEX REPLACE "/RTC[^ ]*" "" ${flag_var} "${${flag_var}}")
	endif()
endforeach(flag_var)

# Specifies no enhanced instructions and also specifies x87 for floating-point calculations.
target_compile_options(${PROJECT_NAME} PUBLIC /arch:IA32)

# Specify floating-point behaviour.
target_compile_options(${PROJECT_NAME} PUBLIC /fp:fast)

# Suppresses _ftol when a conversion from a floating-point type to an integer type is required (x86 only).
target_compile_options(${PROJECT_NAME} PUBLIC /QIfist)

# Force generates fast transcendentals.
target_compile_options(${PROJECT_NAME} PUBLIC /Qfast_transcendentals)

# forces __fastcall as default calling convention.
target_compile_options(${PROJECT_NAME} PUBLIC /Gr)

# Disables buffer security overrun checks.
target_compile_options(${PROJECT_NAME} PUBLIC /GS-)

# Disables buffer security overrun checks.
target_compile_options(${PROJECT_NAME} PUBLIC /GS-)

# Align structures to 4-byte boundaries.
#		target_compile_options(${PROJECT_NAME} PUBLIC /Zp4)

# Replaces some function calls with intrinsic or otherwise special forms of the function.
#		target_compile_options(${PROJECT_NAME} PUBLIC /Oi)

# (Non-debug only) Optimisation. (1) Minimize Size, (2) Maximize Speed.
string(REPLACE "/O2" "/O1" CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
string(REPLACE "/O2" "/O1" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REPLACE "/O2" "/O1" CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
string(REPLACE "/O2" "/O1" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
string(REPLACE "/O2" "/O1" CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL}")
string(REPLACE "/O2" "/O1" CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")

# (Non-debug only) Disable frame pointer omission (FPO).
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Oy")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Oy")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} /Oy")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Oy")
set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} /Oy")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /Oy")

# Inline function expansion.
target_compile_options(${PROJECT_NAME} PUBLIC
		$<$<CONFIG:Debug>:/Ob0>
		$<$<CONFIG:Release>:/Ob1>
		$<$<CONFIG:RelWithDbgInfo>:/Ob1>
		$<$<CONFIG:MinSizeRel>:/Ob1>)

# Build with multiple processes.
target_compile_options(${PROJECT_NAME} PUBLIC /MP2)
