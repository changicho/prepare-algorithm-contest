#include <algorithm>
#include <climits>
#include <cmath>
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

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumScore(string s, string t) {
    int sLength = s.size(), tLength = t.size();
    int right = tLength - 1;

    vector<int> matches(tLength, -1);

    for (int i = sLength - 1; i >= 0 && right >= 0; --i) {
      if (s[i] == t[right]) {
        matches[right] = i;
        right--;
      }
    }

    int answer = right + 1;
    for (int i = 0, j = 0; i < sLength && j < tLength && answer > 0; ++i) {
      if (s[i] == t[j]) {
        while (right < tLength && matches[right] <= i) {
          right++;
        }

        j++;
        answer = min(answer, right - j);
      }
    }

    return answer;
  }
};