# STL
## 1. upper_bound & lower_bound
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
## 2. map & set
- key는 중복될 수 없음
- key를 기준으로 정렬된 상태
- 균형 이진탐색트리 구조
- 탐색, 삽입 : O(logN) <br>
  -> vector, list, array 보다 빠르게 값 탐색 및 삽입 가능
  
### 반복자 (iterator)
- 배열 및 컨테이너 내부 요소를 순회하는 객체
- map, set은 선형 자료구조가 아니기 때문에 iterator를 통해 순회
- iterator를 역참조하여 값에 접근할 수 있음

### 2-1. map : 키(key) - 값(value) 구조
map의 원소의 first에는 key, second에는 value가 저장되어 있음
```
#include <map>

map<int, int> mp;
for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
  cout << iter->first << ' ' << iter->second << '\n';    // key, value
for (auto iter = mp.begin(); iter != mp.end(); iter++) 
  cout << iter->first << ' '<< iter->second << '\n';
```
- 원소 삽입
  - insert : 해당 key에 value 가 대응된 원소 삽입 <br>
    만약 key가 이미 존재할 경우 value 변경되지 않음
    ```
    mp.insert({ 1, 11 });
    mp.insert(make_pair(2, 22));
    mp.insert({ 1, 11 });    // value 변화 없음
    ```
  - operator [] : key 값을 갖는 원소 생성 (default : value = 0) <br>
    만약 key가 이미 존재할 경우 해당 원소의 value 변경
    ```
    mp[1] = 111;
    mp[2] = 222;
    mp[3] += 333;    // mp[3] = 333
    ```
- 원소 유무 확인
  - find : 해당 key를 갖는 원소의 iterator 반환 <br>
    만약 해당 원소가 없을 경우 마지막 iterator 반환
    ```
    if (mp.find(1) != mp.end()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    ```
  - count : 해당 key를 갖는 원소 개수 반환 <br>
    map은 중복된 key를 갖지 않으므로 원소가 있으면 1, 없으면 0을 반환
    ```
    if (mp.count(1)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    ```
- 원소 값 변경
  - find
    ```
    map<int, int>::iterator iter = mp.find(1);
    if (iter != mp.end()) iter->second++;
    ```
  - operator []
    ```
    mp[1]++;
    ```
- 원소 삭제
  - erase : 해당 key를 갖는 원소가 있을 경우 이를 삭제
    ```
    mp.erase(1);
    ```
- 원소 개수
  - size : map의 원소 개수를 반환
    ```
    cout << mp.size() << '\n';
    ```
### 2-2. set : 키(key)값만 저장
set은 중복되지 않는 값들이 오름차순으로 정렬되어 저장된 컨테이너
```
#include <set>

set<int> st;
for (set<int, int>::iterator iter = st.begin(); iter != st.end(); iter++)
  cout << *iter << '\n';    // key
for (auto iter = st.begin(); iter != st.end(); iter++) 
  cout << *iter << '\n';
```

- 원소 삽입
  - insert : 해당 값을 갖는 원소 삽입 <br>
    만약 해당 원소가 이미 있을 경우 set 구성에 변화 없음
    ```
    st.insert(1);
    st.insert(2);
    st.insert(1);    // 변화 없음
    ```
- 원소 유무 확인
  - find : 해당 값을 갖는 원소의 iterator 반환 <br>
    만약 해당 원소가 없을 경우 마지막 iterator 반환
    ```
    if (st.find(1) != st.end()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    ```
  - count : 해당 값를 갖는 원소 개수 반환 <br>
    set은 중복된 원소 갖지 않으므로 원소가 있으면 1, 없으면 0을 반환
    ```
    if (st.count(1)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    ```
- 원소 삭제
  - erase : 해당 값을 갖는 원소가 있을 경우 이를 삭제
    ```
    st.erase(1);
    ```
- 원소 개수
  - size : set의 원소 개수를 반환
    ```
    cout << st.size() << '\n';
    ```
## 3. 
