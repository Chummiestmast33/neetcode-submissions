class Solution {
   public:
    void combinationSum(vector<vector<int>>& subsets, vector<int>& candidates, vector<int>& subset,
                        int& target, int index, int sum) {
        if (sum >= target) {
            if (sum == target) subsets.push_back(subset);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (sum + candidates[i] > target) break;
            subset.push_back(candidates[i]);
            combinationSum(subsets, candidates, subset, target, i + 1, sum + candidates[i]);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        combinationSum(ans, candidates, subset, target, 0, 0);
        return ans;
    }
};
