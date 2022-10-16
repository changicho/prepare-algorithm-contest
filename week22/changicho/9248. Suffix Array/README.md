# 9248. Suffix Array

[링크](https://www.acmicpc.net/problem/9248)

|    난이도    | 정답률(\_%) |
| :----------: | :---------: |
| 플래티넘 III |     39      |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자. N은 최대 50만까지이다. (500,000)

완전 탐색으로 suffix array를 구하고 정렬할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

suffix array를 구하기 위해 맨버-마이어스 알고리즘을 이용한다.

이 경우 분할 정복에 O(log_2(N))의 시간 복잡도를 사용하며, 내부적으로 정렬을 수행한다.

일반 정렬을 이용할 경우 O(N \* log_2^2(N))의 시간 복잡도를 사용한다.

카운팅 정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

LCP array를 구하기 위해 카사이 알고리즘을 사용한다. 이 경우 O(N)의 시간 복잡도로 구할 수 있다.

따라서 최종 시간 복잡도는 O(N \* log_2^2(N)) 이다.

### 공간 복잡도

맨버 마이어스 알고리즘과 카사이 알고리즘을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### Manber-Myers & Kasai

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     556      |       64       |

[Suffix Array and LCP Array](https://www.secmem.org/blog/2021/07/18/suffix-array-and-lcp/)

```cpp
// use Manber Myers algorithm by STL sort
// time : O(N * log_2^2(N))
// space : O(N)
vector<int> getSuffixArray(string &s) {
  int size = s.size();
  vector<int> suffixArray(size), rank(size + 1);

  for (int i = 0; i < size; ++i) {
    suffixArray[i] = i, rank[i] = s[i];
  }

  for (int d = 1; d < size; d *= 2) {
    auto compare = [&](const int &a, const int &b) {
      return rank[a] < rank[b] ||
             (rank[a] == rank[b] && rank[a + d] < rank[b + d]);
    };
    sort(suffixArray.begin(), suffixArray.end(), compare);

    vector<int> newRank(size + 1, 0);
    newRank[suffixArray[0]] = 1;
    for (int i = 1; i < size; i++) {
      newRank[suffixArray[i]] = newRank[suffixArray[i - 1]];

      if (compare(suffixArray[i - 1], suffixArray[i])) {
        newRank[suffixArray[i]]++;
      }
    }
    rank = newRank;
  }
  return suffixArray;
}

// use Manber Myers algorithm by counting sort
// time : O(N * log_2(N))
// space : O(N)
vector<int> getSuffixArrayByCount(string &s) {
  int size = s.size();
  int maximum = max(256, size) + 1;

  vector<int> suffixArray(size), rank(size + size);
  vector<int> count(maximum), idx(size);
  // initialize
  for (int i = 0; i < size; ++i) {
    suffixArray[i] = i, rank[i] = s[i];
  }
  for (int d = 1; d < size; d *= 2) {
    vector<int> newRank(size + size);
    auto compare = [&](const int &a, const int &b) {
      return rank[a] < rank[b] ||
             (rank[a] == rank[b] && rank[a + d] < rank[b + d]);
    };

    for (int i = 0; i < maximum; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[rank[i + d]]++;
    for (int i = 1; i < maximum; ++i) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; --i) idx[--count[rank[i + d]]] = i;

    for (int i = 0; i < maximum; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[rank[i]]++;
    for (int i = 1; i < maximum; ++i) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; --i)
      suffixArray[--count[rank[idx[i]]]] = idx[i];

    newRank[suffixArray[0]] = 1;
    for (int i = 1; i < size; i++) {
      newRank[suffixArray[i]] = newRank[suffixArray[i - 1]];

      if (compare(suffixArray[i - 1], suffixArray[i])) {
        newRank[suffixArray[i]]++;
      }
    }
    rank = newRank;

    // reduce running time
    if (rank[suffixArray[size - 1]] == size) break;
  }
  return suffixArray;
}

// use Kasai algorithm
// time : O(N)
// space : O(N)
vector<int> getLCP(string &s, vector<int> &suffixArray) {
  int size = s.size();
  vector<int> LCPArray(size), idxOfSuffixArray(size);
  for (int i = 0; i < size; i++) {
    idxOfSuffixArray[suffixArray[i]] = i;
  }
  for (int k = 0, i = 0; i < size; ++i) {
    if (idxOfSuffixArray[i] > 0) {
      int j = suffixArray[idxOfSuffixArray[i] - 1];
      while (s[i + k] == s[j + k]) {
        k++;
      }

      LCPArray[idxOfSuffixArray[i]] = (k ? k-- : 0);
    }
  }
  LCPArray[0] = -1;

  return LCPArray;
}
```

## 고생한 점
