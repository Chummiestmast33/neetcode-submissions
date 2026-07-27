class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            set<int> numbers;
    for(int num : nums){
        auto result = numbers.insert(num);
        if(result.second == false){
            return true;
        }
    }
    return false;
    }
};