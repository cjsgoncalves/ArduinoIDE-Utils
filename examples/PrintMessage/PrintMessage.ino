/*
 * Setting the macro "DebugMode" here only works for files that exists in the projet directory.
 * 
 * In order for the macro work in all files (including the libraries) we need to define the macro in the compiler command line
 * For each platfor edit the file "platform.local.txt" and add the option:
 * 
 * -DDebugMode
 * 
 * to the properties "compiler.cpp.extra_flags"
 * 
 * The file "platform.local.txt" must be defined for each hardware platform.
 * 
 * For example, for the ESP32 the file is:
 * 
 * $HOMEPATH$\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.6
 * 
 * where $HOMEPATH$ is the home directory of the user (in my case is C:\Users\cgonc )
 */

#include <Utils.h>

String myString1( "%s %d using a String\n" );

const String myString2( "%s %d using a const String\n" );

void setup() {
  DebugDelay( 2000 );

  DebugSerialBegin( 115200 );

  // The next message is allways printed
  myPrintf( "%s %d using a char*\n", "Printf", 4 );

  // The next message is printed only if the compliler flag -DDebugMode is set
  DebugMessagePrintf( myString1, "Printf", 4 );

  myPrintf( Serial, "%s %d using a char*\n", "Printf", 4 );

  myPrintf( Serial, myString2, "Printf", 4 );
}

void loop() {
}
