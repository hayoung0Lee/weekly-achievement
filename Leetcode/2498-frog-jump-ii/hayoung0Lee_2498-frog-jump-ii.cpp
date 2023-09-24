class Solution {
public:
    int maxJump(vector<int>& stones) {
        // stones = [0,2,5,6,7]
        if(stones.size() == 2) {
            // stones = [0, 8] // max 8
            return stones[1];
        }
        
        int cost = 0; // 코스트 자체는 가장 큰 점프길이
        // 구해야하는건 이거의 가장 최솟값. 
        
        // maximum distance인데, 그중에서는 최대한 작게 만들기
        // 모든 돌이 그다음 돌은 스킵하면 모든 돌을 최대 한번씩 밟게 되고
        // 각각의 거리가 최소화 될 수 있다. 
        // 0, 1, 2, 3, 4, 5
        // 0->2,1->3,2->4,3->5
        // 이때 4->5 같은 거리는 3->5보다 작기때문에 maximum length of a jump가 될수 없다. 
        // 이때 0->1 도 0 -> 2보다 작기때문에 minimum of cost가 될수 없다. 
        // 그래서 총 점프는 0 -> 2 / 2 -> 4 /  4 ->5  / 5 -> 3 /  3 -> 1 -> 1-> 0
        // stones = [0,2,5,6,7]
        // 모든 돌을 다 점프를 하는 경우를 구하면 그 경우에 가장 짧게 뛰는 경우가 무조건 나오고, 
        // 그때 가장 긴걸 구하면 정답이다. 
        for(int i = 0; i < stones.size() - 2; i++){
            cost = max(stones[i+2] - stones[i], cost);
        }
        
        return cost;
    }
};