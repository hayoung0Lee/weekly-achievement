class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char, int> m;
        
        int left = 0;
        int right = 1;
        int answer = 0;
        
        if(s.size() < 3) {
            return answer;
        }
        
        while(right < 3){
            if(m.find(s[right - 1]) != m.end()){
                m[s[right - 1]]++;
            }else{
                m[s[right - 1]] = 1;
            }
            right++;
        }
        
        // 3개가 될때까지 체크    
        while(right <= s.size()){
            if(m.find(s[right - 1]) != m.end()){
                m[s[right - 1]]++;
            }else{
                m[s[right - 1]] = 1;
            }
            
            if(m[s[left]] == 1 && m[s[left + 1]] == 1 && m[s[left + 2]] == 1){
                answer++;
            }
            
            m[s[left]]--;
            left++;
            right++;
        }
    
        return answer;
    }
};