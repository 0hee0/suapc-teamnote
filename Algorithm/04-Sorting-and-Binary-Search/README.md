# 정렬 & 이분 탐색
# 1. 정렬
- 원소들을 번호순이나 사전 순서와 같이 일정한 순서대로 열거하는 알고리즘
## 선택(Selection) 정렬
- 정렬되지 않은 리스트의 최솟값을 선택
- 그 최솟값을 리스트의 맨 앞의 값과 바꾼다.
- 최솟값이 저장된 index의 다음부터 위 과정을 반복한다.
시간복잡도 : 최선 O(n^2) | 평균 O(n^2) | 최악 O(n^2) <br>
공간복잡도 : O(1)
```
void selection_sort() {
  int temp, min_index;
  for (int i = 1; i <= n; i++) {
    min_index = i;
    for (int j = i + 1; j <= n; j++) {
      if (list[j] < list[min_index]) {
        min_index = j;
      }
    }
    temp = list[i];
    list[i] = list[min_index];
    list[min_index] = temp;
  }
}
```
## 삽입(Insertion) 정렬
- 두 번째 index부터 시작, key 값을 index 값으로 함
- key 값과 정렬된 앞의 값들과 비교를 한 뒤에 적절한 위치에 삽입
- index+1 을 한 뒤 위 과정 반복
시간복잡도 : 최선 O(n) | 평균 O(n^2) | 최악 O(n^2) <br>
공간복잡도 : O(1)
```
void insertion_sort() {
  int i, j, key;
  for (i = 2; i <= n; i++) {
    key = list[i];
    for (j = i-1; j > 0 && list[j] > key; j--) {
      list[j+1] = list[j];
    }
    list[j+1] = key;
  }
}
```
## 버블(Bubble) 정렬
- 어떤 index와 index+1을 비교해서 정렬한다.
- index를 리스트의 개수 -1 까지 진행시킨다.
- 마지막 index를 제외한 뒤 위 과정을 반복한다.
시간복잡도 : 최선 O(n^2) | 평균 O(n^2) | 최악 O(n^2) <br>
공간복잡도 : O(1)
```
void bubble_sort() {
  int i, j, temp;
  for (i = n; i > 1; i--) {
    for (j = 0; j < i; j++) {
      if (list[j] < list[j+1]) {
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}
```
## 퀵(Quick) 정렬
- 임의의 index를 pivot으로 잡는다.
- pivot 좌측에는 pivot보다 작은 수, 우측에는 큰 수가 오게끔 배치한다.
- pivot을 제외한 pivot의 좌측과 우측 두 개의 리스트에 대해서 위 과정을 재귀적으로 반복한다.
시간복잡도 : 최선 O(nlogn) | 평균 O(nlogn) | 최악 O(n^2) <br>
공간복잡도 : O(1)
```
void quick_sort(int low, int high) {
  if (low >= high) return;
  int pivot = low;
  int i = low + 1, j = high, temp;
  while (i <= j) {
    while (i <= high && list[i] <= list[pivot]) {
      i++;
    }
    while (i > low && list[j] >= list[pivot]) {
      j--;
    }
    if (i > j) {
      temp = list[j];
      list[j] = list[pivot];
      list[pivot] = temp;
    }
    else {
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }

  quick_sort(low, j - 1);
  quick_sort(j + 1, high);
}
```
## 합병(Merge) 정렬
- 정렬되지 않은 리스트의 크기가 1이 될 때까지 절반으로 잘라 나눈다.
- 인접한 두 개의 리스트를 정렬하면서 합친다. (각각 리스트는 정렬되어 있다.)
- 리스트가 모두 합쳐질 때까지 2-3 과정을 반복한다.
시간복잡도 : 최선 O(nlogn) | 평균 O(nlogn) | 최악 O(nlogn) <br>
공간복잡도 : O(n)
```
void merge(int low, int mid, int high) {
  int l_idx = low;
  int r_idx = mid;
  int t_idx = low;
  while (l_idx < mid && r_idx < high) {
    if (arr[l_idx] < arr[r_idx]) tmp[t_idx++] = arr[;_idx++];
    else tmp[t_idx++] = arr[r_idx++];
  }

  while (l_idx < mid) tmp[t_idx++] = arr[l_idx++];
  while (r_idx < high) tmp[t_idx++] = arr[r_idx++];

  for (int i = low; i < high; i++) arr[i] = tmp[i];
}

void merge_sort(int low, int high) {
  if (low == high - 1) return;
  int mid = (low + high) / 2;
  merge_sort(low, mid);
  merge_sort(mid, high);
  merge(low, mid, high);
}
```
## STL sort 함수
\#include <algorithm>
- 기본형 (오름차순)
```
template <class RandomAccessIterator>
  void sort (RandomAccessIterator first, RandomAccessIterator last);
```
- 직접 비교함수 작성
```
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare cmp);
```
- 여러 개의 조건에 순위를 둬서 정렬하고 싶다면?
-> struct 정의!
```
struct student {
  int eyesight, score;
}

// a와 b의 eyesight가 같다면 score로 비교
bool compare(struct student a, struct student b) {
  if (a.eyesight != b.eyesight) return a.eyesight < b.eyesight;
  return a.score > b.score;
}
```

# 2. 이분(Binary) 탐색
- **정렬**된 리스트에서 특정한 값의 위치를 찾아내는 알고리즘
e.g. up/down 게임
```
int binary_search(int answer) {
  int high = n;
  int low = 1;
  int mid;
  while (high >= low) {
    mid = (high + low) / 2;
    if (num[mid] == answer) return mid;
    if (num[mid] > answer) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}
```
## problem/
- 2805 : 나무 자르기
- 3079 : 입국 심사
