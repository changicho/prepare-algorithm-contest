# C - Flapping Takahashi

[링크](https://atcoder.jp/contests/abc434/tasks/abc434_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

시간의 범위는 10^9까지 이므로 매번 순회할 경우 제한시간 내에 불가능하다.

배열을 순회하며 가능한 범위를 갱신해 나가는 방식으로 접근한다.

이 경우 순회에 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

각 경우마다 범위값만 갱신하므로 O(1)의 공간 복잡도를 가진다.

### 범위 체크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |    O(N)     |    O(1)     |

현재 시간 time에서 접근 가능한 범위를 low, high로 나타내자.

이 경우 다음 goal의 time까지 도달했을 때의 범위는 다음과 같다.

- low = low - (goal.time - before)
- high = high + (goal.time - before)

즉 다음 시간까지 이동할 수 있는 높이는 정해져있으며, 해당 범위값만큼 갱신해주면 된다.

이후 현재 goal에과 도달 가능한 범위가 겹치는 지 확인하며, 겹치지 않는 경우 false를 반환한다.

겹치는 경우 실제 도달가능한 거리와 goal의 범위 중 겹치는 부분으로 low, high를 갱신해준다.

```cpp
struct Goal {
  int time;
  long long low, high;
};

auto solution(int size, int h, vector<Goal>& goals) {
  bool answer = true;

  int before = 0;
  long long low = h;
  long long high = h;

  for (Goal& goal : goals) {
    int timeDiff = goal.time - before;

    low -= timeDiff;
    high += timeDiff;

    bool isOverlap = low <= goal.high && goal.low <= high;

    if (!isOverlap) {
      answer = false;
      break;
    }

    low = max(low, goal.low);
    high = min(high, goal.high);

    before = goal.time;
  }

  return answer;
}
```

## 고생한 점
