// ���ǽ� ����
/*
# SOLUTION

problem/1931 : ȸ�ǽ� ����
- ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ����
-> Greedy Algorithm

problem/11000 : ���ǽ� ����
- �ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� ����
- N : 200,000 , ���ѽð� 1��
-> priority_queue (Heap; nlogn�� �ð� ���⵵)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
#define MAX 200000


int N;
pair<int, int> arr[MAX + 1];
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int S, T;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr + 1, arr + N + 1);

	pq.push(arr[1].second);

	for (int i = 2; i <= N; i++) {
		if (pq.top() <= arr[i].first) {
			pq.pop();
		}
		pq.push(arr[i].second);
	}

	cout << pq.size();
}
