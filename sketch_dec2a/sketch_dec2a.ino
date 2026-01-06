// 定义使用无SSL模式以减少代码大小
#define BLINKER_WITHOUT_SSL
// 禁用WebSocket注册功能以减少代码大小
#define BLINKER_WITHOUT_WS_REG
// 禁用HTTP服务器以减少代码大小
#undef BLINKER_PROTOCOL_HTTP_SERVER
// 禁用ArduinoJson功能以减少代码大小
#undef BLINKER_ARDUINOJSON
// 禁用智能设备平台支持以减少代码大小
#undef BLINKER_ALIGENIE
#undef BLINKER_DUEROS
#undef BLINKER_MIOT
// 禁用调试功能以减少代码大小
#undef BLINKER_LAN_DEBUG
#undef BLINKER_DEBUG_ALL
#define BLINKER_WIFI

#include <Blinker.h>
#include <ESP32Servo.h>

const char auth[] = "3f77d0ef843f";
const char ssid[] = "515";
const char pswd[] = "88888888";

BlinkerButton Button1("btn-abc");
Servo myServo;
bool servoState = false;

#ifndef LED_BUILTIN
#define LED_BUILTIN 8
#endif

#define SERVO_PIN 1

void button1_callback(const String & state) {
    servoState = !servoState;
    myServo.write(servoState ? 150 : 0);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    myServo.setPeriodHertz(50);
    myServo.attach(SERVO_PIN, 500, 2500);
    myServo.write(0);
    
    Blinker.begin(auth, ssid, pswd);
    Button1.attach(button1_callback);
}

void loop() {
    Blinker.run();
}