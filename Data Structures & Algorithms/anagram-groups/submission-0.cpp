class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int pos = 0;
        unordered_map<string, int> wordIndex;
        for (string text : strs) {
            string value;
            vector<int> countChar(26);
            for (char c : text) {
                countChar[c - 'a']++;
            }
            for (int i = 0; i < countChar.size(); i++) {
                value += (char)(i + 'a');
                value += to_string(countChar[i]);
            }
            if (wordIndex.find(value) != wordIndex.end()) {
                ans[wordIndex[value]].push_back(text);
            } else {
                wordIndex[value] = pos;
                ans.push_back({text});
                pos++;
            }
        }
        return ans;
    }
};