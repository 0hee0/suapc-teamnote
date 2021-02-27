// 1, 2, 3 더하기 3
/*
# SOLUTION

재귀 함수로 풀면 메모리 초과 발생. 반복문으로 해야 함.
	- 재귀 함수는 반복적으로 자기 자신을 부르면서 매번 스택에 추가 공간을 사용
	- 따라서 메모리의 제한이 있는 한 stack overflow가 발생
*/

#include <iostream>
using namespace std;
#define MAX 1000000
#define MOD 1000000009


int T;
long long d[MAX + 1];

// 사용 X
long long dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (d[n] != 0) return d[n];
	d[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
	return d[n] = d[n] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int k = 4; k <= MAX; k++) {
		d[k] += d[k - 1] + d[k - 2] + d[k - 3];
		d[k] %= MOD;
	}

	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;

		// cout << dp(n) << '\n';
		cout << d[n] << '\n';
	}
}
