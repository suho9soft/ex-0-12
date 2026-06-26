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
