// A → B
/*
# SOLUTION

X 10 + 1 은 항상 홀수
X 2 는 항상 짝수
이므로 dfs로 탐색을 해도 최적해를 바로 찾을 수 있음
-> dfs / bfs 모두 가능
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