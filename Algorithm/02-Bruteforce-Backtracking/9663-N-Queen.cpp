// N-Queen
/*
# SOLUTION

최대 연산 횟수 = (N^2)^N = (256)^14 >>>> 10^9 (제한시간 10초)
-> ???

체스에서 Queen이 움직일 수 있는 방향: 8가지 방향
하나의 행에 하나의 Queen만 존재해야하므로,
최대 연산 횟수 = N^N <= 14^14 < 10^9 로 **감소!**
-> backtracking

<같은 행 불가>는 행 하나에 Queen 하나 배치하는 것으로 해결!

<같은 열, 대각선 불가>는 각각 bool isused[]를 이용해서 풀기

같은 열 불가 j
같은 우상 대각선 불가 i+j
같은 좌상 대각선 불가 i-j (항상 양수가 되게끔 조절하기 + 절댓값 아님 주의!!!)
**같은 대각선: 이차원 배열의 인덱스의 합과 차 이용!**

*/

#include <iostream>
using namespace std;
#define MAX 15


int N;
int ans = 0;

bool isUsedCol[MAX];	// 중복되면 안되는 열
bool isUsedNE[MAX+MAX];	// 중복되면 안되는 우측 대각선 인덱스 합
bool isUsedNW[MAX+MAX];	// 중복되면 안되는 좌측 대각선 인덱스 차 (음수 방지를 위해 N - (level - j) 로 인덱스 표현)

void sol(int level) {
	if (level == N) {
		ans++;
		return;
	}

	for (int j = 0; j < N; j++) {
		if (isUsedCol[j] == true || isUsedNE[level + j] == true || isUsedNW[N - (level - j)] == true) continue;
		isUsedCol[j] = true;
		isUsedNE[level + j] = true;
		isUsedNW[N - (level - j)] = true;
		
		sol(level + 1);

		isUsedCol[j] = false;
		isUsedNE[level + j] = false;
		isUsedNW[N - (level - j)] = false;
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	sol(0);

	cout << ans;
}
