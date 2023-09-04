# 2503. 숫자 야구

[링크](https://www.acmicpc.net/problem/2503)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| 실버 III |   46.803    |       1       |

## 설계

### 시간 복잡도

입력받은 추정들의 크기를 N이라 하자.

각 추정들에 대해서 가능한 모든 숫자를 대입해보며, 정답이 가능한 경우를 판단해 볼 수 있다.

이 경우 가능한 숫자의 조합은 1000개 이하이다.

따라서 하나의 추정에 대해 모든 수를 검사하는 데 O(1)의 시간 복잡도를 사용한다.

이를 모든 추정에 대해 반복할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 추정들을 저장하는 데 O(N)의 공간 복잡도를 사용한다.

## 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 숫자는 한번만 나타날 수 있다. 또한 1 ~ 9까지의 숫자만 사용한다.

가능한 세 자리 숫자를 모두 생성하며, 주어진 추정들에 대입해본다.

```cpp
bool hasZero(string &number) {
  for (char &c : number) {
    if (c == '0') return true;
  }
  return false;
}

bool isDuplicated(string &number) {
  return number[0] == number[1] || number[1] == number[2] || number[0] == number[2];
}

int answer = 0;
for (int number = 111; number <= 999; number++) {
  string target = to_string(number);
  if (hasZero(target)) continue;
  if (isDuplicated(target)) continue;

  bool allPass = true;
  for (Expect &expect : expects) {
    int ball = 0, strike = 0;

    int counts[10] = {
        0,
    };
    for (char &c : target) {
      counts[c - '0']++;
    }
    for (int i = 0; i < 3; i++) {
      if (expect.number[i] == target[i]) {
        strike++;
        counts[expect.number[i] - '0']--;
      } else if (counts[expect.number[i] - '0'] > 0) {
        ball++;
        counts[expect.number[i] - '0']--;
      }
    }

    if (ball != expect.ball || strike != expect.strike) {
      allPass = false;
    }
  }

  if (allPass) {
    answer++;
  }
}
```

## 고생한 점
