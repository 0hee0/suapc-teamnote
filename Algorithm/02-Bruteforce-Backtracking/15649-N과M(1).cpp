// N�� M (1)
/*
# SOLUTION

�ִ� ���� Ƚ�� = N^M <= 8^8 < 10^8 (�ð����� 1��)
-> ����Ž�� ����
Cf. ����� ���� N����M�� ������, Ž���� N^M�ؾ� N����M���� ��츦 ��� ã�� �� ����

BUT �ִ� 8�� for(1~8)���� �Ұ��ɿ� �����
=> ����Լ� ��� (= Backtracking!)
	- �Լ� Ż�� ���� �� ������ ��1
	function solve(level)
		if level == M then Ż��
		for (i=1~N) do
			�ߺ� ? continue : break (�ߺ�Ȯ��: �������� bool isused[i])
			answer[level] = i
			solve(level + 1)
			isused[i] = false (solve(level+1)�� Ż���ϸ� �� ��ġ�� ���� ��)
		end for
	end
*/

#include <iostream>
using namespace std;
#define MAX 9	// **�迭 ũ��: N�� �ִ�+1**


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

	// i=1���� i=N���� �� ������ �� �迭 ũ�� ����!!! 
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