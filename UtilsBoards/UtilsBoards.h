#ifndef _UtilsBoards_h_
#define _UtilsBoards_h_

#ifdef ARDUINO_TTGO_LoRa32_V1
  // ESP32 – TTGO LoRa32-OLED V1
  #define BOARD_TYPE_1
  #define BOARD_FAMILY	"ESP32"
  #define BOARD_NAME	"ESP32 – TTGO LoRa32-OLED V1"

  #else
    #ifdef ARDUINO_TTGO_T1
      // ESP32 – TTGO T1
      #define BOARD_TYPE_2
      #define BOARD_FAMILY	"ESP32"
      #define BOARD_NAME	"ESP32 – TTGO T1"

    #else
      #ifdef ARDUINO_ESP32_DEV
        // ESP32 – DOIT ESP32 DEVKIT V1
        #define BOARD_TYPE_3
        #define BOARD_FAMILY	"ESP32"
        #define BOARD_NAME	"ESP32 – DOIT DEVKIT V1"

      #else
        #ifdef ARDUINO_ESP8266_WEMOS_D1MINI
           // ESP8266 – LOLIN (WEMOS) D1 R2 & mini
           #define BOARD_TYPE_4
           #define BOARD_FAMILY	"ESP8266"
           #define BOARD_NAME	"ESP8266 – LOLIN (WEMOS) D1 R2"

           #else
             #ifdef ARDUINO_ESP8266_GENERIC
               // ESP8266 – Generic
               #define BOARD_TYPE_5
               #define BOARD_FAMILY	"ESP8266"
               #define BOARD_NAME	"Generic ESP8266"

             #else
               // None of the above boards
               #define BOARD_TYPE_6
               #define BOARD_FAMILY	"Unknown"
               #define BOARD_NAME	"Unknown"
             #endif
        #endif
    #endif
  #endif
#endif

#ifdef BOARD_TYPE_1		// ESP32 – TTGO LoRa32-OLED V1
  #include <WiFi.h>
  #include <WiFiMulti.h>
  #include <ESPmDNS.h>
  
  #include <AsyncTCP.h>
  
  #include <SPIFFS.h>
  
  // Internal led pin
  #define LED_INTERNAL_PIN 2

  // I2C pins
  #define SDA 21
  #define SCL 22
#endif

#ifdef BOARD_TYPE_2		// ESP32 – TTGO T1
  #include <WiFi.h>
  #include <WiFiMulti.h>
  #include <ESPmDNS.h>
  
  #include <AsyncTCP.h>
  
  #include <SPIFFS.h>
  
  // Internal led pin
  #define LED_INTERNAL_PIN 22

  // I2C pins
  #define SDA 21
  #define SCL 22
#endif

#ifdef BOARD_TYPE_3		// ESP32 – DOIT ESP32 DEVKIT V1
  #include <WiFi.h>
  #include <WiFiMulti.h>
  #include <ESPmDNS.h>
  
  #include <AsyncTCP.h>
  
  #include <SPIFFS.h>

  // Internal led pin
  #define LED_INTERNAL_PIN 2

  // I2C pins
  #define SDA 21
  #define SCL 22
#endif

#ifdef BOARD_TYPE_4		// ESP8266 – LOLIN (WEMOS) D1 R2 & mini
  #include <ESP8266WiFi.h>
  #include <ESP8266WiFiMulti.h>
  #include <ESP8266mDNS.h>
  
  #include <ESPAsyncTCP.h>
  
  #include <FS.h>

  // Internal led pin
  #define LED_INTERNAL_PIN 2

  // I2C pins
  #define SDA 19
  #define SCL 20
  
  typedef ESP8266WiFiMulti WiFiMulti;
#endif

#ifdef BOARD_TYPE_5		// ESP8266 – Generic
  #include <ESP8266WiFi.h>
  #include <ESP8266WiFiMulti.h>
  #include <ESP8266mDNS.h>
  
  #include <ESPAsyncTCP.h>
  
  #include <FS.h>
  
  typedef ESP8266WiFiMulti WiFiMulti;

  // Internal led pin
  #define LED_INTERNAL_PIN 1

  // I2C pins
  #define SDA 0
  #define SCL 2	
#endif

#ifdef BOARD_TYPE_6		// Other Boards

  // Internal led pin
  #define LED_INTERNAL_PIN 1
  
  typedef void WiFiMulti;
#endif

#include <Print.h>

typedef struct {
	const char* ssid;
	const char* password;
} WiFiMultiEntry, * PtrWiFiMultiEntry;

// Turn inboard LED ON
#define internalLedOn()  digitalWrite( LED_INTERNAL_PIN, LOW )

// Turn inboard LED OFF
#define internalLedOff() digitalWrite( LED_INTERNAL_PIN, HIGH )

void blinkInternalLed(int onTime, int offTime);

void initInternalLed();

void showBoardType(Print& pr=Serial);

void initWiFi(const char* ssid, const char* password, const bool blinkInternal=false, const char* hostName=NULL, Print& pr=Serial);

void initWiFi(PtrWiFiMultiEntry creds, int sizeOfCreds, const bool blinkInternal=false, const char* hostName=NULL, Print& pr=Serial);

#endif // _UtilsBoards_h_
