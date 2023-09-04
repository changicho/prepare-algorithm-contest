class Solution {
public:
	vector<long long> minOperations(vector<int>& v, vector<int>& q) {
		sort(v.begin(), v.end());
		vector<long long> psum(1, 0);
		for (int i = 0; i < v.size(); i++) {
			psum.push_back(v[i] + psum.back());
		}
		vector<long long> ans(q.size());
		for (int i = 0; i < q.size(); i++) {
			int idx = upper_bound(v.begin(), v.end(), q[i]) - v.begin();
			ans[i] = (1LL * q[i] * idx - psum[idx]) +
				(1LL * psum.back() - psum[idx] - q[i] * (v.size() - idx));
		}
		return ans;
	}
};
