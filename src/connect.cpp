#include "connect.h"
void ConnectObj::setSSID(String s)
{
    ssid = s;
}
void ConnectObj::setPassword(String s)
{
    password = s;
}
boolean ConnectObj::connected()
{
    return connectstatus;
}
int ConnectObj::checkwifi()
{
    if (Ping.ping(WiFi.gatewayIP()))
    {
        Serial.println("Success!!");
        return true;
    }

    Serial.println("Error :(");
    return false;
}
int ConnectObj::checkwifi(const char *p)
{
    if (Ping.ping(p))
    {
        Serial.println("Success!!");
        return true;
    }

    Serial.println("Error :(");
    return false;
}
boolean ConnectObj::apmode(char *ssid, char *password)
{
    WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1), IPAddress(255, 255, 255, 0));
    if (WiFi.softAP(ssid, password))
    {
        IPAddress IP = WiFi.softAPIP();
        Serial.print("AP IP address: ");
        Serial.println(IP);
        return true;
    }
    return false;
}
void ConnectObj::connect()
{
    connectstatus = false;
    WiFi.mode(WIFI_STA);
    wifiMulti.addAP(ssid.c_str(), password.c_str());
    int timeout = 0;
    pinMode(2, OUTPUT);
    digitalWrite(2, 1);
    while (wifiMulti.run() != WL_CONNECTED)
    {
        Serial.print("#");
        timeout++;
        if (timeout > 10)
            break;
        delay(500);
    }
    wifiMulti.addAP("Sirifarm", "0932154741");
    wifiMulti.addAP("test", "12345678");
    wifiMulti.addAP("forpi", "04qwerty");
    wifiMulti.addAP("forpi1", "04qwerty");
    wifiMulti.addAP("forpi5", "04qwerty");
    wifiMulti.addAP("forpi4", "04qwerty");
    wifiMulti.addAP("forpi2", "04qwerty");
    Serial.println("Connecting Wifi...");
    timeout = 0;
    while (wifiMulti.run() != WL_CONNECTED)
    {
        Serial.print(".");
        timeout++;
        if (timeout > 20)
            break;
        delay(500);
    }

    if (wifiMulti.run() == WL_CONNECTED)
    {
        connectstatus = true;
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("");
        Serial.print("Mac:");
        Serial.println(WiFi.macAddress());
        Serial.print("SSID:");
        Serial.println(WiFi.SSID());
        Serial.print("Signal:");
        Serial.println(WiFi.RSSI());
    }
}

ConnectObj Connect;