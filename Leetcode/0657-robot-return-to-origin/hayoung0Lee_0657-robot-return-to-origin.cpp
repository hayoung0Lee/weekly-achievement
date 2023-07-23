class Solution {
public:
    std::unordered_map<std::string, std::vector<int>> m;
    
    bool judgeCircle(string moves) {
        m["R"] = std::vector<int>{0, 1};
        m["L"] = std::vector<int>{0, -1};
        m["U"] = std::vector<int>{-1, 0};
        m["D"] = std::vector<int>{1, 0};
        
        std::vector<int> robot{0, 0};
        
        for(int i = 0; i < moves.size(); i++){
            robot[0] += m[moves.substr(i, 1)][0];
            robot[1] += m[moves.substr(i, 1)][1];
        }
                
        if(robot[0] == 0 && robot[1] == 0){
            return true;
        }
        
        return false;
    }
};