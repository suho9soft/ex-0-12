#include <WiFi.h>
#include <ModbusTCP.h>

const char* ssid = "KT_GiGA_403E";
const char* password = "3cb39dz243";

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
const int OUT7 = 23;
const int OUT8 = 25;

// =====================================
// 타이머용
// Coil 3 -> OUT4
// =====================================
unsigned long timerMillis1 = 0;
bool timerRunning1 = false;
bool lastCoil3 = false;

const unsigned long TIMER_TIME = 60000; // 1분

void setup() {

  Serial.begin(115200);

  // =====================================
  // 출력 설정
  // =====================================
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);

  // =====================================
  // 초기 출력 OFF
  // =====================================
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, LOW);
  digitalWrite(OUT5, LOW);
  digitalWrite(OUT6, LOW);
  digitalWrite(OUT7, LOW);
  digitalWrite(OUT8, LOW);

  // =====================================
  // WiFi 연결
  // =====================================
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

  // =====================================
  // Modbus TCP Server
  // =====================================
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

  // =====================================
  // 일반 출력
  // =====================================
  digitalWrite(OUT1, mb.Coil(0));
  digitalWrite(OUT2, mb.Coil(1));
  digitalWrite(OUT3, mb.Coil(2));

  digitalWrite(OUT5, mb.Coil(4));
  digitalWrite(OUT6, mb.Coil(5));

  // =====================================
  // OUT4 타이머 1분
  // Coil 3
  // =====================================
  bool coil3 = mb.Coil(3);

  if (coil3 && !lastCoil3 && !timerRunning1) {

    timerRunning1 = true;
    timerMillis1 = millis();

    digitalWrite(OUT4, HIGH);

    Serial.println("OUT4 Timer Start");
  }

  lastCoil3 = coil3;

  if (timerRunning1) {

    if (millis() - timerMillis1 >= TIMER_TIME) {

      timerRunning1 = false;

      digitalWrite(OUT4, LOW);

      Serial.println("OUT4 Timer End");
    }
  }

  // =====================================
  // OUT7 일반 버튼 출력
  // Coil 6
  // =====================================
  digitalWrite(OUT7, mb.Coil(6));

  // =====================================
  // OUT8 일반 버튼 출력
  // Coil 7
  // =====================================
  digitalWrite(OUT8, mb.Coil(7));

  // =====================================
  // 아날로그 입력
  // =====================================
  int sensor = analogRead(34);

  mb.Hreg(0, sensor);
}