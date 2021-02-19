// 롤케이크
/* 아무거나 잘라서 되는 것이 아니다. 
20을 한 번 자르면 10이 두 개지만, 30을 한 번 자르면 10이 하나다. 
따라서 짧고, 10의 배수인 것 == 더 많은 롤케이크를 만들 수 있는 조건
먼저 잘라야한다 */
#include <iostream>
#include <vector>
#include <algorithm>

#define LEN 10

using namespace std;


int N ,M;
int ans = 0;
vector<int> isMulTen;		// 길이 = 10의 배수
vector<int> isNotMulTen;	// 길이 != 10의 배수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int length;
	for (int i = 0; i < N; i++) {
		cin >> length;
		if (length % 10 == 0) {
			isMulTen.push_back(length);
		}
		else {
			isNotMulTen.push_back(length);
		}
	}

	sort(isMulTen.begin(), isMulTen.end());
	sort(isNotMulTen.begin(), isNotMulTen.end());

	for(int i = 0; i < isMulTen.size(); i++) {
		while (isMulTen[i] > LEN) {
			if (M == 0) break;
			M--;
			isMulTen[i] = isMulTen[i] - LEN;
			ans++;
		}
		if (isMulTen[i] == LEN) {
			ans++;
		}
	}

	if (M > 0) {
		for (int i = 0; i < isNotMulTen.size(); i++) {
			while (isNotMulTen[i] > LEN) {
				if (M == 0) break;
				M--;
				isNotMulTen[i] = isNotMulTen[i] - LEN;
				ans++;
			}
		}
	}

	cout << ans;
}