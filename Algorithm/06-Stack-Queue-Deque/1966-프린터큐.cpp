// 프린터 큐
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 100


int T, N, M;
int val;
int frontVal, frontIndex;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int print = 0;

		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> val;
			q.push(make_pair(val, j));
			pq.push(val);
		}

		while (!q.empty()) {
			frontVal = q.front().first;
			frontIndex = q.front().second;
			if (pq.top() == frontVal) {
				pq.pop();
				q.pop();
				print++;
				if (frontIndex == M) {
					cout << print << '\n';
					break;
				}
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
}