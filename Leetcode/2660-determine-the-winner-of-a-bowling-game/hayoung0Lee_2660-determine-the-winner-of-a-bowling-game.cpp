class Solution {
public:
    int getScore(vector<int>& player){
        int score = 0 ;
        
        for(int i = 0; i < player.size(); i++){
            if(i == 0){
                score += player[i];
            }else if(i == 1){
                score += (player[i-1] == 10 ? player[i] * 2 : player[i]);
            }else{
                score += ((player[i-1] == 10 || player[i-2] == 10) ? player[i] * 2 : player[i]);
            }
        }
        
        return score;
    }
    
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = getScore(player1);
        int score2 = getScore(player2);
        
        if(score1 == score2){
            return 0;
        }else if(score1 > score2){
            return 1;
        }else{
            return 2;
        }
    }
};