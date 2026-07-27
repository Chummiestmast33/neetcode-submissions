class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        int numsSize = nums.size();
        for(int i = 0; i < numsSize; i++){
            int qTarget = target - nums[i];
            if(numbers.contains(qTarget)){
                return {numbers[qTarget], i};
            }else{
                numbers.insert({nums[i],i});
            }
        }
    }
};
