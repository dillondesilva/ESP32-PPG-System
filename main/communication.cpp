#include <Arduino.h>
#include <Esp.h>
#include <iostream>
#include <string>
#include "BluetoothSerial.h"
#include "communication.h"

using namespace std;

communication::communication(char* ptr_bt_name) 
{
  BluetoothSerial serial_bt;
  Serial.begin(115200);
  Serial.println(strlen(ptr_bt_name));
  Serial.println(*ptr_bt_name);
}

void communication::initialize_bluetooth()
{
  communication::serial_bt.begin((String)"AwesomePPG");
  if (!communication::serial_bt.begin((String)"AwesomePPG"))
  {
    Serial.println("An error occurred initializing Bluetooth");
  }
  else
  {
    Serial.println("Bluetooth initialized");
    Serial.println("AwesomePPG");
  }
}

bool communication::send(char data_packet[]) 
{
  Serial.write((const uint8_t *)data_packet, strlen(data_packet));
  communication::serial_bt.write((const uint8_t *)data_packet, strlen(data_packet));
  return true;
}