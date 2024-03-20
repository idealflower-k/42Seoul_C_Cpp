# webserv

### 프로젝트 설명
- C++, kqueue를 사용하여 I/O multiplexing 정적 웹서버 구현
- 설정파일은 nginx의 설정파일의 구성과 동작을 참고하여 구성
- ./webserv {설정파일} 형식으로 서버 실행

### 맡은 역할 (팀원 총 3명)
- 설정파일 파싱 결과를 받아 웹서버 설정 및 시작
- 클라이언트의 연결 요청처리
- 서버 메인 구조 설계 및 이벤트 관리 로직 구현

### 배운 점
- 객체지향 구조 설계 방법
- HTTP, nginx의 동작
- IPC통신 성능 개선

### 어려웠던 점
- 객체지향 구조 설계
- I/O multiplexing환경에서 kevent관리 구조 설계
- IPC통신 성능 개선

### 인상깊은 점
- socket을 사용한 데이터 전송속도의 문제를 2개의 pipe를 활용하여 약8배 성능 개선
- socket통신은 한번에 약 8kb 전송가능, pipe통신은 약 64kb 전송가능
- 다형성과 오버라이딩을 활용하여 별도의 조건문없이 동작로직 구현

### 설정파일
- config/server 참고

### siege 테스트
```
Transactions:                  65305 hits
Availability:                  99.94 %
Elapsed time:                 121.20 secs
Data transferred:              19.24 MB
Response time:                  0.03 secs
Transaction rate:             538.82 trans/sec
Throughput:                     0.16 MB/sec
Concurrency:                   16.45
Successful transactions:       65305
Failed transactions:              39
Longest transaction:           19.52
Shortest transaction:           0.00
```
