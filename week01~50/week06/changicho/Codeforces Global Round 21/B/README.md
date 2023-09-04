# B. NIT Destroys the Universe

[링크](https://codeforces.com/contest/1696/problem/B)

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자.

모든 수를 0으로 만들어야 하며, 우리가 연산을 수행해 변경해야 하는 경우는 다음 2가지이다.

- 0 X 0
- 0 X 0 X 0

한번 순회를 통해 위 두가지 경우에 대해서 탐색하고, 각 경우마다 최소 횟수를 반환한다.

이 경우 순회에 시간 복잡도는 O(N)이 소요된다.

### 공간 복잡도

변환해야 하는 구간 탐색에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

변경해야 하는 경우는 다음 2가지 이다.

- 0 X 0
- 0 X 0 X 0

여기서 첫번째 경우는 X부분에 operation을 수행하면 0으로 변경할 수 있다.

두 번째 경우는 X ~ X까지 operation을 수행하면 모두 X`인 구간으로 변경 가능하고, 이는 첫번째 경우처럼 한번 더 수행할 경우 0이 된다.

이를 구현하면 다음과 같다.

```cpp
int solution(int n, vector<int>& arr) {
  int left = 0, right = n - 1;
  while (left < n && arr[left] == 0) {
    left++;
  }
  while (right >= 0 && arr[right] == 0) {
    right--;
  }

  if (left == n) return 0;

  int answer = 1;
  bool flag = false;
  for (int i = left; i <= right; i++) {
    if (arr[i] == 0) flag = true;
  }

  if (flag) answer++;

  return answer;
}
```

## 고생한 점
