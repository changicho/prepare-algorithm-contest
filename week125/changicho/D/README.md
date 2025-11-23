# D - 183183

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 숫자의 모든 쌍을 순회하는데 O(N^2)의 시간 복잡도를 사용한다.

각 숫자들에 대해서 각 자리수마다 나머지를 구하는 데 O(10)의 시간 복잡도를 사용한다.

이를 hash map에 나머지에 대해 저장하는 경우 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

각 자리수마다 나머지에 대해 hash map을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 나머지 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1122     |   O(N^2)    |    O(N)     |

다음 임의의 숫자가 있다고 하자.

- A = abc
- B = de

이 경우 abcde 가 m으로 나누어 떨어지기 위한 조건은 다음과 같다.

- abc00 % m == (m - (de % m)) % m

즉 앞에 존재하는 숫자에 10의 자리수를 곱한 나머지가 뒤에 존재하는 숫자의 나머지의 합이 m이 되어야 m으로 나누어 떨어진다. (두 수의 나머지의 합이 m으로 떨어져야 한다)

각 숫자들에 대해서 각 자리수마다 추가된 10의 자리수와 나머지에 대해 hash map에 카운트한다.

이후 각 숫자들을 다시 순회하며, 해당 숫자가 뒤에 붙는 경우에 대해서 가능한 경우의 수를 정답에 추가한다.

```cpp
long long solution(int size, long long m, vector<long long>& nums) {
  vector<unordered_map<long long, int>> digitCount(12);

  for (unsigned long long num : nums) {
    for (int count = 0; count <= 11; count++) {
      digitCount[count][num % m]++;

      num *= 10ULL;
    }
  }

  long long answer = 0;
  for (long long num : nums) {
    int length = log10(num) + 1;

    long long target = (m - (num % m)) % m;
    answer += digitCount[length][target];
  }

  return answer;
}
```

## 고생한 점
