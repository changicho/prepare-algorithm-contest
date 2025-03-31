int solution(vector<int> players, int m, int k) {
    int ans = 0, curServer = 1;
    priority_queue<vector<int>> pq;
    for (int i = 0; i < players.size(); i++) {
        int curUser = players[i];
        while (!pq.empty() && -pq.top()[0] == i) {
            curServer -= pq.top()[1];
            pq.pop();
        }
        int maxUser = curServer * m - 1;

        if (curUser <= maxUser)  continue;
        int needServer = (curUser - maxUser) % m == 0 ? (curUser - maxUser) / m : (curUser - maxUser) / m + 1;
        curServer += needServer;
        pq.push({ -(i + k), needServer });
        ans += needServer;
    }
    return ans;
}

/*
* 매 시간마다 pq를 확인하여 종료되는 서버가 있는지 확인하고, 서버 갯수에 따라 이용가능한 max user를 cur user와 비교한다.
* 
*/
