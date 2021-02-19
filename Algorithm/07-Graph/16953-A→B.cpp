// A �� B
/*
# SOLUTION

X 10 + 1 �� �׻� Ȧ��
X 2 �� �׻� ¦��
�̹Ƿ� dfs�� Ž���� �ص� �����ظ� �ٷ� ã�� �� ����
-> dfs / bfs ��� ����
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;


long long A, B;
queue<pair<long long, long long>> q;
pair<long long, long long> cur;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	q.push({ A, 1 });
	while (q.size()) {
		cur = q.front();
		q.pop();
		if (cur.first == B) {
			cout << cur.second;
			return 0;
		}
		else if (cur.first < B) {
			q.push({ cur.first * 2, cur.second + 1 });
			q.push({ cur.first * 10 + 1, cur.second + 1 });
		}
	}

	cout << "-1";
}