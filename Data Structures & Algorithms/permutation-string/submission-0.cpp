class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int k = s1.length();
        int l = 0;
        vector<int> c1(26, 0);
        for (char c : s1) {
            c1[c - 'a']++;
        }
        vector<int> c2(26, 0);
        for (int r = s1.length() - 1; r < s2.length(); r++) {
            if (l == 0) {
                for (int i = 0; i < s1.length(); i++) {
                    c2[s2[i] - 'a']++;
                }
            }
            if(l != 0){
                c2[s2[l-1] - 'a']--;
                c2[s2[r] - 'a']++;
            }
            if (c1 == c2) {
                return true;
            }
            l++;
        }
        return false;
    }
};
