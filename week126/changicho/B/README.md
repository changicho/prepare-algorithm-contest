# B - Bird Watching

[링크](https://atcoder.jp/contests/abc434/tasks/abc434_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열 A, B의 크기를 N, 타입의 종류를 M이라 하자.

각 값을 타입별로 평균을 구하는데 순회하므로 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 타입별로 무게를 저장하는데 O(N + M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(N + M)   |  O(N + M)   |

```cpp
vector<double> solution(int n, int m, vector<int>& a, vector<int>& b) {
  vector<double> answer(m);

  vector<vector<double>> weights(m + 1);
  for (int i = 0; i < n; i++) {
    weights[a[i]].push_back(b[i]);
  }

  for (int i = 1; i <= m; i++) {
    double sum = accumulate(weights[i].begin(), weights[i].end(), 0.0);
    answer[i - 1] = sum / weights[i].size();
  }

  return answer;
}
```

## 고생한 점
