# 1786. 찾기

[링크](https://www.acmicpc.net/problem/1786)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| 플래티넘 V |     30      |

## 설계

### 시간 복잡도

검색할 문자열 T의 길이를 N, 패턴 문자열 P의 길이를 M이라 하자.

각 문자열의 길이는 100만 이하이다.

따라서 모든 경우를 탐색하는 부르트 포스 방법의 경우 O(N \* M)의 시간 복잡도를 사용하며, 이는 제한시간 내에 불가능하다.

KMP 알고리즘을 이용해 시간복잡도 O(N + M)만에 찾을 수 있다.

### 공간 복잡도

KMP 알고리즘을 이용할 경우 O(N + M)의 공간 복잡도를 사용한다.

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### KMP 알고리즘

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      60      |       40       |

먼저 패턴에서 반복되는 부분에 대한 index 위치를 만든다.

예를 들어 패턴이 다음과 같다고 해보자

"ABCDABD"

이 경우 반복되는 위치를 표로 나타내면 다음과 같다.

|  A  |  B  |  C  |  D  |  A  |  B  |  D  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  0  |  1  |  2  |  0  |

5번째와 6번째에서 5번째는 1번째 패턴의 반복, 6번째는 1~2번까지의 패턴이 반복되는 것을 알 수 있다.

즉 반복되는 패턴의 시작 index를 나타내기 때문에 (접두사를 비교해서 같은경우) 해당 번째 까지는 비교를 더이상 수행하지 않아도 된다.

다음으로 검색할 문자열을 탐색한다.

문자열을 탐색하며 현재 번째 index와 일치할 경우 탐색을 이어나간다.

현재 번째 index와 일치하지 않는 경우, 현재 번째의 패턴 index에서, 이전 패턴 index (반복되는 접두사)가 있으면 그 index부터 비교한다.

만약 패턴이 완료된 경우 정답으로 추가하고, 패턴 index는 접두사가 같은 패턴의 시작점까지 이동한다.

```cpp
int length = line.size(), patternLength = pattern.size();
vector<int> patternIndexArr(patternLength, 0);

// 패턴 인덱스 배열을 만듬
for (int curIdx = 1, patternIdx = 0; curIdx < patternLength; curIdx++) {
  while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
    patternIdx = patternIndexArr[patternIdx - 1];
  }
  if (pattern[curIdx] == pattern[patternIdx]) {
    patternIdx++;
    patternIndexArr[curIdx] = patternIdx;
  }
}

// 문자열을 순회하며 찾는 문자열들을 검색함
for (int lineIdx = 0, patternIdx = 0; lineIdx < length; lineIdx++) {
  while (patternIdx > 0 && line[lineIdx] != pattern[patternIdx]) {
    patternIdx = patternIndexArr[patternIdx - 1];
  }

  if (line[lineIdx] == pattern[patternIdx]) {
    if (patternIdx == patternLength - 1) {
      answer.push_back(lineIdx - patternLength + 1);

      patternIdx = patternIndexArr[patternIdx];
    } else {
      patternIdx++;
    }
  }
}
```

## 고생한 점

pattern에도 공백이 있을 수 있으므로 둘다 getline으로 입력받아야한다.
