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

#include "Entry.hpp"
#include <iostream>

namespace {

    // Some compilers tend to use absolute paths (most often when provided
    // absolute paths for input files).  Strip project root prefix if requested
    // to.

    bool equal (char lhs, char rhs) {
        return ((lhs == rhs) || (lhs == '/' && rhs == '\\'));
    }

    const char * advance (const char * path)
    {
#ifdef CRUMBS_ROOT_PATH
        const char * root = CRUMBS_ROOT_PATH;
        while (*root && *path && equal(*root,*path)) {
            ++root, ++path;
        }
#endif
        return (path);
    }

}

namespace crumbs {

    Entry::Entry (const char * file, int line, const char * function)
        : myFile(::advance(file))
        , myLine(line)
        , myFunction(function)
    {
    }

    const char * Entry::file () const
    {
        return (myFile);
    }

    int Entry::line () const
    {
        return (myLine);
    }

    const char * Entry::function () const
    {
        return (myFunction);
    }

    std::ostream& operator<< (std::ostream& stream, const Entry& entry)
    {
        return (stream << entry.function() << std::endl
                << "    [" << entry.file() << ":" << entry.line() << "]");
    }

}
