#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> sets;
        for (int i = 0; i < nums.size(); i++)   sets.insert(nums[i]);
        for (int i = 0; i < moveFrom.size(); i++) {
            if (sets.find(moveFrom[i]) != sets.end()) {
                sets.erase(moveFrom[i]);
                sets.insert(moveTo[i]);
            }
        }
        vector<int> ans;
        for (auto it : sets)    ans.push_back(it);
        return ans;
    }
};
