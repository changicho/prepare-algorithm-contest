#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode *children[26] = {
      NULL,
  };

  string data;
  string maximum;
  int count;
  int maxCount;

  TrieNode() {
    data = "";
    count = 0;
    maximum = "";
    maxCount = 0;
  }
};

class Trie {
 private:
  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;
    stack<TrieNode *> stk;

    for (char &c : word) {
      stk.push(node);

      if (!node->children[c - 'A']) {
        node->children[c - 'A'] = new TrieNode();
      }

      node = node->children[c - 'A'];
    }
    stk.push(node);

    node->count++;
    if (node->data == "") {
      node->data = word;
      node->maximum = word;
      node->maxCount = node->count;
    } else if (node->count == node->maxCount) {
      node->maximum = min(node->maximum, node->data);
    } else if (node->count > node->maxCount) {
      node->maximum = node->data;
      node->maxCount = node->count;
    }

    while (stk.size() > 0) {
      TrieNode *cur = stk.top();
      stk.pop();

      for (int i = 0; i < 26; i++) {
        TrieNode *child = cur->children[i];
        if (child == NULL) continue;

        if (cur->maxCount == child->maxCount) {
          cur->maximum = min(cur->maximum, child->maximum);
        } else if (cur->maxCount < child->maxCount) {
          cur->maximum = child->maximum;
          cur->maxCount = child->maxCount;
        }
      }
    }
  }

  TrieNode *search(string word) {
    TrieNode *node = root;

    for (char &c : word) {
      if (!node->children[c - 'A']) {
        return NULL;
      }

      node = node->children[c - 'A'];
    }

    return node;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  string word, query;

  Trie *trie = new Trie();

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> word;
    trie->insert(word);
  }

  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> query;

    TrieNode *cur = trie->search(query);

    if (!cur) {
      cout << "0"
           << "\n";
    } else {
      cout << cur->maximum << " " << cur->maxCount << "\n";
    }
  }

  cout << endl;
  return 0;
}