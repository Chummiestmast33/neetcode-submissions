class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> sCounter;
        unordered_map<char, int> tCounter;
        string substring = "";
        int substringSize = 1001;
        for (char c : t) {
            tCounter[c]++;
        }
        int need = tCounter.size();
        int have = 0;
        int r = 0, l = 0;
        while (r < s.size() && l < s.size()) {
            if (sCounter.empty()) {
                if (tCounter.contains(s[r])) {
                    sCounter[s[r]]++;
                    if (tCounter[s[r]] == sCounter[s[r]]) {
                        ++have;
                    }
                }
            }
            // if there is the characters we wanted move the left pointer
            if (have == need) {
                if (substringSize > r - l) {
                    substringSize = r - l;
                    substring = s.substr(l, substringSize + 1);
                }
                ++l;
                if (tCounter.contains(s[l - 1])) {
                    sCounter[s[l - 1]]--;
                    if (tCounter[s[l - 1]] > sCounter[s[l - 1]]) {
                        --have;
                    }
                }

            } else {
                ++r;
                if (r < s.size()) {
                    if (tCounter.contains(s[r])) {
                        sCounter[s[r]]++;
                        if (tCounter[s[r]] == sCounter[s[r]]) {
                            ++have;
                        }
                    }
                }
            }
        }
        return substring;
    }
};
