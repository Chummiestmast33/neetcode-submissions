class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int r;
        int l = 0;
        int currentCount = 0;
        int maxCount = 0;
        unordered_set<char> charSet;
        for (r = 0; r < s.size(); r++) {
            while (charSet.contains(s[r])) {
                charSet.erase(s[l]);
                --currentCount;
                ++l;
            }
            charSet.insert(s[r]);
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        return maxCount;
    }
};
