/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Custom assertion macros with installable custom handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "fatal.h"
#include <cassert>
#include <cstdlib>


extern bool TSPP_IgnoreAllAsserts;
extern bool TSPP_SilentAsserts;
extern bool TSPP_ExitOnAssert;

enum TSPPAssertType {
    TSPP_ASSERT_NORMAL,
    TSPP_ASSERT_FATAL,
};

extern void (*TSPP_Assertion_Handler_Ptr)(TSPPAssertType type, const char* expr, const char* file, int line, const char* function, volatile bool* ignore, volatile bool* allow_break, volatile bool* exit, const char* msg, ...);

void TSPP_Install_Assertion_Handler(void (*handler_ptr)(TSPPAssertType, const char*, const char*, int, const char*, volatile bool*, volatile bool*, volatile bool*, const char*, ...));

#define TSPP_ASSERT(exp)                                                                                                                                                              \
    do {                                                                                                                                                                              \
        if (TSPP_Assertion_Handler_Ptr && !TSPP_IgnoreAllAsserts) {                                                                                                                   \
            static volatile bool _ignore_assert = false;                                                                                                                              \
            static volatile bool _break = false;                                                                                                                                      \
            static volatile bool _exit = false;                                                                                                                                       \
            if (!_ignore_assert) {                                                                                                                                                    \
                if (!(exp)) {                                                                                                                                                         \
                    TSPP_Assertion_Handler_Ptr(TSPP_ASSERT_NORMAL, #exp, __FILE__, __LINE__, __FUNCTION__, &_ignore_assert, &_break, &_exit, nullptr);                                \
                    if (_break) {                                                                                                                                                     \
                        __debugbreak();                                                                                                                                               \
                    }                                                                                                                                                                 \
                    if (_exit || TSPP_ExitOnAssert) {                                                                                                                                 \
                        Emergency_Exit(EXIT_FAILURE);                                                                                                                                 \
                    }                                                                                                                                                                 \
                }                                                                                                                                                                     \
            }                                                                                                                                                                         \
        }                                                                                                                                                                             \
    } while (false)

#define TSPP_ASSERT_PRINT(exp, msg, ...)                                                                                                                                              \
    do {                                                                                                                                                                              \
        if (TSPP_Assertion_Handler_Ptr && !TSPP_IgnoreAllAsserts) {                                                                                                                   \
            static volatile bool _ignore_assert = false;                                                                                                                              \
            static volatile bool _break = false;                                                                                                                                      \
            static volatile bool _exit = false;                                                                                                                                       \
            if (!_ignore_assert) {                                                                                                                                                    \
                if (!(exp)) {                                                                                                                                                         \
                    TSPP_Assertion_Handler_Ptr(TSPP_ASSERT_PRINT, #exp, __FILE__, __LINE__, __FUNCTION__, &_ignore_assert, &_break, &_exit, msg, ##__VA_ARGS__);                      \
                    if (_break) {                                                                                                                                                     \
                        __debugbreak();                                                                                                                                               \
                    }                                                                                                                                                                 \
                    if (_exit || TSPP_ExitOnAssert) {                                                                                                                                 \
                        Emergency_Exit(EXIT_FAILURE);                                                                                                                                 \
                    }                                                                                                                                                                 \
                }                                                                                                                                                                     \
            }                                                                                                                                                                         \
        }                                                                                                                                                                             \
    } while (false)

#define TSPP_ASSERT_FATAL(exp, ...)                                                                                                                                                   \
    do {                                                                                                                                                                              \
        if (TSPP_Assertion_Handler_Ptr && !TSPP_IgnoreAllAsserts) {                                                                                                                   \
            static volatile bool _ignore_assert = false;                                                                                                                              \
            static volatile bool _break = false;                                                                                                                                      \
            static volatile bool _exit = false;                                                                                                                                       \
            if (!_ignore_assert) {                                                                                                                                                    \
                if (!(exp)) {                                                                                                                                                         \
                    TSPP_Assertion_Handler_Ptr(TSPP_ASSERT_FATAL, #exp, __FILE__, __LINE__, __FUNCTION__, &_ignore_assert, &_break, &_exit, nullptr, ##__VA_ARGS__);                  \
                    if (_break) {                                                                                                                                                     \
                        __debugbreak();                                                                                                                                               \
                    }                                                                                                                                                                 \
                    Emergency_Exit(EXIT_FAILURE);                                                                                                                                     \
                }                                                                                                                                                                     \
            }                                                                                                                                                                         \
        }                                                                                                                                                                             \
    } while (false)

#define TSPP_ASSERT_FATAL_PRINT(exp, msg, ...)                                                                                                                                        \
    do {                                                                                                                                                                              \
        if (TSPP_Assertion_Handler_Ptr && !TSPP_IgnoreAllAsserts) {                                                                                                                   \
            static volatile bool _ignore_assert = false;                                                                                                                              \
            static volatile bool _break = false;                                                                                                                                      \
            static volatile bool _exit = false;                                                                                                                                       \
            if (!_ignore_assert) {                                                                                                                                                    \
                if (!(exp)) {                                                                                                                                                         \
                    TSPP_Assertion_Handler_Ptr(TSPP_ASSERT_FATAL, #exp, __FILE__, __LINE__, __FUNCTION__, &_ignore_assert, &_break, &_exit, msg, ##__VA_ARGS__);                      \
                    if (_break) {                                                                                                                                                     \
                        __debugbreak();                                                                                                                                               \
                    }                                                                                                                                                                 \
                    Emergency_Exit(EXIT_FAILURE);                                                                                                                                     \
                }                                                                                                                                                                     \
            }                                                                                                                                                                         \
        }                                                                                                                                                                             \
    } while (false)
