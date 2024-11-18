int solution(vector<int> diffs, vector<int> times, long long limit) {
	int ans = 0;
	int l = 1, r = 300000;
	while (l <= r) {
		int m = (l + r) / 2;
		long long curLimit = 0;

		for (int i = 0; i < diffs.size(); i++) {
			int curDiff = diffs[i], curTimes = times[i];
			if (curDiff <= m)	curLimit += curTimes;
			else {
				int wrongNum = curDiff - m;
				curLimit += wrongNum * (curTimes + (i == 0 ? 0 : times[i - 1])) + curTimes;
			}
		}
		if (curLimit <= limit) {
			ans = min(ans, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

/*
	이분탐색으로 현재 limit이 조건을 만족하는지 확인한다.
*/
