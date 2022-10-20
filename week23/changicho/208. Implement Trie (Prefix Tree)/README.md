# 208. Implement Trie (Prefix Tree)

[링크](https://leetcode.com/problems/implement-trie-prefix-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

### 공간 복잡도

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
