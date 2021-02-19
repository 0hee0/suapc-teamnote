# Graph
## Graph의 정의
- 정점(vertex)과 간선(edge)의 집합으로 정의된 자료구조
- 간선은 정점과 정점을 연결해주고 간선을 통해 연결된 정점은 '인접'해있다고 한다.
- G = (V,E) 로 표현
- 그래프는 크게 두 가지로 분류된다.
  - directed graph (단방향 그래프)
  - undirected graph (양방향 그래프)
- 용어
  - degree (차수) <br>
    정점에 연결된 간선의 수 <br>
    방향그래프에서 indegree, outdegree 로 나뉜다.
  - indegree <br>
    방향 그래프에서 해당 정점으로 돌아오는 간선의 수
  - outdegree <br>
    방향 그래프에서 해당 정점에서 나가는 간선의 수

    ∑ indegree = ∑ outdegree <br>
    ∑ degree = ∑ indegree + ∑ outdegree

    그래프 degree를 이용해 cycle 판정과 위상정렬을 할 수 있다.

  - path (경로)

    0번 정점에서 4번 정점으로 가는 경로들
    - 0 → 1 → 4
    - 0 → 1 → 2 → 4
    - 0 → 1 → 3 → 4
  - cycle <br>
    한 정점에서 path를 따라 동일한 정점으로 돌아올 수 있는 경우
    - 0 → 1 → 3 → 0
  - weight (가중치)
    - 간선에 할당되는 무게
    - 간선의 거리와 비용에 사용
    - 가중치가 존재하는 그래프를 weighted graph(가중치 그래프)라고 한다.

## Graph의 표현
### 1. 인접 행렬, Adjacent Matrix
- 두 정점 간의 간선 연결관계를 |V|*|V| 크기의 행렬(배열) 형태로 표현
- 배열로 행렬을 구현하므로 정점 i - j 간의 연결관계를 파악하고 싶을 때, i행 j열을 참조하면 O(1)에 파악 가능
- 구현이 간단한 대신에 공간복잡도가 O(V^2)이라 정점이 많아지면 사용 불가
### 2. 인접 리스트, Adjacent List
- 각 정점에 연결돈 정점들을 리스트에 담아 보관
- STL vector를 사용해 구현하고, 임의의 두 정점의 연결관계를 체크하는데, O(|V|)에 파악 가능
- 공간복잡도가 O(E)

  0 → [1] <br>
  1 → [2, 3, 4] <br>
  2 → [4] <br>
  3 → [4] <br>
  4 → [0] <br>

  ## Graph의 순회
  ### 1. DFS 깊이 우선 탐색 (Depth First Search)
  - 현재 정점에서 갈 수 있는 정점으로 들어가 계속해서 탐색하고 들어갔던 정점에서의 탐색이 종료되면 (leaf node 와 만나면), 나머지 정점을 탐색한다.
  - 방문체크를 할 배열이 필요하고 보통 재귀함수로 구현한다.

  - 인접 리스트로 구현
  ```
  void dfs(int x) {
    checked[x] = true;
    cout << x << ' ';
    for (int next : v[x]) {
      if (checked[next]) continue;
      dfs(next);
    }
  }
  ```
  - 인접 행렬로 구현
  ```
  void dfx(int x) {
    checked[x] = true;
    cout << x << ' ';
    for (int i = 0; i < MAX; i++) {
      if (connected[x][i] && checked[i]) dfs(i);
    }
  }
  ```

  ### 2. BFS 너비 우선 탐색 (Breadth First Search)
  - 현재 정점에서 인접한 정점들을 우선적으로 탐색하는 방식
  - 방문체크를 할 배열과 방문순서를 관리할 큐가 필요

  - 인접 리스트로 구현
  ```
  void bfs(int x) {
    queue<int> q;
    q.push(x);
    checked[x] = true;
    while (q.size()) {
      int temp = q.front();
      cout << temp << ' ';
      q.pop();
      for (int next : v[temp]) {
        if (checked[next]) continue;
        q.push(next);
        checked[next] = true;
      }
    }
  }
  ```
  - 인접 행렬로 구현
  ```
  void bfs(int x) {
    queue<int> q;
    q.push(x);
    checked[x] = true;
    while (q.size()) {
      int temp = q.front();
      cout << temp << ' ';
      q.pop();
      for (int i = 0; i < MAX; i++) {
        if (connected[temp][i] && !checked[i]) {
          q.push(i);
          checked[i] = true;
        }
      }
    }
  }
  ```
  **dfs로 탐색을 하게 되면, 최악의 경우 모든 경우를 전부 탐색해봐야 한다.<br> -> 따라서 웬만하면 bfs를 사용하자.**

  ### 👩‍💻boj
  - 16953 : A → B
