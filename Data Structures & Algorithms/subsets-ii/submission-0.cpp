class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currentPath;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, currentPath, ans, 0);
        return ans;
    }

   private:
    void dfs(vector<int>& nums, vector<int>& currentPath, vector<vector<int>>& ans, int index) {
        ans.push_back(currentPath);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            currentPath.push_back(nums[i]);
            dfs(nums, currentPath, ans, i + 1);
            currentPath.pop_back();
        }
    }
};
