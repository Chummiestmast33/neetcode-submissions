class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int size = nums.size();
        for(int num : nums){
            counter[num]++;
            if(counter[num] > size/2)
                return num;
        }
    }
};