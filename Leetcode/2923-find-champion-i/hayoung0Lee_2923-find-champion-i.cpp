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
            
            // tempChampion이 그대로라는 뜻은 얘보다 더 잘 싸우는애가 아예 없다는 뜻. 
            // 반드시 하나만 있음. 
            if(champion == tempChampion) {
                return champion;
            }
            
            champion = tempChampion;
        }
    }
};