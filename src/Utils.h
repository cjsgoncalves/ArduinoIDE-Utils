#ifndef _Utils_h_
#define _Utils_h_

#include <Arduino.h>
#include <Print.h>

/**
	\brief
	Print formatted data (equivalent to standard C printf) to the default <b><code>Serial</code></b> port.

	Writes the C string pointed by <b><code>sFmt</code></b> to the <b><code>Serial</code></b> port.

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.

	\param sFmt C string that contains the text to be written to the default <b><code>Serial</code></b> port
*/
void myPrintf(const char* sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to the default <b><code>Serial</b></code> port.

	Writes the Arduino <code>String</code> object <b><code>sFmt</code></b> to the <b><code>Serial</code></b> port.

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param sFmt Arduino <code>String</code> object that contains the text to be written to the default <b><code>Serial</code></b> port
*/
void myPrintf(const String& sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to a <b><code>Print</code></b> object.

	Writes the C string pointed by <b><code>sFmt</code></b> to a <b><code>Print</code></b> object such as a <b><code>Serial</code></b> port or a display that <i>"implements"</i> the <b><code>Print</code></b> interface.

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param pr Arduino <code>Print</code> object that suports the <b><code>print</code></b> and <b><code>println</code></b> methods
	\param sFmt Arduino <code>String</code> object that contains the text to be written to the <b><code>Print</code></b> argument
*/
void myPrintf(Print& pr, const char* sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to a <b><code>Print</code></b> object.

	Writes the Arduino <code>String</code> object <b><code>sFmt</code></b> to a <b><code>Print</code></b> object such as a <b><code>Serial</code></b> port or a display that <i>"implements"</i> the <b><code>Print</code></b> interface.

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param pr Arduino <code>Print</code> object that suports the <b><code>print</code></b> and <b><code>println</code></b> methods
	\param sFmt Arduino <code>String</code> object that contains the text to be written to the <b><code>Print</code></b> argument
*/
void myPrintf(Print& pr, const String& sFmt, ...);


/**
	\brief
	Print formatted data (equivalent to standard C printf) to a C string

	Writes the C string pointed by <b>sFmt</b> to a C string

	If format includes format specifiers (subsequences beginning with %), 
	the additional arguments following format are formatted and inserted in 
	the resulting string replacing their respective specifiers.
	
	\param sFmt Arduino String object that contains the text to be written to Serial
	
	\return the formated string. Caller must delete the returned value in order to free allocated memory
*/
char* format(const char* sFmt, ...);

/**
	\brief
	An utility macro that initialize the default Serial port and waits until the port is ready
*/
#define serialBegin(speed) { Serial.begin(speed); while (!Serial); }

#ifdef DebugMode
	/**
		\brief
		An utility macro that is expanded to myPrintf(...) only if the define <b>DebugMode</b> is active.
	*/
	#define DebugMessagePrintf(...) { myPrintf(__VA_ARGS__); }
	
	/**
		\brief
		An utility macro that is expanded to serialBegin(...) only if the define <b>DebugMode</b> is active.
	*/
	#define DebugSerialBegin(speed) { serialBegin(speed); }

	/**
		\brief
		An utility macro that is expanded to delay(...) only if the define <b>DebugMode</b> is active.
	*/	
	#define DebugDelay(amount) { delay(amount); }
#else
	/**
		\brief
		An utility macro that is expanded to myPrintf(...) only if the define <b>DebugMode</b> is active.
	*/
	#define DebugMessagePrintf(...) { }
	
	/**
		\brief
		An utility macro that is expanded to serialBegin(...) only if the define <b>DebugMode</b> is active.
	*/
	#define DebugSerialBegin(speed) { }
	
	/**
		\brief
		An utility macro that is expanded to delay(...) only if the define <b>DebugMode</b> is active.
	*/
	#define DebugDelay(amount) { }
#endif

#endif // _Utils_h_
