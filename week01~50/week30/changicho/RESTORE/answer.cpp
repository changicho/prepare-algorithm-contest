#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 15;
int restore(int last, int used, int size, int cache[15][(1 << 15) + 1],
            int overlap[16][16]) {
  if (used == (1 << size) - 1) return 0;

  int& result = cache[last][used];

  if (result != -1) return result;

  result = 0;

  for (int next = 0; next < size; next++) {
    if ((used & (1 << next)) == 0) {
      int candidate = overlap[last][next] +
                      restore(next, used + (1 << next), size, cache, overlap);

      result = max(result, candidate);
    }
  }

  return result;
}

string reconstruct(int last, int used, vector<string>& words,
                   int cache[15][(1 << 15) + 1], int overlap[16][16]) {
  int size = words.size();
  if (used == (1 << size) - 1) return "";

  for (int next = 0; next < size; next++) {
    if (used & (1 << next)) continue;

    int ifUsed = restore(next, used + (1 << next), size, cache, overlap) +
                 overlap[last][next];
    if (restore(last, used, size, cache, overlap) == ifUsed) {
      return (words[next].substr(overlap[last][next]) +
              reconstruct(next, used + (1 << next), words, cache, overlap));
    }
  }

  return "";
}

int getOverlap(const string& a, const string& b) {
  for (int length = min(a.size(), b.size()); length > 0; length--)
    if (a.substr(a.size() - length) == b.substr(0, length)) return length;

  return 0;
}

string solution(int size, vector<string>& words) {
  int cache[15][(1 << 15) + 1];
  int overlap[16][16] = {
      0,
  };

  memset(cache, -1, sizeof(cache));

  while (true) {
    bool removed = false;

    for (int from = 0; from < size && !removed; from++) {
      for (int to = 0; to < size; to++) {
        if (from != to && words[from].find(words[to]) != -1) {
          words[to] = words[size - 1];
          size--;
          removed = true;
        }
      }
    }

    if (!removed) break;
  }

  words.resize(size + 1);
  words[size] = "";

  for (int from = 0; from <= size; from++) {
    for (int to = 0; to <= size; to++) {
      overlap[from][to] = getOverlap(words[from], words[to]);
    }
  }

  string answer = reconstruct(size, 0, words, cache, overlap);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int K;
    cin >> K;

    vector<string> words(K);

    for (int i = 0; i < K; i++) {
      cin >> words[i];
    }

    auto answer = solution(K, words);
    cout << answer;
    cout << "\n";
  }

  return 0;
}
