#include <Arduino.h>
#include "connect.h"
ConnectObj ct;
void setup() {
  // put your setup code here, to run once:

ct.setSSID("forpi");
ct.setPassword("04qwerty");
ct.connect();
}

void loop() {
  // put your main code here, to run repeatedly:
 
}