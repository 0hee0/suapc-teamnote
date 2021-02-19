// ü���� �ٽ� ĥ�ϱ�
/*
# SOLUTION

�ִ� ���� Ƚ�� = 50 * 50 * 8 * 8 = 16 * 10^4 < 2 * 10^8 (�ð����� 2��)
-> ���� Ž�� ����

[8*8�� ���߸� �ȴٴ� �� ����� ����]
8*8 ü������ ���� �� �� ���� ����� ���, �������� ���� case ������
������ 8*8 ü������ �� ����: (N-7)*(N-7)

[������ �迭�� �ε����� Ȱ��]
i+j�� ������ �� ��ġ�� ����� ���� ��ġ
Case 1: ��� B ¦���̸鼭 ��� W Ȧ�� (���� ���� �������� ���)
Case 2: ��� B Ȧ���̸鼭 ��� W ¦�� (���� ���� ����� ���)

*/

#include <iostream>

using namespace std;


int N, M;
char board[50][50];
int minVal = 64;	// min�̶�� �ϸ� error!!!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			// CASE 1 a = i, b = j ���
			// a+b = ¦�� -> ��� (0+0, 0+2, 1+1...)
			// a+b = Ȧ�� -> ������

			// CASE 2 a = i, b = j ������
			// a+b = ¦�� -> ������ (0+0, 0+2, 1+1...)
			// a+b = Ȧ�� -> ���
			int countOne = 0, countTwo = 0;
			for (int a = i; a < i + 8; a++) {
				for (int b = j; b < j + 8; b++) {
					if ((a + b) % 2 == 0) {
						if (board[a][b] == 'B') {
							countOne++;
						}
						else {
							countTwo++;
						}
					}
					else {
						if (board[a][b] == 'W') {
							countOne++;
						}
						else {
							countTwo++;
						}
					}
				}
			}
			
			if (minVal > countOne) {
				minVal = countOne;
			}
			if (minVal > countTwo) {
				minVal = countTwo;
			}

		}
	}

	cout << minVal;
}