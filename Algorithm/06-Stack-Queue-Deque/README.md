# Stack & Queue & Deque
# 1. 스택
- LIFO (Last In First Out)
- STL stack 주요 기능
  - 삽입 push()
  - 삭제 pop()
  - 제일 상단의 원소 확인 top()
  - 스택의 사이즈 확인 size()
  - 스택이 비어있는 지 확인 empty()
  Cf. 시간 복잡도 O(1) / 중간 원소 접근 불가
- **주의** 스택이 비어있는 경우, pop(), top() 불가!
### 👩‍💻 boj
- 9012 : 괄호
- 1935 : 후위 표기식 2
# 2. 큐
- FIFO (First In First Out)
- STL queue 주요 기능
  - 삽입 push()
  - 삭제 pop()
  - 제일 앞 / 뒤에 있는 원소 확인 front() / back()
  - 큐의 사이즈 확인 size()
  - 큐가 비어있는 지 확인 empty()
  Cf. 시간 복잡도 O(1) / 중간 원소 접근 불가
- **주의** 큐가 비어있는 경우, pop(), front() back() 불가!
### 👩‍💻 boj
- 1158 : 요세푸스 문제
# 3. 덱 (Double Ended Queue)
- **처음과 끝에서 삽입 삭제가 일어나는 경우에 쓰임**
- 중간 원소에 접근이 가능은 하지만 삽입 삭제에 있어서 효율성이 매우 떨어짐
- STL deque 주요 기능
  - 삽입 push_front() / push_back()
  - 삭제 pop_front() / pop_back()
  - 제일 앞 / 뒤에 있는 원소 확인 front() / back()
  - 덱의 사이즈 확인 size()
  - 덱이 비어있는 지 확인 empty()
