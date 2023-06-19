class Solution {
public:
    int arr[34][34];
    
    int calc(int ii, int jj){
        if(arr[ii][jj] != 0){
            return arr[ii][jj];
        }
        
        calc(ii-1, jj - 1);
        
        arr[ii][0] = 1;
            
        for(int j = 1; j < jj; j++){
            arr[ii][j] = arr[ii - 1][j-1] + arr[ii - 1][j];
        }
        
        arr[ii][jj] = 1;
        
        return 1;
    }
    
    vector<int> getRow(int rowIndex) {
        arr[0][0] = 1;
        arr[1][0] = 1;
        arr[1][1] = 1;
        arr[2][0] = 1;
        arr[2][1] = arr[1][0] + arr[1][1];
        arr[2][2] = 1;
        
        vector<int> v;
        
        calc(rowIndex, rowIndex);
            
        for(int i = 0; i <= rowIndex; i++){
            v.push_back(arr[rowIndex][i]);
        }
        
        return v;
    }
};