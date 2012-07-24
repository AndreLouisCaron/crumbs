##########################################
  crumbs: portable stack traces for C++.
##########################################

:author: Andre Caron (andre.l.caron@gmail.com)

Introduction
============

This project is a simple and portable means of getting stack traces for C++
programs.  Using manual annotations ("crumbs"), you can register functions with
a tracer and access the current call stack at time.  The system is lightweight
and efficient (entering a function essentially consists in pushing a pointer onto a preallocated stack).

Getting started
===============

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
