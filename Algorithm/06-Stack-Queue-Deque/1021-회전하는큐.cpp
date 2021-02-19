// 회전하는 큐
#include <iostream>
#include <deque>
using namespace std;


int N, M;
deque<int> d;
int x;
int ans = 0;

void moveLeft(deque<int> &d) {
	int x = d.front();
	d.pop_front();
	d.push_back(x);
}

void moveRight(deque<int> &d) {
	int x = d.back();
	d.pop_back();
	d.push_front(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}

	for (int i = 1; i <= M; i++) {
		cin >> x;

		if (d.front() == x) {
			d.pop_front();
			ans += 0;
		}
		else {
			int index = 0;
			for (auto val : d) {
				if (val == x) {
					break;
				}
				index++;
			}
			if (index > (d.size() / 2)) {
				while (d.front() != x) {
					moveRight(d);
					ans++;
				}
			}
			else {
				while (d.front() != x) {
					moveLeft(d);
					ans++;
				}
			}
			d.pop_front();
		}
	}

	cout << ans;
}

