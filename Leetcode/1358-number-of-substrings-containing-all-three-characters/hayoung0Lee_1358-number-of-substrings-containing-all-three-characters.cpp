class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> m;
        m['a'] = 0; m['b'] = 0; m['c'] = 0;
        
        // https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/3409128/C%2B%2BJavaPythonJavaScript-or-Sliding-Window-or-Hash-Table
        int answer = 0;
        int n = s.size();
        int left = 0; 
        int right = 0;
        
        while(right < n){
            m[s[right]]++;
            
            while(m['a'] && m['b'] && m['c']){
                answer += n - right;
                m[s[left]]--;
                left++;
            }
            
            right++;
        }
        
        
        
        return answer;
    }
};