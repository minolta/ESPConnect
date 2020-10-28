#ifndef CONNECT_H
#define CONNECT_H
#include <Arduino.h>
#include <WiFiMulti.h>


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
    int checkwifi();
};

#endif