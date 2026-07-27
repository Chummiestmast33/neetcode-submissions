class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> s;
        s.push({0, temperatures[0]});
        for(int i = 1; i < temperatures.size(); i++){
            while(!s.empty() && s.top().second < temperatures[i]){
                result[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push({i,temperatures[i]});
        }
        return result;
    }
};
