# Dijkstra Algorithm
- Graph 내, 시작 정점에서 목표 정점까지의 최단경로를 구해주는 알고리즘
- O((V+E)logE)
- 가중치가 음수인 간선이 존재할 때는 사용할 수 없다.

# Priority_queue
- 다익스트라 알고리즘에서는 우선순위 큐라는 자료구조가 사용된다.
- 일반적인 큐는 먼저 들어온 데이터가 먼저 나간다.
- 우선순위 큐는 **들어간 순서에 상관없이 우리가 정한 우선순위가 높은 원소**를 추출한다.
- 여러 방법으로 구현할 수 있으나 일반적으로 heap 구조를 이용한다.
- 자료구조 heap을 이용하면 우선순위 큐의 삽입과 삭제를 O(logN)에 할 수 있다.
  - heap은 완전 이진 트리이다.
  - 이진 트리란, 각각의 노드가 최대 두 개의 자식 노드를 가지는 트리 자료 구조
  - 완전 이진 트리란, 이진 트리 중에서 마지막 레벨을 제외한 모든 레벨의 node가 완전히 채워져 있으며 마지막 레벨의 node들은 가능한 한 왼쪽부터 채워져 있는 구조

## priority가 수의 크기에 따른 것일 때 pq의 구현
```
priority_queue<int> pq1;    // 기본 pq는 내림차순 정렬
priority_queue<int, vector<int>, greater<>> pq2;    // 오름차순으로 정렬
```

## pq의 구현
```
#include <functional>

struct cmp {
  bool operator() (int x, int y) {
    return abs(x-3) > abs(y-3); 
  }
};
priority_queue<int, vector<int>, cmp> pq3;
}

struct D {
  int a, b;
}
struct cmpD {
  bool operator() (D x, D y) {
    if (x.a < y.a) return true;
    if (x.a > y.a) return false;
    if (x.b < y.b) return true;
    if (x.b > y.b) return false;
    return true;
  }
};
priority_queue<D, vector<D>, greater<cmpD>> pq4;
```

# Dijkstra Algorithm
- 아직 방문하지 않은 정점들 중 시작점으로부터 거리가 가장 짧은 정점 u를 방문한다.
- 해당 정점 u와 인접하고 아직 미방문 상태인 정점들의 거리를 갱신한다.
- 이를 V(정점 개수)번 반복한다.
- 구현은 pq를 이용한다.
- 방문체크를 함에 있어서 유의해야 한다. pq에서 나온 값이 현재 거리와 일치하는 지 여부를 통해 방문체크를 할 수 있다.

### 👩‍💻boj
- 1753 최단경로
