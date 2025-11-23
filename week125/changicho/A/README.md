# A - Happy Birthday! 4

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 세 수를 X, Y, Z라 하자.

방정식을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

방정식에 O(1)의 공간 복잡도를 사용한다.

### 방정식

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

수식을 변화시킬 경우 다음과 같다.

```cpp
x + a == z * (y + a)
x + a == z * y + z * a
x - z * y = (z - 1) * a
(x - z * y) / (z - 1) = a
```

따라서 a가 자연수이기 위해서 다음 두 조건을 만족해야 한다.

- 분모가 0 이상이어야 한다.
- 분모가 분자로 나누어떨어져야 한다.

이를 이용해 판별한다.

```cpp
bool solution(int x, int y, int z) {
  // x + a == z * y + z * a
  // x - z * y = (z - 1) * a

  int parent = x - z * y;
  int child = z - 1;

  if (parent < 0) return false;
  return parent % child == 0;
}
```

## 고생한 점
