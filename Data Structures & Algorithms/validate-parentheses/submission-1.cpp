class Solution {
   public:
    bool isValid(string s) {
        stack<char> pile;
        if (s.length() % 2 == 0) {
            
            for (int i = 0; i < s.size(); i++) {
                if (pile.empty())
                    pile.push(s[i]);
                else if ((pile.top() == '[' && s[i] == ']') || (pile.top() == '{' && s[i] == '}') ||
                         (pile.top() == '(' && s[i] == ')')) {
                    pile.pop();
                }
                else{
                    pile.push(s[i]);
                }
            }
            return pile.empty();
        }
        return false;
    }
};