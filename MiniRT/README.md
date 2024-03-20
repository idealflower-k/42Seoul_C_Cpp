# MiniRT

### 프로젝트 설명
- 오브젝트의 정보를 받아 화면에 3d 렌더링 및 RayTracing을 사용하여 빛효과를 적용합니다.

### 정보 예시
```
A   0.1    255,255,255
C   0,0.5,-12   0,0,1   85
L   -8,0,-6     1    255,255,255
pl  0,-3,0    0,1,0    120,120,120
sp  0,3,0     2.5     100,100,100
cy  0,0,0   0,1,0  1   4   200,0,0
```
A (Ambient lightning): 조명 비율, 조명색상 \
C (Camera):시점의 좌표, 정규화 벡터, 수평 시야 각도\
pl (평면): 평면에 있는 점의 좌표, 정규화 법선 벡터, RGB값\
sp (구): 중심 좌표, 지름, RGB값\
cy (원기둥): 중심좌표, 축 벡터, 지름, 높이, RGB값

### 맡은 역할
- 오브젝트 정보 유효성 검사 및 파싱
- meta구조체안에 obj구조체를 연결리스트로 구성하여 저장
- 각 오브젝트를 3d로 렌더링후 빛 효과적용을 위한 벡터정보 저장

### 배운점
- 각 파트의 데이터에 대한 정확한 명세를 통해 팀원과의 협업 효율성 증가
- 사용자입력 검증 과정에서 중복된 코드의 함수화 및 재활용

### 어려웠던 점
- 다양한 입력 케이스에 대한 에러 기준 확립
- 오브젝트 렌더링을 위한 복잡한 벡터 연산
- 빠른 렌더링속도를 위한 성능 개선

### 결과물
<img width="1348" alt="스크린샷 2024-03-20 14 41 05" src="https://github.com/idealflower-k/42Seoul/assets/77483110/f5b490fe-e132-46f2-90a4-fd1587240b1f">
<img width="1192" alt="스크린샷 2024-03-20 14 43 14" src="https://github.com/idealflower-k/42Seoul/assets/77483110/efc0c8f8-5e2a-43ad-b0f0-bf2a10131952">
<img width="1192" alt="스크린샷 2024-03-20 14 44 02" src="https://github.com/idealflower-k/42Seoul/assets/77483110/8253c8e3-91ec-48e3-b1c8-af0daa4ddb70">
<img width="1192" alt="스크린샷 2024-03-20 14 44 45" src="https://github.com/idealflower-k/42Seoul/assets/77483110/1f57096c-3b72-4560-aed6-e437cd6a4df9">
<img width="1192" alt="스크린샷 2024-03-20 14 45 13" src="https://github.com/idealflower-k/42Seoul/assets/77483110/a5875c70-65f6-4824-844e-b6da3a0215a6">
