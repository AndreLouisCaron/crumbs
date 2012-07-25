#ifndef _crumbs_hpp__
#define _crumbs_hpp__

// Copyright (c) 2012, Andre Caron (andre.l.caron@gmail.com)
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "__configure__.hpp"

/*!
 * @brief Crumbs library.
 */
namespace crumbs {}

#include "Entry.hpp"
#include "Frame.hpp"
#include "Stack.hpp"

/*!
 * @def CRUMBS_ENABLED
 * @brief Enables or disables stack trace management.
 *
 * If undefined, this value is automatically defined to 1.  Explictly set it to
 * 0 if stack tracing is to be disabled.  Rationale: it is assumed that linking
 * against this library means wanting stack traces.
 *
 * @see leave_bread_crumbs()
 */

/*!
 * @def CRUMBS_ROOT_PATH
 * @brief Path prefix to strip from source file names.
 *
 * Define this macro when building the library to strip the path from source
 * file names.
 */

/*!
 * @def leave_bread_crumbs()
 * @brief Register the current function for execution.
 *
 * If @c CRUMBS_ENABLED is 0, this macro evaluates to nothing and absolutely no
 * performance penalty is incurred at runtime.  The downside is that the
 * program will not be able to trace its execution.
 *
 * @note This macro creates two local variables named @c __entry__ and @c
 *  __frame__.  Avoid using those names for other symbols in the current
 *  scope.
 *
 * @see CRUMBS_ENABLED
 */

#ifdef CRUMBS_ENABLED
#   define leave_bread_crumbs()\
        static const crumbs::Entry __entry__\
            (__FILE__, __LINE__, CRUMBS_CURRENT_FUNCTION()); \
        const crumbs::Frame __frame__(__entry__);
#else
#   define leave_bread_crumbs()
#endif

#endif /* _crumbs_hpp__ */
