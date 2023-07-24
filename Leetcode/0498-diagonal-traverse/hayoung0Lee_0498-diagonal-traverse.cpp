class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {            
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> starter;
        vector<int> answer;
        
        for(int i = 0; i < n; i++){
            starter.push_back({0, i});
        }
        
        for(int i = 1; i < m; i++){
            starter.push_back({i, n-1});
        }
        
        // for(int i = 0; i < starter.size(); i++){
        //     std::cout << starter[i][0] << ", " << starter[i][1] << std::endl;
        // }
        
        int reversed = true;
        for(int i = 0; i < starter.size(); i++){
            int x = starter[i][0];
            int y = starter[i][1];
            
            vector<int> temp;
         
            while(true){
                if(x >= m || y < 0){
                    break;
                }

                temp.push_back(mat[x][y]);
                x++;
                y--;
            }
            
            if(reversed){
                std::reverse(temp.begin(), temp.end());   
            }
            for(int j = 0; j < temp.size(); j++){
                answer.push_back(temp[j]);
            }
            reversed = !reversed;
        }
        
        return answer;
    }
};