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

class Solution {
 public:
  int passThePillow(int n, int time) {
    bool isLeft = true;
    int index = 0;
    while (time--) {
      if (isLeft) {
        index++;
      } else {
        index--;
      }

      if (index == 0 || index == (n - 1)) {
        isLeft = !isLeft;
      }
    }
    return index + 1;
  }
};