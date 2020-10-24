#ifndef CONNECT_H
#define CONNECT_H
#include <WiFiMulti.h>
#include <Arduino.h>

class ConnectObj
{
private:
    WiFiMulti wifiMulti;
    String ssid;
    String password;

public:
    void connect(void);
    void setSSID(String);
    void setPassword(String);
};

#endif