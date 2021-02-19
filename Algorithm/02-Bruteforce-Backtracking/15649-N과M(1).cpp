// N과 M (1)
/*
# SOLUTION

최대 연산 횟수 = N^M <= 8^8 < 10^8 (시간제한 1초)
-> 완전탐색 가능
Cf. 경우의 수는 N순열M이 맞지만, 탐색은 N^M해야 N순열M개의 경우를 모두 찾을 수 있음

BUT 최대 8중 for(1~8)문은 불가능에 가까움
=> 재귀함수 사용 (= Backtracking!)
	- 함수 탈출 조건 잘 설정할 것1
	function solve(level)
		if level == M then 탈출
		for (i=1~N) do
			중복 ? continue : break (중복확인: 전역변수 bool isused[i])
			answer[level] = i
			solve(level + 1)
			isused[i] = false (solve(level+1)을 탈출하면 이 위치로 오게 됨)
		end for
	end
*/

#include <iostream>
using namespace std;
#define MAX 9	// **배열 크기: N의 최댓값+1**


int N, M;
bool isUsed[MAX];
int ans[MAX];

void sol(int level) {
	if (level == M) {
		for (int j = 0; j < M; j++) {
			cout << ans[j] << " ";
		}
		cout << "\n";
		
		return;
	}

	// i=1부터 i=N까지 값 저장할 때 배열 크기 주의!!! 
	for (int i = 1; i <= N; i++) {
		if (isUsed[i] == true) {
			continue;
		}
		ans[level] = i;
		isUsed[i] = true;
		sol(level + 1);
		isUsed[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	sol(0);
}