# 2767. Partition String Into Minimum Beautiful Substrings

[링크](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 글자마다 cut하는 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 완전 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(2^N)    |    O(N)     |

각 index에 대해서 cut하는 경우와 cut하지 않는 경우를 모두 탐색한다.

이 때 현재까지 넘어온 부분 문자열이 유효한지 판별해야 한다.

이후 index의 끝에 도달한 경우 정답을 갱신한다.

이 때 정답은 s를 나눈 문자들의 최소 개수이다.

```cpp
int answer = INT_MAX;
string s;
int size;

int convert(string s) {
  int num = 0;
  reverse(s.begin(), s.end());
  int digit = 1;
  for (char &c : s) {
    if (c == '1') {
      num += digit;
    }
    digit *= 2;
  }
  return num;
}

bool checkFivePow(int num) {
  while (num > 1) {
    if (num % 5 != 0) return false;
    num /= 5;
  }
  return true;
}

bool isValid(string s) {
  if (s[0] == '0') return false;
  int num = convert(s);

  return checkFivePow(num);
}

void recursive(int index, int count, string cur) {
  if (index == size) {
    if (cur == "") {
      answer = min(answer, count);
    }
    return;
  }

  cur += s[index];

  if (cur[0] == '0') return;
  // cut case
  if (isValid(cur)) {
    recursive(index + 1, count + 1, "");
  }

  // not cut case
  recursive(index + 1, count, cur);
}

int minimumBeautifulSubstrings(string s) {
  this->s = s;
  this->size = s.size();

  recursive(0, 0, "");

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
