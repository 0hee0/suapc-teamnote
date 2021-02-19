// N-Queen
/*
# SOLUTION

�ִ� ���� Ƚ�� = (N^2)^N = (256)^14 >>>> 10^9 (���ѽð� 10��)
-> ???

ü������ Queen�� ������ �� �ִ� ����: 8���� ����
�ϳ��� �࿡ �ϳ��� Queen�� �����ؾ��ϹǷ�,
�ִ� ���� Ƚ�� = N^N <= 14^14 < 10^9 �� **����!**
-> backtracking

<���� �� �Ұ�>�� �� �ϳ��� Queen �ϳ� ��ġ�ϴ� ������ �ذ�!

<���� ��, �밢�� �Ұ�>�� ���� bool isused[]�� �̿��ؼ� Ǯ��

���� �� �Ұ� j
���� ��� �밢�� �Ұ� i+j
���� �»� �밢�� �Ұ� i-j (�׻� ����� �ǰԲ� �����ϱ� + ���� �ƴ� ����!!!)
**���� �밢��: ������ �迭�� �ε����� �հ� �� �̿�!**

*/

#include <iostream>
using namespace std;
#define MAX 15


int N;
int ans = 0;

bool isUsedCol[MAX];	// �ߺ��Ǹ� �ȵǴ� ��
bool isUsedNE[MAX+MAX];	// �ߺ��Ǹ� �ȵǴ� ���� �밢�� �ε��� ��
bool isUsedNW[MAX+MAX];	// �ߺ��Ǹ� �ȵǴ� ���� �밢�� �ε��� �� (���� ������ ���� N - (level - j) �� �ε��� ǥ��)

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
