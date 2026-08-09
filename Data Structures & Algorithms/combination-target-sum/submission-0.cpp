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
            sum += nums[i];
            combinationSumBuilder(nums, subset, i, sum);
            subset.pop_back();
            sum -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        numTarget = target;
        combinationSumBuilder(nums, vector<int>(), 0, 0);
        return subsetContainer;
    }
};
