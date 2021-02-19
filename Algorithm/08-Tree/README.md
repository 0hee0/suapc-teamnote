# 트리 (Tree)
- 그래프의 일종
  - 모든 정점끼리 연결되어 있어야 한다.
  - 방향을 무시했을 때 사이클이 존재하지 않아야 한다.

  위 두 가지를 만족하는 정점 N개의 그래프는 항상 N-1개의 간선을 갖는다.

  **-> 트리의 간선 개수는 정점-1 개이다.**

## 트리의 특징
- 계층 구조를 이루는 자료를 표현하는 데 유용
- 용어
  - 루트 노드 : 가장 상위의 노드 (level 0 or level 1)
  - 깊이 (depth, or level) : 루트 노드와의 거리
  - 높이 : 가장 깊은 정점의 깊이 or 깊이 + 1

  - 부모 노드 : 연결관계의 두 노드 중 상위 노드
  - 자식 노드 : 연결관계의 두 노드 중 하위 노드
  - 리프 노드 : 자식이 없는 노드

  - 차수 (degree) : 자식 노드의 수
  - 서브 트리 (subtree) : 자식 노드를 루트로 하는 트리
- 임의의 점 u, v에 대해서 path(u, v) 가 유일하다.
- 루트 노드를 제외한 모든 노드는 하나의 부모를 갖는다.
- 재귀적 구조를 이루고 있다. (tree - subtree)

## 트리 구현
- 노드의 값
- 해당 노드의 부모
- 해당 노드의 자식들
```
struct TREENODE {
  int parent = -1;
  vector<int> children;
};

struct TREENODE tree[MAX];

for (int i = 0; i < N-1; i++) {
  int par, child;
  cin >> par >> child;
  tree[child].parent = par;
  tree[par].children.push_back(child);
}
```

# 이진 트리
- 자식 노드의 수가 최대 2개인 트리 구조
- 완전 이진 트리 <br>
위에서부터, 왼쪽부터 차례로 노드가 존재하며, 자식 노드의 수가 최대 2개인 트리 구조
- 포화 이진 트리 <br>
완전 이진 트리에서 자식 노드 수가 딱 2개씩 존재하는 트리 구조

## 이진 트리 구현
- 노드의 값
- 해당 노드의 부모
- 해당 노드의 왼쪽 자식, 오른쪽 자식
```
struct TREENODE {
  int parent = -1;
  int left_child = -1, right_child = -1;
};

struct TREENODE tree[MAX];

for (int i = 0; i < N-1; i++) {
  int par, child;
  cin >> par >> child;
  tree[child].parent = par;
  if (tree[par].left_child == -1) {
    tree[par].left_child = child;
  }
  else {
    tree[par].right_child = child;
  }
}
```

## 이진 트리 구현 (배열)
index
- 부모 노드 * 2 = 왼쪽 자식 노드
- 부모 노드 * 2 + 1 = 오른쪽 자식 노드
- 자식 노드 / 2 (버림) = 부모 노드

## 트리의 순회
- 전위 순회 : 자기 자신을 방문 후에 자식들을 방문 (VLR)
```
void pre_order(int root) {
  cout << root << " ";
  if (tree[root].left_child != -1) pre_order(tree[root].left_child);
  if (tree[root].right_child != -1) pre_order(tree[root].right_child);
}
```
- 중위 순회 : 왼쪽 자식 방문 -> 자신 방문 -> 오른쪽 자식 방문 (LVR)
```
void in_order(int root) {
  if (tree[root].left_child != -1) in_order(tree[root].left_child);
  cout << root << " ";
  if (tree[root].right_child != -1) in_order(tree[root].right_child);
}
```
- 후위 순회 : 왼쪽 자식 방문 -> 오른쪽 자식 방문 -> 자신 방문 (LRV)
```
void post_order(int root) {
  if (tree[root].left_child != -1) post_order(tree[root].left_child);
  if (tree[root].right_child != -1) post_order(tree[root].right_child);
  cout << root << " ";
}
```
## 이진 탐색 트리 (binary search tree)
- 왼쪽 서브 트리의 키들은 루트의 키보다 작아야 한다.
- 오른쪽 서브 트리의 키들은 루트의 키보다 커야 한다.
- 오른쪽 서브 트리와 왼쪽 서브 트리 모두 이진 탐색 트리이다. <br>
재귀적

## 이진 탐색 트리 (탐색)
1. 루트노드부터 시작
2. 노드의 key 값과 찾으려는 key 값을 비교. 찾으려는 값이 더 크면 우측 서브 트리로 진행, 찾으려는 값이 더 작으면 좌측 서브 트리로 진행
3. 노드의 key 값과 찾으려는 key 값이 같으면 탐색 성공
4. 만약 2.에서 이동해야 하는 서브 트리가 존재하지 않으면 탐색 실패 

## 이진 탐색 트리 (삭제)
- 삭제된 노드의 부모 노드가 왼쪽 서브 트리의 최댓값을 가리키거나 오른쪽 서브 트리의 최솟값을 가리키도록 한다.

## 시간 복잡도
- 균형 잡혀 있는 트리라면 O(logN)
- 균형이 잡혀 있지 않은 트리라면 O(N)

## 트리의 지름
- 가장 먼 두 정점 사이의 거리 혹은 가장 먼 두 정점을 연결하는 경로
  - 트리에서 임의의 정점 x를 잡는다.
  - 정점 x에서의 가장 먼 정점 y를 찾는다.
  - 정점 y에서의 가장 먼 정점 z를 찾는다.

  -> y-z의 경로가 트리의 지름

### 👩‍💻boj
  - 1967 : 트리의 지름
