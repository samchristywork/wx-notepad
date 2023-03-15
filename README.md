![Banner](https://s-christy.com/status-banner-service/wx-notepad/banner-slim.svg)

## Overview

This repository aims to be as faithful a recreation of Microsoft Notepad as
possible using the wxWidgets GUI library. I am focusing on the Windows 10
version of Notepad.

## Screenshots

## Features

## Usage

Simply invoke the program with zero or more file names as command-line
arguments.

## Dependencies

You will need a C++ compiler. The default compiler used by this project is
Clang. If you aren't using Clang, then you will need to replace `clang++` with
your compiler in the `Makefile`.

You will need the wxWidgets development library. On ubuntu, this can be acquired
by installing the `libwxgtk3.0-gtk3-dev` library.

You will also need `make`.

## Limitations

- Some style stuff like the scroll bar is dependant on wxWidgets styling.
- The "Help" documentation is different.
- The Time/Date format is likely locale dependant on Windows, but I didn't bother with that for this project.
- No Print/Page Setup... because printers are the devil.
- No check marks next to menu items.
- No disabling menu items.
- I don't use the official Notepad icon in the title bar.

## License

This work is licensed under the GNU General Public License version 3 (GPLv3).

[<img src="https://s-christy.com/status-banner-service/GPLv3_Logo.svg" width="150" />](https://www.gnu.org/licenses/gpl-3.0.en.html)
