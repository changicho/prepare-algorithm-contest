pair<int,int> go(TreeNode* p, multiset<int>& s, int curLevel) {
    if (!p) return { 0, curLevel };
    auto left = go(p->left, s, curLevel + 1), right = go(p->right, s, curLevel + 1);
    int numLeftChild = left.first, leftMaxLevel = left.second;
    int numRightChild = right.first, rightMaxLevel = right.second;
    int curLevel = max(leftMaxLevel, rightMaxLevel) - curLevel, curNodeSum = numLeftChild + numRightChild + 1;
    if (pow(2, curLevel) - 1 == curNodeSum)  s.insert(curNodeSum);
    return { curNodeSum, max(leftMaxLevel, rightMaxLevel) };
}

class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        multiset<int> sets;
        go(root, sets, 0);
        if (sets.size() < k)    return -1;
        auto it = sets.rbegin(); // 역방향 이터레이터 사용
        std::advance(it, k - 1); // k-1 만큼 이동
        return *it; // k번째 큰 값 반환
    }
};

/*
    이진트리 t와 정수 k가 주어진다. n <= 2000
    t의 k번째 largest perfect binary subtree의 사이즈를 계산해라

    - 트리를 순회하면서 현재 노드를 루트로 하는 subtree의 자식 갯수와 level를 계산한다. (= go함수의 리턴 pair값)
    - 현재 트리가 문제의 조건을 만족하려면 (2^(현재 노드에서 가장 멀리 있는 자식의 Level 값+1) - 1 = 자식 노드의 총 갯수) 여야 한다.
    example 1에서 노드 6의 경우, 현재 노드 level이 2이고 가장 먼 자식의 level이 4 이므로 2^3 -1 = 7이여야 한다
    
    O(N) / O(N)

*/
