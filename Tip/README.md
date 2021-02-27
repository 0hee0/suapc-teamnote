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

## 배수 판정법
🔗 [Reference](https://ko.wikipedia.org/wiki/%EB%B0%B0%EC%88%98_%ED%8C%90%EC%A0%95%EB%B2%95)
## 소수점 자릿수 조절
```
const double num = 4321.1234;
// 기본 : 총 자릿수 = 정수부분길이 + 소수부분길이 = 6 
cout << num << endl; // 4321.12
// cout << fixed가 없다면 [총 자릿수 =  precision의 인수]
cout.precision(3);
cout << num << endl; // 4.32e+03
// 소수점 이하 넷째 자리에서 반올림하여 소수점 이하 셋째 자리까지 출력
cout << fixed;    
cout.precision(3); // 4321.123
```
🔗 [Reference](https://pmoncode.tistory.com/20)
## 틀렸습니다
- 경계값을 넣어서 범위 확인을 해보자. e.g. long long을 사용해야하는 데 int를 사용한 경우
## 기타 팁
- 별다른 조건 없이 입력을 끝내고 싶다면 CTRL+Z
- 배열 index<br>
배열의 index는 0부터 시작하므로, character(A-Z)를 배열의 index로 사용하려면 character - 'A' 한 값을 인덱스로 넣어야 한다.

