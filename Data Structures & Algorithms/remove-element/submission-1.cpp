class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        auto it = find(nums.begin(), nums.end(), val);
        do {
            if(it != nums.end())
                nums.erase(it);
            it = find(nums.begin(), nums.end(), val);
        } while (it != nums.end());
        return nums.size();
    }
};