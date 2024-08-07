# A. Round Down the Price

[링크](https://codeforces.com/contest/1702/problem/A)

| 난이도 |
| :----: |
| \*800  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

N과 N이하의 가장 큰 10의 제곱수만큼의 차를 구하기 위해 math 함수를 이용한다.

이 경우 시간 복잡도는 O(log_10(N))이다.

### 공간 복잡도

차이를 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      15      | O(log_10(N)) |    O(1)     |

M에 대해서 log10한 결과의 정수값만을 이용하고, 이 수만큼 10을 제곱한 수에서 뺀다.

```cpp
int solution(int m) {
  int logVal = log10(m);
  return m - pow(10, logVal);
}
```

## 고생한 점
