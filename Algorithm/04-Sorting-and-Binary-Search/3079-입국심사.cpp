// �Ա� �ɻ�
/*
# SOLUTION

�ִ� ���� Ƚ�� = N*M <= (10^5)*(10^9) > 10^9(1��)�̹Ƿ� ����Ž�� �Ұ�
-> ���� Ž�� O(N*logM)

���� Ž���� ���� Ž�� ����� �Ǵ� �迭 ����

���ؾ��� ��: ��� ����� �ɻ縦 �޴µ� �ɸ��� �ð�
	Tk�� �� �ɸ��� �ð����� ��Ÿ����!
	�� �ɸ��� �ð��� �ִ� = M�� �ִ� * T[i]�� �ִ�
	high = 1e18 (10^9 * 10^9)

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000


int N, M;
long long high, low, mid;	// **�� �ɸ��� �ð�**
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