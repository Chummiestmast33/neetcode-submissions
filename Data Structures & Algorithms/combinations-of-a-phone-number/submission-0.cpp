class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<vector<char>> charDigits = {{},
                                           {},
                                           {'a', 'b', 'c'},
                                           {'d', 'e', 'f'},
                                           {'g', 'h', 'i'},
                                           {'j', 'k', 'l'},
                                           {'m', 'n', 'o'},
                                           {'p', 'q', 'r', 's'},
                                           {'t', 'u', 'v'},
                                           {'w', 'x', 'y', 'z'}};
        vector<string> ans;
        string path;
        dfs(charDigits, digits, path, ans, 0);
        return ans;
    }

   private:
    void dfs(vector<vector<char>>& charDigits, string& digits, string& path, vector<string>& ans,
             int index) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < charDigits[digits[index] - '0'].size(); i++) {
            path.push_back(charDigits[digits[index] - '0'][i]);
            dfs(charDigits, digits, path, ans, index + 1);
            path.pop_back();
        }
    }
};
