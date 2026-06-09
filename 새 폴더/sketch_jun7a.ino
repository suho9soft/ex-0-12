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
const int OUT7 = 23;  // 타이머 출력
const int OUT8 = 25;

// =====================================
// 타이머용 (7번만)
// Coil 6 / Hreg 6 -> OUT7
// =====================================
unsigned long timerMillis7 = 0;
bool timerRunning7 = false;
bool lastReg6 = false;

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

  // Modbus TCP Server 시작
  mb.server();

  // Holding Register 0 ~ 8 생성 (추가: Hreg7은 남은 시간 표시용)
  for (int i = 0; i <= 8; i++) {
    mb.addHreg(i);
  }

  // Coil 0 ~ 7 생성 (Bit 태그용)
  for (int i = 0; i < 8; i++) {
    mb.addCoil(i);
  }

  Serial.println("Modbus TCP Ready");
}

void loop() {
  mb.task();

  // Coil 값 읽어서 GPIO 출력 (비트 버튼 제어)
  digitalWrite(OUT1, mb.Coil(0));
  digitalWrite(OUT2, mb.Coil(1));
  digitalWrite(OUT3, mb.Coil(2));
  digitalWrite(OUT4, mb.Coil(3));
  digitalWrite(OUT5, mb.Coil(4));
  digitalWrite(OUT6, mb.Coil(5));
  digitalWrite(OUT8, mb.Coil(7));

  // Coil 값 → Hreg 값으로 동기화 (Word 태그도 같이 갱신)
  for (int i = 0; i < 8; i++) {
    mb.Hreg(i, mb.Coil(i));
  }

  // =====================================
  // OUT7 타이머 1분 (Coil6 / Hreg6)
  // =====================================
  bool reg6 = mb.Coil(6);  // Coil6을 기준으로 동작
  if (reg6 && !lastReg6 && !timerRunning7) {
    timerRunning7 = true;
    timerMillis7 = millis();
    digitalWrite(OUT7, HIGH);
    Serial.println("OUT7 Timer Start");
  }
  lastReg6 = reg6;

  if (timerRunning7) {
    unsigned long elapsed = millis() - timerMillis7;
    unsigned long remaining = (TIMER_TIME - elapsed) / 1000; // 초 단위

    // 남은 시간을 Hreg7에 기록
    mb.Hreg(7, remaining);

    Serial.print("OUT7 남은 시간: ");
    Serial.print(remaining);
    Serial.println(" 초");

    if (elapsed >= TIMER_TIME) {
      timerRunning7 = false;
      digitalWrite(OUT7, LOW);
      Serial.println("OUT7 Timer End");
      mb.Hreg(7, 0); // 타이머 끝나면 0으로 초기화
    }
  }

  // Coil6/Hreg6 상태 동기화
  mb.Coil(6, digitalRead(OUT7));
  mb.Hreg(6, digitalRead(OUT7));
}
