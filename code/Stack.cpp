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

    Stack::Stack (const Frame * frame)
        : mySize(0)
    {
        const std::size_t n = CRUMBS_STACK_DEPTH;
        for (; (mySize < n) && (frame != 0); frame = frame->parent()) {
            myData[mySize++] = frame->entry();
        }
    }

    Stack::Stack (const Stack& other)
        : mySize(0)
    {
        iterator current = other.begin();
        const iterator end = other.end();
        for (; (current != end); ++current) {
            myData[mySize++] = *current;
        }
    }

    std::size_t Stack::size () const
    {
        return (mySize);
    }

    bool Stack::empty () const
    {
        return (mySize == 0);
    }

    Stack::iterator Stack::begin () const
    {
        return (myData);
    }

    Stack::iterator Stack::end () const
    {
        return (myData + mySize);
    }

    std::ostream& operator<< (std::ostream& stream, const Stack& stack)
    {
        Stack::iterator current = stack.begin();
        const Stack::iterator end = stack.end();
        for (; (current != end); ++current) {
            stream << *current << std::endl;
        }
        return (stream);
    }

    std::ostream& call_stack (std::ostream& stream)
    {
        const Frame * frame = current_frame();
        for (; (frame != 0); frame = frame->parent()) {
            stream << frame->entry() << std::endl;
        }
        return (stream);
    }

    std::vector<Entry> full_call_stack ()
    {
        std::vector<Entry> frames;
        const Frame * frame = current_frame();
        for (; (frame != 0); frame = frame->parent()) {
            frames.push_back(frame->entry());
        }
        return (frames);
    }

}
