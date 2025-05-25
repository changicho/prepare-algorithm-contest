# B. Down with Brackets

[링크](https://codeforces.com/contest/2110/problem/B)

| 난이도 |
| :----: |
|  750   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

왼쪽부터 순회하며 여는 괄호와 닫는 괄호의 차이를 저장한다. 이 순회에 O(N) 시간이 걸린다.

### 공간 복잡도

갯수를 세는데 O(1) 공간이 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

괄호 쌍 중 어느곳에서나 닫는,여는 괄호 한개씩을 제거할 수 있다.

괄호의 여는 괄호와 닫는 괄호의 수가 같아지는 지점이 끝 지점이 아닌 경우가 존재할 경우, 해당 지점을 기준으로 괄호를 제거하면 불완전한 괄호 쌍을 만들 수 있다.

```cpp
bool solution(string &s) {
  int size = s.size();
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '(') {
      count++;
    } else if (s[i] == ')') {
      count--;
    }

    if (count == 0 && i != size - 1) {
      return true;
    }
  }

  return false;
}
```

## 고생한 점
