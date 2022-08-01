# B. Party

[링크](https://codeforces.com/contest/1711/problem/B)

| 난이도 |
| :----: |
| \*1300 |

## 설계

### 시간 복잡도

A의 크기를 N, 연결관계 간선의 크기를 M이라 하자.

간선의 갯수, 각 노드의 진입차수에 따라서 최선의 경우만 비교해 문제를 푸이할 수 있다.

이 경우 간선을 순회해 노드의 진입차수를 생성하고, 노드와 간선들을 순회해 정답을 구할 수 있다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 인원이 불참했을때의 비용을 저장하는데 O(N), 연결관계를 저장할 경우 O(M)의 공간 복잡도를 사용한다.

이후 진입차수를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 진입차수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      78      |  O(N + M)   |  O(N + M)   |

각 노드의 간선의 수가 짝수인 경우는 모두 참여해도 된다. 따라서 이 경우는 무시한다.

간선의 갯수가 홀수개인 경우 특정 노드들을 제거하고 간선의 수를 짝수로 만들어야 한다.

정답의 후보중 하나는 모든 노드를 제거하는 것이다.

삭제할 간선을 파악하기 위해 각 노드별로 진입차수를 미리 계산해놓는다. (진입차수를 각 노드에 연결된 간선의 수로 볼 수 있음)

이후 다음 경우에 대해서 탐색할 수 있다.

- 진입차수가 홀수인 노드 하나를 제거
- 진입차수가 짝수인 연결된 노두 두개를 제거

첫번째 경우는 해당 노드를 제거할 경우 간선이 홀수개 제거되므로 결국 남은 간선은 짝수개가 된다.

따라서 각 노드들을 순회하며 최소 비용을 갱신한다.

두번째 경우는 진입차수가 짝수인 연결된 두 노드를 제거할 경우, 각 노드들의 진입차수 만큼의 간선이 삭제되며, 여기서 한 간선은 중복되므로 결국 홀수개가 제거된다.

따라서 연결관계를 순회하며 정답을 갱신한다.

```cpp
long long solution(int n, int m, vector<int> &arr, vector<pair<int, int>> &edges) {
  if (m % 2 == 0) return 0;

  vector<int> inDegree(n, 0);
  for (pair<int, int> &edge : edges) {
    int x = edge.first - 1, y = edge.second - 1;
    inDegree[x]++;
    inDegree[y]++;
  }

  int answer = accumulate(arr.begin(), arr.end(), 0);
  for (int node = 0; node < n; node++) {
    if (inDegree[node] % 2 == 1) {
      answer = min(answer, arr[node]);
    }
  }

  for (pair<int, int> &edge : edges) {
    int x = edge.first - 1, y = edge.second - 1;
    if (inDegree[x] % 2 == 0 && inDegree[y] % 2 == 0) {
      answer = min(answer, arr[x] + arr[y]);
    }
  }

  return answer;
}
```

## 고생한 점
