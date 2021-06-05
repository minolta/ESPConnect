#ifndef CONNECT_H
#define CONNECT_H
#include <Arduino.h>
#include <WiFiMulti.h>
#include <ESP32Ping.h>

class ConnectObj
{
private:
    WiFiMulti wifiMulti;
    String ssid;
    String password;
    boolean connectstatus=false;
public:
    void connect(void);
    void setSSID(String);
    void setPassword(String);
    int checkwifi();
    int checkwifi(const char*);
    boolean connected();
    boolean apmode(char *ssid,char *password);
    boolean checkconnection(boolean restart);
};

#endif