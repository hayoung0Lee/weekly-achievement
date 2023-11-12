class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n); // v[0].push_back(1); // 1이 0보다 쎔
        
        for(int i = 0; i < edges.size(); i++){
            int winner = edges[i][0];
            int loser = edges[i][1];
            
            v[loser].push_back(winner);
        }
        
        int totalWinner = -1;
        
        for(int i = 0; i < n; i++){
            if(totalWinner == -1 && v[i].size() == 0){
                totalWinner = i;
            }else if(totalWinner != -1 && v[i].size() == 0){
                totalWinner = -1;
                break;
            }
        }
        
        
        return totalWinner;
    }
};