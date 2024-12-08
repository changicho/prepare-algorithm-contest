class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> candidate; // max heap
        priority_queue<int, vector<int>, greater<int>> choice;  // min heap
        int qIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (qIdx < queries.size() && queries[i][0] == i) {
                candidate.push(queries[i][1]);
                qIdx++;
            }
            nums[i] -= choice.size();
            while (nums[i] > 0 && !candidate.empty() && candidate.top() >= i) {
                choice.push(candidate.top());
                candidate.pop();
                nums[i]--;
            }
            if (nums[i] > 0)    return -1;
            while (!choice.empty() && choice.top() == i)    choice.pop();
        }
        return candidate.size();
    }
};

/*
    query 배열에서 삭제 가능한 최대 원소 갯수를 계산
    
    candidate = 현재 배열의 값을 -1 하기 위해 사용가능한 쿼리의 right idx
    choice = 현재 배열을 커버 가능한 쿼리의 right idx

    배열을 순회하면서 현재 idx가 query의 left 값과 동일하다면 query의 right값을 candidate에 push한다.
    현재 배열에서 chocie의 사이즈만큼 뺀다. 
    만약 nums[i] 라면 쿼리를 더 선택해야 하므로, candidate에서 더 가져온다. candidate는 query의 right idx를 가지고 있으므로, 항상 nums[i]를 커버할 수 있는 것이 보장된다
    chocie는 query의 right idx이므로 i를 증가시키전 choice를 갱신한다. 
    candidate에 모든 query가 1번 들어가므로, candidate에 사용되지 않은 query는 버릴 수 있다. 따라서 candidate size가 답이 된다.

    O(NlogN) / O(N)
*/
