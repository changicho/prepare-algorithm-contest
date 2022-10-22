#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */