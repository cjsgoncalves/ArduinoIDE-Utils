#include <Utils.h>

void myPrintf(const char* sFmt, ...) {
  char msgBuf[1024];

  va_list args;

  va_start( args, sFmt );
  vsprintf( msgBuf, sFmt, args );
  va_end( args );
  
  Serial.print( msgBuf );  
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvarargs"
void myPrintf(const String& sFmt, ...) {
  char msgBuf[1024];

  va_list args;

  va_start( args, sFmt.c_str() );
  vsprintf( msgBuf, sFmt.c_str(), args );
  va_end( args );
  
  Serial.print( msgBuf );
}
#pragma GCC diagnostic pop

void myPrintf(Print& pr, const char* sFmt, ...) {
  char msgBuf[1024];

  va_list args;

  va_start( args, sFmt );
  vsprintf( msgBuf, sFmt, args );
  va_end( args );
  
  pr.print( msgBuf );  
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvarargs"
void myPrintf(Print& pr, const String& sFmt, ...) {
  char msgBuf[1024];

  va_list args;

  va_start( args, sFmt.c_str() );
  vsprintf( msgBuf, sFmt.c_str(), args );
  va_end( args );
  
  pr.print( msgBuf );  
}
#pragma GCC diagnostic pop

char* format(const char* sFmt, ...) {
  char msgBuf[1024];

  va_list args;

  va_start( args, sFmt );
  int size;
  size = vsprintf( msgBuf, sFmt, args );
  va_end( args );
  
  char* result = new char[ size + 1 ];
  strcpy( result, msgBuf);
  
  return result;  
}
