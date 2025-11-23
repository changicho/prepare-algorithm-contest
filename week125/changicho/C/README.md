# C - 1122 Substring 2

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

각 index별로 현재값과 같은값이 왼쪽, 오른쪽에 몇개 있는지 구하는데 투 포인터를 사용해 O(N)의 시간 복잡도를 사용한다.

이후 해당 값을 이용해 조건을 만족하는 부분 문자열의 개수를 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 index별로 연속된 방향의 같은 수를 관리하는 데 O(N)의 공간 복잡도를 사용한다.

### 투 포인터 (연속된 수)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |    O(N)     |    O(N)     |

각 index별로 왼쪽, 오른쪽 방향으로 현재 자신과 연속된 같은 수의 갯수를 구한다.

이를 투 포인터를 이용해 O(N)의 시간 복잡도로 구한다.

이후 각 index i에 대해 `s[i] + 1 == s[i + 1]`인 경우에 대해 왼쪽부분과 오른쪽 부분의 연속된 수를 각각 구한다.

이 두 값들 중 작은 값이 조건을 만족하므로 이 길이를 정답에 더해준다.

```cpp
long long solution(string& s) {
  int size = s.size();

  vector<int> l2rLength(size, 0);
  vector<int> r2lLength(size, 0);

  int left = 0, right = 0;
  for (; right <= size; right++) {
    if (s[left] == s[right]) {
      continue;
    }

    while (left < right) {
      l2rLength[left] = right - left;
      left++;
    }
  }

  while (left < size) {
    l2rLength[left] = size - left;
    left++;
  }

  left = size - 1, right = size - 1;
  for (; left >= 0; left--) {
    if (s[left] == s[right]) {
      continue;
    }

    while (right > left) {
      r2lLength[right] = right - left;
      right--;
    }
  }
  while (right > left) {
    r2lLength[right] = right - left;
    right--;
  }

  long long answer = 0;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] + 1 != s[i + 1]) continue;

    int leftLen = r2lLength[i];
    int rightLen = l2rLength[i + 1];

    answer += min(leftLen, rightLen);
  }

  return answer;
}
```

## 고생한 점
