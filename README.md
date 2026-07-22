📌 프로젝트 개요
구성 요소: Weintek MT8102iP HMI 패널 + ESP32

통신 방식: Modbus/TCP

기능: HMI 화면의 버튼 입력 → ESP32가 신호를 받아 GPIO 제어

🔑 주요 기능
HMI ↔ ESP32 간 Modbus/TCP 통신

HMI 화면에서 직관적인 버튼 UI 제공

ESP32 펌웨어에서 버튼 입력 처리

아두이노 IDE 기반 예제 코드 포함

🔧 확장성
멀티 버튼 제어: 여러 GPIO 핀 활용 → 2개 이상 버튼 제어 가능

HMI 확장: 버튼 UI만 추가하면 손쉽게 확장 가능

Raspberry Pi 연동:

Pi OFF → ESP32 세팅값으로 HMI 작동

Pi ON + CODESYS SL 실행 → 스마트폰 제어 가능

즉, HMI 터치 제어 ↔ 모바일 제어를 상황에 따라 선택 가능

🌐 Node-RED 활용
Node-RED는 IoT 및 자동화용 비주얼 프로그래밍 툴로, 중앙 제어 및 모니터링을 지원합니다.

특징

웹 브라우저 기반 플로우 에디터 제공

MQTT, Modbus, HTTP 등 다양한 프로토콜 지원

ESP32 센서 데이터 시각화 및 버튼 제어 가능

스마트폰, PC, HMI와 연동하여 통합 제어

활용 예시

ESP32 버튼 상태를 Node-RED 대시보드에 표시

HMI 버튼 입력을 Node-RED로 받아 다른 장치 제어

Raspberry Pi에서 Node-RED 실행 → 스마트폰 웹 브라우저로 접속해 원격 제어

📱 IoT MQTT Panel (모바일 제어)
개요: 안드로이드 기반 MQTT 클라이언트 앱

설정 방법

MQTT Broker 준비 (Mosquitto 등)

ESP32가 Broker에 접속하도록 코드 작성

IoT MQTT Panel 앱 설치 및 Broker 연결 설정

위젯 추가 (버튼, 텍스트, 그래프 등)

활용 예시

스마트폰 버튼 → ESP32 GPIO 제어

ESP32 센서값 → 스마트폰에서 실시간 확인

HMI, 스마트폰, Node-RED 모두 같은 Broker로 통합 제어

🏠 Home Assistant (스마트 홈 확장)
개요: 오픈소스 스마트 홈 자동화 플랫폼

ESP32 연동 방법

MQTT Broker 준비

ESP32가 Broker에 연결되도록 코드 작성

Home Assistant 설치 및 MQTT 통합 활성화

ESP32 토픽 등록 (예: esp32/button1, esp32/status)

스마트폰 앱에서 대시보드 UI 구성

활용 예시

버튼 제어 → ESP32 GPIO 동작

센서 모니터링 → 온도/습도 값 실시간 확인

자동화 시나리오 → 특정 시간/조건에 따라 장치 제어

📊 전체 요약
Weintek HMI → 현장 터치 제어

ESP32 → 실제 하드웨어 제어

Raspberry Pi + CODESYS SL → 스마트폰 제어 가능

Node-RED → 중앙 데이터 흐름 관리 및 시각화

IoT MQTT Panel → 간단한 모바일 MQTT 제어

Home Assistant → 스마트 홈 통합 제어

👉 📌 프로젝트 개요
이 프로젝트는 ESP32/RP2040 기반 Modbus TCP 서버를 구현하여,

Coil(00001~00008) → 출력 제어 (GPIO2~GPIO9)

Holding Register(40001~40009) → 출력 상태 및 타이머 피드백

을 제공하고, WEINTEK HMI와 연동하여 버튼/램프를 통해 제어 및 모니터링할 수 있도록 구성한 예시입니다.

⚙️ 주요 기능
WiFi 연결: 고정 IP 설정 및 자동 재연결 로직 포함

Modbus TCP 서버: Coil/Hreg 등록 및 CODESYS/HMI와 호환

출력 제어: Coil → GPIO 매핑 (OUT1~OUT8)

상태 피드백: Hreg → GPIO 상태 반영 (램프 표시)

타이머 기능: Coil6 트리거 시 OUT7을 1분간 ON 후 자동 OFF

Watchdog (선택적): 일정 시간 Modbus 요청이 없으면 전체 출력 OFF

🖥️ HMI 구성 예시
버튼 (출력 제어)
버튼1 → Coil 00001 → OUT1(GPIO2)

버튼2 → Coil 00002 → OUT2(GPIO3)

…

버튼8 → Coil 00008 → OUT8(GPIO9)

램프 (상태 피드백)
램프1 → Hreg 40001 → OUT1 상태

램프2 → Hreg 40002 → OUT2 상태

…

램프8 → Hreg 40009 → OUT8 상태

👉 버튼으로 Coil을 제어하면, 램프에서 실제 출력 상태를 확인할 수 있습니다.

🚀 사용 방법
Arduino IDE에서 ESP32/RP2040 보드 선택

WiFi.h, ModbusTCP.h 라이브러리 설치

소스 코드 업로드 후 ESP32 전원 연결

WEINTEK HMI 또는 CODESYS에서 Modbus TCP 장치 추가

IP: 172.30.1.52

Port: 502

Coil/Hreg 주소 매핑
