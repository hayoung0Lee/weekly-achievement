class Solution {
public: 
    int arr[51][5];
    
    int count(int n, int c){
        // length is n, and ends with c
        if(arr[n][c] != 0){
            return arr[n][c];
        }
        
        int ans = 0;
        
        for(int i = 0; i <= c; i++){
            ans += count(n-1, i);
        }
        
        arr[n][c] = ans;
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        arr[1][0] = 1;
        arr[1][1] = 1;
        arr[1][2] = 1;
        arr[1][3] = 1;
        arr[1][4] = 1;
        
        arr[2][0] = 1;
        arr[2][1] = 2;
        arr[2][2] = 3;
        arr[2][3] = 4;
        arr[2][4] = 5;
        
        arr[3][0] = arr[2][0];
        arr[3][1] = arr[2][0] + arr[2][1];
        arr[3][2] = arr[2][0] + arr[2][1] + arr[2][2];
        arr[3][3] = arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3];
        arr[3][4] = arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3] + arr[2][4];
        
        return count(n, 0) + count(n, 1) + count(n, 2) + count(n, 3) + count(n, 4);   
    }
};