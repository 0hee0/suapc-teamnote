// 트리의 지름
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10000

struct NODE {
	vector<pair<int, int>> children;
};

int n;
struct NODE tree[MAX + 1];
bool visited[MAX + 1];
int maxVal = 0;
int pos;

void dfs(int x, int sum) {
	visited[x] = true;
	if (sum > maxVal) {
		maxVal = sum;
		pos = x;
	}
	for (pair<int, int> next : tree[x].children) {
		if (visited[next.first]) continue;
		dfs(next.first, next.second + sum);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	int par, child, w;
	for (int i = 1; i < n; i++) {
		cin >> par >> child >> w;
		tree[par].children.push_back({ child, w });
		tree[child].children.push_back({ par, w });
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(pos, 0);

	cout << maxVal;
}