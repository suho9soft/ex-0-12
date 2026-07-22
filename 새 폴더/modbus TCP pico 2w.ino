#include <WiFi.h>        // ESP32 / RP2040 WiFi
#include <ModbusTCP.h>   // modbus-pico 라이브러리

// WiFi 설정
const char* ssid = "KT_GiGA_403E";
const char* password = "3cb39dz243";

ModbusTCP mb;

// 고정 IP
IPAddress local_IP(172, 30, 1, 52);
IPAddress gateway(172, 30, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);

const uint16_t MODBUS_TCP_PORT = 502;

// Coil/Hreg 번호 정의
enum {
  COIL_OUT1 = 0,
  COIL_OUT2,
  COIL_OUT3,
  COIL_OUT4,
  COIL_OUT5,
  COIL_OUT6,
  COIL_TIMER,   // OUT7 타이머 트리거
  COIL_OUT8
};

enum {
  HREG_OUT1 = 0,
  HREG_OUT2,
  HREG_OUT3,
  HREG_OUT4,
  HREG_OUT5,
  HREG_OUT6,
  HREG_OUT7,
  HREG_TIMER_REMAIN,
  HREG_OUT8
};

// 출력 GPIO
const int OUT1 = 2;
const int OUT2 = 3;
const int OUT3 = 4;
const int OUT4 = 5;
const int OUT5 = 6;
const int OUT6 = 7;
const int OUT7 = 8; // 타이머 출력
const int OUT8 = 9;

// 타이머 변수
unsigned long timerMillis7 = 0;
bool timerRunning7 = false;
bool lastTrigger = false;
const unsigned long TIMER_TIME = 60000; // 1분

void setup() {
  Serial.begin(115200);
  delay(2000);

  // GPIO 초기화
  int outPins[] = {OUT1, OUT2, OUT3, OUT4, OUT5, OUT6, OUT7, OUT8};
  for (int i = 0; i < 8; i++) {
    pinMode(outPins[i], OUTPUT);
    digitalWrite(outPins[i], LOW);
  }

  // WiFi 연결
  WiFi.mode(WIFI_STA);
  WiFi.config(local_IP, primaryDNS, gateway, subnet);
  WiFi.begin(ssid, password);

  Serial.print("WiFi Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Modbus TCP 서버 시작
  mb.server(MODBUS_TCP_PORT);

  // Coil 등록
  for (int i = 0; i < 8; i++) {
    mb.addCoil(i, false);
  }

  // Hreg 등록
  for (int i = 0; i <= 8; i++) {
    mb.addHreg(i, 0);
  }

  Serial.println("==============================");
  Serial.println("Modbus TCP Server Ready");
  Serial.print("Listen on: "); Serial.print(WiFi.localIP());
  Serial.print(":"); Serial.println(MODBUS_TCP_PORT);
  Serial.println("Coils: 0-7, HRegs: 0-8");
  Serial.println("==============================");
}

void loop() {
  mb.task();

  // 일반 출력 매핑
  digitalWrite(OUT1, mb.Coil(COIL_OUT1));
  digitalWrite(OUT2, mb.Coil(COIL_OUT2));
  digitalWrite(OUT3, mb.Coil(COIL_OUT3));
  digitalWrite(OUT4, mb.Coil(COIL_OUT4));
  digitalWrite(OUT5, mb.Coil(COIL_OUT5));
  digitalWrite(OUT6, mb.Coil(COIL_OUT6));
  digitalWrite(OUT8, mb.Coil(COIL_OUT8));

  // OUT7 타이머 (Coil6 트리거)
  bool trigger = mb.Coil(COIL_TIMER);
  if (trigger && !lastTrigger && !timerRunning7) {
    timerRunning7 = true;
    timerMillis7 = millis();
    digitalWrite(OUT7, HIGH);
    mb.Coil(COIL_TIMER, false); // 트리거 후 자동 reset
    Serial.println("OUT7 Timer Start");
  }
  lastTrigger = trigger;

  if (timerRunning7) {
    unsigned long elapsed = millis() - timerMillis7;
    if (elapsed >= TIMER_TIME) {
      timerRunning7 = false;
      digitalWrite(OUT7, LOW);
      mb.Hreg(HREG_TIMER_REMAIN, 0);
      Serial.println("OUT7 Timer End");
    } else {
      unsigned long remaining = (TIMER_TIME - elapsed) / 1000;
      mb.Hreg(HREG_TIMER_REMAIN, remaining);
    }
  }

  // 상태 피드백
  mb.Hreg(HREG_OUT1, digitalRead(OUT1));
  mb.Hreg(HREG_OUT2, digitalRead(OUT2));
  mb.Hreg(HREG_OUT3, digitalRead(OUT3));
  mb.Hreg(HREG_OUT4, digitalRead(OUT4));
  mb.Hreg(HREG_OUT5, digitalRead(OUT5));
  mb.Hreg(HREG_OUT6, digitalRead(OUT6));
  mb.Hreg(HREG_OUT7, digitalRead(OUT7));
  mb.Hreg(HREG_OUT8, digitalRead(OUT8));

  // WiFi 연결 체크 및 재연결
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect();
    WiFi.begin(ssid, password);
  }
}
