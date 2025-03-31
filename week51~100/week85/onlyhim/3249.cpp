int ans;

int go(vector<vector<int>>& adj, vector<int>& visit, int cur) {
	if (adj[cur].size() == 0) {
		ans++;
		return 1;
	}
	int childSize = -1, numChild = 0;
	bool isAllSame = 1;
	visit[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (visit[adj[cur][i]])	continue;
		int candidateChild = go(adj, visit, adj[cur][i]);
		if (childSize == -1)	childSize = candidateChild;
		else {
			if (childSize != candidateChild)	isAllSame = 0;
		}
		numChild += candidateChild;
	}
	ans += isAllSame;
	return numChild+1;
}

class Solution {
public:
	int countGoodNodes(vector<vector<int>>& edges) {
		int n = edges.size()+1;
		ans = 0;
		vector<vector<int>> adj(n);
		vector<int> visit(n, 0);
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i][0], b = edges[i][1];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		go(adj, visit, 0);
		return ans;
	}
};

/*
	go(cur) = 루트가 cur인 subtree의 자식노드의 갯수
	명시된 루트노드인 0부터 순회하면서 자식 subtree의 갯수를 각각 카운팅한다.
	leaf node는 항상 good node

	O(n) / O(n)
*/
