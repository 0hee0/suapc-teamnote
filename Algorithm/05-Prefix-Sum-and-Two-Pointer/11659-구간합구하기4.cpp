// 구간 합 구하기 4
/*
# SOLUTION

구간 합 구하는 법
	- Prefix sum
	- Segment Tree

여기서는 prefix sum 사용

*/

#include <iostream>
using namespace std;
#define MAX 1000000

int N, M;
int pre[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int num;
	for (int k = 1; k <= N; k++) {
		cin >> num;
		pre[k] = pre[k - 1] + num;
	}

	int i, j;
	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		cout << pre[j] - pre[i - 1] << '\n';
	}
}