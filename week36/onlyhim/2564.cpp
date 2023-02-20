class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, pair<int,int>> mm;
        for (int len = 1; len <= 30; len++) {
            int l = s.size() - len, r = s.size() - 1;
            while (l >= 0) {
                if ((len > 1 && s[l] != '0')|| len==1) {
                    int bin = stoi(s.substr(l, len), 0, 2);
                    if (mm.find(bin) != mm.end()) {
                        if (mm[bin].first > l) {
                            mm[bin].first = l;
                            mm[bin].second = r;
                        }
                    }
                    else mm.insert({ bin, {l, r} });
                }
                if (r - l + 1 >= len) r--;
                l--;
            }
        }
        vector<vector<int>> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int bin = stoi(to_string(queries[i][0] ^ queries[i][1]));
            auto it = mm.find(bin);
            if (it == mm.end())    ans[i] = { -1, -1 };
            else ans[i] = { it->second.first, it->second.second };
        }
        return ans;
    }
};
