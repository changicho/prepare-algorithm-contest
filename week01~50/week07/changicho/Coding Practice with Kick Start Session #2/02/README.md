# Sherlock and Parentheses (5pts, 7pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b5496b)

|    난이도    |
| :----------: |
| (5pts, 7pts) |

## 설계

### 시간 복잡도

입력받은 수를 L, R이라 하자.

가장 많은 괄호쌍을 만들 수 있는 경우는 괄호쌍의 반복으로 문자열을 구성하는 것이다. "()()..."

이후 해당 괄호쌍의 갯수 min(L, R)을 X라고 하자. 가능한 경우의 수는 1 ~ X의 합이다.

이를 구하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

1부터 X까지의 합을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 정리

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(1)     |    O(1)     |

L, R을 입력 받을 때 가장 많은 경우의 수를 만들 수 있는 경우는 아래와 같은 형태이다.

"()()()..."

해당 갯수는 min(L, R)개까지 유효한 괄호를 만들 수 있다.

여기서 연속된 괄호의 갯수가 1, 2, 3, ... , X개인 경우의 수는 각각 다음과 같다.

X, (X-1), (X-2), ... , 2, 1

이를 모두 더한것이 정답이 된다.

## 고생한 점