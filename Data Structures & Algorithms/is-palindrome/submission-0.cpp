class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        for(int i = 0; i < s.length(); i++)
            if(isalnum(s[i]))
                str.push_back(tolower(s[i]));
        int max = str.size() / 2;
        
        for(int i = 0; i < max; i++){
            if(str[i] != str[str.size() - 1 -i])
                return false;
        }
        return true;
    }
};
