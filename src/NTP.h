#ifndef NTP_H
#define NTP_H

/*
  This is an example file for using the time function in ESP8266 or ESP32 tu get NTP time
  It offers two functions:

  - getNTPtime(struct tm * info, uint32_t ms) where info is a structure which contains time
  information and ms is the time the service waits till it gets a response from NTP.
  Each time you cann this function it calls NTP over the net.

  If you do not want to call an NTP service every second, you can use
  - getTimeReducedTraffic(int ms) where ms is the the time between two physical NTP server calls. Betwwn these calls,
  the time structure is updated with the (inaccurate) timer. If you call NTP every few minutes you should be ok

  The time structure is called tm and has teh following values:

  Definition of struct tm:
  Member  Type  Meaning Range
  tm_sec  int seconds after the minute  0-61*
  tm_min  int minutes after the hour  0-59
  tm_hour int hours since midnight  0-23
  tm_mday int day of the month  1-31
  tm_mon  int months since January  0-11
  tm_year int years since 1900
  tm_wday int days since Sunday 0-6
  tm_yday int days since January 1  0-365
  tm_isdst  int Daylight Saving Time flag

  because the values are somhow akwardly defined, I introduce a function makeHumanreadable() where all values are adjusted according normal numbering.
  e.g. January is month 1 and not 0 And Sunday or monday is weekday 1 not 0 (according definition of MONDAYFIRST)

  Showtime is an example on how you can use the time in your sketch

  The functions are inspired by work of G6EJD ( https://www.youtube.com/channel/UCgtlqH_lkMdIa4jZLItcsTg )

*/

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <time.h>

const char *ssid = "Kebabhaus_5GHz";
const char *password = "1907eb1907";

const char *NTP_SERVER = "ch.pool.ntp.org";
const char *TZ_INFO = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00"; // enter your time zone (https://remotemonitoringsystems.ca/time-zone-abbreviations.php)

tm timeinfo;
time_t now;
unsigned long lastNTPtime;
unsigned long lastEntryTime;

void NTP_setup();
bool getNTPtime(int sec);
void showTime(tm localTime);

#endif