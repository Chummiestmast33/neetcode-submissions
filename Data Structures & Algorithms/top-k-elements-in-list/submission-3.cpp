class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> helper;
        for (int num : nums) {
            helper[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (pair<int, int> p : helper) {
            bucket[p.second].push_back(p.first);
        }
        vector<int> answer;
        int counter = 0;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            vector<int> v = bucket[i];
            for (int number : v) {
                answer.push_back(number);
                ++counter;
                if(counter == k){
                    return answer;
                }
            }
        }
        return answer;
    }
};
