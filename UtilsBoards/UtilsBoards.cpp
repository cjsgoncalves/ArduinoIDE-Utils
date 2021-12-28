#include <Arduino.h>

#include <Utils.h>
#include <UtilsBoards.h>

// Value in milliseconds
const int ConnSleepTimeOn	= 250;

// Value in milliseconds
const int ConnSleepTimeOff	= 250;

// Value in seconds
const int ConnectionTimeOut	= 30;
const int ConnSleepTime		= (ConnSleepTimeOn+ConnSleepTimeOff);

const int ConnectionSteps	= ( 1000 / ConnSleepTime)*ConnectionTimeOut;

void showBoardType(Print& pr) {
  myPrintf( pr, "Board family: %s\n", BOARD_FAMILY );
  myPrintf( pr, "Board name: %s\n", BOARD_NAME );
}

void blinkInternalLed(int onTime, int offTime) {
  internalLedOn();
  delay( onTime );
  internalLedOff();
  delay( offTime );
}

void initInternalLed() {
  pinMode( LED_BUILTIN, OUTPUT );
  internalLedOff();
}

void waitAndReset(int& counter, const bool blinkInternal, Print& pr) {

  #ifdef DebugModeWiFi 
	DebugMessagePrintf( pr, "(Counter=%3d, ConnectionSteps=%3d, ConnSleepTime=%5d)\n", counter, ConnectionSteps, ConnSleepTime );
  #else
	DebugMessagePrintf( pr, "." );  
  #endif
  
  if ( blinkInternal==true ) {
    blinkInternalLed( ConnSleepTimeOn, ConnSleepTimeOff );
  }
  else {
    delay( ConnSleepTime );
  }
    
  if ( ++counter>ConnectionSteps ) {
    // After "ConnectionTimeOut" there was no connection to WiFi
    DebugMessagePrintf( pr, "\nAfter %d seconds there was no connection to WiFi.\n", ConnectionTimeOut );
    DebugMessagePrintf( pr, "Resetting device..." );
    ESP.restart();
  }
}

void initWiFi(const char* ssid, const char* password, const bool blinkInternal, const char* hostName, Print& pr) {
  #ifdef DebugMode
    unsigned long timeOnInitWiFiBegin = millis();
  #endif
  
  DebugMessagePrintf(     
    pr,
    "Initializing WiFi(%s, ******, %s, board host name=%s, Print&)\n\n",
    ssid,
    blinkInternal==true ? "blinkOn" : "blinkOff", 
    hostName!=NULL ? hostName : "Not set" );

  WiFi.disconnect();
  WiFi.mode( WIFI_STA );

  if ( hostName!=NULL ) {
    DebugMessagePrintf( "Setting hostName to \"%s\".\n", hostName );

    #ifdef ESP8266
      WiFi.hostname( hostName );
    #endif

    #ifdef ESP32
      WiFi.config( INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE );
      WiFi.setHostname( hostName );
    #endif
  }

  WiFi.begin( ssid, password );

  int counter = 0;
  // Wait for connection
  while ( WiFi.status()!=WL_CONNECTED ) {
    waitAndReset( counter, blinkInternal, pr);
  }

  if ( blinkInternal==true ) {
    internalLedOff();
  }
  
  // We are connected
  DebugMessagePrintf( pr, "\nSSID: %s\n", WiFi.SSID().c_str() );
  DebugMessagePrintf( pr, "IP: %s\n", WiFi.localIP().toString().c_str() );
  DebugMessagePrintf( pr, "RSSI: %d dBm\n", WiFi.RSSI() );

  #ifdef DebugMode
    DebugMessagePrintf( "WiFi initialized in %ld miliseconds.\n" , ( (unsigned long) (millis() - timeOnInitWiFiBegin) ) );
  #endif
}

void initWiFi(PtrWiFiMultiEntry creds, int sizeOfCreds, const bool blinkInternal, const char* hostName, Print& pr) {
  #ifdef DebugMode
    unsigned long timeOnInitWiFiBegin = millis();
  #endif

  DebugMessagePrintf( 
    pr, 
    "Initializing WiFi(PtrWiFiMultiEntry, %d, %s, board host name=%s, Print&)\n\n", 
    sizeOfCreds,
    blinkInternal==true ? "blinkOn" : "blinkOff", 
    hostName!=NULL ? hostName : "Not set" );

  WiFi.disconnect();
  WiFi.mode( WIFI_STA );
  
  WiFiMulti wifiMulti;
  
  for( int idxCreds=0; idxCreds<sizeOfCreds; ++idxCreds) {
    DebugMessagePrintf( pr, "Adding %s SSID\n", creds[ idxCreds ].ssid );
    wifiMulti.addAP( creds[ idxCreds ].ssid, creds[ idxCreds ].password );
  }
  
  DebugMessagePrintf( "Done adding credentials.\n" );
  
  if ( hostName!=NULL ) {
    DebugMessagePrintf( "Setting hostName to \"%s\".\n", hostName );

    #ifdef ESP8266
      WiFi.hostname( hostName );
    #endif

    #ifdef ESP32
      WiFi.config( INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE );
      WiFi.setHostname( hostName );
    #endif
  }

  int counter = 0;
  // Wait for connection
  while ( wifiMulti.run()!=WL_CONNECTED ) {
    waitAndReset( counter, blinkInternal, pr);
  }

  if ( blinkInternal==true ) {
    internalLedOff();
  }

  WiFi.setAutoReconnect( true );
  WiFi.persistent( true );

  // We are connected
  DebugMessagePrintf( pr, "\nSSID: %s\n", WiFi.SSID().c_str() );
  DebugMessagePrintf( pr, "IP: %s\n", WiFi.localIP().toString().c_str() );
  DebugMessagePrintf( pr, "RSSI: %d dBm\n", WiFi.RSSI() );

  #ifdef DebugMode
    DebugMessagePrintf( "WiFi initialized in %ld miliseconds.\n" , ( (unsigned long) (millis() - timeOnInitWiFiBegin) ) );
  #endif
}
