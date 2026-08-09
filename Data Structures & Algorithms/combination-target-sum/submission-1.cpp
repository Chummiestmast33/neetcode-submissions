class Solution {
   public:
    vector<vector<int>> subsetContainer;
    int numTarget;
    void combinationSumBuilder(vector<int>& nums, vector<int> subset, int index, int sum) {
        if (sum >= numTarget) {
            if (sum == numTarget) subsetContainer.push_back(subset);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            combinationSumBuilder(nums, subset, i, sum + nums[i]);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        numTarget = target;
        combinationSumBuilder(nums, vector<int>(), 0, 0);
        return subsetContainer;
    }
};
