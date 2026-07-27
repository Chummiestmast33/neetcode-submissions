class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //String del resultado
        string res = "";

        //Recorrer todo el string
        for(int i = 0; i < strs[0].size(); i++){
            //Recorrer todo string
            for(string s : strs){
                //Verificar si no se ha pasado del tamaño y que sean iguales
                if (i == s.size() || s[i] != strs[0][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
    }
};