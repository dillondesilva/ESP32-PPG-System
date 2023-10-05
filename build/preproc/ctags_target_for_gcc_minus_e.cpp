# 1 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
# 2 "/Users/dillon/projects/esp32-ppg-system/main/main.ino" 2


void setup() {
    Serial.begin(115200);
}

void loop() {
    sensor_control panel = sensor_control(25, 13, 4, 4, 2);
    Serial.println("Hello");
}
