#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct node {
	node() {
		num = 0;
		child.resize(26);
	}
	int num;
	vector<node*> child;
};

void insert(node* root, string& str, int idx) {
	if (str.size() == idx) {
		root->num++;
		return;
	}
	char curChar = str[idx] - 'A';
	if (root->child[curChar] == 0)	root->child[curChar] = new node;
	insert(root->child[curChar], str, idx + 1);
}

void findCandidate(node* root, string& str, int& cnt, string& ansStr) {
	if (root->num != 0) {
		if (root->num >= cnt) {
			if (root->num == cnt) ansStr = min(str, ansStr);
			else {
				cnt = root->num;
				ansStr = str;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (root->child[i] != 0) {
			str += char(i + 'A');
			findCandidate(root->child[i], str, cnt, ansStr);
			str.pop_back();
		}
	}
}

void findPrefix(node* root, string& str, int idx, int& cnt, string& ansStr) {
	if (str.size() == idx) {
		findCandidate(root, str, cnt, ansStr);
		return;
	}
	char curChar = str[idx] - 'A';
	if (root->child[curChar] == 0)	return;
	findPrefix(root->child[curChar], str, idx + 1, cnt, ansStr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node root;
	int n, k;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		insert(&root, str, 0);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> str;
		string ansStr;
		int ansCount = 0;
		findPrefix(&root, str, 0, ansCount, ansStr);
		if (ansCount == 0)	cout << 0 << '\n';
		else cout << ansStr << ' ' << ansCount << '\n';
	}
	return 0;
}
