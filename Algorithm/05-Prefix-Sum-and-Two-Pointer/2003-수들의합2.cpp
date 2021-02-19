// ������ �� 2
/*
# SOLUTION

�ð� ���� 0.5�� -> ���� ������ �ð� �ʰ�...!

-> Two Pointer

**/
#include <iostream>
using namespace std;
using ll = long long;
#define MAX 10000


int N;
ll M;
int A[MAX + 1];
ll sum = 0;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int start = 1, end = 1;
	for (;;) {
		if (sum >= M) {
			sum -= A[start++];
		}
		else if (end > N) break;
		else {
			sum += A[end++];
		}
		if (sum == M) {
			ans++;
		}
	}

	cout << ans;
}