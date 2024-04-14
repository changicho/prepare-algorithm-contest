class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& qqq, vector<int>& disappear) {
        vector<int> ans(n, 1e9);
        priority_queue<vector<int>> pq;
        vector<map<int, int>> edge(n);
        for (int i = 0; i < qqq.size(); i++) {
            int vert1 = qqq[i][0], vert2 = qqq[i][1], val = qqq[i][2];            
            if (edge[vert1].find(vert2) == edge[vert1].end())   edge[vert1][vert2] = val;
            else edge[vert1][vert2] = min(edge[vert1][vert2], val);
            if (edge[vert2].find(vert1) == edge[vert2].end())   edge[vert2][vert1] = val;
            else edge[vert2][vert1] = min(edge[vert2][vert1], val);
        }
        int maxDis = -1;
        for (int i = 0; i < disappear.size(); i++)  maxDis = max(maxDis, disappear[i]);
        pq.push({ 0, 0 });
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int curCost = -top[0], curV = top[1];
            if (curCost >= disappear[curV] || ans[curV] < curCost)  continue;
            ans[curV] = curCost;
            for (auto it : edge[curV]) {
                int nextV = it.first, nextCost = it.second;
                if (ans[nextV] <= curCost + nextCost || curCost + nextCost >= disappear[nextV]) continue;
                pq.push({ -(curCost + nextCost), nextV });
            }
        }
        for (int i = 0; i < n; i++) if (ans[i] == 1e9)   ans[i] = -1;
        return ans;
    }
};

/*
    가중치가 있는 무향그래프, 정수 배열 dis[i]가 주어진다
    dis[i] = 정점 i가 사라지는 시간을 의미한다.
    정점 0에서 부터 i번째 노드까지 도달가능한 최소 시간을 계산해라. 불가능하면 -1
    edge는 여러개 존재할 수 있다.
    정점 갯수 n <= 10^5

    visit[i] = 0에서 정점 i까지 도착시 최소 비용
    0에서부터 다익스트라 돌면서 visit 값을 갱신해 나간다.
    단 dis[i] >= 이면 -1

    * 연결된 edge를 돌면서 가지치기를 하는 것 보다, 현재 정점에서 한개라도 조건이 만족 안되면 가지치기를 하는 것이 훨씬 효율적임
*/
