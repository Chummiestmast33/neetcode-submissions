class Solution {
   public:
   string replace_all(string str, const string &from, const string &to){
        int pos = 0;
        int flen = from.length();
        int tlen = to.length();
        while((pos = str.find(from,pos)) != string::npos){
            str.replace(pos, flen, to);
            pos += tlen;
        }
        return str;
    }

    string encode(vector<string>& strs) {
        string answer = "";
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            if (strs[i] == "") {
                answer.append("\"\"");
            } else {
                string replacement = replace_all(strs[i], " ", "%*");
                answer.append(replacement);
            }
            if (i < n - 1) {
                answer.append(" ");
            }
        }
        return answer;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        stringstream ss(s);
        string text;
        while (ss >> text) {
            if (text == "\"\"") {
                answer.push_back("");
            } else {
                string replacement = replace_all(text, "%*", " ");
                answer.push_back(replacement);
            }
        }
        return answer;
    }

    
};
