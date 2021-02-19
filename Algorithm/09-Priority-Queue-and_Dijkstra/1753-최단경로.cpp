// 최단경로
/*
# SOLUTION

Dijkstra Algorithm

priority_queue<pair<int,int>>는 pair의 first를 기준으로 정렬되므로
first에 거리, second에 정점 번호를 넣어야함
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 20000
#define INF 1e12

int V, E, K;
vector<pair<int, int>> edge[MAX + 1];	// v[u].{v,w}
long long d[MAX + 1];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	while (pq.size()) {
		int cur = pq.top().second;
		long long distance = pq.top().first;
		pq.pop();
		if (d[cur] < distance) continue;
		for (auto next : edge[cur]) {
			long long nextDistance = distance + next.first;
			if (nextDistance < d[next.second]) {
				d[next.second] = nextDistance;
				pq.push({ d[next.second], next.second });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ w, v });
	}

	fill(d, d + V + 1, INF);

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
			continue;
		}
		cout << d[i] << '\n';
	}
}
