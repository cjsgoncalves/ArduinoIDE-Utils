#ifndef _Utils_h_
#define _Utils_h_

#include <Arduino.h>
#include <Print.h>

/**
	\brief
	Print formatted data (equivalent to standard C printf) to Serial

	Writes the C string pointed by <b>sFmt</b> to <b>Serial</b>

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.

	\param <b>sFmt</b> C string that contains the text to be written to <b>Serial</b>
*/
void myPrintf(const char* sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to Serial

	Writes the Arduino String object <b>sFmt</b> to <b>Serial< /b>

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param <b>sFmt</b> Arduino String object that contains the text to be written to <b>Serial</b>
*/
void myPrintf(const String& sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to Serial

	Writes the C string pointed by <b>sFmt</b> to <b>Serial</b>

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param <b>pr</b> Arduino Print object that suports the <b>print</b> and <b>println<b> methods
	\param <b>sFmt</b> Arduino String object that contains the text to be written to <b>Serial</b>
*/
void myPrintf(Print& pr, const char* sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to Serial

	Writes the Arduino String object <b>sFmt</b> to the specified <b>Print<b>

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param <b>pr</b> Arduino Print object that suports the <b>print</b> and <b>println<b> methods
	\param <b>sFmt</b> Arduino String object that contains the text to be written to <b>Serial</b>
*/
void myPrintf(Print& pr, const String& sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to a C string

	Writes the C string pointed by <b>sFmt</b> to a c string

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param sFmt Arduino String object that contains the text to be written to Serial
	
	\return the formated string. Caller must call delete in the returned value in order to free allocated resources
*/
char* format(const char* sFmt, ...);

#define serialBegin(speed) { Serial.begin(speed); while (!Serial); }

#ifdef DebugMode
	#define DebugMessagePrintf(...) { myPrintf(__VA_ARGS__); }
	
	#define DebugSerialBegin(speed) { Serial.begin(speed); while (!Serial); }
	
	#define DebugDelay(amount) { delay(amount); }
#else
	#define DebugMessagePrintf(...) { }
	
	#define DebugSerialBegin(speed) { }
	
	#define DebugDelay(amount) { }
#endif

#endif // _Utils_h_
