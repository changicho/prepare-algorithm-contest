# Wildcard

[링크](https://www.algospot.com/judge/problem/read/WILDCARD)

| 정답률 |
| :----: |
|  32%   |

## 설계

### 시간 복잡도

패턴의 길이를 L, 입력받은 단어의 수를 N, 각 단어의 평균 길이를 M이라 하자.

각 단어들을 순회하며 패턴에 일치하는지 확인해야 한다. 이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

각 패턴과 단어마다 일치하는 지 판단하는데 완전 탐색을 수행할 경우 O(2^M)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 풀이할 경우 O(L \* M)의 시간 복잡도로 단어가 패턴에 매칭되는지 확인할 수 있다.

이 경우 충 시간 복잡도는 O(N \* L \* M)이 된다.

### 공간 복잡도

각 경우마다 동적 계획법을 사용하는 데 O(L \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     12ms     | O(N \* L \* M) |  O(L \* M)  |

```cpp
bool recursive(int pI, int wI, vector<vector<int>> &dp, string &word,
               string &pattern) {
  if (dp[pI][wI] != -1) return dp[pI][wI];

  if (wI < word.size() && pI < pattern.size() &&
      (pattern[pI] == '?' || pattern[pI] == word[wI])) {
    return dp[pI][wI] = recursive(pI + 1, wI + 1, dp, word, pattern);
  }

  if (pI == pattern.size()) {
    return dp[pI][wI] = wI == word.size();
  }

  if (pattern[pI] == '*') {
    if (recursive(pI + 1, wI, dp, word, pattern) ||
        (wI < word.size() && recursive(pI, wI + 1, dp, word, pattern))) {
      return dp[pI][wI] = 1;
    }
  }
  return dp[pI][wI] = 0;
}

bool isMatch(string word, string pattern) {
  vector<vector<int>> dp(101, vector<int>(101, -1));

  recursive(0, 0, dp, word, pattern);
  return dp[pattern.size()][word.size()] == 1;
}

vector<string> solution(string &pattern, vector<string> &words) {
  vector<string> answer;

  for (string &word : words) {
    if (isMatch(word, pattern)) {
      answer.push_back(word);
    }
  }
  sort(answer.begin(), answer.end());

  return answer;
}
```

## 고생한 점
