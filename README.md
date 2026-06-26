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

👉 정리하면, 이 프로젝트는 현장(HMI) 제어 ↔ 모바일 제어 ↔ 스마트 홈 확장까지 단계적으로 확장 가능한 IoT 제어 시스템입니다.
