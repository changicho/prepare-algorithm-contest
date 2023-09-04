# 합친 LIS

[링크](https://algospot.com/judge/problem/read/JLIS)

| 정답률 |
| :----: |
|  24%   |

## 설계

### 시간 복잡도

입력받은 배열 A, B의 크기를 각각 N, M이라 하자.

모든 경우를 탐색해 정답을 구할 경우 O(2^(N + M))의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전의 계산 결과를 재사용한다.

이 경우 방문하는 총 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|    308ms     |  O(N \* M)  |  O(N \* M)  |

```cpp
int jLIS(int idx1, int idx2, vector<int> &first, vector<int> &second,
         vector<vector<int>> &dp) {
  if (dp[idx1 + 1][idx2 + 1] != -1) return dp[idx1 + 1][idx2 + 1];

  long long a = (idx1 == -1 ? INT_MIN : first[idx1]);
  long long b = (idx2 == -1 ? INT_MIN : second[idx2]);

  long long maximum = max(a, b);

  int ret = 0;
  for (int next1 = idx1 + 1; next1 < first.size(); next1++) {
    if (maximum < first[next1]) {
      ret = max(ret, jLIS(next1, idx2, first, second, dp) + 1);
    }
  }
  for (int next2 = idx2 + 1; next2 < second.size(); next2++) {
    if (maximum < second[next2]) {
      ret = max(ret, jLIS(idx1, next2, first, second, dp) + 1);
    }
  }
  return dp[idx1 + 1][idx2 + 1] = ret;
}

int solution(vector<int> &first, vector<int> &second) {
  vector<vector<int>> dp(102, vector<int>(102, -1));

  return jLIS(-1, -1, first, second, dp);
}
```

## 고생한 점
