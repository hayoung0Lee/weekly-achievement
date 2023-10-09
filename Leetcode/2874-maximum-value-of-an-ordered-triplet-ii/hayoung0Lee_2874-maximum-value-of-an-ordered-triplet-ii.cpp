class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        // i < j < k
        // (nums[i] - nums[j]) * nums[k]
        // prefix_max[i] = max(nums[0], ...., nums[i]) // 누적해서 각 index마다 최대를 구한다. 
        // suffix_max[k] = max(nums[k], nums[k+1], ... nums[n - 1]) // k는 최대를 구한다
        // j는 그사이에 있는 값이다. 
        vector<int> prefix_max(nums.size());
        vector<int> suffix_max(nums.size());
        
        prefix_max[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix_max[i] = max(prefix_max[i-1], nums[i]);
        }
        
        suffix_max[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix_max[i] = max(suffix_max[i+1], nums[i]);
        }
        
        for(int j = 1; j < nums.size() - 1; j++){
            long long temp = (prefix_max[j-1] - nums[j]);
            temp *= suffix_max[j + 1];
            answer = max(answer, temp);
        }
        
        
        return answer;
    }
};