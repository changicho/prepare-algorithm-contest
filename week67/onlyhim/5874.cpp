int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	vector<int> leftLegs;
	vector<int> rightLegs;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(' && str[i + 1] == '(')	leftLegs.push_back(i);
		if (str[i] == ')' && str[i + 1] == ')')	rightLegs.push_back(i);
	}
	long long ans = 0;
	int rightLegsIdx = 0;
	for (int i = 0; i < leftLegs.size(); i++) {
		while (rightLegsIdx < rightLegs.size() && rightLegs[rightLegsIdx] <= leftLegs[i])	rightLegsIdx++;
		ans += rightLegs.size() - rightLegsIdx;
	}
	cout << ans;
	return 0;
}
