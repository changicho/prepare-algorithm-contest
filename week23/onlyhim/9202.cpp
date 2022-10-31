#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int goy[8] = { -1,-1,-1, 0, 1, 1, 1, 0 };
int gox[8] = { -1,0,1,1,1,0,-1,-1 };
int points[8] = { 0, 0, 1, 1, 2, 3, 5, 11 };

bool judge(int y, int x) {
	return y >= 0 && x >= 0 && y < 4 && x < 4;
}

int toNum(char a) {
	return a - 'A';
}

struct trieNode {
	trieNode() {
		v.resize(26, 0);
		isTerminal = 0;
	}
	vector<trieNode*> v;
	bool isTerminal;
};

void makeTrie(string& s, int sidx, trieNode* p) {
	if (sidx == s.size()) {
		p->isTerminal = 1;
		return;
	}
	int idx = toNum(s[sidx]);
	if (p->v[idx] == 0) {
		p->v[idx] = new trieNode();
	}
	makeTrie(s, sidx + 1, p->v[idx]);
}

bool isPrefix(trieNode* p, string& s, int sidx) {
	if (sidx == s.size()) {
		return 1;
	}
	int idx = toNum(s[sidx]);
	if (p->v[idx]) {
		return isPrefix(p->v[idx], s, sidx + 1);
	}
	else return 0;
}

bool find(trieNode* p, string& s, int sidx) {
	if (sidx == s.size()) {
		return p->isTerminal;
	}
	int idx = toNum(s[sidx]);
	if (p->v[idx]) {
		return find(p->v[idx], s, sidx + 1);
	}
	else return 0;
}

int score, cnt, longs;
string longss;

void go(vector<vector<char>>& g, unordered_set<string>& sets, trieNode* p, string& s, int y ,int x, int idx) {
	if (idx >= 8)	return;
	for (int i = 0; i < 8; i++) {
		int ny = goy[i] + y;
		int nx = gox[i] + x;
		if (judge(ny, nx)) {
			if (g[ny][nx] == '.')	continue;
			s += g[ny][nx];
			char curChar = g[ny][nx];
			g[ny][nx] = '.';
			if (isPrefix(p, s, 0) && find(p, s, 0)) {
				if (sets.find(s) == sets.end()) {
					sets.insert(s);
					score += points[idx];
					cnt++;
					if (idx >= longs) {
						longs = idx;
						if (longss.size() < s.size())	longss = s;
						else if (longss.size() == s.size())	longss = min(longss, s);
					}
				}
			}
			go(g, sets, p, s, ny, nx, idx + 1);
			g[ny][nx] = curChar;
			s.pop_back();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w,b;
	string s;
	trieNode root;
	cin >> w;
	for (int i = 0; i < w; i++) {
		cin >> s;
		makeTrie(s, 0, &root);
	}
	cin >> b;
	vector<vector<char>> g(4, vector<char>(4));
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 4; j++)	for (int k = 0; k < 4; k++)	cin >> g[j][k];
		unordered_set<string> sets;
		score = 0;
		cnt = 0;
		longs = 0;
		longss = "z";
		string ss;
		for (int j = 0; j < 4; j++)	for (int k = 0; k < 4; k++)	go(g, sets, &root, ss, j, k, 0);
		cout << score << ' ' << longss << ' ' << cnt << '\n';
	}
}
