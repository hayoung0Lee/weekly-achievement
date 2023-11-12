class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champion = 0;
        int n = grid.size();
        
        while(true){
            int tempChampion = champion;
            
            for(int i = 0; i < n; i++){
                if(tempChampion != i && grid[tempChampion][i] == 0) {
                    tempChampion = i;
                }    
            }
            
            if(champion == tempChampion) {
                return champion;
            }
            
            champion = tempChampion;
        }
    }
};