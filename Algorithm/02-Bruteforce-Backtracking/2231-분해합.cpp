// 분해합
/*
최대 연산 횟수 = N <= 10^6 < 2 * 10^8 (시간제한 2초)
-> 완전 탐색 가능

[각 자릿수 계산 방법]
	do while (num/=10) != 0
		num%10
*/

#include <iostream>

using namespace std;


int N, M;

int sol(int N) {
	int sum;

	for (int i = 1; i <= N; i++) {
		int num = i;
		sum = num;
		do {
			sum += num % 10;
		} while ((num /= 10) != 0);

		if (sum == N) {
			return i;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << sol(N);
}
