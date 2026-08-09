class Solution {
   public:
    void combinationSumBuilder(vector<int>& nums, vector<int>& subset, int& target,
                               vector<vector<int>>& subsetContainer, int index, int sum) {
        if (sum >= target) {
            if (sum == target) subsetContainer.push_back(subset);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            combinationSumBuilder(nums, subset, target, subsetContainer, i, sum + nums[i]);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> subsets;
        vector<int> subset;
        combinationSumBuilder(nums,subset, target, subsets, 0, 0);
        return subsets;
    }
};
