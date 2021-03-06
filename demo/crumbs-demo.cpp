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

#include <crumbs.hpp>
#include <exception>
#include <iostream>

namespace {

    class CustomException :
        public std::exception
    {
        /* data. */
    private:
        crumbs::Stack myCallStack;

        /* construction. */
    public:
        CustomException ()
            : myCallStack(crumbs::current_frame())
        {}

        /* methods. */
    public:
        const crumbs::Stack& call_stack () const {
            return (myCallStack);
        }
    };

    void do_something ()
    {
        leave_bread_crumbs();

        // Print the current call stack.
        std::cerr
            << crumbs::call_stack
            << std::endl;

        // Make sure the caller gets a chance to print it too!
        throw (CustomException());
    }

}

int main (int, char **)
try
{
    leave_bread_crumbs();

    ::do_something();
}
catch (const ::CustomException& error)
{
    std::cerr
        << "Uncaught error at:" << std::endl
        << error.call_stack()   << std::endl;
    return (EXIT_FAILURE);
}
catch (const std::exception& error)
{
    std::cerr
        << "Uncaught error: '" << error.what() << "'."
        << std::endl;
    return (EXIT_FAILURE);
}
catch (...)
{
    std::cerr
        << "Unknown error."
        << std::endl;
    return (EXIT_FAILURE);
}
