class Solution {
public:
    int arr[100][100];
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        arr[0][0] = obstacleGrid[0][0] ? 0 : 1;
        
        for(int i = 1; i < m; i++){
            arr[i][0] = obstacleGrid[i][0] ? 0 : arr[i-1][0];
        }
        
        for(int j = 1; j < n; j++){
            arr[0][j] = obstacleGrid[0][j] ? 0 : arr[0][j-1];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    arr[i][j] = 0;
                }else{
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];                  
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        return arr[m-1][n-1];
    }
};