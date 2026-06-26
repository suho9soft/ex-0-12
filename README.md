이 프로젝트는 Weintek MT8102iP HMI 패널과 ESP32를 연결하여 버튼 제어를 구현하는 예제입니다.
HMI 화면에서 버튼을 누르면 ESP32가 Modbus/TCP 통신을 통해 신호를 받아 실제 하드웨어를 제어합니다.

주요 기능

HMI ↔ ESP32 간 Modbus/TCP 통신

HMI 화면에서 직관적인 버튼 UI 제공

ESP32 펌웨어에서 버튼 입력 처리

아두이노 IDE 기반 예제 코드 포함

확장성

여러 GPIO 핀을 활용해 2개 이상 버튼 제어 가능

HMI 화면에 버튼 UI 추가만으로 확장 가능

Raspberry Pi 연동

Raspberry Pi를 끄면 ESP32 세팅값으로 HMI 작동

Raspberry Pi에서 CODESYS SL 실행 시 스마트폰으로 제어 가능

즉, HMI 터치 제어 ↔ 모바일 제어를 상황에 따라 선택 가능

🌐 Node-RED 간단 설명
Node-RED는 IoT 및 자동화용 비주얼 프로그래밍 툴로, 블록(노드)을 연결하여 데이터 흐름을 쉽게 구성할 수 있습니다.
ESP32와 HMI, Raspberry Pi를 함께 사용할 때 Node-RED를 추가하면 중앙 제어 및 모니터링이 가능합니다.

특징

웹 브라우저 기반의 플로우 에디터 제공

MQTT, Modbus, HTTP 등 다양한 프로토콜 지원

ESP32 센서 데이터 시각화 및 버튼 제어 가능

스마트폰, PC, HMI와 연동하여 통합 제어

활용 예시

ESP32 버튼 상태를 Node-RED 대시보드에 표시

HMI 버튼 입력을 Node-RED로 받아 다른 장치 제어

Raspberry Pi에서 Node-RED 실행 → 스마트폰 웹 브라우저로 접속해 원격 제어

👉 요약하면:

ESP32 + Weintek HMI → 기본 버튼 제어

Raspberry Pi + CODESYS SL → 스마트폰 제어

Node-RED → 중앙에서 데이터 흐름 관리 및 시각화

핸드폰에서 IoT MQTT Panel 사용하기
ESP32와 Weintek HMI를 제어할 때, 스마트폰 앱 IoT MQTT Panel을 활용하면 모바일에서도 버튼 제어와 상태 모니터링이 가능합니다.

🔌 IoT MQTT Panel 개요
안드로이드에서 많이 쓰이는 MQTT 클라이언트 앱

MQTT Broker(예: Mosquitto, EMQX, HiveMQ)에 연결하여 ESP32와 데이터 송수신

버튼, 스위치, 그래프, 텍스트 등 다양한 UI 위젯 제공

스마트폰 화면에서 직접 장치 제어 및 상태 확인 가능

⚙️ 설정 방법
MQTT Broker 준비

Raspberry Pi, PC, 또는 클라우드 서버에 Mosquitto 같은 MQTT Broker 설치

ESP32가 이 Broker에 접속하도록 코드 작성

IoT MQTT Panel 앱 설치

구글 플레이스토어에서 IoT MQTT Panel 다운로드

앱에서 Broker 연결 설정

Broker 주소(IP), 포트(기본 1883), 사용자/비밀번호 입력

연결 테스트 후 성공하면 장치와 통신 가능

위젯 추가

버튼 위젯 → ESP32로 제어 신호 전송 (topic: esp32/button1)

텍스트/그래프 위젯 → ESP32 상태값 표시 (topic: esp32/status)

📊 활용 예시
HMI 버튼 제어와 동일하게 스마트폰에서 버튼을 누르면 ESP32 GPIO 제어

상태 모니터링: ESP32가 센서값을 MQTT로 전송 → 스마트폰에서 실시간 확인

멀티 제어: HMI, 스마트폰, Node-RED 대시보드 모두 같은 MQTT Broker를 통해 동작
스마트폰에서 Home Assistant 사용하기
ESP32 + Weintek HMI 프로젝트를 확장하면, 스마트폰에서 Home Assistant 앱을 통해 제어할 수 있습니다.
Home Assistant는 오픈소스 스마트 홈 플랫폼으로, MQTT와 같은 프로토콜을 지원하여 ESP32와 쉽게 연동됩니다.

🔌 Home Assistant 개요
오픈소스 스마트 홈 자동화 플랫폼

안드로이드/iOS 앱 제공 → 스마트폰에서 직접 제어 가능

MQTT, Modbus, HTTP, Zigbee, Z-Wave 등 다양한 프로토콜 지원

대시보드(UI)를 커스터마이징하여 버튼, 스위치, 센서값 표시 가능

⚙️ ESP32 + Home Assistant 연동 방법
MQTT Broker 준비

Raspberry Pi, PC, 또는 클라우드에 Mosquitto 설치

ESP32가 MQTT Broker에 연결되도록 코드 작성

Home Assistant 설치

Raspberry Pi, Docker, 또는 서버에 Home Assistant 설치

MQTT 통합(Add-on)을 활성화

ESP32 토픽 등록

예:

esp32/button1 → 버튼 제어

esp32/status → 상태 모니터링

스마트폰 앱에서 제어

Home Assistant 앱 실행 → 대시보드에서 버튼 UI 추가

ESP32와 실시간으로 통신하여 제어 가능

📊 활용 예시
HMI 버튼 제어와 동일하게 스마트폰에서 버튼을 누르면 ESP32 GPIO 제어

센서 모니터링: ESP32가 온도/습도 센서값을 MQTT로 전송 → Home Assistant 대시보드에서 확인

자동화 시나리오:

버튼 누르면 → LED 켜기

특정 시간에 → 장치 자동 제어

👉 정리하면:

Weintek HMI → 현장 터치 제어

IoT MQTT Panel → 간단한 모바일 MQTT 제어

Home Assistant → 스마트폰 앱 기반의 스마트 홈 통합 제어
