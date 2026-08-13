class Solution {
   public:
    void dfs(int& n, string& currentPath, vector<string>& ans, int open, int end) {
        if (open == n && end == n) {
            ans.push_back(currentPath);
            return;
        }

        if (open < n) {
            currentPath.push_back('(');
            dfs(n, currentPath, ans, open + 1, end);
            currentPath.pop_back();
        }
        if (open > end && end < n) {
            currentPath.push_back(')');
            dfs(n, currentPath, ans, open, end + 1);
            currentPath.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string currentPath;
        vector<string> ans;
        dfs(n, currentPath, ans, 0,0);
        return ans;
    }
};
