class Solution {
public:
    string pushDominoes(string dominoes) {
        // https://leetcode.com/problems/push-dominoes/discuss/2356371/Easy-Solution-using-BFS
        queue<pair<char, int>> q; // left or right, index

        for(int i = 0; i < dominoes.size(); i++){
            if(dominoes[i] != '.'){
                q.push({dominoes[i], i});
            }
        }
        
        vector<pair<int,char>>temp;
        while(!q.empty()){
            int size = q.size(); // 그때그때 큐에 있는걸 다 검사한다. 
            
            while(size--){
                char ch = q.front().first;
                int index = q.front().second;
                q.pop();
                
                if(ch == 'L'){
                    if(index - 2 >= 0 && dominoes[index-2] == 'R') {// R.L
                        // cout << "1" << endl; // 가만히 두면 된다. 
                        continue;
                    }
                    if(index - 1 >= 0 && dominoes[index-1] == '.'){
                        // cout << "2" << endl;
                        q.push({ 'L', index-1});
                        temp.push_back({index-1, 'L'});
                    }           
                }else {
                    // ch == 'R'
                    if(index+2< dominoes.size() and dominoes[index+2]=='L') {
                        // cout << "3" << endl; // 가만히 두면됨. 
                        continue;
                    }
                    if(index+1< dominoes.size() and dominoes[index+1]=='.'){
                        // cout << "4" << endl;
                        q.push({'R', index+1});
                        temp.push_back({index+1,'R'});
                    }
                }  
            }
            for( auto i:temp)//after a level of BFS is done update the original string 
            {
                pair<int,char>&p=i;
                // cout << p.first << ", " << p.second << endl;
                dominoes[p.first]=p.second;
            }
            // cout << "here" <<  endl;
        }
        return dominoes;
    }
};