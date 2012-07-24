##########################################
  crumbs: portable stack traces for C++.
##########################################

:author: Andre Caron (andre.l.caron@gmail.com)


Introduction
============

This project is a simple and portable means of getting stack traces for C++
programs.  Using manual annotations ("crumbs"), you can register functions with
a tracer and access the current call stack at time.  The system is lightweight
and efficient (entering a function essentially consists in pushing a pointer
onto a preallocated stack).


Usage
=====

1. Build the library (see *Compiling* section below)

2. Embed in your CMake application (see *Embedding* section below) or configure
   your compiler to point to the appropriate include and library paths.

3. Sprinkle calls to ``leave_bread_crumbs()`` all over the place.

   ::

      #include <crumbs.hpp>

      int main (int, char **)
      {
          leave_bread_crumbs();

          // ...
      }

4. Use the call stack information somewhere in your program.

   The easiest way is to print a stack trace where desired:

   ::

      #include <iostream>
      #include <crumbs.hpp>

      class CustomException :
          public std::exception
      {
      public:
          CustomException ()
          {
              std::cerr
                  << "Error raised at:"   << std::endl
                  << crumbs::call_stack() << std::endl;
              // ...
          }
      };

   If you prefer to save the information for later (optional) display, you can
   save the current stack to save it as part of your exception object:

   ::

      class CustomException :
          public std::exception
      {
          crumbs::Stack myCallStack;
      public:
          CustomException ()
              : myCallStack(crumbs::call_stack())
          {
              // ...
          }

          const crumbs::Stack& call_stack () const {
              return (myCallStack);
          }
      };

5. Start using the advanced configuration.

   1. Enable/disable the library using compiler settings.  Have your compiler
      predefine the ``CRUMBS_ENABLE`` macro to 1 or 0 to conditionally compile
      the stack trace code.  It is set to 1 by default and is not automatically
      disabled when compiling in release (optimized) mode.

   2. Show file paths relative to your project root.  Have your compiler
      predefine the ``CRUMBS_ROOT_PATH`` macro to the prefix you with to
      remove.  If using CMake, define it as follows:

      ::

         add_definitions(
           -DCRUMBS_ROOT_PATH="${CMAKE_SOURCE_DIR}"
         )

   3. Implement the ``crumbs::call_stack()`` function for multi-threaded
      programs.  If using the crumbs library from multiple threads, you need to
      disable the default ``crumbs::call_stack()`` implementation by setting
      the ``CRUMBS_SINGLE_THREADED`` to 0 and implement the
      ``crumbs::call_stack()`` function to return a ``crumbs::Stack`` instance
      located in thead-local storege.  Refer to your threading library's
      documentation if necessary.


Compiling
=========

1. Get the source code.

   ::

      git clone git@github.com:AndreLouisCaron/crumbs.git
      cd crumbs
      git submodule init
      git submodule update

2. Generate build scripts.

   ::

      mkdir work
      cd work
      cmake -G "NMake Makefiles" ..

   If you prefer to use Visual Studio, generate a solution using one of the
   Visual Studio solution generators built-in to CMake.  Type ``cmake`` on
   the command line for a list of supported Visual Studio versions.

3. Compile the libraries and demo projects.

   ::

      nmake

   If you generated Visual Studio solution instead of the Makefiles, start
   Visual Studio, open the solution and build the project (``Ctrl+Shift+B``
   hotkey).

4. Build the API documentation.

   ::

      nmake help

   Open the ``help/html/index.html`` file (relative to the source code root)
   to consult the docmentation.


Embedding
=========

The preferred way to compile and install the library is to embed it in another
CMake project as a Git submodule.

1. Add ``crumbs`` as a submodule in your project.

   ::

      cd my-project
      mkdir libs
      git submodule add git://.../crumbs.git libs/crumbs

2. Add ``crumbs`` to the list of build targets in your root ``CMakeLists.txt``.

   ::

      # Locate crumbs and add its target(s).
      set(crumbs_DIR
        ${CMAKE_SOURCE_DIR}/libs/crumbs
      )
      find_package(crumbs)

      # Resolve <crumbs.hpp> anywhere your project.
      include_directories(${crumbs_include_dir})

3. Instruct other targets to link against ``crumbs``.

  ::

     # Make sure crumbs is built before dependent targets.
     add_dependencies(my-target
       crumbs
       # ...
     )

     # Have dependent targets link against crumbs.
     target_link_libraries(my-target
       crumbs
       # ...
     )


License
=======

This software is free for use in open source and commercial/closed-source
applications so long as you respect the terms of this 2-clause BSD license:

::

   Copyright (c) 2012, Andre Caron (andre.l.caron@gmail.com)
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
