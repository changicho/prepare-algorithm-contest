#include <string>
#include <vector>

using namespace std;
int ansUser, ansRevenue;

void go(vector<vector<int>>& users, vector<int>& emoticon, vector<pair<int, double>>& discount, int userIdx, int curRevenue, int curPlusUser) {
    if (userIdx == users.size()) {
        if (ansUser < curPlusUser || (ansUser == curPlusUser && ansRevenue < curRevenue)) {
            ansUser = curPlusUser;
            ansRevenue = curRevenue;
        }
        return;
    }
    int revenue = 0;
    for (int j = 0; j < emoticon.size(); j++) {
        int curDisPercent = discount[j].first;
        if (curDisPercent >= users[userIdx][0]) {
            revenue += emoticon[j] * discount[j].second;
        }
    }
    if (revenue >= users[userIdx][1]) {
        go(users, emoticon, discount, userIdx + 1, curRevenue, curPlusUser + 1);
    }
    else go(users, emoticon, discount, userIdx + 1, curRevenue + revenue, curPlusUser);
}

void makeDiscount(vector<vector<int>>& users, vector<int>& emoticon, vector<pair<int,double>>& dis, int idx) {
    if (idx == emoticon.size()) {
        go(users, emoticon, dis, 0, 0, 0);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            dis[idx].first = 10;
            dis[idx].second = 0.9;
        }
        else if (i == 2) {
            dis[idx].first = 20;
            dis[idx].second = 0.8;
        }
        else if (i == 1) {
            dis[idx].first = 30;
            dis[idx].second = 0.7;
        }
        else if (i == 0) {
            dis[idx].first = 40;
            dis[idx].second = 0.6;
        }
        makeDiscount(users, emoticon, dis, idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> ans;
    vector<pair<int, double>> dis(emoticons.size());
    ansUser = ansRevenue = 0;
    makeDiscount(users, emoticons, dis, 0);
    ans.push_back(ansUser);
    ans.push_back(ansRevenue);
    return ans;
}


/*
가능한 경우의 수 = emoticons갯수^할인종류 = m^4 <= 7^4
가능한 경우의 수를 유저마다 이모티콘 갯수만큼 돌면서 확인한다.
O(nm * 7^4)

*/
