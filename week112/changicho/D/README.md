# D - Match, Mod, Minimize 2

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

두 바열의 크기를 N이라 하자.

그리디 알고리즘을 이용해 가장 유리한 값을 선택하는 방식으로 진행한다.

이 때 정렬, multiset을 사용해 이분 탐색을 사용할 경우 O(N \* log_2(N))으로 해결할 수 있다.

### 공간 복잡도

정렬과 multiset을 사용하는데 O(N) 공간 복잡도가 필요하다.

### 정렬 & multiset

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     256      | O(N \* log_2(N)) |    O(N)     |

a의 배열의 원소들을 hash map에 count한 뒤, b를 순회하며 더해서 m으로 나누어 떨어지는 쌍들을 미리 제거한다.

이후 남은 쌍들을 정렬한 뒤 아래와 같은 방식으로 진행한다.

- 현재 배열 b의 원소를 B라 하자.
- 배열 a에서 특정 원소를 B와 더했을 때 m을 초과하는 가장 작은 원소 A를 찾는다.
- 만약 없는 경우 그냥 가장 작은 원소를 선택한다.

이는 m으로 나누어지는 쌍을 만들 수 없는 경우 더했을 때 m을 초과해 값을 최대한 사라지게 만들어야 하기 때문이다.

```cpp
long long solution(int n, int m, vector<int> &a, vector<int> &b) {
  long long answer = 0;

  unordered_map<int, int> count;
  vector<int> remains;
  for (int &num : a) {
    num %= m;
    count[num]++;
  }

  // greedy one pass
  for (int &num : b) {
    num %= m;

    int target = (m - num + m) % m;

    if (count[target] > 0) {
      count[target]--;
      if (count[target] == 0) {
        count.erase(target);
      }
    } else {
      remains.push_back(num);
    }
  }

  multiset<int> remainsB;
  for (auto [num, cnt] : count) {
    for (int i = 0; i < cnt; i++) {
      remainsB.insert(num);
    }
  }

  sort(remains.begin(), remains.end(), greater<int>());

  int size = remains.size();
  for (int i = 0; i < size; i++) {
    // remains[i] + remainsB[i] > m;
    // smallest remainsB[i];
    long long target = ((remains[i] - m) % m) * -1;

    auto it = remainsB.lower_bound(target);
    if (it == remainsB.end()) {
      it = remainsB.begin();
    }

    answer += (remains[i] + *it) % m;
    remainsB.erase(it);
  }

  return answer;
}
```

## 고생한 점
