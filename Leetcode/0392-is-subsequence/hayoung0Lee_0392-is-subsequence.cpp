class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        
        while(left <= s.size() && right <= t.size()){
            if(s[left] == t[right]){
                left++;
                right++;
            }else{
                right++;
            }
        }
        
        if(left < s.size()){
            return false;
        }
        
        return true;
    }
};