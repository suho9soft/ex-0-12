#include <WiFi.h>
#include <ModbusTCP.h>

const char* ssid = "KT_GiGA_403E";
const char* password = "3cb39dz243";

ModbusTCP mb;

// 고정 IP 설정 (ESP32-1)
IPAddress local_IP(172, 30, 1, 50);
IPAddress gateway(172, 30, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

// 출력 GPIO 총 8개
const int OUT1 = 16;
const int OUT2 = 17;
const int OUT3 = 18;
const int OUT4 = 19;
const int OUT5 = 21;
const int OUT6 = 22;
const int OUT7 = 23;  // 타이머 출력
const int OUT8 = 25;

// 타이머용 변수
unsigned long timerMillis7 = 0;
bool timerRunning7 = false;
bool lastReg6 = false;

const unsigned long TIMER_TIME = 60000; // 1분

void setup() {
  Serial.begin(115200);

  // 출력 핀 초기화
  pinMode(OUT1, OUTPUT); pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT); pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT); pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT); pinMode(OUT8, OUTPUT);

  digitalWrite(OUT1, LOW); digitalWrite(OUT2, LOW);
  digitalWrite(OUT3, LOW); digitalWrite(OUT4, LOW);
  digitalWrite(OUT5, LOW); digitalWrite(OUT6, LOW);
  digitalWrite(OUT7, LOW); digitalWrite(OUT8, LOW);

  // 고정 IP 설정
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  // WiFi 연결
  WiFi.begin(ssid, password);
  Serial.print("WiFi Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Modbus TCP Server 시작
  mb.server();

  // Holding Register 0 ~ 8 생성
  for (int i = 0; i <= 8; i++) mb.addHreg(i);

  // Coil 0 ~ 7 생성
  for (int i = 0; i < 8; i++) mb.addCoil(i);

  Serial.println("Modbus TCP Ready");
}

void loop() {
  mb.task();

  // Coil 값 → GPIO 출력
  digitalWrite(OUT1, mb.Coil(0));
  digitalWrite(OUT2, mb.Coil(1));
  digitalWrite(OUT3, mb.Coil(2));
  digitalWrite(OUT4, mb.Coil(3));
  digitalWrite(OUT5, mb.Coil(4));
  digitalWrite(OUT6, mb.Coil(5));
  digitalWrite(OUT8, mb.Coil(7));

  // Coil 값 → Hreg 값 동기화
  for (int i = 0; i < 8; i++) mb.Hreg(i, mb.Coil(i));

  // OUT7 타이머 (Coil6/Hreg6)
  bool reg6 = mb.Coil(6);
  if (reg6 && !lastReg6 && !timerRunning7) {
    timerRunning7 = true;
    timerMillis7 = millis();
    digitalWrite(OUT7, HIGH);
    Serial.println("OUT7 Timer Start");
  }
  lastReg6 = reg6;

  if (timerRunning7) {
    unsigned long elapsed = millis() - timerMillis7;
    unsigned long remaining = (TIMER_TIME - elapsed) / 1000;
    mb.Hreg(7, remaining);

    if (elapsed >= TIMER_TIME) {
      timerRunning7 = false;
      digitalWrite(OUT7, LOW);
      Serial.println("OUT7 Timer End");
      mb.Hreg(7, 0);
    }
  }

  mb.Coil(6, digitalRead(OUT7));
  mb.Hreg(6, digitalRead(OUT7));
}