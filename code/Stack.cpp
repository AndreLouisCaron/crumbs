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

#include "Stack.hpp"
#include "Entry.hpp"
#include "Frame.hpp"
#include <iostream>

namespace crumbs {

    Stack::Stack (std::size_t depth)
        : myFrames()
    {
        myFrames.reserve(depth);
    }

    std::size_t Stack::size () const
    {
        return (myFrames.size());
    }

    bool Stack::empty () const
    {
        return (myFrames.empty());
    }

    void Stack::push (const Entry& entry)
    {
        myFrames.push_back(&entry);
    }

    const Entry& Stack::top () const
    {
        return (*myFrames.back());
    }

    void Stack::pop ()
    {
        myFrames.pop_back();
    }

    Stack::iterator Stack::begin () const
    {
        return (myFrames.rbegin());
    }

    Stack::iterator Stack::end () const
    {
        return (myFrames.rend());
    }

    std::ostream& operator<< (std::ostream& stream, const Stack& stack)
    {
        Stack::iterator current = stack.begin();
        const Stack::iterator end = stack.end();
        for (; (current != end); ++current) {
            stream << **current << std::endl;
        }
        return (stream);
    }

}

#ifdef CRUMBS_SINGLE_THREADED
    crumbs::Stack& crumbs::call_stack ()
    {
        static crumbs::Stack
            __call_stack__;
        return (__call_stack__);
    }
#endif
