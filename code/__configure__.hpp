#ifndef _crumbs_configure_hpp__
#define _crumbs_configure_hpp__

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

// Unless explicitly disabled.
#ifndef CRUMBS_ENABLED
#   define CRUMBS_ENABLED 1
#endif

// Default to single threaded mode.
#if CRUMBS_ENABLED
#   ifndef CRUMBS_SINGLE_THREADED
#      define CRUMBS_SINGLE_THREADED 1
#   endif
#endif

/*!
 * @def CRUMBS_STACK_DEPTH
 * @brief Maximum stack depth for pre-allocated call stacks.
 *
 * This constant is used to avoid dynamic memory allocation in @c Stack in
 * order to guarantee safe use in exception classes.  See the Error and
 * Exception Handling in the Boost documentation for details on why dynamic
 * memory allocation in exception classes can cause @c std::terminate() to be
 * called.
 *
 * If not defined, it defaults to 8.
 *
 * @warning Do not try to set this value using a @c #define preprocessor
 *  directive in source files: this could easily result in incompatible
 *  definitions across compilation units.  Instead, prefer to set this macro
 *  using a compiler option.  See your compiler documentation for details.
 *
 * @see http://www.boost.org/community/error_handling.html
 */

#ifndef CRUMBS_STACK_DEPTH
#   define CRUMBS_STACK_DEPTH 8
#endif

// Introspection is not portable :-(
#ifdef _MSC_VER
#   define CRUMBS_CURRENT_FUNCTION() __FUNCSIG__
#elif defined(__GNUC__)
#   define CRUMBS_CURRENT_FUNCTION() __PRETTY_FUNCTION__
#else
#   error "CRUMBS_CURRENT_FUNCTION() is not defined for current compiler."
#endif

#endif /* _crumbs_configure_hpp__ */
