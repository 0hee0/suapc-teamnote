// 1, 2, 3 ¥ı«œ±‚ 3
#include <iostream>
using namespace std;
#define MAX 1000000
#define MOD 1000000009


int T;
long long d[MAX + 1];

long long dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (d[n] != 0) return d[n];
	d[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
	return d[n] = d[n] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int k = 4; k <= MAX; k++) {
		d[k] += d[k - 1] + d[k - 2] + d[k - 3];
		d[k] %= MOD;
	}

	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;

		// cout << dp(n) << '\n';
		cout << d[n] << '\n';
	}
}