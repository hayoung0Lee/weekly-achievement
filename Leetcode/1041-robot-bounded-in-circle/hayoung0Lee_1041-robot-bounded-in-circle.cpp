class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<std::vector<int>> dir;
        // +1방향은 오른쪽으로 돌기 R인 경우
        // -1방향은 왼쪽으로 돌기 L인 경우
        dir.push_back({0, 1}); // north
        dir.push_back({1, 0}); // east
        dir.push_back({0, -1}); // south
        dir.push_back({-1, 0}); // west
        
        int answer = false;
        int pos[2] = {0, 0};
        int dir_index = 0;
        int count = 0;
        
        for(int i = 0; i < instructions.size(); i++){
            if(instructions[i] == 'L'){
                // left
                dir_index++;
                if(dir_index > 3){
                    dir_index = 0;
                }
                count++;
            } else if(instructions[i] == 'R'){
                // right
                dir_index--;
                if(dir_index < 0){
                    dir_index = 3;
                }
                count++;
            } else {
                pos[0] += dir[dir_index][0];
                pos[1] += dir[dir_index][1];
            }   
        }
        
        
        return pos[0] == 0 && pos[1] == 0 || dir_index != 0;
    }
};