# B - Nearest Taller

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

완전 탐색을 수행할 경우 O(N^2)의 시간 복잡도를 사용한다.

모노토닉 스택을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

각 index별로 자신보다 작은 index중 현재 값보다 큰 값들 중 가장 오른쪽에 있는 index를 찾아야 한다.

이를 위해 감소하는 모노토닉 스택을 사용한다.

현재 값보다 작은 값들이 모노토닉 스택에 존재하는 경우 스택에서 제거한다.

이후 스택이 비어있는 경우 -1을, 비어있지 않은 경우 스택의 최상단 값(index)을 정답에 추가한다.

```cpp
vector<int> solution(int size, const vector<int>& nums) {
  vector<int> answer;

  stack<int> s;
  for (int i = 0; i < size; i++) {
    int target = -1;
    while (!s.empty() && nums[s.top()] <= nums[i]) {
      s.pop();
    }

    if (s.empty()) {
      answer.push_back(-1);
    } else {
      answer.push_back(s.top() + 1);
    }
    s.push(i);
  }

  return answer;
}
```

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |    O(N)     |

```cpp
vector<int> solution(int size, const vector<int>& nums) {
  vector<int> answer;

  for (int i = 0; i < size; i++) {
    int target = -1;
    for (int before = i - 1; before >= 0; before--) {
      if (nums[before] > nums[i]) {
        target = before + 1;
        break;
      }
    }

    answer.push_back(target);
  }

  return answer;
}
```

## 고생한 점
