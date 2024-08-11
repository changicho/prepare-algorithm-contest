int k, ans;

void go(vector<int>& v, vector<vector<int>>& students, int n) {
    if (v.size() == k) {
        int curTime = 0;
        priority_queue<int, vector<int>, greater<int>> pq[6];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < v[i]; j++) {
                pq[i+1].push(0);
            }
        }
        for (int i = 0; i < students.size(); i++) {
            int arriveTime = students[i][0], talkTime = students[i][1], type = students[i][2];
            int curMento = pq[type].top();
            int waitTime = arriveTime < curMento ? curMento - arriveTime : 0;
            pq[type].pop();
            pq[type].push(arriveTime + talkTime + waitTime);
            curTime += waitTime;
        }
        ans = min(ans, curTime);
        return;
    }
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        go(v, students, n - i);
        v.pop_back();
    }
}

int solution(int kk, int n, vector<vector<int>> reqs) {
    ans = 1e9;
    k = kk;
    vector<int> v;
    go(v, reqs, n);
    return ans;
}
