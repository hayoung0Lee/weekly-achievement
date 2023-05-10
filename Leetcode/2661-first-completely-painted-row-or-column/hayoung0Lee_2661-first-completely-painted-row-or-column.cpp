class Solution {
public:
    // https://leetcode.com/problems/first-completely-painted-row-or-column/discuss/3468316/Easy-to-understand-code-oror-Simple-Mapping
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(); 
        int n = mat[0].size();
        
        // 행이 m개 있고, 각 행이 얼마나 차있는지를 체크한다. 
        vector<int>rowFill(m, 0);
        // 열도 마찬가지
        vector<int>colFill(n, 0);
        
        // 값은 유니크하기때문에 값을 기준으로 인덱스를 구할 수 있다. 
        vector<int>rowIndexMap((m*n) + 1);
        vector<int>colIndexMap((m*n) + 1);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = mat[i][j];
                rowIndexMap[val] = i;
                colIndexMap[val] = j;
            }
        }
        
        // arr를 순회한다. 
        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            int rowIndex = rowIndexMap[val];
            int colIndex = colIndexMap[val];
            
            rowFill[rowIndex]++;
            colFill[colIndex]++;
            
            if(rowFill[rowIndex] == n || colFill[colIndex] == m) return i;
        }
        
        return -1;  
    }
};