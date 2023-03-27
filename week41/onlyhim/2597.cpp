#include <vector>
using namespace std;

int ans, k;

void dfs(vector<int>& v, int idx, int mask) {
	if (idx == v.size()) {
		ans++;
		return;
	}
	bool isValid = 1;
	for (int i = 0; i < idx && isValid; i++) {
		if (mask & (1 << i)) {
			if (abs(v[i] - v[idx]) == k) isValid = 0;
		}
	}
	if (isValid)	dfs(v, idx + 1, mask | (1 << idx));
	dfs(v, idx + 1, mask);
}

class Solution {
public:
	int beautifulSubsets(vector<int>& nums, int K) {
		k = K;
		ans = 0;
		dfs(nums, 0, 0);
		return ans - 1;
	}
};
