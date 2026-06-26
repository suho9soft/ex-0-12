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
## 확장성

이 프로젝트는 ESP32에 단일 반도체 버튼만 연결하는 데 그치지 않고,  
2개, 3개, 4개 이상의 버튼을 병렬로 연결하여 제어할 수 있습니다.  

- ESP32의 GPIO 핀을 활용해 여러 버튼 입력을 동시에 처리 가능  
- Weintek MT8102iP HMI 화면에서 각 버튼을 개별적으로 표시 및 제어  
- 버튼 수가 늘어나도 Modbus/TCP 통신 구조는 동일하게 유지  
- 확장 시에는 HMI 프로젝트에서 버튼 UI를 추가하고, ESP32 코드에서 핀 매핑만 변경하면 됩니다
- Raspberry pi 끄면 ESP32 반도체에 세팅값이 있어 WE!NTEK 작동 시킬수 있습니다 하지만 CODESYS Raspberry pi SL 돌리면 핸드폰에서 작동 합니다
- 그러니까요 터치을 하고 싶으면 Raspberry pi 끄고요 핸드폰으로 하고 싶으면 Raspberry pi 켜 세요 꼭 성공 하길 바랍니다 ok 땡큐!
- # ESP32 Button Control with Weintek MT8102iP HMI

이 프로젝트는 **Weintek MT8102iP HMI 패널**을 이용하여 **ESP32 기반 반도체 버튼**을 제어하는 예제입니다.  
MT8102iP는 10.1인치 터치스크린을 갖춘 산업용 HMI로, ESP32와 **Modbus/TCP 통신**을 통해 버튼 신호를 전달합니다.  
사용자는 HMI 화면에서 버튼을 누르면 ESP32가 신호를 받아 실제 하드웨어 동작을 수행합니다.

---

## 주요 기능
- Weintek MT8102iP HMI와 ESP32 간 Modbus/TCP 통신
- HMI 화면에서 직관적인 버튼 UI 제공
- ESP32 펌웨어에서 버튼 입력 신호 처리
- 아두이노 IDE 기반 예제 코드 포함

---

## 필요 장비
- ESP32 개발 보드
- Weintek MT8102iP HMI 패널
- 아두이노 IDE
- (선택) Raspberry Pi + CODESYS SL

---

## 설치 방법
1. 아두이노 IDE에서 ESP32 보드 설정
2. `src/` 폴더의 코드를 ESP32에 업로드
3. Weintek MT8102iP HMI 프로젝트 파일을 HMI에 로드
4. 버튼을 눌러 ESP32 반도체 제어 확인

---

## 장비 설명
### Weintek MT8102iP
- 10.1인치 터치스크린을 갖춘 산업용 HMI 패널
- ESP32와 Modbus/TCP 통신 지원
- 직관적인 UI로 버튼 제어 가능
- 산업 현장에서 안정적인 제어 환경 제공

---

## 확장성
이 프로젝트는 단일 버튼 제어에서 확장 가능합니다:
- ESP32의 GPIO 핀을 활용해 2개, 3개, 4개 이상의 버튼 입력을 동시에 처리 가능  
- Weintek HMI 화면에서 각 버튼을 개별적으로 표시 및 제어  
- 버튼 수가 늘어나도 Modbus/TCP 통신 구조는 동일  
- 확장 시 HMI 프로젝트에서 버튼 UI를 추가하고, ESP32 코드에서 핀 매핑만 변경하면 됨  

---

## Raspberry Pi 연동
- Raspberry Pi를 **끄면** ESP32 반도체에 저장된 세팅값으로 Weintek HMI가 정상 작동  
- Raspberry Pi에서 **CODESYS SL**을 실행하면, **스마트폰을 통해 제어** 가능  
- 즉,  
  - **터치 제어**를 원하면 Raspberry Pi를 끄고 HMI를 사용  
  - **모바일 제어**를 원하면 Raspberry Pi를 켜서 CODESYS SL을 실행  

---

## 참고 자료
- Weintek MT8102iP 공식 매뉴얼
- ESP32 아두이노 라이브러리 문서
- 프로젝트 회로도 및 HMI 화면 캡처

---

## 라이선스
MIT License

