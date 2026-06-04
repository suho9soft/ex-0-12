#include <WiFi.h>
#include <ModbusTCP.h>

const char* ssid = "공유기 이름";
const char* password = "공유기 패스워드";

ModbusTCP mb;

// =====================================
// 출력 GPIO 총 8개
// =====================================
const int OUT1 = 16;
const int OUT2 = 17;
const int OUT3 = 18;
const int OUT4 = 19;
const int OUT5 = 21;
const int OUT6 = 22;
const int OUT7 = 23;  // 타이머 출력
const int OUT8 = 25;

// =====================================
// 타이머용 (7번만)
// Coil 6 -> OUT7
// =====================================
unsigned long timerMillis7 = 0;
bool timerRunning7 = false;
bool lastCoil6 = false;

const unsigned long TIMER_TIME = 60000; // 1분

void setup() {
  Serial.begin(115200);

  // 출력 핀 설정
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);

  // 초기 출력 OFF
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, LOW);
  digitalWrite(OUT5, LOW);
  digitalWrite(OUT6, LOW);
  digitalWrite(OUT7, LOW);
  digitalWrite(OUT8, LOW);

  // WiFi 연결
  WiFi.begin(ssid, password);
  Serial.print("WiFi Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Modbus TCP Server
  mb.server();

  // Coil 0 ~ 7 생성
  for (int i = 0; i < 8; i++) {
    mb.addCoil(i);
  }

  // 아날로그 입력 레지스터
  mb.addHreg(0);

  Serial.println("Modbus TCP Ready");
}

void loop() {
  mb.task();

  // 일반 출력 (버튼 제어)
  digitalWrite(OUT1, mb.Coil(0));
  digitalWrite(OUT2, mb.Coil(1));
  digitalWrite(OUT3, mb.Coil(2));
  digitalWrite(OUT4, mb.Coil(3));
  digitalWrite(OUT5, mb.Coil(4));
  digitalWrite(OUT6, mb.Coil(5));
  digitalWrite(OUT8, mb.Coil(7));

  // =====================================
  // OUT7 타이머 1분 (Coil 6)
  // =====================================
  bool coil6 = mb.Coil(6);

  if (coil6 && !lastCoil6 && !timerRunning7) {
    timerRunning7 = true;
    timerMillis7 = millis();
    digitalWrite(OUT7, HIGH);
    Serial.println("OUT7 Timer Start");
  }

  lastCoil6 = coil6;

  if (timerRunning7) {
    if (millis() - timerMillis7 >= TIMER_TIME) {
      timerRunning7 = false;
      digitalWrite(OUT7, LOW);
      Serial.println("OUT7 Timer End");
    }
  }

  // 아날로그 입력
  int sensor = analogRead(34);
  mb.Hreg(0, sensor);
}
