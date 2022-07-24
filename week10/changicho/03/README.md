# Touchbar Typing (8pts, 12pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caea6/0000000000b76f44)

## 설계

### 시간 복잡도

(마지막 테스트 케이스 TLE)

동적 계획법을 이용해 이전에 방문한 경우 및 백트래킹을 수행할 수 있다.

이 경우 N개의 문자열을 선택해야 하므로 가장 외부에 O(N)의 시간 복잡도를 사용한다.

내부적으로 dp값을 갱신하는 데 O(M^2)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* M^2)이다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

각 index들을 미리 분류하고 저장하는 데 O(M)의 공간 복잡도를 사용한다.

### 동적 계획법 (TLE)

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
| O(N \* M^2) |  O(N \* M)  |

각 글자에 대해서 index들을 모아놓는다.

이후 다음과 같은 dp값을 선언한다.

```cpp
// definition
long long dp[i][cursor]; // i번째 글자를 완성하고, 현재 커서의 위치가 cursor일때의 최소값
```

이 경우 현재 커서에 대해서 dp값을 갱신할 경우 다음과 같이 갱신할 수 있다.

```cpp
// 현재 갱신할 cursor
for (int& cursor : indexes[s[index]]) {
  // 이전 문자에 대한 cursor
  for (int& beforeCursor : indexes[s[index - 1]]) {
    long long nextCost = dp[index - 1][beforeCursor] + abs(beforeCursor - cursor);

    dp[index][cursor] = min(dp[index][cursor], nextCost);
  }
}
```

이를 모든 index에 대해서 구하고 (N까지) 마지막에 정답을 갱신한다.

```cpp
long long solution(int n, int m, vector<int>& s, vector<int>& k) {
  unordered_map<int, vector<int>> indexes;
  for (int i = 0; i < m; i++) {
    int idx = k[i];
    indexes[idx].push_back(i);
  }

  vector<vector<long long>> dp(n, vector<long long>(m, -1));
  for (int& i : indexes[s[0]]) {
    dp[0][i] = 0;
  }
  for (int index = 1; index < n; index++) {
    for (int& nextCursor : indexes[s[index]]) {
      for (int& cursor : indexes[s[index - 1]]) {
        long long nextCost = dp[index - 1][cursor] + abs(cursor - nextCursor);
        if (dp[index][nextCursor] == -1) {
          dp[index][nextCursor] = nextCost;
        } else {
          dp[index][nextCursor] = min(dp[index][nextCursor], nextCost);
        }
      }
    }
  }

  long long answer = n * m;
  for (long long val : dp[n - 1]) {
    if (val == -1) continue;
    answer = min(answer, val);
  }
  return answer;
}
```

## 고생한 점
