// DFS와 BFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1000


int N, M, V;
vector<int> v[MAX + 1];
// int arr[MAX][MAX];
int dfsChecked[MAX + 1];
int bfsChecked[MAX + 1];

void dfs(int x) {
	dfsChecked[x] = true;
	cout << x << ' ';
	for (int next : v[x]) {		// 탈출 조건: v[x]에 next가 더 이상 없는 경우
		if (dfsChecked[next]) continue;
		dfs(next);
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	bfsChecked[x] = true;
	while (q.size()) {
		int temp = q.front();
		cout << temp << ' ';
		q.pop();
		for (int next : v[temp]) {
			if (bfsChecked[next]) continue;
			q.push(next);
			bfsChecked[next] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;
	
	int firstV, secondV;
	for (int i = 0; i < M; i++) {
		cin >> firstV >> secondV;
		v[firstV].push_back(secondV);
		v[secondV].push_back(firstV);
	}

	for (int i = 0; i < MAX; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V);
	cout << '\n';
	bfs(V);
}