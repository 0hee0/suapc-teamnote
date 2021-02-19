# 💡TIP
## 이차원 배열 인덱스의 합과 차
- 같은 우상 대각선 : i+j
- 같은 좌상 대각선 : i-j (항상 양수가 되게끔 값 조절할 것 **절댓값 아님 주의**)
## 표기식
1. 중위 표기식 (Infix) <br>
  A*(B+C) -> A*(B+C)
2. 전위 표기식 (Prefix)
3. 후위 표기식 (Postfix) <br>
  A*(B+C) -> ABC+* <br>
  A*B+C -> AB*C+ <br>
  A+B*C+D*E+G -> ABC*+DE*G+
## 기타 팁
- 별다른 조건 없이 입력을 끝내고 싶다면 CTRL+Z
- 배열 index<br>
배열의 index는 0부터 시작하므로, character(A-Z)를 배열의 index로 사용하려면 character - 'A' 한 값을 인덱스로 넣어야 한다.