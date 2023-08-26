class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans(2, -1); // {-1, -1}
        map <int,int> mp; 
        
        int aliceSum = 0; 
        for(int i = 0; i < aliceSizes.size(); i++){
            aliceSum += aliceSizes[i];
        }
        
        int bobSum = 0; 
        for(int i = 0; i < bobSizes.size(); i++){
            mp[bobSizes[i]] = 1; // add value
            bobSum += bobSizes[i];
        }
        
        // aliceSum - a[i] + b[j] = bobSum - b[j] + a[i]
        // b[i] = (bobSum - aliceSum + a[i] + a[i]) / 2
        for(int i = 0; i < aliceSizes.size(); i++){
            if(mp.find((bobSum - aliceSum + aliceSizes[i] + aliceSizes[i]) / 2) != mp.end()){
                ans[0] = aliceSizes[i];
                ans[1] = (bobSum - aliceSum + aliceSizes[i] + aliceSizes[i]) / 2;
            }
        }

        return ans;
    }
};