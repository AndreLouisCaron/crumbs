#ifndef _crumbs_Stack_hpp__
#define _crumbs_Stack_hpp__

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
#include <iosfwd>
#include <vector>

namespace crumbs {

    class Entry;
    class Frame;

    class Stack
    {
        /* nested types. */
    public:
        typedef std::vector<const Entry*>::const_reverse_iterator iterator;

        /* data. */
    private:
        std::vector<const Entry*> myFrames;

        /* construction. */
    public:
        Stack (std::size_t depth=32);

        /* methods. */
    public:
        std::size_t size () const;
        bool empty () const;
        void push (const Entry& entry);
        const Entry& top () const;
        void pop ();

        iterator begin () const;
        iterator end () const;
    };

    std::ostream& operator<< (std::ostream& stream, const Stack& stack);

    /*!
     * @brief Access the current call stack.
     *
     * If @c CRUMBS_SINGLE_THREADED is 1 (the default), crumbs provides its own
     * definition for this function.  In multi-threaded programs, this
     * definition is unsafe and you should provide your own theaad-local call
     * stack object.
     *
     * @see CRUMBS_SINGLE_THREADED
     */
    crumbs::Stack& call_stack ();

}

#endif /* _crumbs_Stack_hpp__ */
