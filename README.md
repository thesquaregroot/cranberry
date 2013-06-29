cranberry
=========

A semi-natural-language code generation platform for projects that need similar data structures in multiple languages.

Cranberry is an open source program licensed under the GNU Lesser General Public License (LGPL).

Architecture
------------
Cranberry is structured as a recursive-descent parser, fed by tokens generated by flex.  The grammar and token definitions
can be found in the accompanying READEME file.

Dependencies
------------
Cranberry is written in C++ and has no external dependancies. Some of the code is generated with
flex, a lexical analyser, but the generated code should compile with any C++ compiler.

