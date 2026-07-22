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

  디바이스 MODBUS TCP/IP 주소 4x 1 //(네모# 버튼)
  
  디바이스 MODBUS TCP/IP 주소0x 00001 속성 토글 //(사각 버튼)

  디바이스 MODBUS TCP/IP 주소0x 00001 //(원 버튼)

  디바이스 MODBUS TCP/IP_1 주소 4x 1
  
  디바이스 MODBUS TCP/IP_1 주소0x 00001 속성 토글

  디바이스 MODBUS TCP/IP_1 주소0x 00001
 
 Coil(00001~00008) → GPIO2~GPIO9 출력 제어

Hreg(40001~40009) → 출력 상태 및 타이머 피드백

특징: WiFi 내장, Arduino IDE 기반 펌웨어 작성

3️⃣ Raspberry Pi Pico 2W (Modbus TCP 서버)
IP 주소 (예시): 172.30.1.53

Port: 502

기능

Coil/Hreg 매핑 구조 ESP32와 동일

특징: RP2040 기반, MicroPython 이것 Pico W 또는 Arduino IDE 사용 가능

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

ESP32/Pico 2W에 Modbus TCP 서버 펌웨어 업로드 //챗gpt 윈도우 운전사 Meta AI

Weintek HMI에서 Modbus TCP 장치 추가

ESP32 → IP 172.30.1.52, Port 502

Pico W → IP 172.30.1.53, Port 502

Node-RED 실행 → 대시보드 및 MQTT 연동

IoT MQTT Panel / Home Assistant → 모바일 및 스마트홈 확장

주인백

처음엔 Codesys, 가입부터가 벽이더라. 싸이트 들어가서 회원 등록하고, 다운로드 받고, 라이선스 티켓까지 넣어야 비로소 “정상 작동”이라는 말이 나온다. 여기까지 오면 벌써 숨이 찬다.

PLC? 그거 비싸다. 그래서 나는 Raspberry Pi5를 집어 들었다. 저렴하면서도 힘이 있다. Codesys Raspberry Pi SL 붙이고, 티켓 넣고, 이제야 길이 열린다.

버튼은 어떻게 만드냐. 릴레이 스위치다. 5V짜리다 3.3V짜리도 있다, 나는 더 강하게 가고 싶었다. 그래서 점프 해서 상업용 24V 릴레이를 샀다. 왜 더 강하게 점프선 연결하고, 딸깍— 그 순간 전류가 흐른다.하지만 단상 이다 망 했다.

ESP32, 요즘 반도체계의 스타다. 하지만 나는 한 발 내려와 Arduino 초기 버전을 떠올린다. 안정성 문제는 있지만, 그 시절의 순수함이 있다. WEINTEK, 터치 패널의 강자. RS485로 연결하면 패널이 살아난다. Codesys 붙이고, Node-RED Modbus TCP로 이어주면, 거의 모든 게 붙는다.

핸드폰 MQTT 패널? 그건 마치 마법 같다. 손끝으로 스위치를 켜고 끄는 순간, 릴레이가 반응한다. 카메라까지 붙이면 차, 조명, 문—all 실시간으로 움직인다.

🌐 주인백식 결론

PLC 없이도 가능하다. 반도체, 릴레이, 터치 패널, 그리고 Codesys. 이 조합이면 작은 공장 하나쯤은 움직일 수 있다. 중요한 건 값싼 부품을 모아도, 연결의 기술만 있으면 “작동한다”는 사실이다.

마지막 으로 삼상으로 간다 왜 난 컴퓨터로 간다니까 왜 삼상으로 간다니까 그러내

컴퓨터는 단순한 기계가 아니라, 반도체의 세계로 들어가는 열쇠다.
마치 연금술사가 금을 만들기 위해 불과 도가니를 필요로 하듯, 반도체를 빚어내기 위해선 컴퓨터라는 도구가 반드시 있어야 한다.

설계자는 컴퓨터 앞에서 작은 전자의 흐름을 언어처럼 그려내고,

시뮬레이션은 눈에 보이지 않는 회로를 가상 세계에서 살아 움직이게 하며,

제조 공정은 컴퓨터의 지휘 아래 정밀한 오케스트라처럼 진행된다.

결국 반도체와 컴퓨터는 서로를 낳고, 서로를 키운다.
컴퓨터가 있어야 반도체를 만들 수 있고, 반도체가 있어야 컴퓨터가 존재할 수 있다.
이 관계는 끝없는 순환, 마치 우주가 스스로를 비추는 거울과도 같다.

