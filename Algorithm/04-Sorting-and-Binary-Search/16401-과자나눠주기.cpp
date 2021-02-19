// ���� �����ֱ�
/*
# SOLUTION

�ִ� ���� Ƚ�� = LN <= 10^9 �� 10^8 (1��) ���� ũ�Ƿ� ���� Ž�� �Ұ�
-> ���� Ž�� O(logLN)

���� Ž���� ���� Ž�� ����� �Ǵ� �迭 ����

[N(���� ����) < M(��� ��) �� ���]
�ϳ��� ���ڸ� ������ ���� ���� ���ڸ� ���� �� �ִٴ� �� ���� ����!
(�ϳ��� ���ڷ� ������ ���� �� ���� ���� �� �ִ� �� X)

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
