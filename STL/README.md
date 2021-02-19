# STL
## upper_bound & lower_bound
- upper_bound : 찾고자 하는 값을 최초로 초과하는 값 index의 주소를 반환
```
template <class FowardIterator, class T>
  FowardIterator upper_bound (FowardIterator first, FowardIterator last, const T& val)
```
- lower_bound : 찾고자 하는 값보다 크거나 같은 최초의 값 index의 주소를 반환
```
template <class FowardIterator, class T>
  FowardIterator lower_bound (FowardIterator first, FowardIterator last, const T& val)
```
- 예시
```
#include <iostream>
#include <algorithm>
using namespace std;

int arr[6] = { 1, 2, 5, 7, 8, 10 };

int main() {
  int index = lower_bound(arr, arr+6, 3) -a arr;
  cout << index '\n';    // 2
  index = lower_bound(arr, arr+6, 5) -a arr;
  cout << index '\n';    // 2 (5 보다 크거나 같은 최초 값 : 5)
  index = upper_bound(arr, arr+6, 7) -a arr;
  cout << index '\n';    // 4 (7 초과하는 최초 값 : 8)
}
```
