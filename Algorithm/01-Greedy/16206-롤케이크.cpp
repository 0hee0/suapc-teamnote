// ������ũ
/* �ƹ��ų� �߶� �Ǵ� ���� �ƴϴ�. 
20�� �� �� �ڸ��� 10�� �� ������, 30�� �� �� �ڸ��� 10�� �ϳ���. 
���� ª��, 10�� ����� �� == �� ���� ������ũ�� ���� �� �ִ� ����
���� �߶���Ѵ� */
#include <iostream>
#include <vector>
#include <algorithm>

#define LEN 10

using namespace std;


int N ,M;
int ans = 0;
vector<int> isMulTen;		// ���� = 10�� ���
vector<int> isNotMulTen;	// ���� != 10�� ���

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