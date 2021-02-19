// 과자 나눠주기
/*
# SOLUTION

최대 연산 횟수 = LN <= 10^9 는 10^8 (1초) 보다 크므로 완전 탐색 불가
-> 이진 탐색 O(logLN)

이진 탐색을 위해 탐색 대상이 되는 배열 정렬

[N(과자 개수) < M(사람 수) 인 경우]
하나의 과자를 나눠서 여러 개의 과자를 만들 수 있다는 점 잊지 말자!
(하나의 과자로 무조건 과자 한 개만 만들 수 있는 것 X)

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000


int M, N;
int high, low, mid;
int maxVal = 0;
int cnt;
long long quotient;
long long L[MAX + 1];

bool compare(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		cin >> L[i];
	}

	sort(L+1, L+1 + N, compare);

	high = 1e9;
	low = 1;
	while (high >= low) {
		cnt = 0;
		mid = (high + low) / 2;
		for (int i = 1; i <= N; i++) {
			quotient = L[i] / mid;
			if (quotient) {
				cnt += quotient;
				if (cnt >= M) {	
					maxVal = mid;
					low = mid + 1;
					break;
				}
			}
			else {
				high = mid - 1;
				break;
			}
			if (i == N) {
				high = mid - 1;
				break;
			}
		}	
	}

	cout << maxVal;
}
