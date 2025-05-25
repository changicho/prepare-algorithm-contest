# C. Racing

[링크](https://codeforces.com/contest/2110/problem/C)

| 난이도 |
| :----: |
|  1500  |

## 설계

### 시간 복잡도

두 배열의 길이를 N이라 하자.

각 경우마다 탐욕 알고리즘을 사용해 드론의 위치를 조정할 수 있다.

이 경우 O(N) 시간 복잡도로 문제를 해결할 수 있다.

### 공간 복잡도

정답 배열을 별도로 생성할 경우 O(N) 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     155      |    O(N)     |    O(N)     |

드론의 명령 배열에서 -1로 빈 공간을 활용할 수 있다.

만약 현재 드론의 위치가 목표 위치보다 작다면 현재까지 순회한 -1을 1로 바꿔 드론을 띄울 수 있다.

만약 현재 드론의 위치에 빈 공간을 모두 1로 채웠을 때 목표 위치보다 커질 수 있는 경우 해당 -1을 0으로 바꿔 드론의 위치가 목표 위치보다 커지지 않도록 조정할 수 있다.

```cpp
vector<int> solution(int size, vector<int> &diff, vector<pair<int, int>> &height) {
  int cur = 0;
  stack<int> stk;
  for (int i = 0; i < size; i++) {
    int left = height[i].first;
    int right = height[i].second;

    if (diff[i] == -1) {
      stk.push(i);
    } else {
      cur += diff[i];
    }

    while (cur < left) {
      if (stk.empty()) {
        return {-1};
      }

      int idx = stk.top();
      stk.pop();
      diff[idx] = +1;
      cur += 1;
    }

    while (cur + stk.size() > right) {
      if (stk.empty()) {
        return {-1};
      }

      int idx = stk.top();
      stk.pop();
      diff[idx] = 0;
    }
  }

  for (int &d : diff) {
    if (d == -1) d = 0;
  }

  return diff;
}
```

## 고생한 점
