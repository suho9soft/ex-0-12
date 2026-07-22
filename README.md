📌 ESP32 Dev Module / Raspberry Pi Pico 2W + Weintek HMI + CODESYS + Node-RED 프로젝트
🖥️ 프로젝트 개요
이 프로젝트는 PLC(CODESYS SL, Raspberry Pi)를 출발점으로 하여,
ESP32 / Pico 2W / Weintek HMI / Node-RED / MQTT / Home Assistant를 확장 모듈로 연동하는 현장 중심 제어 시스템입니다.

1️⃣ CODESYS SL (Raspberry Pi → PLC 역할)
출발점: 라즈베리파이에 CODESYS SL 설치 → PLC처럼 동작

역할

Modbus TCP 클라이언트 → ESP32/Pico 2W 서버 접속

WebVisu 기능 → 스마트폰/PC 브라우저 제어

현장 중심: PLC가 메인 컨트롤러, HMI/ESP32/Pico 2W는 주변 장치

2️⃣ ESP32 (Modbus TCP 서버)
IP 주소 (예시): 172.30.1.52

Port: 502

기능

Coil(00001~00008) → GPIO2~GPIO9 출력 제어

Hreg(40001~40009) → 출력 상태 및 타이머 피드백

특징: WiFi 내장, Arduino IDE 기반 펌웨어 작성

3️⃣ Raspberry Pi Pico 2W (Modbus TCP 서버)
IP 주소 (예시): 172.30.1.53

Port: 502

기능

Coil/Hreg 매핑 구조 ESP32와 동일

특징: RP2040 기반, MicroPython 또는 Arduino IDE 사용 가능

4️⃣ Weintek HMI (MT8102iP)
역할: 현장 터치 패널 → Modbus TCP 클라이언트

설정 방법

ESP32 접속 시: IP 172.30.1.52, Port 502

Pico 2W 접속 시: IP 172.30.1.53, Port 502

화면 구성

버튼 → Coil 제어

램프 → Hreg 상태 표시

5️⃣ Node-RED (라즈베리파이에서 실행)
역할: 중앙 데이터 흐름 관리 및 시각화

기능

ESP32/Pico 2W 상태 → 대시보드 표시

HMI 입력 → 다른 장치 제어

MQTT 연동 → 스마트폰/PC에서 원격 제어

6️⃣ IoT MQTT Panel & Home Assistant
IoT MQTT Panel: 안드로이드 앱 → MQTT Broker 통해 ESP32/Pico 2W 제어

Home Assistant: 스마트홈 플랫폼 → MQTT 기반 자동화 및 대시보드 UI 제공

📊 전체 아키텍처 요약
코드
   [PLC (CODESYS, Raspberry Pi)]
          ↓ Modbus TCP
   [ESP32 (172.30.1.52)]   [Pico 2W (172.30.1.53)]
          ↓
   [Weintek HMI (MT8102iP)]
          ↓ MQTT
   [Node-RED] ←→ [IoT MQTT Panel / Home Assistant]
🚀 사용 방법
Raspberry Pi에 CODESYS SL 설치 → PLC 역할

ESP32/Pico 2W에 Modbus TCP 서버 펌웨어 업로드

Weintek HMI에서 Modbus TCP 장치 추가

ESP32 → IP 172.30.1.52, Port 502

Pico W → IP 172.30.1.53, Port 502

Node-RED 실행 → 대시보드 및 MQTT 연동

IoT MQTT Panel / Home Assistant → 모바일 및 스마트홈 확장
