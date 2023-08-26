class Solution {
public:
    int maxJump(vector<int>& stones) {
        // maxmum distance인데, 그중에서는 최대한 작게 만들기
        // 모든 돌이 그다음 돌은 스킵하면 모든 돌을 최대 한번씩 밟게 되지만
        // 각각의 거리가 최소화 될 수 있다. 
        // 0, 1, 2, 3, 4, 5
        // 0 -> 2, 2 -> 4  
        // 1 -> 3, 3 -> 5
        // 이때 4->5 같은 거리는 3 -> 5보다 작기때문에 minimum of cost가 될수 없다. 
        // 이때 0->1 도 0 -> 2보다 작기때문에 minimum of cost가 될수 없다. 
        // 그래서 총 점프는 0 -> 2 / 2 -> 4 /  4 ->5  / 5 -> 3 /  3 -> 1 -> 1-> 0
        if(stones.size() == 2){
            return stones[1];
        }
        
        int cost = 0;
        for(int i = 0; i < stones.size() - 2; i++){
            cost = max(stones[i+2] - stones[i], cost);
        }
        
        return cost;
    }
};