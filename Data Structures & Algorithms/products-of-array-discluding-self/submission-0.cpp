class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> prefix;
        vector<int> suffix;
        int numsSize = nums.size();
        prefix.push_back(nums[0]);
        suffix.push_back(nums[numsSize - 1]);
        for (int i = 1; i < numsSize; i++) {
            prefix.push_back(prefix[i - 1] * nums[i]);
            suffix.push_back(suffix[i - 1] * nums[(numsSize - 1) - i]);
        }
        for (int i = 0; i < numsSize; i++) {
            if (i == numsSize - 1) {
                ans.push_back(prefix[i-1]);
            } else if (i == 0) {
                ans.push_back(suffix[numsSize-2]);
            } else {
                ans.push_back(prefix[i - 1] * suffix[(numsSize - 2) - i]);
            }
        }
        return ans;
    }
};
