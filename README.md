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
# ESP32 Button Control with Weintek MT8102iP HMI

이 프로젝트는 Weintek MT8102iP HMI 패널을 이용하여 ESP32 기반 반도체 버튼을 제어하는 예제입니다.  
MT8102iP는 10.1인치 터치스크린을 갖춘 산업용 HMI로, ESP32와 Modbus/TCP 통신을 통해 버튼 신호를 전달합니다.  
사용자는 HMI 화면에서 버튼을 누르면 ESP32가 신호를 받아 실제 하드웨어 동작을 수행합니다.

## 주요 기능
- Weintek MT8102iP HMI와 ESP32 간 Modbus/TCP 통신
- HMI 화면에서 직관적인 버튼 UI 제공
- ESP32 펌웨어에서 버튼 입력 신호 처리
- 아두이노 IDE 기반 예제 코드 포함

## 필요 장비
- ESP32 개발 보드
- Weintek MT8102iP HMI 패널
- 아두이노 IDE

## 설치 방법
1. 아두이노 IDE에서 ESP32 보드 설정
2. `src/` 폴더의 코드를 ESP32에 업로드
3. Weintek MT8102iP HMI 프로젝트 파일을 HMI에 로드
4. 버튼을 눌러 ESP32 반도체 제어 확인
## 장비 설명 (추가)

### Weintek MT8102iP
- 10.1인치 터치스크린을 갖춘 산업용 HMI 패널
- ESP32와 Modbus/TCP 통신을 지원
- 직관적인 UI로 버튼 제어 가능
- 산업 현장에서 안정적인 제어 환경 제공
## 참고 자료
- Weintek MT8102iP 공식 매뉴얼
- ESP32 아두이노 라이브러리 문서
- 프로젝트 회로도 및 HMI 화면 캡처
