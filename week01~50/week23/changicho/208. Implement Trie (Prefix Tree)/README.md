# 208. Implement Trie (Prefix Tree)

[링크](https://leetcode.com/problems/implement-trie-prefix-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력되는 문자열의 갯수를 N, 길이를 L이라 하자.

문자열을 트라이에 저장할 때마다 각 문자들을 순차적으로 트라이 노드로 생성하고 방문하므로 O(L)의 시간 복잡도를 사용한다.

문자열을 트라이에서 검색할 경우 동일하게 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

트라이의 경우 (알파벳의 수)^(길이) 만큼의 공간 복잡도를 사용한다.

주어진 알파벳의 종류는 26이므로 26^L의 공간 복잡도를 사용한다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     156      |  O(N \* L)  |   O(26^L)   |

```cpp
class Trie {
 private:
  struct TrieNode {
    TrieNode* children[26] = {
        NULL,
    };
    bool isEnd = false;
  };

  TrieNode* root = new TrieNode;

 public:
  Trie() {}

  void insert(string word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'a'] == NULL) {
        cur->children[c - 'a'] = new TrieNode;
      }
      cur = cur->children[c - 'a'];
    }

    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'a'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'a'];
    }

    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* cur = root;

    for (char& c : prefix) {
      if (cur->children[c - 'a'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'a'];
    }
    return true;
  }
};
```

## 고생한 점
