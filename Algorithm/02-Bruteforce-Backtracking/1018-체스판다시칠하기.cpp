// 체스판 다시 칠하기
/*
# SOLUTION

최대 연산 횟수 = 50 * 50 * 8 * 8 = 16 * 10^4 < 2 * 10^8 (시간제한 2초)
-> 완전 탐색 가능

[8*8만 맞추면 된다는 것 까먹지 말기]
8*8 체스판의 왼쪽 맨 위 색이 흰색인 경우, 검은색인 경우로 case 나누기
가능한 8*8 체스판의 총 개수: (N-7)*(N-7)

[이차원 배열의 인덱스를 활용]
i+j의 합으로 각 위치의 색상과 숫자 매치
Case 1: 모든 B 짝수이면서 모든 W 홀수 (왼쪽 위가 검은색인 경우)
Case 2: 모든 B 홀수이면서 모든 W 짝수 (왼쪽 위가 흰색인 경우)

*/

#include <iostream>

using namespace std;


int N, M;
char board[50][50];
int minVal = 64;	// min이라고 하면 error!!!

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
			// CASE 1 a = i, b = j 흰색
			// a+b = 짝수 -> 흰색 (0+0, 0+2, 1+1...)
			// a+b = 홀수 -> 검은색

			// CASE 2 a = i, b = j 검은색
			// a+b = 짝수 -> 검은색 (0+0, 0+2, 1+1...)
			// a+b = 홀수 -> 흰색
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