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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> sums;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      long long curSum = 0;

      int size = q.size();
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        curSum += cur->val;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      sums.push_back(curSum);
    }

    sort(sums.begin(), sums.end(), greater<long long>());

    if (sums.size() < k) {
      return -1;
    }

    return sums[k - 1];
  }
};