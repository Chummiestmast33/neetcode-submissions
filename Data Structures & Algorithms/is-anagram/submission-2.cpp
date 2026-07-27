class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        for (char a : s) {
            sMap[a]++;
        }
        unordered_map<char,int> tMap;
        for(char a: t){
            tMap[a]++;
        }
        return tMap == sMap;
    }
};
