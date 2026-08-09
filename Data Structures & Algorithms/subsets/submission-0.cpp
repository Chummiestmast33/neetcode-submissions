class Solution {
    vector<vector<int>> subsetsVector;

   public:
    void subsetsBuilder(vector<int>& nums, int index, vector<int> subset) {
        subsetsVector.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            subsetsBuilder(nums, i + 1, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (subsetsVector.size() > 0) subsetsVector.clear();
        subsetsBuilder(nums, 0, vector<int>());
        return subsetsVector;
    }
};
