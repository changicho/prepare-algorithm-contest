# Problem A: Leapfrog: Ch. 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2019/qualification-round/problems/A)

## 시간 복잡도

입력받은 문자열의 길이를 N이라고 하자.

모든 경우를 탐색할 경우 O(N!)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

주어진 입력값에서 빈공간과 beta개구리의 수를 세 문제를 풀이할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

## 공간 복잡도

개구리와 빈 공간의 수를 세서 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

## 풀이

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

빈 공간이 0개인 경우 맨 왼쪽에서 맨 오른쪽까지 도달 불가능한 것은 당연하다.

따라서 빈 공간이 0개인 경우는 불가능하다.

빈 공간의 갯수와 베타 개구리의 수를 각각 A, B라고 하자.

만약 B가 A 이상이면 맨 왼쪽에서 맨 오른쪽까지 도달 가능하다.

```cpp
bool leapfrog(string &line) {
  int size = line.size();

  int countB = count(line.begin(), line.end(), 'B');
  int countPoint = count(line.begin(), line.end(), '.');

  return countB >= countPoint && countPoint > 0;
}
```
