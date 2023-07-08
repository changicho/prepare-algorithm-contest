#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Song {
  string name;
  int length;
};

string answer = "";
int target = 0;

string compare(string &a, string &b) {
  if (a.size() > b.size()) return a;
  if (a.size() < b.size()) return b;
  return min(a, b);
}

struct TrieNode {
  TrieNode *children[26] = {
      NULL,
  };

  int length = 0;
};

class Trie {
 private:
  TrieNode *root = new TrieNode;

 public:
  void insert(Song &song) {
    TrieNode *node = root;

    string temp = "";
    for (char &c : song.name) {
      temp += c;

      if (!node->children[c - 'a']) {
        node->children[c - 'a'] = new TrieNode();
      }

      node = node->children[c - 'a'];
      node->length += song.length;

      if (node->length == target) {
        answer = compare(answer, temp);
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  target = K;

  Trie trie;

  for (int i = 0; i < N; i++) {
    Song cur;
    cin >> cur.name >> cur.length;

    if (cur.length == target) {
      answer = compare(answer, cur.name);
      continue;
    }

    trie.insert(cur);
  }

  cout << answer.size() << " " << answer << endl;
  return 0;
}