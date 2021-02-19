// ȸ�ǽ� ����
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int N;
int ans = 0;
vector<pair<int, int>> conference;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	// ���� ������ �ð��� ª�� ȸ�Ǹ� �׸����ϰ� ����
	int S, E;
	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		conference.push_back(make_pair(E, S));
	}

	sort(conference.begin(), conference.end());

	int assignedE;
	if (N > 0) {
		assignedE = conference[0].first;
		ans = ans + 1;
	}
	for (int i = 1; i < N; i++) {
		if (conference[i].second >= assignedE) {
			ans = ans + 1;
			assignedE = conference[i].first;
		}
	}

	cout << ans;
}