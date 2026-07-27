class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for(int num : nums){
            if(numbers.insert(num).second == false){
                return true;
            }
        }
        return false;
    }
};