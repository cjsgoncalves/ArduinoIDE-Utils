# Utils

### Carlos Gonçalves <cajocasa@gmail.com>
#### Version 1.0.1
<br/>
  
Utility functions and macros to print with arguments

This library provides utility functions and macros that behaves like the printf with arguments. The macros can be activated or deactivated using a global define (DebugMode). Activating the define `DebugMode` must be done globally to all the files that use the library.

The simplest way to accomplish this is set the define using the property `compiler.cpp.extra_flags`. To activate the define in the project files (including the libraries) edit the file **platform.local.txt** and add the option `-DDebugMode` to the existing property `compiler.cpp.extra_flags`.

The file **platform.local.txt** must be defined for each hardware platform. For example, for the ESP32 the file is: **\$HOMEPATH\$\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.6** where **\$HOMEPATH\$** is the home directory of the user (e.g. *C:\Users\cgonc*)
