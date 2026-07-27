class Solution {
public:
    bool isAnagram(string s, string t) {
if(s.size() == t.size()){
            unordered_map<char,int> sMap;
            unordered_map<char,int> tMap;
            for(char cha: s){
                sMap[cha] = 1 + sMap.count(cha);
            }
            for(char cha:t){
                tMap[cha] = 1 + tMap.count(cha);
            }
            return tMap == sMap;
        }
        return false;
    }
};
