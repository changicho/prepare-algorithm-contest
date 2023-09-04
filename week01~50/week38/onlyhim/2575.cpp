#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> divisibilityArray(string word, int m) {
		int n = word.size(), idx = 0;
		vector<int> ans(n, 0);
		long long val = word[idx] -'0';
		for (; idx < n; idx++) {
			if (val >= m) {
				if (val % m == 0)	ans[idx] = 1;
				val %= m;
			}
			else {
				val = (val * 10) + (word[idx] - '0');
			}
		}
		return ans;
	}
};
