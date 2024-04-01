class Solution {
public:    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        // a b a
        // a b b a
        while(left <= right){
            // alphanumeric - alphabet이거나 숫자인것
            // non-alphanumeric - alphabet도 숫자도 아닌것
            if(!isalpha(s[left]) && !isdigit(s[left])){
                left++;
            }else if(!isalpha(s[right]) && !isdigit(s[right])){
                right--;
            }else if(tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
            }else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
        }
        
        return true;
    }
};