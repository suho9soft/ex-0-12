# ESP32 Button Control with Weintek HMI

이 프로젝트는 Weintek HMI 패널을 이용하여 ESP32 기반 반도체 버튼을 제어하는 예제입니다.  
사용자는 HMI 화면에서 버튼을 누르면 ESP32가 신호를 받아 실제 하드웨어 동작을 수행합니다.

## 주요 기능
- Weintek HMI와 ESP32 간 Modbus/TCP 통신
- HMI 화면에서 버튼 UI 제공
- ESP32 펌웨어에서 버튼 입력 신호 처리
- 간단한 아두이노 코드 예제 포함

## 필요 장비
- ESP32 개발 보드
- Weintek HMI 패널
- 아두이노 IDE

## 설치 방법
1. 아두이노 IDE에서 ESP32 보드 설정
2. `src/` 폴더의 코드를 ESP32에 업로드
3. Weintek HMI 프로젝트 파일을 HMI에 로드
4. 버튼을 눌러 ESP32 반도체 제어 확인

## 라이선스
MIT License
