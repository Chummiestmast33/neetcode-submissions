class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int oSize = nums.size();
        vector<int> ans(2 * oSize);

        for (int i = 0; i < oSize; i++)
        {
            ans[i] = nums[i];
            ans[oSize + i] = nums[i];
        }
        return ans;

    }
};