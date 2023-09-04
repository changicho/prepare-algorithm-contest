#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int ans = 0;
vector<int> ans2;
void KMP(string t, string p) {
	vector<int> pi(p.size(),0);
	int k = 0;
	for (int i = 1; i < p.size(); i++) {
		while (k > 0 && p[i] != p[k])	k = pi[k - 1];
		if (p[k] == p[i])	pi[i] = ++k;
	}
	int q = 0;
	for (int i = 0; i < t.size(); i++) {
		while (q > 0 && p[q] != t[i]) q = pi[q - 1];
		if (p[q] == t[i])	q++;
		if (q == p.size()) {
			ans2.push_back(i-p.size()+2);
			ans++;
			q = pi[q - 1];
		}
	}
}

int main() {
	string txt, pat;
	getline(cin, txt);
	getline(cin, pat);
	KMP(txt, pat);
	cout << ans << endl;
	
	for (auto i : ans2)	printf("%d\n", i);
}
