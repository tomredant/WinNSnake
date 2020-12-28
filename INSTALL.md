# WinNSnake Installation How-To

This file tells you how to manually install WinNSnake (a Windows port of NSnake) on Windows systems. WinNSnake is NSnake with a few minor modifications to make it work in Windows. The build has been verified on a Mingw-w64 environment. There is no need for MSYS. Instead, Qmake as part of Qt is used.

## Dependencies

WinNSnake only depends on `PDCurses`; it's used to show cute things on the terminal.

Make sure you have downloaded and compiled PDCurses by means with its default settings.

## Installation

You may first have to make sure all path variables are set accordingly to make sure the toolchain and qmake executable is found.  Furthermore, edit the WinNSnake.pro file (last two lines of the file), pointing to the directory in which PDCurses is installed.
Briefly, the following shell commands should configure,
and build this package:

    $ qmake
    $ make

Further reading on the version on which this is based: 
https://github.com/alexdantas/nSnake/

