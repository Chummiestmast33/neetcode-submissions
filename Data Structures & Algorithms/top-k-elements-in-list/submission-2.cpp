class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> helper;
        vector<int> answer(k,0);
        for(int num :  nums){
            helper[num]++;
        }  
        vector<pair<int,int>> pairs;
        for(const auto& p: helper){
            pairs.push_back({p.second,p.first});
        }

        sort(pairs.rbegin(), pairs.rend());

        for(int i = 0; i < k; ++i){
            answer[i] = (pairs[i].second);
        }
        return answer;
    }
};
