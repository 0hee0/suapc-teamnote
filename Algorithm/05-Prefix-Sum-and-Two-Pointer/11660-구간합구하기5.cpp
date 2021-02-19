// 구간 합 구하기 5
#include <iostream>
using namespace std;
# define MAX 1024 


int N, M;
int val;
int pre[MAX + 1][MAX + 1];
int x, y, w, z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> val;
			pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + val;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> w >> z;
		cout << pre[w][z] - pre[w][y-1] - pre[x-1][z] + pre[x-1][y-1] << '\n';
	}
}