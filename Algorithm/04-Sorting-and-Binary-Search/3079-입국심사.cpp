// 입국 심사
/*
# SOLUTION

최대 연산 횟수 = N*M <= (10^5)*(10^9) > 10^9(1초)이므로 완전탐색 불가
-> 이진 탐색 O(N*logM)

이진 탐색을 위해 탐색 대상이 되는 배열 정렬

구해야할 것: 모든 사람이 심사를 받는데 걸리는 시간
	Tk를 총 걸리는 시간으로 나타내기!
	총 걸리는 시간의 최대 = M의 최대 * T[i]의 최대
	high = 1e18 (10^9 * 10^9)

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000


int N, M;
long long high, low, mid;	// **총 걸리는 시간**
long long cnt;
long long minVal = 1e18;
long long T[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> T[i];
	}

	sort(T + 1, T + 1 + N);

	high = 1e18;
	low = 1;
	while (high >= low) {
		mid = (high + low) / 2;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += mid / T[i];
			if (cnt >= M) {
				minVal = mid;
				break;
			}
		}
		if (cnt >= M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << minVal;
}