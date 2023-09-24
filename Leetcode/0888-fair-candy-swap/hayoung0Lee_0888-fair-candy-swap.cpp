class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>ans;
        int asum=0,bsum=0;
        for(auto x:aliceSizes) 
            asum+=x;
        for(auto x:bobSizes)
            bsum+=x;
        int diff=(bsum-asum)/2; // bobSizes: 4, AliceSizes: 2 -> diff: 1 각각 1을 빼고 1을 더하면 같아짐
        unordered_set<int> s(bobSizes.begin(), bobSizes.end());
        
        for(auto x: aliceSizes)
        {
            // 1 + 1 => 2 2가 bobSizes에 있다는 뜻은 1(Alice)이랑 2(Bob)랑 바꾼다는 뜻인데, 
            // [1, 1] [1 + diff, 2] 를 바꾼다는 뜻
            if(s.find(x + diff) != s.end()){
                ans.push_back(x);
                ans.push_back(x+diff);
                break;
            }
        }      
        
        return ans;
    }
};