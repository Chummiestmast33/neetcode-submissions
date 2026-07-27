class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tarValues;
        for(int i = 0; i < nums.size(); i++){
            if(tarValues.contains(target-nums[i])){
                return {tarValues[target-nums[i]], i};
            }
            tarValues[nums[i]] = i;
        }
    }
};
