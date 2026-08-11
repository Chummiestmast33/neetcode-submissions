class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        vector<bool> boolSet(nums.size(), false);
        dfs(subsets, subset, nums,boolSet, 0 );
        return subsets;
    }

   private:
    void dfs(vector<vector<int>>& subsets, vector<int>& subset, vector<int>& nums,
             vector<bool>& boolNums, int index) {
        if (nums.size() == subset.size()) {
            subsets.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (boolNums[i]) continue;
            subset.push_back(nums[i]);
            boolNums[i] = true;
            dfs(subsets, subset, nums, boolNums, index + 1);
            boolNums[i] = false;
            subset.pop_back();
        }
    }
};
