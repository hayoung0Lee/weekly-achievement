class Solution {    
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<std::vector<int>> dir;
        // north
        // east
        // south
        // west
        // +1방향은 오른쪽으로 돌기 -1인 경우
        // -1방향은 왼쪽으로 돌기 -2인 경우
        dir.push_back({0, 1});
        dir.push_back({1, 0});
        dir.push_back({0, -1});
        dir.push_back({-1, 0});
        
        std::set<std::pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(std::make_pair(obstacle[0], obstacle[1]));
        }

        int j = 0;
        vector<int> pos({0, 0});
        int answer = 0;
        
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                j++;
                if(j > 3){
                    j = 0;
                }
            }else if(commands[i] == -2){
                j--;
                if(j < 0){
                    j = 3;
                }
            }
            else{
                for(int k = 0; k < commands[i]; k++){
                    int next_x = pos[0] + dir[j][0];
                    int next_y = pos[1] + dir[j][1];
                    
                    if(obstacleSet.count(std::make_pair(next_x, next_y))){
                        break;
                    }
                    
                    pos[0] += dir[j][0];
                    pos[1] += dir[j][1];
                    
                    answer = std::max(pos[0] * pos[0] + pos[1] * pos[1], answer);
                }         
            }    
        }
        
        return answer;
    }
};