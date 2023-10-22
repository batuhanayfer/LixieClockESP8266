#include "NTP.h"

void NTP_setup()
{
    Serial.begin(115200);
    Serial.println("\n\nNTP Time Test\n");
    WiFi.begin(ssid, password);

    int counter = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        if (++counter > 100)
            ESP.restart();
        Serial.print(".");
    }
    Serial.println("\n\nWiFi connected\n\n");

    configTime(0, 0, NTP_SERVER);
    // See https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv for Timezone codes for your region
    setenv("TZ", TZ_INFO, 1);

    if (getNTPtime(10))
    { // wait up to 10sec to sync
    }
    else
    {
        Serial.println("Time not set");
        ESP.restart();
    }
    showTime(timeinfo);
    lastNTPtime = time(&now);
    lastEntryTime = millis();
}

bool getNTPtime(int sec)
{

    {
        uint32_t start = millis();
        do
        {
            time(&now);
            localtime_r(&now, &timeinfo);
            Serial.print(".");
            delay(10);
        } while (((millis() - start) <= (unsigned long)(1000 * sec)) && (timeinfo.tm_year < (2016 - 1900)));
        if (timeinfo.tm_year <= (2016 - 1900))
        {
            return false; // the NTP call was not successful
        }
        Serial.print("now ");
        Serial.println(now);
        char time_output[30];
        strftime(time_output, 30, "%a  %d-%m-%y %T", localtime(&now));
        Serial.println(time_output);
        Serial.println();
    }
    return true;
}

// This function is obsolete because the time() function only calls the NTP server every hour. So you can always use getNTPtime()
// It can be deleted and only stays here for the video

/*
  void getTimeReducedTraffic(int sec) {
  tm *ptm;
  if ((millis() - lastEntryTime) < (1000 * sec)) {
    now = lastNTPtime + (int)(millis() - lastEntryTime) / 1000;
  } else {
    lastEntryTime = millis();
    lastNTPtime = time(&now);
    now = lastNTPtime;
    Serial.println("Get NTP time");
  }
  ptm = localtime(&now);
  timeinfo = *ptm;
  }
*/

void showTime(tm localTime)
{
    Serial.print(localTime.tm_mday);
    Serial.print('/');
    Serial.print(localTime.tm_mon + 1);
    Serial.print('/');
    Serial.print(localTime.tm_year - 100);
    Serial.print('-');
    Serial.print(localTime.tm_hour);
    Serial.print(':');
    Serial.print(localTime.tm_min);
    Serial.print(':');
    Serial.print(localTime.tm_sec);
    Serial.print(" Day of Week ");
    if (localTime.tm_wday == 0)
        Serial.println(7);
    else
        Serial.println(localTime.tm_wday);
}
