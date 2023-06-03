class Solution {
public:
    bool divisorGame(int n) {
        //https://leetcode.com/problems/divisor-game/discuss/1949351/Easy-C%2B%2B-Solution-or-DP-Bottom-Up-or-Explained
        if(n == 1) {
            // d[1] 일때 Alice가 어떤 move도 못함
            return false;
        }
        
        vector<int> dp(n+1, 0);
        
        for(int j = 2; j <= n; j++){
            // dp[j]일때 Alice가 이기는지            
            for(int i = 1; i < j; i++){
                // j 보다 작으면서 j % i == 0인 i를 하나 고른다. 
                // 이때 dp[j-i]는 Bob이 지는지. Bob이 지는 i를 뽑았을거라고 친다(optimal하게 플레이한다고함)
                if(j % i == 0 && dp[j-i] == 0){
                    dp[j] = 1;
                }
            }
        }
        
        if(dp[n]){
            return true;
        }else{
            return false;
        }    
    }
};