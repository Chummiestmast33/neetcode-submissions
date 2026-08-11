class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        vector<bool> boolSet(nums.size(), false);
        dfs(subsets, nums, 0);
        return subsets;
    }

   private:
    void dfs(vector<vector<int>>& subsets, vector<int>& nums, int start) {
        if (start == nums.size()) {
            subsets.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);

            dfs(subsets, nums, start + 1);

            swap(nums[start], nums[i]);
        }
    }
};
