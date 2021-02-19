// 강의실 배정
/*
# SOLUTION

problem/1931 : 회의실 배정
- 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수
-> Greedy Algorithm

problem/11000 : 강의실 배정
- 최소의 강의실을 사용해서 모든 수업을 가능하게 배정
- N : 200,000 , 제한시간 1초
-> priority_queue (Heap; nlogn의 시간 복잡도)
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
