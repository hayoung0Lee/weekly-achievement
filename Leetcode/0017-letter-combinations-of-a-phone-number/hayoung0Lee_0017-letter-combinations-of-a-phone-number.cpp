#include <string>

class Solution {
    string pad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> answer;
    string str;
    
    void recursive(string digits, int index){
        if(str.size() == digits.size()){
            if(str != "") {
                answer.push_back(str);
            }
            return;
        }
        
        for(int i = index; i < digits.size(); i++){
            for(int j = 0; j < pad[digits[i] - '0'].size(); j++){
                str += pad[digits[i] - '0'][j];     
                recursive(digits, i + 1);
                str.pop_back();
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        recursive(digits, 0);
        return answer;
    }
};